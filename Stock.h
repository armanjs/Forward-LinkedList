//
// Created by Arman Sadeghi on 10/1/20.
//

#ifndef LINKEDLIST_STOCK_H
#define LINKEDLIST_STOCK_H
#include <iostream>
using namespace std;

class Stock {
    friend ostream& operator << (ostream& output, const Stock& stk);

public:

    Stock(string sym = "", int c = 0, int sh = 0);
    // setters & getters
    void setSymbol(string sym);
    void setCost(int c);
    void setShares(int sh);
    string getSymbol();
    int getCost();
    int getShares();

private:
    string symbol;
    int cost;
    int shares;
};

#endif //LINKEDLIST_STOCK_H
