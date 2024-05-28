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
    cout << "\t| Press 1 to Login                             |" << endl;
    cout << "\t| Press 2 to Reginster                         |" << endl;
    cout << "\t| Press 3 to If you forget your password       |" << endl;
    cout << "\t| Press 4 to EXIT                              |" << endl;
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
    cout << "\t\t\t Please enter the UserName and Password : " << endl;
    cout << "\t\t\t If you want to go back regresiter or main menu , Please Enter 0 !";
    cout << "\t\t\t UserName : ";
    cin >> UserName;

    if (UserName == "0") {
        menu();
    }

    cout << "\t\t\t Password :";
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
    cout << "\t\t\t Enter the Username :";
    cin >> ruserID;
    cout << "\t\t\t Enter the Password : ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserID << ' ' << rpassword << endl;
    system("cls");
    cout << "\n\t\t\t Registration is successfull ! \n";
    login();
}




void forget() {
    int select;
    string UID, sid, spassword;
    system("cls");
    cout << "\t\t\t Press 1 to Show Password by username " << endl;
    cout << "\t\t\t Press 2 to go back main menu " << endl;
    cout << "\t\t\t Enter your choice : ";
    cin >> select;

    switch (select) {
    case 1: {
        int count = 0;
        cout << "\n\t\t\t Enter Your UserName :";
        cin >> UID;

        ifstream f2("records.txt");
        if (!f2.is_open()) {
            cout << "\n\t Error opening file!";
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
            cout << "\n\t Sorry! Cannot find your account\n";
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