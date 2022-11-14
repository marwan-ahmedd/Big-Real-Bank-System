#include "Header.hpp"

SavingsBankAccount ::SavingsBankAccount(double balance) 
{
    if (balance >= minimumBalance)
        BankAccount(balance);
    else
        BankAccount(minimumBalance);
}

SavingsBankAccount :: SavingsBankAccount() : BankAccount(minimumBalance)
{}

int SavingsBankAccount :: withDraw(double amount)
{
    if (getBalance() - amount >= minimumBalance and amount <= getBalance())
    {
        setBalance(getBalance() - amount);
        return 1;
    }
    else if (getBalance() - amount < minimumBalance)
        cout << "Sorry. You Can't withdraw money below the minimum balance\n";
    else
        cout << "Sorry. This is more than what you can withdraw.\n";
    return 0;
}

int SavingsBankAccount :: deposit(double amount)
{
    if (amount < 100)
    {
        cout << "Sorry This is less than what you can deposit.\n";
        return 0;
    }
    else
    {
        setBalance(getBalance() + amount);
        return 1;
    }
}