#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include "Record.h"

class FileManager;

class Album : public Record {
private:
    std::string title;
    int artistId;
    std::string genre;
    double price;
    int stock;

    friend class FileManager;

public:
    Album(int id, std::string title, int artistId,
          std::string genre, double price, int stock);

    void display() const override;
    void updateStock(int quantity);
    double getPrice() const;
    int getStock() const;
    bool sellStock(int quantity);
};

#endif