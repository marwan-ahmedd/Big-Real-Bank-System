#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
using namespace std;

class BankApplication
{

};
////////////////////////////////////////////////////////
class Client
{

};
////////////////////////////////////////////////////////
class BankAccount
{
    private:
        string accountID;
        int id = 1;
        double balance;

    public:
        BankAccount();
        BankAccount(double amount);

        string getID() {return accountID;}
        double getBalance() {return balance;}

        virtual int withDraw(double amount);
        virtual int deposit(double amount);
};
////////////////////////////////////////////////////////
class SavingsBankAccount : public BankAccount
{
    private:
        double minimumBalance = 1000;

    public:
        SavingsBankAccount();
        SavingsBankAccount(double balance);

        double getMinimumBalance() {return minimumBalance;}
        void setMinimumBalance(double value) {minimumBalance = value;}

        int withDraw(double amount);
        int deposit(double amount);
};

#endif