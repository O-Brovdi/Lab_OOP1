#include "money.h"
#include <iostream>

using namespace std;

void addMoney(money& total, money& prod) {
    total.grn += prod.grn;
    total.kop += prod.kop;

    total.grn += total.kop / 100;
    total.kop = total.kop % 100;
}

void multiplyMoney(money& prod, unsigned short int count) {
    prod.grn *= count;
    prod.kop *= count;

    prod.grn += prod.kop / 100;
    prod.kop = prod.kop % 100;
}

void aroundMoney(money& total) {
    if (total.kop % 10 < 5)
        total.kop = (total.kop / 10) * 10;
    else {
        total.kop = (total.kop / 10 + 1) * 10;
        if (total.kop >= 100) {
            total.grn++;
            total.kop = 0;
        }
    }
}

void printMoney(money& total) {
    cout << total.grn << " грн " << total.kop << " коп";
}
