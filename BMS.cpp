#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <windows.h>

using namespace std;

class bank
{
private:
    string id, password, name, fname, address, phonenumber;
    double balance;
    int pin;

public:
    void menu();
    void bank_management();
    void atm_management();
    void new_user();
    void already_user();
    void deposit();
    void withdraw();
    void transfer();
    void searchUserRecord();
    void editUserRecord();
    void deleteUserRecord();
    void showAllRecord();
    void paymentRecord();    
};

void bank::menu()
{
    while (true)
    {
        int choice;
        char ch;
        string pin, pass, email;
        system("cls");
        cout << "\n\n\t\tControl Panel";
        cout << "\n\n 1. Bank Management";
        cout << "\n 2. ATM Management";
        cout << "\n 3. Exit";
        cout << "\n\n Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n\n\t\tEnter your login credentials";
            cout << "\n E-mail: ";
            cin >> email;
            cout << "\n Pin-code: ";
            for (int i = 1; i <= 6; i++)
            {
                ch = getch();
                pin += ch;
                cout << "*";
            }
            cout << "\n Password: ";
            for (int i = 1; i <= 8; i++)
            {
                ch = getch();
                pass += ch;
                cout << "*";
            }
            if (email == "prince.12325635@sbi.in" && pin == "732008" && pass == "12345678")
            {
                bank_management();
            }
            else
            {
                cout << "\n\n Invalid email, pin, or password. Please try again.";
            }
            break;

        case 2:
            atm_management();
            break;

        case 3:
            exit(0);

        default:
            cout << "\n\n Invalid choice. Please try again.";
        }

        getch();
    }
}

void bank::bank_management()
{
    while (true)
    {
        system("cls");
        int choice;
        cout << "\n\n\t\tBank Management System";
        cout << "\n\n 1. New User";
        cout << "\n 2. Existing User";
        cout << "\n 3. Deposit";
        cout << "\n 4. Withdraw";
        cout << "\n 5. Transfer";
        cout << "\n 6. Payment";
        cout << "\n 7. Search User Record";
        cout << "\n 8. Edit User Record";
        cout << "\n 9. Delete User Record";
        cout << "\n 10. Show All Records";
        cout << "\n 11. Payment Records";
        cout << "\n 12. Go Back to Main Menu";
        cout << "\n\n Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            new_user();
            break;

        case 2:
            already_user();
            break;

        case 3:
            deposit();
            break;

        case 4:
            withdraw();
            break;

        case 5:
            transfer();
            break;
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
            cout << "\n\n Feature not implemented yet.";
            break;

        case 12:
            menu();
            break;

        default:
            cout << "\n\n Invalid choice. Please try again.";
        }

        getch();
    }
}

void bank::atm_management()
{
    while (true)
    {
        system("cls");
        int choice;
        cout << "\n\n\t\tATM Management System";
        cout << "\n\n 1. User Login & Check Balance";
        cout << "\n 2. Withdraw Amount";
        cout << "\n 3. Account Details";
        cout << "\n 4. Exit";
        cout << "\n\n Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        case 2:
        case 3:
            cout << "\n\n Feature not implemented yet.";
            break;

        case 4:
            menu();
            break;

        default:
            cout << "\n\n Invalid choice. Please try again.";
        }

        getch();
    }
}

void bank::new_user()
{
    while (true)
    {
        system("cls");
        fstream file;
        string id, name, fname, address, password, phonenumber;
        int pin;
        double balance;

        cout << "\n\n\t\tAdd New User";
        cout << "\n\n User ID: ";
        cin >> id;
        cout << "\n Name: ";
        cin >> name;
        cout << "\n Father's Name: ";
        cin >> fname;
        cout << "\n Address: ";
        cin >> address;
        cout << "\n Pin-code (6-digit): ";
        cin >> pin;
        cout << "\n Password: ";
        cin >> password;
        cout << "\n Phone Number: ";
        cin >> phonenumber;
        cout << "\n Current Balance (deposited): ";
        cin >> balance;

        file.open("bank.txt", ios::in);
        if (!file)
        {
            file.open("bank.txt", ios::app | ios::out);
            file << id << " " << name << " " << fname << " " << address << " " << pin << " " << password << " " << phonenumber << " " << balance << "\n";
            file.close();
            cout << "\n\n New user added successfully.";
            break;
        }
        else
        {
            string i, na, fna, add;
            int pi;
            double bal;
            file >> i >> na >> fna >> add >> pi >> password >> phonenumber >> bal;
            bool userExists = false;

            while (!file.eof())
            {
                if (i == id)
                {
                    cout << "\n\n User ID already exists.";
                    userExists = true;
                    break;
                }
                file >> i >> na >> fna >> add >> pi >> password >> phonenumber >> bal;
            }
            file.close();

            if (userExists)
            {
                getch();
                continue;
            }

            file.open("bank.txt", ios::app | ios::out);
            file << id << " " << name << " " << fname << " " << address << " " << pin << " " << password << " " << phonenumber << " " << balance << "\n";
            file.close();
            cout << "\n\n New user added successfully.";
            break;
        }
    }
}

