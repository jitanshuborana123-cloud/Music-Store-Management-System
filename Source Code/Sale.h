#ifndef SALE_H
#define SALE_H

#include "Record.h"

class FileManager;

class Sale : public Record {
private:
    int customerId;
    int albumId;
    int quantity;
    double totalAmount;

    friend class FileManager;

public:
    Sale(int id, int customerId, int albumId,
         int quantity, double totalAmount);

    void display() const override;
};

#endif