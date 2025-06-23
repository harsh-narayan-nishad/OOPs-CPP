#include <iostream>
#include <fstream>
#include <unistd.h> // for sleep()
using namespace std;

class University {
private:
    string RollNo, Name, Subject, Address;
public:
    University() : RollNo(""), Name(""), Subject(""), Address("") {}

    void setRollNo(string rollNo) {
        RollNo = rollNo;
    }

    void setName(string name) {
        Name = name;
    }

    void setSubject(string subject) {
        Subject = subject;
    }

    void setAddress(string address) {
        Address = address;
    }

    string getRollNo() {
        return RollNo;
    }

    string getName() {
        return Name;
    }

    string getSubject() {
        return Subject;
    }

    string getAddress() {
        return Address;
    }
};

void add(University student) {
    string rollNo, name, subject, address;

    cout << "\tEnter RollNo Of Student: ";
    cin >> rollNo;
    student.setRollNo(rollNo);

    cout << "\tEnter Name Of Student: ";
    cin >> name;
    student.setName(name);

    cout << "\tEnter Subject Of Student: ";
    cin >> subject;
    student.setSubject(subject);

    cout << "\tEnter Address Of Student: ";
    cin >> address;
    student.setAddress(address);

    ofstream out("university.txt", ios::app);
    if (!out) {
        cout << "\tError: File Can't Open!" << endl;
    } else {
        out << "\t" << student.getRollNo() << " : " << student.getName() << " : " << student.getSubject()
            << " : " << student.getAddress() << endl
            << endl;
        cout << "\tStudent Added Successfully!" << endl;
    }
    out.close();
}

void search() {
    string rollNo;
    cout << "\tEnter RollNo Of Student: ";
    cin >> rollNo;

    ifstream in("university.txt");
    if (!in) {
        cout << "\tError: File Can't Open!" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(in, line)) {
        int data = line.find(rollNo);
        if (data != string::npos) {
            cout << "\t" << line << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "\tStudent Not Found!" << endl;
    }

    in.close();
}

void update(University student) {
    string rollNo;
    cout << "\tEnter RollNo Of Student: ";
    cin >> rollNo;

    ifstream infile("university.txt");
    ofstream outfile("university_temp.txt");
    if (!infile || !outfile) {
        cout << "\tError: File Can't Open!" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(infile, line)) {
        int pos = line.find(rollNo);
        if (pos != string::npos) {
            string address;
            cout << "\tEnter New Address: ";
            cin >> address;
            student.setAddress(address);

            int newPos = line.find_last_of(':');
            if (newPos != string::npos) {
                line.replace(newPos + 2, string::npos, student.getAddress());
            }

            found = true;
        }
        outfile << line << endl;
    }

    infile.close();
    outfile.close();

    remove("university.txt");
    rename("university_temp.txt", "university.txt");

    if (found) {
        cout << "\tData Updated!" << endl;
    } else {
        cout << "\tStudent Not Found!" << endl;
    }
}

int main() {
    University student;

    bool exitFlag = false;
    while (!exitFlag) {
        cout << "\tWelcome To University Management System" << endl;
        cout << "\t***************************************" << endl;
        cout << "\t1. Add Student." << endl;
        cout << "\t2. Search Student." << endl;
        cout << "\t3. Update Data Of Student." << endl;
        cout << "\t4. Exit." << endl;
        cout << "\tEnter Your Choice: ";
        int val;
        cin >> val;

        if (val == 1) {
            add(student);
            sleep(3);
        } else if (val == 2) {
            search();
            sleep(3);
        } else if (val == 3) {
            update(student);
            sleep(3);
        } else if (val == 4) {
            exitFlag = true;
            cout << "\tGood Luck!" << endl;
            sleep(2);
        }
    }

    return 0;
}