void bank::already_user()
{
    bool found = false;
    string SearchId;
    system("cls");
    fstream file;
    cout << "\n\n\t\tExisting User Account";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n Error opening file.";
        return;
    }

    cout << "\n\n Enter User ID: ";
    cin >> SearchId;
    string id, name, fname, address, password, phonenumber;
    int pin;
    double balance;

    while (file >> id >> name >> fname >> address >> pin >> password >> phonenumber >> balance)
    {
        if (SearchId == id)
        {
            system("cls");
            cout << "Account found";
            cout << "\n User Pin: " << pin;
            cout << "\n User Password: " << password;
            found = true;
            break;
        }
    }
    file.close();

    if (!found)
    {
        cout << "\n Data not found.";
    }
}

void bank::deposit()
{
    string SearchId;
    double dep;
    bool found = false;
    system("cls");
    fstream file, file1;
    cout << "\n\n\t\tDeposit Amount Option";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File not found.";
        return;
    }

    cout << "\n\n Enter User ID: ";
    cin >> SearchId;
    file1.open("bank1.txt", ios::out);

    string id, name, fname, address, password, phonenumber;
    int pin;
    double balance;

    while (file >> id >> name >> fname >> address >> pin >> password >> phonenumber >> balance)
    {
        if (SearchId == id)
        {
            cout << "\n\n Enter Amount for Deposit: ";
            cin >> dep;
            balance += dep;
            file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << password << " " << phonenumber << " " << balance << "\n";
            cout << "\n\n Your amount " << dep << " has been successfully deposited.";
            found = true;
        }
        else
        {
            file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << password << " " << phonenumber << " " << balance << "\n";
        }
    }
    file.close();
    file1.close();
    remove("bank.txt");
    rename("bank1.txt", "bank.txt");

    if (!found)
    {
        cout << "\n Data not found.";
    }
}

void bank::withdraw()
{
    string SearchId;
    double wdraw;
    bool found = false;
    system("cls");
    fstream file, file1;
    cout << "\n\n\t\tWithdraw Amount Option";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File not found.";
        return;
    }

    cout << "\n\n Enter User ID: ";
    cin >> SearchId;
    file1.open("bank1.txt", ios::out);

    string id, name, fname, address, password, phonenumber;
    int pin;
    double balance;

    while (file >> id >> name >> fname >> address >> pin >> password >> phonenumber >> balance)
    {
        if (SearchId == id)
        {
            cout << "\n\n Enter Amount for Withdrawal: ";
            cin >> wdraw;
            if (wdraw > balance)
            {
                cout << "\n\n Insufficient balance. Current balance: " << balance;
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << password << " " << phonenumber << " " << balance << "\n";
            }
            else
            {
                balance -= wdraw;
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << password << " " << phonenumber << " " << balance << "\n";
                cout << "\n\n Your amount " << wdraw << " has been successfully withdrawn.";
                found = true;
            }
        }
        else
        {
            file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << password << " " << phonenumber << " " << balance << "\n";
        }
    }
    file.close();
    file1.close();
    remove("bank.txt");
    rename("bank1.txt", "bank.txt");

    if (!found)
    {
        cout << "\n Data not found.";
    }
}
void bank::transfer()
{
    system("cls");
    string s_id, r_id;
    double amount;
    bool s_match = false;
    bool r_match = false;

    cout << "\n\n\t\tTransfer Option";
    cout << "\n\n Enter Sender User ID: ";
    cin >> s_id;
    cout << "\n Enter Receiver User ID: ";
    cin >> r_id;
    cout << "\n Enter Transfer Amount: ";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "\n\n Transfer amount must be positive.";
        return;
    }

    fstream file, file1;
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File not found.";
        return;
    }

    file1.open("bank1.txt", ios::out);
    if (!file1)
    {
        cout << "\n\n Error creating temporary file.";
        file.close();
        return;
    }

    string id, name, fname, address, password, phonenumber;
    int pin;
    double balance;
    bool sufficient_balance = false;

    while (file >> id >> name >> fname >> address >> pin >> password >> phonenumber >> balance)
    {
        if (s_id == id)
        {
            s_match = true;
            if (balance >= amount)
            {
                balance -= amount;
                sufficient_balance = true;
            }
            else
            {
                cout << "\n\n Insufficient balance.";
                file1.close();
                file.close();
                return;
            }
        }
        if (r_id == id)
        {
            r_match = true;
            balance += amount;
        }
        file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << password << " " << phonenumber << " " << balance << "\n";
    }

    file.close();
    file1.close();

    if (!s_match)
    {
        cout << "\n\n Sender ID not found.";
        remove("bank1.txt"); 
        return;
    }

    if (!r_match)
    {
        cout << "\n\n Receiver ID not found.";
        remove("bank1.txt"); 
        return;
    }

    remove("bank.txt");
    rename("bank1.txt", "bank.txt");

    cout << "\n\n Transfer successful.";
}


int main()
{
    bank obj;
    obj.menu();
    return 0;
}
