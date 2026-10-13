#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Save albums
void FileManager::saveAlbums(const vector<Album>& albums) {
    ofstream file("albums.txt");

    for (const Album& a : albums) {
        file << a.id << "|"
             << a.title << "|"
             << a.artistId << "|"
             << a.genre << "|"
             << a.price << "|"
             << a.stock << "\n";
    }
}

// Load albums
vector<Album> FileManager::loadAlbums() {
    vector<Album> albums;
    ifstream file("albums.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string id, title, artistId, genre, price, stock;

        getline(ss, id, '|');
        getline(ss, title, '|');
        getline(ss, artistId, '|');
        getline(ss, genre, '|');
        getline(ss, price, '|');
        getline(ss, stock, '|');

        if (!id.empty() && !title.empty() && !artistId.empty()
            && !genre.empty() && !price.empty() && !stock.empty()) {
            albums.emplace_back(
                stoi(id), title, stoi(artistId), genre,
                stod(price), stoi(stock)
            );
        }
    }

    return albums;
}

// Save artists
void FileManager::saveArtists(const vector<Artist>& artists) {
    ofstream file("artists.txt");

    for (const Artist& a : artists) {
        file << a.id << "|"
             << a.name << "|"
             << a.genre << "\n";
    }
}

// Load artists
vector<Artist> FileManager::loadArtists() {
    vector<Artist> artists;
    ifstream file("artists.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, genre;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, genre, '|');

        if (!id.empty() && !name.empty() && !genre.empty()) {
            artists.emplace_back(stoi(id), name, genre);
        }
    }

    return artists;
}

// Save customers
void FileManager::saveCustomers(const vector<Customer>& customers) {
    ofstream file("customers.txt");

    for (const Customer& c : customers) {
        file << c.id << "|"
             << c.name << "|"
             << c.phone << "\n";
    }
}

// Load customers
vector<Customer> FileManager::loadCustomers() {
    vector<Customer> customers;
    ifstream file("customers.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, phone;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, phone, '|');

        if (!id.empty() && !name.empty() && !phone.empty()) {
            customers.emplace_back(stoi(id), name, phone);
        }
    }

    return customers;
}

// Save sales
void FileManager::saveSales(const vector<Sale>& sales) {
    ofstream file("sales.txt");

    for (const Sale& s : sales) {
        file << s.id << "|"
             << s.customerId << "|"
             << s.albumId << "|"
             << s.quantity << "|"
             << s.totalAmount << "\n";
    }
}

// Load sales
vector<Sale> FileManager::loadSales() {
    vector<Sale> sales;
    ifstream file("sales.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string id, customerId, albumId, quantity, totalAmount;

        getline(ss, id, '|');
        getline(ss, customerId, '|');
        getline(ss, albumId, '|');
        getline(ss, quantity, '|');
        getline(ss, totalAmount, '|');

        if (!id.empty() && !customerId.empty() && !albumId.empty()
            && !quantity.empty() && !totalAmount.empty()) {
            sales.emplace_back(
                stoi(id), stoi(customerId), stoi(albumId),
                stoi(quantity), stod(totalAmount)
            );
        }
    }

    return sales;
}