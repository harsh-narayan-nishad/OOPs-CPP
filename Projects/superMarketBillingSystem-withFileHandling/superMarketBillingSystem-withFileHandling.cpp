#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
using namespace std;

// Cross-platform screen clear function
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Cross-platform sleep function
void sleepFor(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

class Bill {
private:
    string Item;
    int Rate, Quantity;

public:
    Bill(): Item(""), Rate(0), Quantity(0) { }

    void setItem(string item) {
        Item = item;
    }

    void setRate(int rate) {
        Rate = rate;
    }

    void setQuant(int quant) {
        Quantity = quant;
    }

    string getItem() {
        return Item;
    }

    int getRate() {
        return Rate;
    }

    int getQuant() {
        return Quantity;
    }
};

void addItem(Bill b) {
    bool close = false;
    while (!close) {
        int choice;
        cout << "\t1. Add." << endl;
        cout << "\t2. Close." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1) {
            clearScreen();
            string item;
            int rate, quant;

            cout << "\tEnter Item Name: ";
            cin >> item;
            b.setItem(item);

            cout << "\tEnter Rate Of Item: ";
            cin >> rate;
            b.setRate(rate);

            cout << "\tEnter Quantity Of Item: ";
            cin >> quant;
            b.setQuant(quant);

            ofstream out("Bill.txt", ios::app);
            if (!out) {
                cout << "\tError: File Can't Open!" << endl;
            } else {
                out << "\t" << b.getItem() << " : " << b.getRate() << " : " << b.getQuant() << endl << endl;
                cout << "\tItem Added Successfully" << endl;
            }
            out.close();
            sleepFor(3);
        } else if (choice == 2) {
            clearScreen();
            close = true;
            cout << "\tBack To Main Menu!" << endl;
            sleepFor(3);
        }
    }
}

void printBill() {
    clearScreen();
    int count = 0;
    bool close = false;

    while (!close) {
        clearScreen();
        int choice;
        cout << "\t1. Add Bill." << endl;
        cout << "\t2. Close Session." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1) {
            string item;
            int quant;
            cout << "\tEnter Item: ";
            cin >> item;
            cout << "\tEnter Quantity: ";
            cin >> quant;

            ifstream in("Bill.txt");
            ofstream out("Bill_Temp.txt");

            string line;
            bool found = false;

            while (getline(in, line)) {
                stringstream ss(line);
                string itemName;
                int itemRate, itemQuant;
                char delimiter;

                ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;

                if (item == itemName) {
                    found = true;
                    if (quant <= itemQuant) {
                        int amount = itemRate * quant;
                        cout << "\t Item | Rate | Quantity | Amount" << endl;
                        cout << "\t" << itemName << "\t " << itemRate << "\t " << quant << "\t " << amount << endl;
                        int newQuant = itemQuant - quant;
                        count += amount;

                        out << "\t" << itemName << " : " << itemRate << " : " << newQuant << endl;
                    } else {
                        cout << "\tSorry, " << item << " not enough in stock!" << endl;
                        out << line << endl;
                    }
                } else {
                    out << line << endl;
                }
            }

            if (!found) {
                cout << "\tItem Not Available!" << endl;
            }

            in.close();
            out.close();
            remove("Bill.txt");
            rename("Bill_Temp.txt", "Bill.txt");

            sleepFor(3);
        } else if (choice == 2) {
            close = true;
            cout << "\tCounting Total Bill" << endl;
            sleepFor(3);
        }
    }

    clearScreen();
    cout << endl << endl;
    cout << "\t Total Bill ----------------- : " << count << endl << endl;
    cout << "\tThanks For Shopping!" << endl;
    sleepFor(5);
}

int main() {
    Bill b;
    bool exit = false;

    while (!exit) {
        clearScreen();
        int val;

        cout << "\tWelcome To Super Market Billing System" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t\t1. Add Item." << endl;
        cout << "\t\t2. Print Bill." << endl;
        cout << "\t\t3. Exit." << endl;
        cout << "\t\tEnter Choice: ";
        cin >> val;

        if (val == 1) {
            clearScreen();
            addItem(b);
        } else if (val == 2) {
            printBill();
        } else if (val == 3) {
            clearScreen();
            exit = true;
            cout << "\tGood Luck!" << endl;
            sleepFor(3);
        }
    }

    return 0;
}
