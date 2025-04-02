#ifndef MONEY_H
#define MONEY_H

struct money {
    unsigned grn;
    unsigned short int kop;
};

void addMoney(money& total, money& prod);
void multiplyMoney(money& prod, unsigned short int count);
void aroundMoney(money& total);
void printMoney(money& total);

#endif
