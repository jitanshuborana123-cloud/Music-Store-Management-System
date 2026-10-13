#include "Album.h"
#include <iostream>

using namespace std;

Album::Album(int id, string title, int artistId,
             string genre, double price, int stock)
    : Record(id),
      title(title),
      artistId(artistId),
      genre(genre),
      price(price),
      stock(stock) {
}

void Album::display() const {
    cout << "\n--- Album Details ---\n";
    cout << "Album ID: " << id << "\n";
    cout << "Title: " << title << "\n";
    cout << "Artist ID: " << artistId << "\n";
    cout << "Genre: " << genre << "\n";
    cout << "Price: " << price << "\n";
    cout << "Stock: " << stock << "\n";
}

void Album::updateStock(int quantity) {
    stock += quantity;
}

double Album::getPrice() const {
    return price;
}

int Album::getStock() const {
    return stock;
}

bool Album::sellStock(int quantity) {
    if (quantity <= 0 || quantity > stock) {
        return false;
    }

    stock -= quantity;
    return true;
}