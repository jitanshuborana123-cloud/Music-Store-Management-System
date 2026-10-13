#include "Sale.h"
#include <iostream>

using namespace std;

Sale::Sale(int id, int customerId, int albumId,
           int quantity, double totalAmount)
    : Record(id),
      customerId(customerId),
      albumId(albumId),
      quantity(quantity),
      totalAmount(totalAmount) {
}

void Sale::display() const {
    cout << "\n--- Sale Details ---\n";
    cout << "Sale ID: " << id << "\n";
    cout << "Customer ID: " << customerId << "\n";
    cout << "Album ID: " << albumId << "\n";
    cout << "Quantity: " << quantity << "\n";
    cout << "Total Amount: " << totalAmount << "\n";
}