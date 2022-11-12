#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

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
////////////////////////////////////////////////////////
class Client
{
private:
    string name, address, phone_number;
    int type_account;
    BankAccount *client_account = NULL;
public:
    void setName(string name)
    {
        this->name = name;
    }
    void setAddress(string address)
    {
        this->address = address;
    }
    void setPhone(string phone)
    {
        this->phone_number = phone;
    }
    void setType(int type)
    {
        type_account = type;
    }
    void setID(string ID)
    {
        client_account->setId(ID);
    }
    void setBalance(double balance)
    {
        client_account->setBalance(balance);
    }
    void createAccount(int type, double startingBalance)
    {
        type_account = (type==1? 1:2);
        if(type == 1){
            client_account = new BankAccount(startingBalance);
            client_account->setId(nextClient);
        }
        else{
            client_account = new SavingsBankAccount(startingBalance);
            client_account->setId(nextClient);
        }
    }
    string getName()
    {
        return name;
    }
    string getAddress()
    {
        return address;
    }
    string getPhone()
    {
        return phone_number;
    }
    int getType()
    {
        return type_account;
    }
    string getClientID()
    {
        string myid = client_account->getId();
        return myid;
    }
    void print(){
        cout << "Name-> " << getName() << endl;
        cout << "ID-> " << getClientID() << endl;
        cout << "Address-> " << getAddress() << endl;
        cout << "Type-> " << getType() << endl;
        cout << "ClientBalance-> " << getClientBalance() << endl;
        cout << "Phone-> " << getPhone() << endl;
    }
    double getClientBalance()
    {
        double mybalance = client_account->getbalance();
        return mybalance;
    }
    // the functions that can modify the balance by
    void clientWithdraw(long long valuewithdraw)
    {
        client_account->withdraw(valuewithdraw);
    }
    void clientDeposit(long long valuedeposit)
    {
        client_account->deposit(valuedeposit);
    }
};
////////////////////////////////////////////////////////
class BankApplication
{
private:
    static int ind;
    int type;
    double amount, balance;
    string name, phone, address;
public:
    virtual void withDraw (double amount);
    virtual void deposit (double amount);
    BankApplication ()
    {
        int choice; // The Main Menu launched when creating an object
        cout << "\nWelcome to FCAI Banking Application.\n";
        cout << "1. Create a New Account\n" << "2. List Clients and Accounts\n";
        cout << "3. Withdraw Money\n" << "4. Deposit Money\n\n";
        cout << "Please Enter Choice =========> "; cin >> choice;

        if (choice == 1){   // To Add Clients. each Client is stored in a separate file
            Client user;    // name after the Client's ID
            string id = "FCAI-", idCopy;
            id += to_string(ind);   // ID
            idCopy = id;

            cout << "Please Enter Client Name =========> ";
            cin >> name; user.setName(name);

            cout << "\nPlease Enter Client Address =========> ";
            cin >> address; user.setAddress(address);

            cout << "\nPlease Enter Client Phone =========> ";
            cin >> phone; user.setPhone(phone);

            cout << "\nWhat Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 =========> ";
            cin >> type; user.setType(type);

            cout << "\nPlease Enter the Starting Balance =========> ";
            cin >> balance; user.setBalance(balance);

            cout << "\nAn Account was Created with ID " << id << " and Starting Balance " << balance << " L.E.\n";
            cout << "------------------------------------------------------\n";

            ofstream file;  // Creating a file to store the client's data in it.
            id += ".txt";
            file.open(id.c_str());
                                    // Printing the client's data into the file
            file << "---------- " << user.getName() << " -----------\n";
            file << "Address: " << user.getAddress() << ", Phone: " << user.getPhone();
            file << "\nAccount ID: " << idCopy;
            if (type == 1)
                file << " (Basic)\n";
            else if (type == 2)
                file << " (Savings)\n";
            file << "Balance: " << balance;

            file.close();   // closing the file
            ++ind;  // increase the index by one to go to the next ID. ex: ID is FCAI-1, ++ind, ID now is FCAI-2
        }
        else if (choice == 2){
            int i = 1;
                    // To print all existed Clients on the console screen
            while (i <= ind)
            {   // open a file to read data from it
                ifstream dataFile;
                string s = "FCAI-", line;
                s = s + to_string(i) + ".txt";

                dataFile.open(s.c_str());

                while (getline(cin, line)){ // Reading from the file and printing to console screen
                    cout << line << "\n";
                }
                cout << "----------------------------------\n";

                dataFile.close();
                ++i; // increase to go to next ID
            }
        }
        else if (choice == 3){
            withDraw(amount);
        }
        else if (choice == 4){
            deposit(amount);
        }
        else{
            cout << "Wrong Input.\n";
            exit(1);
        }
    }
};
int BankApplication::ind = 1;

#endif
