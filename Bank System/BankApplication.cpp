#include "Header.hpp"

BankApplication :: BankApplication()
{

    int choice;
    cout << "\nWelcome to FCAI Banking Application\n";
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
        case 4:
            deposit();
            break;
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
    cout << "What Type of Account Do You Like? (1) Basic (2) Saving - Type 1 or 2 =========> ";
    cin >> choice;
    
    user.setAccountType(choice);

    mp[user.clientAccount->getID()] = user;

    ofstream file;
    file.open("Clients-Data.txt", ios::app);
    file << user;
    file.close();

    return true;
}

void BankApplication :: listAccounts()
{
    ifstream dataFile;
    string line;

    dataFile.open("Clients-Data.txt");

    while (getline(dataFile, line))
    {
        cout << line << endl;
    }

    dataFile.close();
}

void BankApplication :: withDraw()
{
    string id;
    double val;

    cout << "Please Enter Account ID (e.g., FCAI-015) =========> ";
    cin >> id;
    cout << mp[id];

    tag:;   
    cout << "Please Enter The Amount to Withdraw =========> ";
    cin >> val;
    if (mp[id].clientAccount->withDraw(val))
    {
        goto tag;
    }

    cout << "Thank You.\n";
    cout << "Account ID: " << mp[id].clientAccount->getID() << '\n';
    cout << "New Balance: " << mp[id].clientAccount->getBalance() << '\n';
}

void BankApplication :: deposit()
{
    string id;
    double val;

    cout << "Please Enter Account ID (e.g., FCAI-015) =========> ";
    cin >> id;
    cout << mp[id];

    tag:;
    cout << "Please Enter The Amount to deposit =========> ";
    cin >> val;
    if (mp[id].clientAccount->deposit(val))
    {
        goto tag;
    }
    cout << "Thank You.\n";
    cout << "Account ID: " << mp[id].clientAccount->getID() << '\n';
    cout << "New Balance: " << mp[id].clientAccount->getBalance() << '\n';
}