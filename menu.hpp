#ifndef def_menu
#include "vehicle.hpp"
class Menu : public Car, Bike
{
    string *menuSelect;
    fstream file;

public:
    Menu()
    {
        menuSelect = new string;
    }
    void exitSystem()
    {
        if (totalAmount > 0)
        {
            char withoutBuy;
            cout << "Do you want to exit without buying? (Y/N): ";
        wB:
            cin >> withoutBuy;
            if (withoutBuy == 'Y' || withoutBuy == 'y')
            {
                cout << "\t==================================================\n\n";
                cout << "\t\t\tThank you for coming\n\n";
                cout << "\t==================================================\n\n";
                // Sleep(2000); // For Windows
                sleep(2); // -> For Mac
                exit(0);
            }
            else if (withoutBuy == 'N' || withoutBuy == 'n')
            {
                showBill();
            }
            else
            {
                cout << "Invalid input! Please try again: ";
                goto wB;
            }
        }
        else
        {
            cout << "\t==================================================\n\n";
            cout << "\t\t\tThank you for coming\n\n";
            cout << "\t==================================================\n\n";
            // Sleep(2000); // For Windows
            sleep(2); // -> For Mac
            exit(0);
        }
    }
    void showBill()
    {
        if (totalAmount > 0)
        {
            string line;
            // system("cls"); // -> For Windows
            system("clear"); // -> For Mac
            cout << "\t==================================================\n\n";
            cout << "\t\t\tYour Shopping Bill\n\n";
            cout << "\t==================================================\n\n";
            cout << "Item\t\t Color\t\t Price\n";
            file.open("bill.txt", ios::in);
            while (!file.eof())
            {
                getline(file, line);
                cout << line << endl;
            }
            file.close();
            cout << "\n\t\tTotal Amount: $" << totalAmount << endl;
            string card;
            int pay;
            char buy;
            cout << "Do you want to buy the items? (Y/N): ";
            cin >> buy;
            if (buy == 'Y' || buy == 'y')
            {
                // system("cls"); // -> For Windows
                system("clear"); // -> For Mac
                cout << "\t==================================================\n\n";
                cout << "\t\tWhich payment method do you want?\n\n";
                cout << "\t==================================================\n\n";
                cout << "\t1. Credit Card\t\t\t2. Cash\n";
                cout << "Enter your choice: ";
            p:
                cin >> pay;
                if (pay == 1)
                {
                    cout << "Enter your Credit Card number: ";
                    cin >> card;
                    cout << "Your payment has been accepted.\n";
                }
                else if (pay == 2)
                {
                    cout << "Your payment has been accepted.\n";
                }
                else
                {
                    cout << "Invalid input! Please try again: ";
                    goto p;
                }
            }
            else if (buy == 'N' || buy == 'n')
            {
                exitSystem();
            }
        }
        else
        {
            // system("cls"); -> For Windows
            system("clear"); // -> For Mac
            cout << "\t==================================================\n\n";
            cout << "\t\t\tNo items selected\n\n";
            cout << "\t==================================================\n\n";
            // Sleep(2000); // For Windows
            sleep(2); // -> For Mac
            showMenu();
        }
    }
    void showMenu()
    {
    sM:
        system("clear"); // -> For Mac
        cout << "==================================================================\n\n";
        cout << "               <- Welcome to Vehicle Selling Shop ->              \n\n";
        cout << "==================================================================\n\n\n";
        cout << "                     Which vehicle do you want\n\n";
        cout << " 1. Car\n";
        cout << " 2. Bike\n";
        cout << " 3. Proceed to Bill\n";
        cout << " 4. Quit the System\n";
        cout << "\n Enter your choice: ";
    s:
        cin >> *menuSelect;
        if (*menuSelect == "1")
        {
            Car car;
            car.selectCar();
        }
        else if (*menuSelect == "2")
        {
            Bike bike;
            bike.selectBike();
        }
        else if (*menuSelect == "3")
        {
            showBill();
        }
        else if (*menuSelect == "4")
        {
            exitSystem();
        }
        else
        {
            cout << "\n\n\t\tInvalid Choice! Try Again: ";
            goto s;
        }
    }
    ~Menu()
    {
        delete menuSelect;
        menuSelect = NULL;
    }
};
void backtoMainMenu()
{
    Menu m;
    m.showMenu();
}
#endif