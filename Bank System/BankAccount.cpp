#include "header.h"

BankAccount ::BankAccount() : balance(0)
{
    accountID = "FCAI-" + id++;
    cout << " An account was created Successfully with ID " << accountID << " and Starting Balance =  0\n";
}

BankAccount ::BankAccount(double amount) : balance(amount)
{
    accountID = "FCAI-" + to_string(id++);
    cout << "An account was created Successfully with ID " << accountID << " and Starting Balance = " << amount << '\n';
}

int BankAccount ::withDraw(double amount)
{
    if (amount <= balance)
    {
        balance -= amount;
        cout << "Thank You\n";
        return 0;
    }
    else if (amount > balance)
    {
        cout << "Sorry. This is more than what you can withdraw.\n";
        return 1;
    }
    cout << "Sorry, Invalid Number.\n";
    return 1;
}

int BankAccount ::deposit(double amount)
{
    if (amount <= 0)
    {
        cout << "Sorry, Invalid Number.\n";
        return 0;
    }
    else
    {
        balance += amount;
        return 1;
    }
}