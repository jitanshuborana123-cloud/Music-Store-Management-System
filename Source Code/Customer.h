#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Record.h"

class FileManager;

class Customer : public Record {
private:
    std::string name;
    std::string phone;

    friend class FileManager;

public:
    Customer(int id, std::string name, std::string phone);

    void display() const override;
};

#endif