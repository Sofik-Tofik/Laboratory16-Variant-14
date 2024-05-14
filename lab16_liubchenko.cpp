#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

class Phone {
private:
    string lastName;
    string firstName;
    string middleName;
    string address;
    string number;
    int localCallTime;
    int internationalCallTime;

public:
    void setLastName(string lName) { lastName = lName; }
    void setFirstName(string fName) { firstName = fName; }
    void setMiddleName(string mName) { middleName = mName; }
    void setAddress(string addr) { address = addr; }
    void setNumber(string num) { number = num; }
    void setLocalCallTime(int localTime) { localCallTime = localTime; }
    void setInternationalCallTime(int internationalTime) { internationalCallTime = internationalTime; }

    string getLastName() const { return lastName; }
    string getFirstName() const { return firstName; }
    string getMiddleName() const { return middleName; }
    string getAddress() const { return address; }
    string getNumber() const { return number; }
    int getLocalCallTime() const { return localCallTime; }
    int getInternationalCallTime() const { return internationalCallTime; }

    void show() const {
        cout << "Name: " << lastName << " " << firstName << " " << middleName << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << number << endl;
        cout << "Local Call Time: " << localCallTime << " minutes" << endl;
        cout << "International Call Time: " << internationalCallTime << " minutes" << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    string lastName, firstName, middleName, address, number;
    int localCallTime, internationalCallTime;

    cout << "Enter the number of subscribers: ";
    cin >> N;

    vector<Phone> phoneBook(N);

    for (int i = 0; i < N; ++i) {
        cout << "Enter last name: ";
        cin >> lastName;
        phoneBook[i].setLastName(lastName);

        cout << "Enter first name: ";
        cin >> firstName;
        phoneBook[i].setFirstName(firstName);

        cout << "Enter middle name: ";
        cin >> middleName;
        phoneBook[i].setMiddleName(middleName);

        cout << "Enter address: ";
        cin >> address;
        phoneBook[i].setAddress(address);

        cout << "Enter phone number: ";
        cin >> number;
        phoneBook[i].setNumber(number);

        cout << "Enter local call time (in minutes): ";
        cin >> localCallTime;
        phoneBook[i].setLocalCallTime(localCallTime);

        cout << "Enter international call time (in minutes): ";
        cin >> internationalCallTime;
        phoneBook[i].setInternationalCallTime(internationalCallTime);
    }

    cout << "\nSubscribers whose local call time exceeds the limit:" << endl;
    for (const auto& subscriber : phoneBook) {
        if (subscriber.getLocalCallTime() > 60) {
            subscriber.show();
            cout << endl;
        }
    }

    cout << "\nSubscribers who used international calls:" << endl;
    for (const auto& subscriber : phoneBook) {
        if (subscriber.getInternationalCallTime() > 0) {
            subscriber.show();
            cout << endl;
        }
    }

    sort(phoneBook.begin(), phoneBook.end(), [](const Phone& a, const Phone& b) {
        return a.getLastName() < b.getLastName();
        });

    cout << "\nSubscribers sorted alphabetically:" << endl;
    for (const auto& subscriber : phoneBook) {
        subscriber.show();
        cout << endl;
    }

    return 0;
}
