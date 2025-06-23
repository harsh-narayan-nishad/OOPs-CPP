#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

// Cross-platform screen clear
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Cross-platform sleep
void sleepFor(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

class Hostel {
private:
    string Name;
    int Rent, Bed;

public:
    Hostel(string name, int rent, int bed) {
        Name = name;
        Rent = rent;
        Bed = bed;
    }

    string getName() {
        return Name;
    }

    int getRent() {
        return Rent;
    }

    int getBed() {
        return Bed;
    }

    void reserve() {
        ifstream in("Hostel.txt");
        ofstream out("Hostel_Temp.txt");

        string line;
        while (getline(in, line)) {
            int pos = line.find("3star");
            if (pos != string::npos) {
                int bed = Bed - 1;
                Bed = bed;

                stringstream ss;
                ss << bed;
                string strBed = ss.str();

                int bedPos = line.find_last_of(':');
                line.replace(bedPos + 1, string::npos, " " + strBed);
            }
            out << line << endl;
        }

        in.close();
        out.close();
        remove("Hostel.txt");
        rename("Hostel_Temp.txt", "Hostel.txt");

        cout << "\tBed Reserved Successfully!" << endl;
    }
};

class Student {
private:
    string Name, RollNo, Address;

public:
    Student() : Name(""), RollNo(""), Address("") {}

    void setName(string name) {
        Name = name;
    }

    void setRollNo(string rollNo) {
        RollNo = rollNo;
    }

    void setAddress(string address) {
        Address = address;
    }

    string getName() {
        return Name;
    }

    string getRollNo() {
        return RollNo;
    }

    string getAddress() {
        return Address;
    }
};

int main() {
    Hostel h("3star", 5000, 2);

    // Save initial hostel data
    ofstream out("Hostel.txt");
    out << "\t" << h.getName() << " : " << h.getRent() << " : " << h.getBed() << endl << endl;
    out.close();
    cout << "Hostel Data Saved" << endl;

    Student s;
    bool exit = false;

    while (!exit) {
        clearScreen();
        int val;

        cout << "\tWelcome To Hostel Accommodation System" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t1. Reserve A Bed." << endl;
        cout << "\t2. Exit." << endl;
        cout << "\tEnter Choice: ";
        cin >> val;

        if (val == 1) {
            clearScreen();
            string name, rollNo, address;

            cout << "\tEnter Name of Student: ";
            cin >> name;
            s.setName(name);

            cout << "\tEnter RollNo of Student: ";
            cin >> rollNo;
            s.setRollNo(rollNo);

            cout << "\tEnter Address of Student: ";
            cin >> address;
            s.setAddress(address);

            if (h.getBed() > 0) {
                h.reserve();
            } else {
                cout << "\tSorry, Bed Not Available!" << endl;
            }

            ofstream outFile("Student.txt", ios::app);
            outFile << "\t" << s.getName() << " : " << s.getRollNo() << " : " << s.getAddress() << endl << endl;
            outFile.close();

            sleepFor(5000);  // 5 seconds
        } else if (val == 2) {
            clearScreen();
            exit = true;
            cout << "Good Luck!" << endl;
            sleepFor(3000);  // 3 seconds
        }
    }

    return 0;
}
