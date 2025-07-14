#include <iostream>
#include <string>
#include <ctime>
#include <unistd.h>
using namespace std;
string username;
string password = "0";
int initialbalance;
bool loginsuccess = false;
void showoperationmenu()
{
    while (true)
    {    
        int amount, expression;
        bool num1 = true;
        bool num2 = true;
        while (num1 == true)
        {
            cout << "Welcome, " << username << "!" << endl;
            cout << "1. Display balance" << endl;
            cout << "2. Withdraw balance" << endl;
            cout << "3. Quit" << endl;
            cin >> expression;
            switch (expression)
            {
                case 1:
                    cout << "Welcome, " << username << "!" << endl;
                    cout << "Your current balance is: " << initialbalance << endl;
                    break;
                case 2:
                    num2 = true;
                    while (num2 == true)
                    {
                        cout << "Amount of withdrawal: " << endl;
                        cin >> amount;
                        if (amount < 0)
                        {
                            cout << "Please enter positive amount" << endl;
                            continue;
                        }        
                        else if (amount > initialbalance)
                        {
                            cout << "Withdrawl more than current balance is not possible." << endl;
                            continue;
                        }
                        else
                        {
                            initialbalance -= amount;
                            cout << "Your remaining balance is: " << initialbalance << endl;
                            num2 = false;
                        }
                    }
                    break;
                case 3:
                    return;
                default:
                    cout << "Invalid choice! Select from 1 to 3" << endl;
                    continue;
            }
        }
    }
}
void login()
{
    string enteredusername; 
    string enteredpassword;
    for (int i = 0; i < 3;)
    {       
        cout << "Please enter your name: " << endl;
        cin.ignore();
        getline(cin,enteredusername);
        cout << "Please enter your password: " << endl;
        cin >> enteredpassword;
        if (password == "0")
        {
            cout << "As You are a new user So, You have to create your account first." << endl;
            return;
        }
        else if (username == enteredusername && password == enteredpassword)
        {
            loginsuccess = true;
            return;
        }
        else
        {
            i++;
            cout << "Invalid username or password. You have " << 3-i << " attempts left." << endl;
        }
        if (i==3)
        {
            cout << "Access blocked. Please try again in 15 minutes." << endl;
            sleep(15);
            i=0;
        }        
    }
}
void createaccount()
{
    int confirmation;
    bool ref=true;
    while (ref == true)
    {
        string newusername;
        string newpassword;
        int newbalance;
        cout << "Please enter your complete name: " << endl;
        cin.ignore();
        getline(cin, newusername);
        cout << "Please enter 4 digit password: " << endl;
        cin >> newpassword;
        cout << "Please enter initial balance: " << endl;
        cin >> newbalance;
        if (newpassword < "0")
        {
            cout << "Password should contains only positive letters" << endl;
            continue;
        }
        else
        if (newusername.empty() || (newpassword).length()!= 4)
        {
            cout << "Error! Please fill all the fields and password should be 4 digits." << endl;
            continue;
        }                    
        cout << "Your name is: " << newusername << endl;
        cout << "Your 4 digit password is: " << newpassword << endl;
        cout << "Your initial balance is: " << newbalance << endl;
        cout << "Do you want to save these details?  " << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> confirmation;
        switch (confirmation)
        {
            case 1:
                cout << "Congratulations, you have successfully created a new account." << endl;
                username = newusername;
                password = newpassword;
                initialbalance = newbalance;
                ref = false;
                break;
            case 2:
                return;
            default:
                cout << "Invalid Choice" << endl;
                break;
            }
    }
}
int main()
{
    bool num0 = true;
    int num1;
    while (num0 == true)
    {
        cout << "Please select an option from the menu below: " << endl;
        cout << "1. Create new account" << endl;
        cout << "2. Log in" << endl;
        cout << "3. Quit" << endl;
        cin >> num1;      
        switch (num1)
        {
            case 1:
                createaccount();
                break;
            case 2:
                login();
                if (loginsuccess == true)
                {
                    showoperationmenu();   
                }            
                break;
            case 3:
                cout << "Thank You for using ATM. " << endl;
                num0 = false;
                break;
            default:
                cout << "Invalid choice! Select from 1 to 3" << endl;
                continue;
                break;
        }
    }
    return 0;
}