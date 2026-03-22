#include <iostream>
#include <vector>
using namespace std;

class Transaction
{
public:
    string type;
    double amount;

    Transaction(string t, double a)
    {
        type = t;
        amount = a;
    }
    void display()
    {
        cout << type << ":" << amount << endl;
    }
};

class Account
{
public:
    int accNumber;
    double balance;
    vector<Transaction> transactions;

    Account(int accNo = 0)
    {
        accNumber = accNo;
        balance = 0;
    }

    void deposite(double amount)
    {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
        cout << "Amount deposited successfully! \n";
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Amount withdrawn successfully \n";
        }
    }

    void showTransactions()
    {
        cout << "\n Transaction History :\n";
        for (auto &t : transactions)
        {
            t.display();
        }
    }

    void showBalance()
    {
        cout << "Current Balance :" << balance << endl;
    }
};
class Customer
{
public:
    string name;
    int customerid;
    Account account;

    Customer(string n = "", int id = 0, int accNo = 0) : account(accNo)
    {
        name = n;
        customerid = id;
    }
    void display()
    {
        cout << "\n Name :" << name << endl;
        cout << "ID :" << customerid << endl;
        cout << "Account No :" << endl;
        account.showBalance();
    }
};

void transfer(Account &from, Account &to, double amount)
{
    if (amount > from.balance)
    {
        cout << "Transfer failed! Insufficient balance \n";
    }
    else
    {
        from.balance -= amount;
        to.balance += amount;

        from.transactions.push_back(Transaction("Transfer sent", amount));
        to.transactions.push_back(Transaction("Transfer Received", amount));

        cout << "Transfer Successfully! \n";
    }
}

// Main function

int main()
{
    Customer c1, c2;
    int choice;

    // create customers

    cout << "Enter customer 1 Name :" << endl;
    cin >> c1.name;
    cout << "Enter Customer 1 Id" << endl;
    cin >> c1.customerid;
    cout << "Enter Account number" << endl;
    cin >> c1.account.accNumber;

    cout << "Enter customer 2 Name :" << endl;
    cin >> c2.name;
    cout << "Enter Customer 2 Id" << endl;
    cin >> c2.customerid;
    cout << "Enter Account number" << endl;
    cin >> c2.account.accNumber;

    do
    {
        cout << "\n=====BANK MENU====\n";
        cout << "1.Depostiee\n";
        cout << "2.Withdraw\n";
        cout << "3.Transfer\n";
        cout << "4.Show Customer 1 Details\n";
        cout << "5.show Customer 2 Details\n";
        cout << "6.Exit\n";
        cout << "Enter choice :" << endl;
        cin >> choice;

        double amount;

        switch (choice)
        {
        case 1:
            cout << "Enter amount to deposite(Customer 1):";
            cin >> amount;
            c1.account.deposite(amount);
            break;

        case 2:
            cout << "Enter amount to withdraw (Customer 1):";
            cin >> amount;
            c1.account.withdraw(amount);
            break;

        case 3:
            cout << "Enter amount to transfer (C1 -> C2):";
            cin >> amount;
            transfer(c1.account, c2.account, amount);
            break;

        case 4:
            c1.display();
            c1.account.showTransactions();
            break;

        case 5:
            c2.display();
            c2.account.showTransactions();
            break;

        case 6:
            cout << "Exist program....\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);
    return 0;
}
