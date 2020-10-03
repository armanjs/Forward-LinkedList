#include <iostream>
#include "Stock.h"
#include "Node.h"

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

void printList(){
    Node* temp = head;
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
            // it should not happen
            exit(1);
        }
        fast = fast->next;
        slow = slow->next;
        if (fast->next != NULL){
            fast = fast->next;
        }
    }
    return slow;
}

int main() {

    srand(time(NULL)); // initialize the random seed

    for (int i = 0; i < 3; ++i) {
        // generate random numbers for shares and cost
        int randomCost = rand() % 100 + 1;
        int randomShares = rand() % 100 + 1;
        Stock s1("A" + to_string(i + 1), randomCost, randomShares);
        insertFront(s1);
    }
    printList();
    cout << findMiddle()->current;
    return 0;
}
