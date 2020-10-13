//
// Created by Arman Sadeghi on 10/1/20.
//

#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H
#include <iostream>
#include "Stock.h"
using namespace std;

class Node{

public:
    Node();
    Node(Stock);
    Stock current;
    Node* next;
    Node* prev;
};

#endif //LINKEDLIST_NODE_H
