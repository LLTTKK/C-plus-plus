#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void menu();
void forget();
void loginsuccess();

void menu()
{
    int choose;
    cout << "\t\t\t___________________________________________\n\n\n";
    cout << "\t\t\t             Welcome!!                     \n\n\n";
    cout << "\t\t\t___________     MENU    ___________________\n\n\n";
    cout << "| Press 1 to Login                             |" << endl;
    cout << "| Press 2 to Reginster                         |" << endl;
    cout << "| Press 3 to If you forget your password       |" << endl;
    cout << "| Press 4 to EXIT                              |" << endl;
    cout << "Please enter your choice :" << endl;
    cin >> choose;
    cout << endl;


    switch (choose)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forget();
        break;
    case 4:
        cout << "Thank you For using our service \n\n" << "See you again !! \n\n";
        break;
    default:
        system("cls");
        cout << "Please select correcrt number!! " << endl;
        menu();

    }
}


void login()
{
    int se;
    string UserName, Password, Fid, Fpass;
    system("cls");
    cout << "\nPlease enter the UserName and Password : " << endl;
    cout << "If you want to go back regresiter or main menu , Please Enter 0 !";
    cout << "UserName : ";
    cin >> UserName;

    if (UserName == "0") {
        menu();
    }

    cout << "Password :";
    cin >> Password;

    ifstream input("records.txt");

    while (input >> Fid >> Fpass)
    {
        if (Fid == UserName && Fpass == Password) {
            se = 1;
            system("cls");

        }
    }
    input.close();
    if (se == 1) {
        cout << UserName << "\n Your Login Success , Welcome !!\n";
        loginsuccess();
    }
    else {
        cout << "\n Login Error , please check your login Info or Regressiter!\n ";
    }
}



void registration()
{
    string ruserID, rpassword, rid, rpass;
    system("cls");
    cout << "\nEnter the Username :";
    cin >> ruserID;
    cout << "Enter the Password : ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserID << ' ' << rpassword << endl;
    system("cls");
    cout << "\nRegistration is successfull ! \n";
    login();
}




void forget() {
    int select;
    string UID, sid, spassword;
    system("cls");
    cout << "\nPress 1 to Show Password by username " << endl;
    cout << "Press 2 to go back main menu " << endl;
    cout << "Enter your choice : ";
    cin >> select;

    switch (select) {
    case 1: {
        int count = 0;
        cout << "\nEnter Your UserName :";
        cin >> UID;

        ifstream f2("records.txt");
        if (!f2.is_open()) {
            cout << "\n Error opening file!";
            menu();
            break;
        }

        while (f2 >> sid >> spassword) {
            if (sid == UID) {
                count = 1;
                break;
            }
        }

        f2.close();
        if (count == 1) {
            cout << "\n\n Your Password is : " << spassword;
        }
        else {
            cout << "\nSorry! Cannot find your account\n";
        }
        forget();
        break;
    }

    case 2:
        menu();
        break;

    default:
        cout << "\nInvalid choice, please try again.";
        forget();
        break;
    }
}








void loginsuccess() {
    cout << "";
}


int main() {
    menu();
}