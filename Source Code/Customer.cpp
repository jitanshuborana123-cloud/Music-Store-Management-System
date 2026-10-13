#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer(int id, string name, string phone)
    : Record(id), name(name), phone(phone) {
}

void Customer::display() const {
    cout << "\n--- Customer Details ---\n";
    cout << "Customer ID: " << id << "\n";
    cout << "Name: " << name << "\n";
    cout << "Phone: " << phone << "\n";
}