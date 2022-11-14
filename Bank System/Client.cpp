#include "Header.hpp"

istream &operator>>(istream &in, Client user)
{
    cout << "Please Enter Client Name =========> ";
    in >> user.name;

    cout << "Please Enter Client Address =======> ";
    in >> user.address;

    cout << "Please Enter Client Phone =======> ";
    in >> user.phoneNumber;

    cout << "What Type of Account Do You Like? (1) Basic (2) Saving � Type 1 or 2 =========> ";
    in >> user.accountType;
    
    return in;
}
//////////////////////////////////////////////////////////////
ostream &operator<<(ostream &out, Client user)
{
    out << "---------- " << user.getName() << " -----------\n";
    out << "Address: " << user.getAddress() << ", Phone: " << user.getPhone();
    out << "\nAccount ID: " << user.clientAccount->getID();

    if (user.getType() == 1)
        out << " (Basic)\n";
    else if (user.getType() == 2)
        out << " (Savings)\n";
    out << "Balance: " << user.clientAccount->getBalance();

    return out;
}
//////////////////////////////////////////////////////////////
void Client ::setAccountType(int type)
{
    accountType = (type == 1 ? 1 : 2);
    if (type == 1)
    {
        double startingBalance;
        cout << "Please Enter the Starting Balance =========> ";
        cin >> startingBalance;

        if (startingBalance == '\n')
            clientAccount = new BankAccount();
        else
            clientAccount = new BankAccount(startingBalance);
    }
    else if (type == 2)
    {
        double startingBalance;
        cout << "Please Enter the Starting Balance =========> ";
        cin >> startingBalance;

        if (startingBalance == '\n')
            clientAccount = new SavingsBankAccount();
        else
            clientAccount = new SavingsBankAccount(startingBalance);
    }
}

