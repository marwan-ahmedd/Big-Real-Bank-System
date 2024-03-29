#include "Header.hpp"

istream &operator>>(istream &in, Client& user)
{
    cout << "Please Enter Client Name =========> ";
    in >> user.name;

    cout << "Please Enter Client Address =======> ";
    cin >> user.address;

    cout << "Please Enter Client Phone =======> ";
    in >> user.phoneNumber;
    
    return in;
}
//////////////////////////////////////////////////////////////
ostream &operator<<(ostream &out, Client& user)
{
    out << "---------- " << user.name << " -----------\n";
    out << "Address: " << user.address << ", Phone: " << user.getPhone();
    out << "\nAccount ID: " << user.clientAccount->getID();

    if (user.getType() == 1)
        out << " (Basic)\n";
    else if (user.getType() == 2)
        out << " (Savings)\n";
    out << "Balance: " << user.clientAccount->getBalance() << '\n';

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

