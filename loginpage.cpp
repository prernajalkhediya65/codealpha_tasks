#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class temp
{
    string username, email, password;
    fstream file;

public:
    void login();
    void signup();
    void forgot();
} obj;

int main()
{
    char choice;
    cout << "\n1-login";
    cout << "\n2-sign-up";
    cout << "\n3-change password";
    cout << "\n4-exit";
    cout << "\n enter your choice::";
    cin >> choice;

    switch (choice)
    {
    case '1':
        obj.login();
        break;

    case '2':
        obj.signup();
        break;

    case '3':
        obj.forgot();
        break;

    case '4':
        return 0;
        break;

    default:
        cout << "invalid choice" << endl;
    }
}
void temp ::signup()
{
    cin.ignore();
    cout << ("\n enter your username ::");
    getline(cin, username);
    cout << "\n enter your email address :: ";
    getline(cin, email);
    cout << "\n enetr your password ::";
    getline(cin, password);

    file.open("logindata.txt", ios::out | ios ::app);
    file << username << "*" << email << "*" << password << endl;
    file.close();
}
void temp ::login()
{
    cin.ignore();
    string searchname, searchpass, searchemail;
    cout << "----------LOGIN-----------" << endl;
    cout << "enter your user name :" << endl;
    getline(cin, searchname);
    cout << "enter password :" << endl;
    getline(cin, searchpass);

    file.open("logindata.txt", ios ::in);
    bool found = false;
    while (getline(file, username, '*'))
    {
        getline(file, email, '*');
        getline(file, password, '\n');
        while (!file.eof())
        {
            if (username == searchname)
            {
                if (password == searchpass)
                {

                    cout << "\n accout successfully login";
                    cout << "/n username :: " << username << endl;
                    cout << "/n email :: " << email << endl;
                    found = true;
                    break;
                }
            }
            else
            {
                cout << "password is incorrect" << endl;
                found = true;
                break;
            }
        }
    }
    if (!found)
    {
        cout << "user not found" << endl;
    }
    file.close();
}

void temp ::forgot()
{
    cin.ignore();
    string searchname, searchemail;
    cout << "\n enter username ::";
    getline(cin, searchname);
    cout << "\n enter your email address ::";
    getline(cin, searchemail);

    file.open("logindata.txt", ios ::in);
    bool found = false;
    while (getline(file, username, '*'))
    {
        getline(file, email, '*');
        getline(file, password, '\n');

        if (username == searchname && email == searchemail)

        {
            cout << "\n account found" << endl;
            cout << "your password ::" << password << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "not found" << endl;
    }
    file.close();
}
