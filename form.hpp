#ifndef def_form
#include "menu.hpp"
class Form
{
    string userName, email, password;
    string searchName, searchPassword, searchEmail;
    fstream formFile;
    string *formChoice;

public:
    Form()
    {
        formChoice = new string;
        userName = "";
        email = "";
        password = "";
    }
    void showFormMenu()
    {
        // system("cls") -> For Windows
        system("clear"); // -> For Mac
        cout << "==================================================================\n\n";
        cout << "                      <- Login / Register ->                  \n\n";
        cout << "==================================================================\n\n\n";
        cout << "1. Create Account\n\n";
        cout << "2. Sign In\n\n";
        cout << "3. Forget Password\n\n";
        cout << "4. Exit\n\n";
        cout << "Enter your choice: ";
    Form:
        cin >> *formChoice;
        if (*formChoice == "1")
        {
            createAccount();
        }
        else if (*formChoice == "2")
        {
            signIn();
        }
        else if (*formChoice == "3")
        {
            forgetPassword();
        }
        else if (*formChoice == "4")
        {
            cout << "Exiting...";
            // Sleep(2000); -> For Windows
            sleep(2); // -> For Mac
            exit(0);
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
            goto Form;
        }
    }
    void createAccount()
    {
        // system("cls"); -> For Windows
        system("clear"); // -> For Mac
        cout << "==================================================================\n\n";
        cout << "                          <- Register ->                  \n\n";
        cout << "==================================================================\n\n\n";
        cout << "Enter your username: ";
        cin >> userName;
        cout << "Enter your email: ";
        cin >> email;
        cout << "Enter your password: ";
        cin >> password;
        formFile.open("form.txt", ios::out | ios::app);
        formFile << userName << "|" << email << "|" << password << "\n";
        formFile.close();
        cout << "Account created successfully.\n";
        // Sleep(2000); -> For Windows
        sleep(2); // -> For Mac
        showFormMenu();
    }
    void signIn()
    {
        // system("cls"); -> For Windows
        system("clear"); // -> For Mac
        cout << "==================================================================\n\n";
        cout << "                           <- Login ->                  \n\n";
        cout << "==================================================================\n\n\n";
        cout << "Enter your username: ";
        cin >> searchName;
        cout << "Enter your password: ";
        cin >> searchPassword;
        formFile.open("form.txt", ios::in);
        getline(formFile, userName, '|');
        getline(formFile, email, '|');
        getline(formFile, password, '\n');
        while (!formFile.eof())
        {
            if (userName == searchName && password == searchPassword)
            {
                cout << "Login successful.\n";
                // Sleep(2000); -> For Windows
                sleep(2); // -> For Mac
                Menu menu;
                menu.showMenu();
            }
            getline(formFile, userName, '|');
            getline(formFile, email, '|');
            getline(formFile, password, '\n');
            if (formFile.eof() && userName != searchName && password != searchPassword)
            {
                cout << "Invalid credentials. Please try again.\n";
                // Sleep(2000); -> For Windows
                sleep(2); // -> For Mac
                formFile.close();
                signIn();
            }
        }
        formFile.close();
    }
    void forgetPassword()
    {
        system("clear"); // -> For Mac
        cout << "==================================================================\n\n";
        cout << "                     <- Forget the Password ->                  \n\n";
        cout << "==================================================================\n\n\n";
        cout << "Enter your email: ";
        cin >> searchEmail;
        formFile.open("form.txt", ios::in);
        getline(formFile, userName, '|');
        getline(formFile, email, '|');
        getline(formFile, password, '\n');
        while (!formFile.eof())
        {
            if (email == searchEmail)
            {
                cout << "Your password is: " << password << "\n";
                // Sleep(2000); -> For Windows
                sleep(2); // -> For Mac
                showFormMenu();
            }
            getline(formFile, userName, '|');
            getline(formFile, email, '|');
            getline(formFile, password, '\n');
            if (formFile.eof())
            {
                cout << "Email not found. Please try again.\n";
                // Sleep(2000); -> For Windows
                sleep(2); // -> For Mac
                formFile.close();
                forgetPassword();
            }
        }
        formFile.close();
    }
    ~Form()
    {
        delete formChoice;
        formChoice = NULL;
    }
};
#endif