#ifndef _HEADER_HPP
#define _HEADER_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
using namespace std;

class BankApplication
{
    map <string, Client> mp;
    string name, phone, address;
    public:
        BankApplication();
        bool addClient();
        void listAccounts();
        void withDraw();
        void deposit();
};
//////////////////////////////////////////////////////////////
class BankAccount
{
    private:
        string accountID;
        int id = 1;
        double balance;

    public:
        BankAccount();
        BankAccount(double amount);

        string getID() { return accountID; }
        double getBalance() { return balance; }

        virtual int withDraw(double amount);
        virtual int deposit(double amount);
};
//////////////////////////////////////////////////////////////
class SavingsBankAccount : public BankAccount
{
    private:
        double minimumBalance = 1000;

    public:
        SavingsBankAccount();
        SavingsBankAccount(double balance);

        double getMinimumBalance() { return minimumBalance; }
        void setMinimumBalance(double value) { minimumBalance = value; }

        int withDraw(double amount);
        int deposit(double amount);
};
//////////////////////////////////////////////////////////////
class Client
{
    string name;
    string address;
    string phoneNumber;
    int accountType;
    public:
        BankAccount* clientAccount = NULL;
        friend istream& operator>> (istream& in, Client user);
        friend ostream& operator<< (ostream& out, Client user);

        string getName() {return name;}
        string getAddress() {return address;}
        string getPhone() {return phoneNumber;}
        int getType() {return accountType;}

        void setName(string name) {this->name = name;}
        void setAddress(string address) {this->address = address;}
        void setPhone(string phoneNumber) {this->phoneNumber = phoneNumber;}
        void setAccountType(int type) {this->accountType = type;}
};
#endif