#include <iostream>
#include "Stock.h"
#include "Node.h"

// ===========================
// Forward Linked List of stock objects, project 3
// CMPE 126, section 6
// Arman Sadeghi
// October 7, 2020
// ===========================

Node* head = NULL;
Node* tail = NULL;
int currentSize = 0;

void insertFront(Stock stk){
    // create a new node
    Node* newNode = new Node;
    // set the current node to stock
    newNode->current = stk;
    if (currentSize == 0){
        head = newNode;
        head->next = tail;
    }
    else {
        newNode->next = head; // insert at the front
        head = newNode;
    }
    currentSize++;
}

void printList(Node* temp){
    int count = 1;
    while (temp != NULL){
        cout << count << ") " << temp->current << endl;
        temp = temp->next;
        count++;
    }
    if (currentSize == 0){
        cout << "List is empty." << endl;
    }
}

Node* findMiddle(){
    Node* slow = head;
    Node* fast = head;
    while (fast->next != NULL){
        if (slow == NULL){
            exit(1); // it should not happen
        }
        // move to the next node
        fast = fast->next;
        if (fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow; // return middle
}

Node* splitHalfList(Node* head){
//    find middle
//    assign middleHead = middle.next
//    middleHead.next = null

    Node* middle = findMiddle();
    Node* middleHead = middle->next;
    middle->next = NULL; // cuts the list
    return middleHead;

    //printList(head);
    //printList(middleHead);
}

int main() {

    srand(time(NULL)); // initialize the random seed

    int nStocks;
    cout << "Enter the numbers of random stocks you wish to generate: ";
    cin >> nStocks;

    for (int i = 0; i < nStocks; ++i) {
        // generate random numbers for shares and cost
        int randomCost = rand() % 100 + 1;
        int randomShares = rand() % 100 + 1;
        Stock s1("A" + to_string(i + 1), randomCost, randomShares);
        insertFront(s1);
    }
    cout << "The following is the complete list:" << endl;
    printList(head);
    cout << endl << "The following is the first half:" << endl;
    printList(splitHalfList(head));
    cout << endl << "The following is the second half:" << endl;
    printList(head);

    return 0;
}
