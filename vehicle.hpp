#ifndef def_vehicle
#include<iostream>
#include<fstream>
#include<unistd.h>
using namespace std;
void backtoMainMenu();
class Vehicle
{
protected:
    string brand[500];
    string model[500];
    int year[500];
    int price[500];
    string color[5];
    fstream vehicleFile;
    static int totalAmount;
    string buyColor;
    char add;
    string *brandSelect;

public:
    Vehicle()
    {
        brandSelect = new string;
        color[0] = "Black";
        color[1] = "White";
        color[2] = "Red";
        color[3] = "Blue";
        color[4] = "Royal Blue";
    }
    ~Vehicle()
    {
        delete brandSelect;
        brandSelect = NULL;
    }
};
int Vehicle::totalAmount = 0;
class Car : public Vehicle
{
    char buyCar;
    string *carSelect;

public:
    Car()
    {
        carSelect = new string;
    }
    void showCar()
    {
        system("clear"); // -> For Mac
        cout << "==================================================================\n\n";
        cout << "                           <- Cars List ->                        \n\n";
        cout << "==================================================================\n\n\n";
        cout << "\t\t    Which brand car do you want?\n";
        cout << "\n 1. Audi";
        cout << "\n 2. BMW";
        cout << "\n 3. Mercedes";
        cout << "\n 4. Toyota";
        cout << "\n 5. Back to the Main Menu\n";
    }
    void selectCar()
    {
        showCar();
        cout << "\nEnter your choice: ";
        cin >> *brandSelect;
        if (*brandSelect == "1")
        {
            audiCars();
        }
        else if (*brandSelect == "2")
        {
            bmwCars();
        }
        else if (*brandSelect == "3")
        {
            mercedesCars();
        }
        else if (*brandSelect == "4")
        {
            toyotaCars();
        }
        else if (*brandSelect == "5")
        {
            // back to main menu
            backtoMainMenu();
        }
    }
    void audiCars()
    {
    audi:
        system("clear"); // -> For Mac
        cout << "==================================================================\n\n";
        cout << "                         <- Audi Car List ->                      \n\n";
        cout << "==================================================================\n\n\n";
        cout << "\n 1. Audi A3 (2019)";
        cout << "\n 2. Audi A4 (2018)";
        cout << "\n 3. Audi A6 (2020)";
        cout << "\n 4. Audi A8 (2024)";
        cout << "\n 5. Audi Q3 (2021)";
        cout << "\n 6. Audi Q5 (2024)";
        cout << "\n 7. Back to the Car List";
        cout << "\n\n Enter your choice: ";
        cin >> *carSelect;
        if (*carSelect == "1")
        {
            brand[0] = "Audi";
            model[0] = "A3";
            year[0] = 2019;
            price[0] = 31950;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "                   <- Selected Car:" << brand[0] << " " << model[0] << " " << year[0] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Audi/Audi A3.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this car? (Y/N): ";
        a3:
            cin >> buyCar;
            if (buyCar == 'Y' || buyCar == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Audi Car List";
                cout << "\n\n Enter your choice: ";
            A3:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[0];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[0] << " " << model[0] << " " << year[0] << " " << color[0] << " -> $" << price[0] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[0];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[0] << " " << model[0] << " " << year[0] << " " << color[1] << " -> $" << price[0] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[0];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[0] << " " << model[0] << " " << year[0] << " " << color[2] << " -> $" << price[0] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[0];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[0] << " " << model[0] << " " << year[0] << " " << color[3] << " -> $" << price[0] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[0];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[0] << " " << model[0] << " " << year[0] << " " << color[4] << " -> $" << price[0] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto audi;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto A3;
                }
            }
            else if (buyCar == 'N' || buyCar == 'n')
            {
                goto audi;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto a3;
            }
        }
        else if (*carSelect == "2")
        {
            brand[1] = "Audi";
            model[1] = "A4";
            year[1] = 2018;
            price[1] = 36000;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "                 <- Selected Car:" << brand[1] << " " << model[1] << " " << year[1] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Audi/Audi A4.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this car? (Y/N): ";
        a4:
            cin >> buyCar;
            if (buyCar == 'Y' || buyCar == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Audi Car List";
                cout << "\n\n Enter your choice: ";
            A4:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[1];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[1] << " " << model[1] << " " << year[1] << " " << color[0] << " -> $" << price[1] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[1];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[1] << " " << model[1] << " " << year[1] << " " << color[1] << " -> $" << price[1] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[1];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[1] << " " << model[1] << " " << year[1] << " " << color[2] << " -> $" << price[1] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[1];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[1] << " " << model[1] << " " << year[1] << " " << color[3] << " -> $" << price[1] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[1];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[1] << " " << model[1] << " " << year[1] << " " << color[4] << " -> $" << price[1] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto audi;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto A4;
                }
            }
            else if (buyCar == 'N' || buyCar == 'n')
            {
                goto audi;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto a4;
            }
        }
        else if (*carSelect == "3")
        {
            brand[2] = "Audi";
            model[2] = "A6";
            year[2] = 2020;
            price[2] = 49700;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "            <- Selected Car:" << brand[2] << " " << model[2] << " " << year[2] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Audi/Audi A6.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this car? (Y/N): ";
        a6:
            cin >> buyCar;
            if (buyCar == 'Y' || buyCar == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Audi Car List";
                cout << "\n\n Enter your choice: ";
            A6:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[2];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[2] << " " << model[2] << " " << year[2] << " " << color[0] << " -> $" << price[2] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[2];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[2] << " " << model[2] << " " << year[2] << " " << color[1] << " -> $" << price[2] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[2];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[2] << " " << model[2] << " " << year[2] << " " << color[2] << " -> $" << price[2] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[2];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[2] << " " << model[2] << " " << year[2] << " " << color[3] << " -> $" << price[2] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[2];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[2] << " " << model[2] << " " << year[2] << " " << color[4] << " -> $" << price[2] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto audi;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto A6;
                }
            }
            else if (buyCar == 'N' || buyCar == 'n')
            {
                goto audi;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto a6;
            }
        }
        else if (*carSelect == "4")
        {
            brand[3] = "Audi";
            model[3] = "A8";
            year[3] = 2024;
            price[3] = 82500;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "            <- Selected Car:" << brand[3] << " " << model[3] << " " << year[3] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Audi/Audi A8.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this car? (Y/N): ";
        a8:
            cin >> buyCar;
            if (buyCar == 'Y' || buyCar == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Audi Car List";
                cout << "\n\n Enter your choice: ";
            A8:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[3];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[3] << " " << model[3] << " " << year[3] << " " << color[0] << " -> $" << price[3] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[3];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[3] << " " << model[3] << " " << year[3] << " " << color[1] << " -> $" << price[3] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[3];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[3] << " " << model[3] << " " << year[3] << " " << color[2] << " -> $" << price[3] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[3];
                    cout << "You have selected " << color[3] << " car" << endl;
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[3] << " " << model[3] << " " << year[3] << " " << color[3] << " -> $" << price[3] << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[3];
                    cout << "You have selected " << color[4] << " car" << endl;
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[3] << " " << model[3] << " " << year[3] << " " << color[4] << " -> $" << price[3] << endl;
                }
                else if (buyColor == "6")
                {
                    goto audi;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto A8;
                }
            }
            else if (buyCar == 'N' || buyCar == 'n')
            {
                goto audi;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto a8;
            }
        }
        else if (*carSelect == "5")
        {
            brand[4] = "Audi";
            model[4] = "Q3";
            year[4] = 2021;
            price[4] = 32900;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "            <- Selected Car:" << brand[4] << " " << model[4] << " " << year[4] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Audi/Audi Q3.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this car? (Y/N): ";
        q3:
            cin >> buyCar;
            if (buyCar == 'Y' || buyCar == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Audi Car List";
                cout << "\n\n Enter your choice: ";
            Q3:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[4];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[4] << " " << model[4] << " " << year[4] << " " << color[0] << " -> $" << price[4] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[4];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[4] << " " << model[4] << " " << year[4] << " " << color[1] << " -> $" << price[4] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[4];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[4] << " " << model[4] << " " << year[4] << " " << color[2] << " -> $" << price[4] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[4];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[4] << " " << model[4] << " " << year[4] << " " << color[3] << " -> $" << price[4] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[4];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[4] << " " << model[4] << " " << year[4] << " " << color[4] << " -> $" << price[4] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto audi;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto Q3;
                }
            }
            else if (buyCar == 'N' || buyCar == 'n')
            {
                goto audi;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto q3;
            }
        }
        else if (*carSelect == "6")
        {
            brand[5] = "Audi";
            model[5] = "Q5";
            year[5] = 2024;
            price[5] = 41500;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "            <- Selected Car:" << brand[5] << " " << model[5] << " " << year[5] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Audi/Audi Q5.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this car? (Y/N): ";
        q5:
            cin >> buyCar;
            if (buyCar == 'Y' || buyCar == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Audi Car List";
                cout << "\n\n Enter your choice: ";
            Q5:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[5];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[5] << " " << model[5] << " " << year[5] << " " << color[0] << " -> $" << price[5] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[5];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[5] << " " << model[5] << " " << year[5] << " " << color[1] << " -> $" << price[5] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[5];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[5] << " " << model[5] << " " << year[5] << " " << color[2] << " -> $" << price[5] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[5];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[5] << " " << model[5] << " " << year[5] << " " << color[3] << " -> $" << price[5] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[5];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[4] << " " << model[4] << " " << year[4] << " " << color[4] << " -> $" << price[5] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto audi;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto Q5;
                }
            }
            else if (buyCar == 'N' || buyCar == 'n')
            {
                goto audi;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto q5;
            }
        }
        else if (*carSelect == "7")
        {
            selectCar();
        }
        cout << "Do you want add more Audi Vehicles? (Y/N): ";
    back:
        cin >> add;
        if (add == 'Y' || add == 'y')
        {
            vehicleFile.close();
            goto audi;
        }
        else if (add == 'N' || add == 'n')
        {
            cout << "Your Total Amount: $" << totalAmount << endl;
            cout << "Press Enter to Proceed...";
            cin.ignore();
            cin.get();
            vehicleFile.close();
            selectCar();
        }
        else
        {
            cout << "\n\nInvalid Choice! Try Again: ";
            goto back;
        }
    }
    void bmwCars()
    {
    bmw:
        system("clear"); // -> For Mac
        cout << "==================================================================\n\n";
        cout << "                         <- BMW Car List ->                      \n\n";
        cout << "==================================================================\n\n\n";
        cout << "\n 1. BMW 3 Series (2022)";
        cout << "\n 2. BMW 5 Series (2018)";
        cout << "\n 3. BMW X3 (2020)";
        cout << "\n 4. BMW Z4 (2024)";
        cout << "\n 5. Back to the Car List";
        cout << "\n\n Enter your choice: ";
        cin >> *carSelect;
        if (*carSelect == "1")
        {
            brand[10] = "BMW";
            model[10] = "3 Series";
            year[10] = 2022;
            price[10] = 44000;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "                   <- Selected Car:" << brand[10] << " " << model[10] << " " << year[10] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("BMW/BMW 3 Series.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this car? (Y/N): ";
        s3:
            cin >> buyCar;
            if (buyCar == 'Y' || buyCar == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to BMW Car List";
                cout << "\n\n Enter your choice: ";
            S3:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[10];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[10] << " " << model[10] << " " << year[10] << " " << color[0] << " -> $" << price[10] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[10];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[10] << " " << model[10] << " " << year[10] << " " << color[1] << " -> $" << price[10] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[10];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[10] << " " << model[10] << " " << year[10] << " " << color[2] << " -> $" << price[10] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[10];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[10] << " " << model[10] << " " << year[10] << " " << color[3] << " -> $" << price[10] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[10];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[10] << " " << model[10] << " " << year[10] << " " << color[4] << " -> $" << price[10] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto bmw;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto S3;
                }
            }
            else if (buyCar == 'N' || buyCar == 'n')
            {
                goto bmw;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto s3;
            }
        }
        else if (*carSelect == "2")
        {
            brand[11] = "BMW";
            model[11] = "5 Series";
            year[11] = 2018;
            price[11] = 58000;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "                 <- Selected Car:" << brand[11] << " " << model[11] << " " << year[11] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("BMW/BMW 5 Series.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this car? (Y/N): ";
        s5:
            cin >> buyCar;
            if (buyCar == 'Y' || buyCar == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to BMW Car List";
                cout << "\n\n Enter your choice: ";
            S5:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[11];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[11] << " " << model[11] << " " << year[11] << " " << color[0] << " -> $" << price[11] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[11];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[11] << " " << model[11] << " " << year[11] << " " << color[1] << " -> $" << price[11] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[11];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[11] << " " << model[11] << " " << year[11] << " " << color[2] << " -> $" << price[11] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[11];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[11] << " " << model[11] << " " << year[11] << " " << color[3] << " -> $" << price[11] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[11];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[11] << " " << model[11] << " " << year[11] << " " << color[4] << " -> $" << price[11] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto bmw;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto S5;
                }
            }
            else if (buyCar == 'N' || buyCar == 'n')
            {
                goto bmw;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto s5;
            }
        }
        else if (*carSelect == "3")
        {
            brand[12] = "BMW";
            model[12] = "X3";
            year[12] = 2020;
            price[12] = 46000;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "            <- Selected Car:" << brand[12] << " " << model[12] << " " << year[12] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("BMW/BMW X3.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this car? (Y/N): ";
        x3:
            cin >> buyCar;
            if (buyCar == 'Y' || buyCar == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to BMW Car List";
                cout << "\n\n Enter your choice: ";
            X3:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[12];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[12] << " " << model[12] << " " << year[12] << " " << color[0] << " -> $" << price[12] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[12];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[12] << " " << model[12] << " " << year[12] << " " << color[1] << " -> $" << price[12] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[12];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[12] << " " << model[12] << " " << year[12] << " " << color[2] << " -> $" << price[12] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[12];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[12] << " " << model[12] << " " << year[12] << " " << color[3] << " -> $" << price[12] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[12];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[12] << " " << model[12] << " " << year[12] << " " << color[4] << " -> $" << price[12] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto bmw;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto X3;
                }
            }
            else if (buyCar == 'N' || buyCar == 'n')
            {
                goto bmw;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto x3;
            }
        }
        else if (*carSelect == "4")
        {
            brand[13] = "BMW";
            model[13] = "Z4";
            year[13] = 2024;
            price[13] = 54000;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "            <- Selected Car:" << brand[13] << " " << model[13] << " " << year[13] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("BMW/BMW Z4.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this car? (Y/N): ";
        z4:
            cin >> buyCar;
            if (buyCar == 'Y' || buyCar == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to BMW Car List";
                cout << "\n\n Enter your choice: ";
            Z4:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[13];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[13] << " " << model[13] << " " << year[13] << " " << color[0] << " -> $" << price[13] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[13];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[13] << " " << model[13] << " " << year[13] << " " << color[1] << " -> $" << price[13] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[13];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[13] << " " << model[13] << " " << year[13] << " " << color[2] << " -> $" << price[13] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[13];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[13] << " " << model[13] << " " << year[13] << " " << color[3] << " -> $" << price[13] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[13];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[13] << " " << model[13] << " " << year[13] << " " << color[4] << " -> $" << price[13] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto bmw;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto Z4;
                }
            }
            else if (buyCar == 'N' || buyCar == 'n')
            {
                goto bmw;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto z4;
            }
        }
        else if (*carSelect == "5")
        {
            selectCar();
        }
        cout << "Do you want add more BMW Vehicles? (Y/N): ";
    back:
        cin >> add;
        if (add == 'Y' || add == 'y')
        {
            vehicleFile.close();
            goto bmw;
        }
        else if (add == 'N' || add == 'n')
        {
            cout << "Your Total Amount: $" << totalAmount << endl;
            cout << "Press Enter to Proceed...";
            cin.ignore();
            cin.get();
            vehicleFile.close();
            selectCar();
        }
        else
        {
            cout << "\n\nInvalid Choice! Try Again: ";
            goto back;
        }
    }
    void mercedesCars()
    {
    mercedes:
        system("clear"); // -> For Mac
        cout << "==================================================================\n\n";
        cout << "                      <- Mercedes Car List ->                      \n\n";
        cout << "==================================================================\n\n\n";
        cout << "\n 1. Mercedes-Benz A-Class (2022)";
        cout << "\n 2. Mercedes-Benz C-Class (2022)";
        cout << "\n 3. Mercedes-Benz E-Class (2021)";
        cout << "\n 4. Mercedes-Benz GLA-Class (2023)";
        cout << "\n 5. Mercedes-Benz GLC-Class (2024)";
        cout << "\n 6. Back to the Car List";
        cout << "\n\n Enter your choice: ";
        cin >> *carSelect;
        if (*carSelect == "1")
        {
            brand[20] = "Mercedes-Benz";
            model[20] = "A-Class";
            year[20] = 2022;
            price[20] = 34000;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "                   <- Selected Car:" << brand[20] << " " << model[20] << " " << year[20] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Mercedes/A Class.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this car? (Y/N): ";
        aC:
            cin >> buyCar;
            if (buyCar == 'Y' || buyCar == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Mercedes Car List";
                cout << "\n\n Enter your choice: ";
            AC:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[20];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[20] << " " << model[20] << " " << year[20] << " " << color[0] << " -> $" << price[20] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[20];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[20] << " " << model[20] << " " << year[20] << " " << color[1] << " -> $" << price[20] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[20];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[20] << " " << model[20] << " " << year[20] << " " << color[2] << " -> $" << price[20] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[20];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[20] << " " << model[20] << " " << year[20] << " " << color[3] << " -> $" << price[20] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[20];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[20] << " " << model[20] << " " << year[20] << " " << color[4] << " -> $" << price[20] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto mercedes;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto AC;
                }
            }
            else if (buyCar == 'N' || buyCar == 'n')
            {
                goto mercedes;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto aC;
            }
        }
        else if (*carSelect == "2")
        {
            brand[21] = "Mercedes-Benz";
            model[21] = "C-Class";
            year[21] = 2022;
            price[21] = 43000;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "                 <- Selected Car:" << brand[21] << " " << model[21] << " " << year[21] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Mercedes/C Class.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this car? (Y/N): ";
        cC:
            cin >> buyCar;
            if (buyCar == 'Y' || buyCar == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Mercedes Car List";
                cout << "\n\n Enter your choice: ";
            CC:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[21];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[21] << " " << model[21] << " " << year[21] << " " << color[0] << " -> $" << price[21] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[21];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[21] << " " << model[21] << " " << year[21] << " " << color[1] << " -> $" << price[21] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[21];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[21] << " " << model[21] << " " << year[21] << " " << color[2] << " -> $" << price[21] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[21];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[21] << " " << model[21] << " " << year[21] << " " << color[3] << " -> $" << price[21] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[21];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[21] << " " << model[21] << " " << year[21] << " " << color[4] << " -> $" << price[21] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto mercedes;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto CC;
                }
            }
            else if (buyCar == 'N' || buyCar == 'n')
            {
                goto mercedes;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto cC;
            }
        }
        else if (*carSelect == "3")
        {
            brand[22] = "Mercedes-Benz";
            model[22] = "E-Class";
            year[22] = 2021;
            price[22] = 54000;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "            <- Selected Car:" << brand[22] << " " << model[22] << " " << year[22] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Mercedes/E Class.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this car? (Y/N): ";
        eC:
            cin >> buyCar;
            if (buyCar == 'Y' || buyCar == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Mercedes Car List";
                cout << "\n\n Enter your choice: ";
            EC:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[22];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[22] << " " << model[22] << " " << year[22] << " " << color[0] << " -> $" << price[22] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[22];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[22] << " " << model[22] << " " << year[22] << " " << color[1] << " -> $" << price[22] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[22];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[22] << " " << model[22] << " " << year[22] << " " << color[2] << " -> $" << price[22] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[22];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[22] << " " << model[22] << " " << year[22] << " " << color[3] << " -> $" << price[22] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[22];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[22] << " " << model[22] << " " << year[22] << " " << color[4] << " -> $" << price[22] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto mercedes;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto EC;
                }
            }
            else if (buyCar == 'N' || buyCar == 'n')
            {
                goto mercedes;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto eC;
            }
        }
        else if (*carSelect == "4")
        {
            brand[23] = "Mercedes-Benz";
            model[23] = "GLA-Class";
            year[23] = 2023;
            price[23] = 38000;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "            <- Selected Car:" << brand[23] << " " << model[23] << " " << year[23] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Mercedes/GLA Class.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this car? (Y/N): ";
        gla:
            cin >> buyCar;
            if (buyCar == 'Y' || buyCar == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Mercedes Car List";
                cout << "\n\n Enter your choice: ";
            GLA:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[23];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[23] << " " << model[23] << " " << year[23] << " " << color[0] << " -> $" << price[23] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[23];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[23] << " " << model[23] << " " << year[23] << " " << color[1] << " -> $" << price[23] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[23];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[23] << " " << model[23] << " " << year[23] << " " << color[2] << " -> $" << price[23] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[23];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[23] << " " << model[23] << " " << year[23] << " " << color[3] << " -> $" << price[23] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[23];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[23] << " " << model[23] << " " << year[23] << " " << color[4] << " -> $" << price[23] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto mercedes;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto GLA;
                }
            }
            else if (buyCar == 'N' || buyCar == 'n')
            {
                goto mercedes;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto gla;
            }
        }
        else if (*carSelect == "5")
        {
            brand[24] = "Mercedes-Benz";
            model[24] = "GLC-Class";
            year[24] = 2024;
            price[24] = 44500;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "            <- Selected Car:" << brand[24] << " " << model[24] << " " << year[24] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Mercedes/GLC Class.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this car? (Y/N): ";
        glc:
            cin >> buyCar;
            if (buyCar == 'Y' || buyCar == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Mercedes Car List";
                cout << "\n\n Enter your choice: ";
            GLC:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[24];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[24] << " " << model[24] << " " << year[24] << " " << color[0] << " -> $" << price[24] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[24];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[24] << " " << model[24] << " " << year[24] << " " << color[1] << " -> $" << price[24] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[24];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[24] << " " << model[24] << " " << year[24] << " " << color[2] << " -> $" << price[24] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[24];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[24] << " " << model[24] << " " << year[24] << " " << color[3] << " -> $" << price[24] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[24];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[24] << " " << model[24] << " " << year[24] << " " << color[4] << " -> $" << price[24] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto mercedes;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto GLC;
                }
            }
            else if (buyCar == 'N' || buyCar == 'n')
            {
                goto mercedes;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto glc;
            }
        }
        else if (*carSelect == "6")
        {
            selectCar();
        }
        cout << "Do you want add more Mercedes Vehicles? (Y/N): ";
    back:
        cin >> add;
        if (add == 'Y' || add == 'y')
        {
            vehicleFile.close();
            goto mercedes;
        }
        else if (add == 'N' || add == 'n')
        {
            cout << "Your Total Amount: $" << totalAmount << endl;
            cout << "Press Enter to Proceed...";
            cin.ignore();
            cin.get();
            vehicleFile.close();
            selectCar();
        }
        else
        {
            cout << "\n\nInvalid Choice! Try Again: ";
            goto back;
        }
    }
    void toyotaCars()
    {
    toyota:
        system("clear"); // -> For Mac
        cout << "==================================================================\n\n";
        cout << "                      <- Toyota Car List ->                      \n\n";
        cout << "==================================================================\n\n\n";
        cout << "\n 1. Toyota Camry (2022)";
        cout << "\n 2. Toyota Corolla (2021)";
        cout << "\n 3. Toyota Highlander (2023)";
        cout << "\n 4. Toyota RAV4 (2020)";
        cout << "\n 5. Back to the Car List";
        cout << "\n\n Enter your choice: ";
        cin >> *carSelect;
        if (*carSelect == "1")
        {
            brand[30] = "Toyota";
            model[30] = "Camry";
            year[30] = 2022;
            price[30] = 25000;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "                   <- Selected Car:" << brand[30] << " " << model[30] << " " << year[30] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Toyota/Toyota Camry.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this car? (Y/N): ";
        camry:
            cin >> buyCar;
            if (buyCar == 'Y' || buyCar == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Toyota Car List";
                cout << "\n\n Enter your choice: ";
            Camry:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[30];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[30] << " " << model[30] << " " << year[30] << " " << color[0] << " -> $" << price[30] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[30];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[30] << " " << model[30] << " " << year[30] << " " << color[1] << " -> $" << price[30] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[30];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[30] << " " << model[30] << " " << year[30] << " " << color[2] << " -> $" << price[30] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[30];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[30] << " " << model[30] << " " << year[30] << " " << color[3] << " -> $" << price[30] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[30];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[30] << " " << model[30] << " " << year[30] << " " << color[4] << " -> $" << price[30] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto toyota;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto Camry;
                }
            }
            else if (buyCar == 'N' || buyCar == 'n')
            {
                goto toyota;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto camry;
            }
        }
        else if (*carSelect == "2")
        {
            brand[31] = "Toyota";
            model[31] = "Corolla";
            year[31] = 2021;
            price[31] = 20000;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "                 <- Selected Car:" << brand[31] << " " << model[31] << " " << year[31] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Toyota/Toyota Corolla.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this car? (Y/N): ";
        corolla:
            cin >> buyCar;
            if (buyCar == 'Y' || buyCar == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Toyota Car List";
                cout << "\n\n Enter your choice: ";
            Corolla:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[31];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[31] << " " << model[31] << " " << year[31] << " " << color[0] << " -> $" << price[31] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[31];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[31] << " " << model[31] << " " << year[31] << " " << color[1] << " -> $" << price[31] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[31];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[31] << " " << model[31] << " " << year[31] << " " << color[2] << " -> $" << price[31] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[31];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[31] << " " << model[31] << " " << year[31] << " " << color[3] << " -> $" << price[31] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[31];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[31] << " " << model[31] << " " << year[31] << " " << color[4] << " -> $" << price[31] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto toyota;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto Corolla;
                }
            }
            else if (buyCar == 'N' || buyCar == 'n')
            {
                goto toyota;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto corolla;
            }
        }
        else if (*carSelect == "3")
        {
            brand[32] = "Toyota";
            model[32] = "Highlander";
            year[32] = 2023;
            price[32] = 36000;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "            <- Selected Car:" << brand[32] << " " << model[32] << " " << year[32] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Toyota/Toyota Highlander.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this car? (Y/N): ";
        highlander:
            cin >> buyCar;
            if (buyCar == 'Y' || buyCar == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Toyota Car List";
                cout << "\n\n Enter your choice: ";
            Highlander:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[32];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[32] << " " << model[32] << " " << year[32] << " " << color[0] << " -> $" << price[32] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[32];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[32] << " " << model[32] << " " << year[32] << " " << color[1] << " -> $" << price[32] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[32];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[32] << " " << model[32] << " " << year[32] << " " << color[2] << " -> $" << price[32] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[32];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[32] << " " << model[32] << " " << year[32] << " " << color[3] << " -> $" << price[32] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[32];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[32] << " " << model[32] << " " << year[32] << " " << color[4] << " -> $" << price[32] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto toyota;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto Highlander;
                }
            }
            else if (buyCar == 'N' || buyCar == 'n')
            {
                goto toyota;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto highlander;
            }
        }
        else if (*carSelect == "4")
        {
            brand[33] = "Toyota";
            model[33] = "RAV4";
            year[33] = 2020;
            price[33] = 26000;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "            <- Selected Car:" << brand[33] << " " << model[33] << " " << year[33] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Toyota/Toyota RAV4.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this car? (Y/N): ";
        rav4:
            cin >> buyCar;
            if (buyCar == 'Y' || buyCar == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Toyota Car List";
                cout << "\n\n Enter your choice: ";
            RAV4:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[33];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[33] << " " << model[33] << " " << year[33] << " " << color[0] << " -> $" << price[33] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[33];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[33] << " " << model[33] << " " << year[33] << " " << color[1] << " -> $" << price[33] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[33];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[33] << " " << model[33] << " " << year[33] << " " << color[2] << " -> $" << price[33] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[33];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[33] << " " << model[33] << " " << year[33] << " " << color[3] << " -> $" << price[33] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[33];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[33] << " " << model[33] << " " << year[33] << " " << color[4] << " -> $" << price[33] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto toyota;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto RAV4;
                }
            }
            else if (buyCar == 'N' || buyCar == 'n')
            {
                goto toyota;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto rav4;
            }
        }
        else if (*carSelect == "5")
        {
            selectCar();
        }
        cout << "Do you want add more Toyota Vehicles? (Y/N): ";
    back:
        cin >> add;
        if (add == 'Y' || add == 'y')
        {
            vehicleFile.close();
            goto toyota;
        }
        else if (add == 'N' || add == 'n')
        {
            cout << "Your Total Amount: $" << totalAmount << endl;
            cout << "Press Enter to Proceed...";
            cin.ignore();
            cin.get();
            vehicleFile.close();
            selectCar();
        }
        else
        {
            cout << "\n\nInvalid Choice! Try Again: ";
            goto back;
        }
    }
    ~Car()
    {
        delete carSelect;
        carSelect = NULL;
    }
};
class Bike : public Vehicle
{
    string *bikeSelect;
    char buyBike;

public:
    Bike()
    {
        bikeSelect = new string;
    }
    void showBike()
    {
        system("clear"); // -> For Mac
        cout << "==================================================================\n\n";
        cout << "                          <- Bikes List ->                        \n\n";
        cout << "==================================================================\n\n\n";
        cout << "\t\t   Which brand bike do you want?\n";
        cout << "\n 1. Suzuki";
        cout << "\n 2. Kawasaki";
        cout << "\n 3. Honda";
        cout << "\n 4. Back to the Main Menu\n";
    }
    void selectBike()
    {
        showBike();
        cout << "\n Enter your choice: ";
        cin >> *brandSelect;
        if (*brandSelect == "1")
        {
            suzukiBikes();
        }
        else if (*brandSelect == "2")
        {
            kawasakiBikes();
        }
        else if (*brandSelect == "3")
        {
            hondaBikes();
        }
        else if (*brandSelect == "4")
        {
            backtoMainMenu();
        }
    }
    void suzukiBikes()
    {
    suzuki:
        system("clear"); // -> For Mac
        cout << "==================================================================\n\n";
        cout << "                      <- Suzuki Bikes List ->                     \n\n";
        cout << "==================================================================\n\n\n";
        cout << "\t\t   Which model bike do you want?\n";
        cout << "\n 1. Suzuki GSX-R1000 (2023)";
        cout << "\n 2. Suzuki Hayabusa (2021)";
        cout << "\n 3. Suzuki V-Storm 650 (2022)";
        cout << "\n 4. Back to Bikes List\n";
        cout << "Enter your choice: ";
        cin >> *bikeSelect;
        if (*bikeSelect == "1")
        {
            brand[100] = "Suzuki";
            model[100] = "GSX-R1000";
            year[100] = 2023;
            price[100] = 18000;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "                   <- Selected Car:" << brand[100] << " " << model[100] << " " << year[100] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Suzuki/GSX-R1000.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this bike? (Y/N): ";
        gsx:
            cin >> buyBike;
            if (buyBike == 'Y' || buyBike == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Suzuki Bike List";
                cout << "\n\n Enter your choice: ";
            GSX:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[100];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[100] << " " << model[100] << " " << year[100] << " " << color[0] << " -> $" << price[100] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[100];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[100] << " " << model[100] << " " << year[100] << " " << color[1] << " -> $" << price[100] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[100];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[100] << " " << model[100] << " " << year[100] << " " << color[2] << " -> $" << price[100] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[100];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[100] << " " << model[100] << " " << year[100] << " " << color[3] << " -> $" << price[100] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[100];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[100] << " " << model[100] << " " << year[100] << " " << color[4] << " -> $" << price[100] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto suzuki;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto GSX;
                }
            }
            else if (buyBike == 'N' || buyBike == 'n')
            {
                goto suzuki;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto gsx;
            }
        }
        else if (*bikeSelect == "2")
        {
            brand[101] = "Suzuki";
            model[101] = "Hayabusa";
            year[101] = 2021;
            price[101] = 18599;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "                 <- Selected Car:" << brand[101] << " " << model[101] << " " << year[101] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Suzuki/Hayabusa.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this bike? (Y/N): ";
        hayabusa:
            cin >> buyBike;
            if (buyBike == 'Y' || buyBike == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Suzuki Bike List";
                cout << "\n\n Enter your choice: ";
            Hayabusa:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[101];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[101] << " " << model[101] << " " << year[101] << " " << color[0] << " -> $" << price[101] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[101];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[101] << " " << model[101] << " " << year[101] << " " << color[1] << " -> $" << price[101] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[101];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[101] << " " << model[101] << " " << year[101] << " " << color[2] << " -> $" << price[101] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[101];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[101] << " " << model[101] << " " << year[101] << " " << color[3] << " -> $" << price[101] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[101];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[101] << " " << model[101] << " " << year[101] << " " << color[4] << " -> $" << price[101] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto suzuki;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto Hayabusa;
                }
            }
            else if (buyBike == 'N' || buyBike == 'n')
            {
                goto suzuki;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto hayabusa;
            }
        }
        else if (*bikeSelect == "3")
        {
            brand[102] = "Suzuki";
            model[102] = "V-Storm 650";
            year[102] = 2020;
            price[102] = 49700;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "            <- Selected Car:" << brand[102] << " " << model[102] << " " << year[102] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Suzuki/V-Storm 650.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this bike? (Y/N): ";
        vS:
            cin >> buyBike;
            if (buyBike == 'Y' || buyBike == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Suzuki Bike List";
                cout << "\n\n Enter your choice: ";
            VS:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[102];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[102] << " " << model[102] << " " << year[102] << " " << color[0] << " -> $" << price[102] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[102];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[102] << " " << model[102] << " " << year[102] << " " << color[1] << " -> $" << price[102] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[102];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[102] << " " << model[102] << " " << year[102] << " " << color[2] << " -> $" << price[102] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[102];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[102] << " " << model[102] << " " << year[102] << " " << color[3] << " -> $" << price[102] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[102];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[102] << " " << model[102] << " " << year[102] << " " << color[4] << " -> $" << price[102] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto suzuki;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto VS;
                }
            }
            else if (buyBike == 'N' || buyBike == 'n')
            {
                goto suzuki;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto vS;
            }
        }
        else if (*bikeSelect == "4")
        {
            selectBike();
        }
        cout << "Do you want add more Suzuki Vehicles? (Y/N): ";
    back:
        cin >> add;
        if (add == 'Y' || add == 'y')
        {
            vehicleFile.close();
            goto suzuki;
        }
        else if (add == 'N' || add == 'n')
        {
            cout << "Your Total Amount: $" << totalAmount << endl;
            cout << "Press Enter to Proceed...";
            cin.ignore();
            cin.get();
            vehicleFile.close();
            selectBike();
        }
        else
        {
            cout << "\n\nInvalid Choice! Try Again: ";
            goto back;
        }
    }
    void kawasakiBikes()
    {
    kawasaki:
        system("clear"); // -> For Mac
        cout << "==================================================================\n\n";
        cout << "                     <- Kawasaki Bikes List ->                     \n\n";
        cout << "==================================================================\n\n\n";
        cout << "\t\t   Which model bike do you want?\n";
        cout << "\n 1. Kawasaki Ninja 400 (2023)";
        cout << "\n 2. Kawaski Versys 650 (2022)";
        cout << "\n 3. Kawasaki Vulcan S (2021)";
        cout << "\n 4. Kawasaki Z900 (2023)";
        cout << "\n 5. Back to Bikes List\n";
        cout << "Enter your choice: ";
        cin >> *bikeSelect;
        if (*bikeSelect == "1")
        {
            brand[200] = "Kawasaki";
            model[200] = "Ninja 400";
            year[200] = 2023;
            price[200] = 5200;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "                   <- Selected Car:" << brand[200] << " " << model[200] << " " << year[200] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Kawasaki/Ninja 400.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this bike? (Y/N): ";
        ninja:
            cin >> buyBike;
            if (buyBike == 'Y' || buyBike == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Kawasaki Bike List";
                cout << "\n\n Enter your choice: ";
            Ninja:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[200];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[200] << " " << model[200] << " " << year[200] << " " << color[0] << " -> $" << price[200] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[200];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[200] << " " << model[200] << " " << year[200] << " " << color[1] << " -> $" << price[200] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[200];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[200] << " " << model[200] << " " << year[200] << " " << color[2] << " -> $" << price[200] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[200];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[200] << " " << model[200] << " " << year[200] << " " << color[3] << " -> $" << price[200] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[200];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[200] << " " << model[200] << " " << year[200] << " " << color[4] << " -> $" << price[200] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto kawasaki;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto Ninja;
                }
            }
            else if (buyBike == 'N' || buyBike == 'n')
            {
                goto kawasaki;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto ninja;
            }
        }
        else if (*bikeSelect == "2")
        {
            brand[201] = "Kawasaki";
            model[201] = "Versys 650";
            year[201] = 2022;
            price[201] = 8500;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "                 <- Selected Car:" << brand[201] << " " << model[201] << " " << year[201] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Kawasaki/Versys 650.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this bike? (Y/N): ";
        versys:
            cin >> buyBike;
            if (buyBike == 'Y' || buyBike == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Kawasaki Bike List";
                cout << "\n\n Enter your choice: ";
            Versys:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[201];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[201] << " " << model[201] << " " << year[201] << " " << color[0] << " -> $" << price[201] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[201];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[201] << " " << model[201] << " " << year[201] << " " << color[1] << " -> $" << price[201] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[201];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[201] << " " << model[201] << " " << year[201] << " " << color[2] << " -> $" << price[201] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[201];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[201] << " " << model[201] << " " << year[201] << " " << color[3] << " -> $" << price[201] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[201];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[201] << " " << model[201] << " " << year[201] << " " << color[4] << " -> $" << price[201] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto kawasaki;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto Versys;
                }
            }
            else if (buyBike == 'N' || buyBike == 'n')
            {
                goto kawasaki;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto versys;
            }
        }
        else if (*bikeSelect == "3")
        {
            brand[202] = "Kawasaki";
            model[202] = "Vulcan S";
            year[202] = 2022;
            price[202] = 7200;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "            <- Selected Car:" << brand[202] << " " << model[202] << " " << year[202] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Suzuki/V-Storm 650.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this bike? (Y/N): ";
        vU:
            cin >> buyBike;
            if (buyBike == 'Y' || buyBike == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Suzuki Bike List";
                cout << "\n\n Enter your choice: ";
            VU:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[202];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[202] << " " << model[202] << " " << year[202] << " " << color[0] << " -> $" << price[202] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[202];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[202] << " " << model[202] << " " << year[202] << " " << color[1] << " -> $" << price[202] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[202];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[202] << " " << model[202] << " " << year[202] << " " << color[2] << " -> $" << price[202] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[202];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[202] << " " << model[202] << " " << year[202] << " " << color[3] << " -> $" << price[202] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[202];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[202] << " " << model[202] << " " << year[202] << " " << color[4] << " -> $" << price[202] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto kawasaki;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto VU;
                }
            }
            else if (buyBike == 'N' || buyBike == 'n')
            {
                goto kawasaki;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto vU;
            }
        }
        else if (*bikeSelect == "4")
        {
            brand[203] = "Kawasaki";
            model[203] = "Z900";
            year[203] = 2023;
            price[203] = 9000;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "            <- Selected Car:" << brand[203] << " " << model[203] << " " << year[203] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Kawasaki/Z900.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this bike? (Y/N): ";
        vS:
            cin >> buyBike;
            if (buyBike == 'Y' || buyBike == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Kawasaki Bike List";
                cout << "\n\n Enter your choice: ";
            VS:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[203];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[203] << " " << model[203] << " " << year[203] << " " << color[0] << " -> $" << price[203] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[203];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[203] << " " << model[203] << " " << year[203] << " " << color[1] << " -> $" << price[203] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[203];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[203] << " " << model[203] << " " << year[203] << " " << color[2] << " -> $" << price[203] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[203];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[203] << " " << model[203] << " " << year[203] << " " << color[3] << " -> $" << price[203] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[203];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[203] << " " << model[203] << " " << year[203] << " " << color[4] << " -> $" << price[203] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto kawasaki;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto VS;
                }
            }
            else if (buyBike == 'N' || buyBike == 'n')
            {
                goto kawasaki;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto vS;
            }
        }
        else if (*bikeSelect == "5")
        {
            selectBike();
        }
        cout << "Do you want add more Kawasaki Vehicles? (Y/N): ";
    back:
        cin >> add;
        if (add == 'Y' || add == 'y')
        {
            vehicleFile.close();
            goto kawasaki;
        }
        else if (add == 'N' || add == 'n')
        {
            cout << "Your Total Amount: $" << totalAmount << endl;
            cout << "Press Enter to Proceed...";
            cin.ignore();
            cin.get();
            vehicleFile.close();
            selectBike();
        }
        else
        {
            cout << "\n\nInvalid Choice! Try Again: ";
            goto back;
        }
    }
    void hondaBikes()
    {
    honda:
        system("clear"); // -> For Mac
        cout << "==================================================================\n\n";
        cout << "                     <- Honda Bikes List ->                     \n\n";
        cout << "==================================================================\n\n\n";
        cout << "\t\t   Which model bike do you want?\n";
        cout << "\n 1. Honda Africa Twin (2023)";
        cout << "\n 2. Honda CBR 600 (2022)";
        cout << "\n 3. Back to Bikes List\n";
        cout << "Enter your choice: ";
        cin >> *bikeSelect;
        if (*bikeSelect == "1")
        {
            brand[300] = "Honda";
            model[300] = "Africa Twin";
            year[300] = 2023;
            price[300] = 14500;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "                   <- Selected Car:" << brand[300] << " " << model[300] << " " << year[300] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Honda/Africa Twin.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this bike? (Y/N): ";
        africa:
            cin >> buyBike;
            if (buyBike == 'Y' || buyBike == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Honda Bike List";
                cout << "\n\n Enter your choice: ";
            Africa:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[300];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[300] << " " << model[300] << " " << year[300] << " " << color[0] << " -> $" << price[300] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[300];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[300] << " " << model[300] << " " << year[300] << " " << color[1] << " -> $" << price[300] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[300];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[300] << " " << model[300] << " " << year[300] << " " << color[2] << " -> $" << price[300] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[300];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[300] << " " << model[300] << " " << year[300] << " " << color[3] << " -> $" << price[300] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[300];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[300] << " " << model[300] << " " << year[300] << " " << color[4] << " -> $" << price[300] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto honda;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto Africa;
                }
            }
            else if (buyBike == 'N' || buyBike == 'n')
            {
                goto honda;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto africa;
            }
        }
        else if (*bikeSelect == "2")
        {
            brand[301] = "Honda";
            model[301] = "CBR 600";
            year[301] = 2022;
            price[301] = 11800;
            system("clear"); // -> For Mac
            cout << "==================================================================\n\n";
            cout << "                   <- Selected Car:" << brand[301] << " " << model[301] << " " << year[301] << " ->\n\n";
            cout << "==================================================================\n\n\n";
            vehicleFile.open("Honda/Africa Twin.txt", ios::in);
            if (vehicleFile.is_open())
            {
                string line;
                while (!vehicleFile.eof())
                {
                    getline(vehicleFile, line);
                    cout << line << endl;
                }
            }
            vehicleFile.close();
            cout << "\n\nDo you want to buy this bike? (Y/N): ";
        cbr:
            cin >> buyBike;
            if (buyBike == 'Y' || buyBike == 'y')
            {
                cout << "\n\nWhich Color Do You Want to Buy? : ";
                cout << "\n 1. " << color[0];
                cout << "\n 2. " << color[1];
                cout << "\n 3. " << color[2];
                cout << "\n 4. " << color[3];
                cout << "\n 5. " << color[4];
                cout << "\n 6. Back to Honda Bike List";
                cout << "\n\n Enter your choice: ";
            CBR:
                cin >> buyColor;
                if (buyColor == "1")
                {
                    totalAmount += price[301];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[301] << " " << model[301] << " " << year[301] << " " << color[0] << " -> $" << price[301] << endl;
                    cout << "You have selected " << color[0] << " car" << endl;
                }
                else if (buyColor == "2")
                {
                    totalAmount += price[301];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[301] << " " << model[301] << " " << year[301] << " " << color[1] << " -> $" << price[301] << endl;
                    cout << "You have selected " << color[1] << " car" << endl;
                }
                else if (buyColor == "3")
                {
                    totalAmount += price[301];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[301] << " " << model[301] << " " << year[301] << " " << color[2] << " -> $" << price[301] << endl;
                    cout << "You have selected " << color[2] << " car" << endl;
                }
                else if (buyColor == "4")
                {
                    totalAmount += price[301];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[301] << " " << model[301] << " " << year[301] << " " << color[3] << " -> $" << price[301] << endl;
                    cout << "You have selected " << color[3] << " car" << endl;
                }
                else if (buyColor == "5")
                {
                    totalAmount += price[301];
                    vehicleFile.open("bill.txt", ios::app);
                    vehicleFile << brand[301] << " " << model[301] << " " << year[301] << " " << color[4] << " -> $" << price[301] << endl;
                    cout << "You have selected " << color[4] << " car" << endl;
                }
                else if (buyColor == "6")
                {
                    goto honda;
                }
                else
                {
                    cout << "\n\nInvalid Choice! Try Again: ";
                    goto CBR;
                }
            }
            else if (buyBike == 'N' || buyBike == 'n')
            {
                goto honda;
            }
            else
            {
                cout << "\n\nInvalid Choice! Try Again: \n";
                goto cbr;
            }
        }
        else if (*bikeSelect == "3")
        {
            selectBike();
        }
        cout << "Do you want add more Kawasaki Vehicles? (Y/N): ";
    back:
        cin >> add;
        if (add == 'Y' || add == 'y')
        {
            vehicleFile.close();
            goto honda;
        }
        else if (add == 'N' || add == 'n')
        {
            cout << "Your Total Amount: $" << totalAmount << endl;
            cout << "Press Enter to Proceed...";
            cin.ignore();
            cin.get();
            vehicleFile.close();
            selectBike();
        }
        else
        {
            cout << "\n\nInvalid Choice! Try Again: ";
            goto back;
        }
    }
    ~Bike()
    {
        delete bikeSelect;
        bikeSelect = NULL;
    }
};

#endif