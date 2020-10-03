//
// Created by Arman Sadeghi on 10/1/20.
//

#include "Stock.h"
#include <iostream>
using namespace std;

ostream &operator << (ostream& output, const Stock& stk){
    output << stk.shares << " share(s) of " << stk.symbol  << " at $" << stk.cost << endl;
    return output;
}

Stock::Stock(string sym, int c, int sh) {
    symbol = sym;
    cost = c;
    shares = sh;
}

void Stock::setCost(int c) {
    cost = c;
}

void Stock::setShares(int sh) {
    shares = sh;
}

void Stock::setSymbol(string sym) {
    symbol = sym;
}

string Stock::getSymbol() {
    return symbol;
}

int Stock::getCost() {
    return cost;
}

int Stock::getShares() {
    return shares;
}





