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
    // link the newNode with the head
    newNode->next = head;
    // now head points to newNode
    head = newNode;
    // increase list size
    currentSize++;
    // if the new node is the only node in the list
    if (tail == NULL){
        tail = head;
    }
    // update the head previous
    if (head != tail){
        head->next->prev = head;
    }
}

Node* removeFront(){
    // if the list is empty
    if (currentSize == 0){
        return NULL;
    }
    else {
        // set the temp node to head
        Node* temp = head;
        // point the head to its next node
        head = head->next;
        // reduce the size after removal
        currentSize--;
        // if list becomes empty after removal
        if (head == NULL){
            tail = NULL;
        }
        return temp;
    }
}

Node* findMiddle(){
    int counter = 1;
    Node* slow = head;
    Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        counter++;

        // move to the next node
        /* fast = fast->next;
         if (fast->next != NULL){
             fast = fast->next;
             slow = slow->next;
         }*/
    }
    //cout << "This is the middle: " << slow->current << "At index: " << counter << endl;
    return slow; // return middle
}

void insertMiddle(Stock stk){
    // create a new node to be inserted
    Node* newNode = new Node;
    // set the current to stk
    newNode->current = stk;
    // find the middle of the list
    Node* middle = findMiddle();
    // create a temp node to save the link
    Node* temp = middle->next;
    // link the middle node to the new node
    middle->next = newNode;
    // link the middle with the rest of the list
    middle->next->next = temp;
    // increment the size
    currentSize++;
    // link the previous
    temp->prev = middle->next;
    middle->next->prev = middle;
}

Node* removeMiddle(){
    // if the list is empty
    if (currentSize == 0){
        return NULL;
    }
    // if there's only one element
    else if (currentSize == 1){
        return removeFront();
    }
    // if currentSize > 1
    else {
        // point the middle node to the middle of the list
        Node* middle = findMiddle();
        // point previous to the node before middle
        Node* previousNode = middle->prev;
        // point next to the node after the middle
        Node* nextNode = middle->next;
        // delete the middle node
        previousNode->next = nextNode;
        nextNode->prev = previousNode;
        // decrement the size
        currentSize--;
        return middle;
    }
}

void insertLast(Stock stk){
    // create a new node
    Node* newNode = new Node;
    newNode->current = stk;
    // create a temp and set it to tail
    Node* temp = tail;
    // if the only one in the list
    if (tail == NULL){
        head = tail = newNode;
    }
    else {
        // link the new node with the last node
        tail->next = newNode;
        // point tail to the last node
        tail = tail->next;
    }
    currentSize++;
    // link the previous
    tail->prev = temp;
}

Node* removeLast(){
    // if list is empty
    if (currentSize == 0){
        return NULL;
    }
    else if (currentSize == 1){
        // set the temp node to head
        Node* temp = head;
        head = tail = NULL;
        currentSize = 0;
        return temp;
    }
    else { // currentSize > 1
        // set the current node to head
        Node* current = head;
        // traverse through the list till we reach our desired node
        for (int i = 0; i < currentSize - 2; ++i) {
            current = current->next;
        }
        Node* temp = tail;
        tail = current;
        // delete the last node
        tail->next = NULL;
        // decrement the size of the list
        currentSize--;
        return temp;
    }
}

void printList(Node* temp){
    int count = 1;
    while (temp != NULL){
        cout << count << ") " << temp->current << endl << endl;
        temp = temp->next;
        count++;
    }
    if (currentSize == 0){
        cout << "List is empty." << endl;
    }
}

void printReverse(Node* temp){
    while (temp != NULL){
        cout << temp->current << endl << endl;
        temp = temp->prev;
    }
    if (currentSize == 0){
        cout << "List is empty." << endl;
    }
}

void splitHalfList(Node* head){
    // find middle
    Node* middle = findMiddle();
    // assign middleHead = middle.next
    Node* middleHead = middle->next;
    // middleHead.next = null
    middle->next = NULL; // cuts the list

    cout << endl << "The following is the first half:" << endl;
    printList(head);
    cout << endl << "The following is the second half:" << endl;
    printList(middleHead);
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

    cout << endl << "The following is the complete list of randomly generated stocks:" << endl << endl;
    printList(head);

    int selection = 0;
    cout << "Enter a (1) for insertFront, (2) for removeFront"
            ", (3) for insertMiddle, (4) for removeMiddle, \n"
            "(5) for insertEnd, (6) for removeEnd, "
            "(7) for printList, (8) for printReverse and (-1) to quit: ";
    cin >> selection;


    while (selection != -1){

        if (selection == 1){
            string symbol;
            int cost = 0, shares = 0;
            cout << "What stock do u wish to insertFront? Please enter symbol, cost and share "
                    "separated by spaces: ";
            cin >> symbol >> cost >> shares;
            Stock stock(symbol, cost, shares);
            insertFront(stock);
            cout << "(" << stock << ")" << " Has been added to your list" << endl;
        }
        else if (selection == 2) {
            cout << "(" << removeFront()->current << ")" <<
            " has been removed from the front of the list" << endl;
        }
        else if (selection == 3){
            string symbol;
            int cost = 0, shares = 0;
            cout << "What stock do u wish to insertMiddle? Please enter symbol, cost and share "
                    "separated by spaces: ";
            cin >> symbol >> cost >> shares;
            Stock stock(symbol, cost, shares);
            insertMiddle(stock);
            cout << "(" << stock << ")" << " Has been added to your list" << endl;
        }
        else if (selection == 4){
            cout << "(" << removeMiddle()->current << ")" <<
            " has been removed from the middle of the list" << endl;
        }
        else if (selection == 5){
            string symbol;
            int cost = 0, shares = 0;
            cout << "What stock do u wish to insertLast? Please enter symbol, cost and share "
                    "separated by spaces: ";
            cin >> symbol >> cost >> shares;
            Stock stock(symbol, cost, shares);
            insertLast(stock);
            cout << "(" << stock << ")" << " Has been added to your list" << endl;
        }
        else if (selection == 6){
            cout << "(" << removeLast()->current << ")" <<
                 " has been removed from the end of the list" << endl;
        }
        else if (selection == 7){
            printList(head);
        }
        else if (selection == 8){
            printReverse(tail);
        }
        cout << "Enter a number from (1-8), enter -1 to quit: ";
        cin >> selection;
    }

    return 0;
}
