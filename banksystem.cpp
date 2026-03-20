#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* ---------- Transaction Class ---------- */
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
};

/* ---------- Account Class ---------- */
class Account
{
private:
    int accountNumber;
    double balance;
    vector<Transaction> transactions;

public:
    Account(int accNo)
    {
        accountNumber = accNo;
        balance = 0.0;
    }

    int getAccountNumber()
    {
        return accountNumber;
    }

    double getBalance()
    {
        return balance;
    }

    void deposit(double amount)
    {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
        cout << "Amount deposited successfully.\n";
    }

    bool withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance.\n";
            return false;
        }
        balance -= amount;
        transactions.push_back(Transaction("Withdrawal", amount));
        cout << "Amount withdrawn successfully.\n";
        return true;
    }

    void transfer(Account &toAccount, double amount)
    {
        if (withdraw(amount))
        {
            toAccount.deposit(amount);
            transactions.push_back(Transaction("Transfer Sent", amount));
            cout << "Fund transfer successful.\n";
        }
    }

    void displayAccountInfo()
    {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nCurrent Balance: " << balance << endl;
        cout << "Transaction History:\n";

        if (transactions.empty())
        {
            cout << "No transactions found.\n";
        }
        else
        {
            for (auto &t : transactions)
            {
                cout << t.type << " : " << t.amount << endl;
            }
        }
    }
};

/* ---------- Customer Class ---------- */
class Customer
{
private:
    string name;
    int customerId;
    vector<Account> accounts;

public:
    Customer(int id, string n)
    {
        customerId = id;
        name = n;
    }

    void createAccount(int accNo)
    {
        accounts.push_back(Account(accNo));
        cout << "Account created successfully.\n";
    }

    Account *getAccount(int accNo)
    {
        for (auto &acc : accounts)
        {
            if (acc.getAccountNumber() == accNo)
            {
                return &acc;
            }
        }
        return nullptr;
    }

    void displayCustomerInfo()
    {
        cout << "\nCustomer ID: " << customerId;
        cout << "\nCustomer Name: " << name << endl;
        for (auto &acc : accounts)
        {
            acc.displayAccountInfo();
        }
    }
};

/* ---------- Main Function ---------- */
int main()
{
    Customer customer(101, "User");
    int choice;

    do
    {
        cout << "\n----- Banking System Menu -----\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Transfer Funds\n";
        cout << "5. Display Account Info\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int accNo, toAccNo;
        double amount;

        switch (choice)
        {
        case 1:
            cout << "Enter Account Number: ";
            cin >> accNo;
            customer.createAccount(accNo);
            break;

        case 2:
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Amount: ";
            cin >> amount;
            if (customer.getAccount(accNo))
                customer.getAccount(accNo)->deposit(amount);
            else
                cout << "Account not found.\n";
            break;

        case 3:
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Amount: ";
            cin >> amount;
            if (customer.getAccount(accNo))
                customer.getAccount(accNo)->withdraw(amount);
            else
                cout << "Account not found.\n";
            break;

        case 4:
            cout << "Enter From Account Number: ";
            cin >> accNo;
            cout << "Enter To Account Number: ";
            cin >> toAccNo;
            cout << "Enter Amount: ";
            cin >> amount;

            if (customer.getAccount(accNo) && customer.getAccount(toAccNo))
                customer.getAccount(accNo)->transfer(*customer.getAccount(toAccNo), amount);
            else
                cout << "One or both accounts not found.\n";
            break;

        case 5:
            customer.displayCustomerInfo();
            break;

        case 6:
            cout << "Thank you for using the banking system.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
