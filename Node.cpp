//
// Created by Arman Sadeghi on 10/1/20.
//

#include "Node.h"
#include <iostream>
using namespace std;


Node::Node(Stock stk) {
    stk.setSymbol(stk.getSymbol());
    stk.setShares(stk.getShares());
    stk.setCost(stk.getCost());
}

Node::Node() {
    Stock temp;
    next = NULL;
    current = temp;
}
