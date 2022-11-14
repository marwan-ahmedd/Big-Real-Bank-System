#include "Header.hpp"

BankApplication ::BankApplication()
{

    int choice;
    cout << "Welcome to FCAI Banking Application\n";
    cout << "1. Create a New Account\n";
    cout << "2. List Clients and Accounts\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Deposit Money\n\n";
    cout << "Please Enter you Choice =========> ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        addClient();
        break;
    case 2:
        listAccounts();
        break;
    case 3:
        withDraw();
        break;
    // case 4:
    //     // TODO ->
    default:
        break;
    }
    cout << "-------------------------------------------------------------------\n";
}
//////////////////////////////////////////////////////////////
bool BankApplication :: addClient()
{
    Client user;
    cin >> user;

    int choice;
    cout << "What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 =========> ";
    cin >> choice;
    
    user.setAccountType(choice);

    mp[user.clientAccount->getID()] = user;

    ofstream file;
    file.open("Clients-Data.txt");
    file << user;
    file.close();
}