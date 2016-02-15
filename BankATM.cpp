/*
Author: Allen Owen
Date: 11/2015
Description: This program simulates a Bank ATM teller machine. It allows a user to create their own account and deposit
withdraw virtual money, and finally obtain their overall bank balance.
Algorithm: Call mainMenu function, loop main menu until quit selected, if valid input call appropriate function,
if login successful call bankMenu, loop bank menu until quit selected, if valid input call appropriate function, if user selects
quit program ends.
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void mainMenu(); // display  and loop main menu
void createAccount(int, int);//create account and write to file
int login(int,int);//check file for valid login
void bankingMenu();//display and loop banking menu
void deposit(double);//deposit to global balance variable, write to file
void withdraw(double);//withdraw from global balance variable, write to file
void displayBalance();//display global balance variable
double balance = 0.00;

ofstream transaction;
ofstream account;

int main()
{
    account.open("Accounts.txt");//open file for user accounts
    transaction.open("Transactions.txt");//open file for user transactions
    mainMenu();//call main menu function
    account.close();
    transaction.close();
    return 0;
}

void mainMenu()// display  and loop main menu
{
    bool logIn = 0;
    char choice;
    int username = 0, password = 0;
    cout << "Hi! Welcome to Future Computer Programmer ATM Machine! ";

    do
    {
        cout << "Please select an option from the menu below:" << endl;
        cout << "L -> Login" << endl;
        cout << "C -> Create New Account" << endl;
        cout << "Q -> Quit" << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
            case 'L':
                {
                    cout << "Please enter your user id: ";
                    cin >> username;
                    cout << "Please enter your password: ";
                    cin >> password;
                    cout << endl << endl;
                    logIn = login(username, password);
                    if (logIn == 0)
                    {
                        cout << "No match was found! Login Failed !" << endl << endl;
                    }
                    if (logIn == 1)
                    {
                        cout << "Access Granted!" << endl << endl;
                        bankingMenu();
                    }

                } break;
            case 'l':
                {
                    cout << "Please enter your user id: ";
                    cin >> username;
                    cout << "Please enter your password: ";
                    cin >> password;
                    cout << endl;
                    logIn = login(username, password);
                    if (logIn == 0)
                    {
                        cout << "No match was found! Login Failed !" << endl << endl;
                    }
                    if (logIn == 1)
                    {
                        cout << "Access Granted!" << endl << endl;
                        bankingMenu();
                    }
                } break;
            case 'C':
                {
                    do
                    {
                        cout << "Please enter a user name and password as integers greater than 0" << endl;
                        cout << "Please enter your user name: ";
                        cin >> username;
                        cout << "Please enter your password: ";
                        cin >> password;
                    }while (username < 1 || password < 1);
                    createAccount (username, password);
                    cout << endl;
                    cout << "Thank You! Your account has been created!" << endl;
                    cout << endl;
                } break;
            case 'c':
                {
                    do
                    {
                        cout << "Please enter a user name and password as integers greater than 0" << endl;
                        cout << "Please enter your user name: ";
                        cin >> username;
                        cout << "Please enter your password: ";
                        cin >> password;
                    }while (username < 1 || password < 1);
                    createAccount (username, password);
                    cout << endl << endl;
                    cout << "Thank You! Your account has been created!" << endl;
                    cout << endl;
                } break;
            case 'Q':
                {
                    cout << "Thanks for stopping by!" << endl << endl;
                    account.close();
                    transaction.close();
                    exit(1);
                } break;
            case 'q':
                {
                    cout << "Thanks for stopping by!" << endl << endl;
                    account.close();
                    transaction.close();
                    exit(1);
                } break;
            default: cout << "Invalid Input! Try again" << endl << endl;
                    break;
        }


    }while (choice != 'L' || choice != 'C' || choice != 'Q' || logIn == 0);


}

void createAccount(int userID, int password)//create account and write to file
{
    account << userID << endl;
    account << password << endl;
}

int login(int userID, int password)//check file for valid login
{
    ifstream login;
    login.open("Accounts.txt");
    int id, pw;
    while (login >> id)
    {
        if (id == userID)
        {
            while (login >> pw)
            {
                if (password == pw)
                {
                    return 1;
                }
            }
        }
    }
    login.close();
    return 0;
}

void bankingMenu()//display and loop banking menu
{
    char choice;
    double dep,with;
    do
    {
        cout << "Please select an option from the menu below" << endl << endl;
        cout << "D -> Deposit Money" << endl;
        cout << "W -> Withdraw Money" << endl;
        cout << "R -> Request Balance" << endl;
        cout << "Q -> Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 'D':
                {
                    cout << endl;
                    cout << "Enter amount of deposit: $";
                    cin >> dep;
                    deposit(dep);
                } break;
            case 'd':
                {
                    cout << endl;
                    cout << "Enter amount of deposit: $";
                    cin >> dep;
                    deposit(dep);
                } break;
            case 'W':
                {
                    cout << endl;
                    cout << "Enter amount of withdrawal: $";
                    cin >> with;
                    withdraw(with);
                } break;
            case 'w':
                {
                    cout << endl;
                    cout << "Enter amount of withdrawal: $";
                    cin >> with;
                    withdraw(with);
                } break;
            case 'R':
                {
                    displayBalance();
                } break;
            case 'r':
                {
                    displayBalance();
                } break;
            case 'Q':
                {
                    cout << endl << "Thanks for stopping by!" << endl << endl;
                    account.close();
                    transaction.close();
                    exit(1);
                } break;
            case 'q':
                {
                    cout << endl << "Thanks for stopping by!" << endl << endl;
                    account.close();
                    transaction.close();
                    exit(1);
                } break;
            default: cout << endl << "Invalid input! Try again!" << endl << endl; break;

        }


    } while(choice != 'D' || choice != 'W' || choice != 'R' || choice != 'Q');


}

void deposit(double dep)//deposit to global balance variable, write to file
{
    balance += dep;
    transaction << "$" << dep << " was deposited." << endl;
    cout << "$" << dep << " was deposited." << endl << endl;
}

void withdraw(double with)//withdraw from global balance variable, write to file
{
    if (with > balance)
    {
        cout << "Sorry withdrawal amount exceeds the balance. Can't withdraw!" << endl << endl;
    }
    else if (balance > with)
    {
        balance -= with;
        transaction << "$" << with << " was withdrawn." << endl;
        cout << "$" << with << " was withdrawn." << endl << endl;
    }
}

void displayBalance()//display global balance variable
{
    cout << endl << "Your balance is $" << balance << endl << endl;
}
