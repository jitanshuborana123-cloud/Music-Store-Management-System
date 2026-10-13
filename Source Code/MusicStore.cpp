#include "MusicStore.h"
#include "FileManager.h"
#include <iostream>

using namespace std;

// Add Album
void MusicStore::addAlbum(const Album& album) {
    for (const Album& existing : albums) {
        if (existing.getId() == album.getId()) {
            cout << "Error: Album ID already exists!\n";
            return;
        }
    }

    if (album.getId() <= 0 ||
        album.getPrice() <= 0 ||
        album.getStock() < 0) {
        cout << "Error: Album ID and price must be positive, "
             << "and stock cannot be negative!\n";
        return;
    }

    albums.push_back(album);
    cout << "Album added successfully!\n";
}

// Display Albums
void MusicStore::displayAlbums() const {
    if (albums.empty()) {
        cout << "No albums available.\n";
        return;
    }

    for (const Album& album : albums) {
        album.display();
    }
}

// Search Album
void MusicStore::searchAlbum(int albumId) const {
    for (const Album& album : albums) {
        if (album.getId() == albumId) {
            album.display();
            return;
        }
    }

    cout << "Album not found!\n";
}

// Add Artist
void MusicStore::addArtist(const Artist& artist) {
    for (const Artist& existing : artists) {
        if (existing.getId() == artist.getId()) {
            cout << "Error: Artist ID already exists!\n";
            return;
        }
    }

    if (artist.getId() <= 0) {
        cout << "Error: Artist ID must be positive!\n";
        return;
    }

    artists.push_back(artist);
    cout << "Artist added successfully!\n";
}

// Display Artists
void MusicStore::displayArtists() const {
    if (artists.empty()) {
        cout << "No artists available.\n";
        return;
    }

    for (const Artist& artist : artists) {
        artist.display();
    }
}

// Add Customer
void MusicStore::addCustomer(const Customer& customer) {
    for (const Customer& existing : customers) {
        if (existing.getId() == customer.getId()) {
            cout << "Error: Customer ID already exists!\n";
            return;
        }
    }

    if (customer.getId() <= 0) {
        cout << "Error: Customer ID must be positive!\n";
        return;
    }

    customers.push_back(customer);
    cout << "Customer added successfully!\n";
}

// Display Customers
void MusicStore::displayCustomers() const {
    if (customers.empty()) {
        cout << "No customers available.\n";
        return;
    }

    for (const Customer& customer : customers) {
        customer.display();
    }
}

// Process Sale
void MusicStore::processSale(
    int saleId, int customerId, int albumId, int quantity) {

    if (saleId <= 0) {
        cout << "Error: Sale ID must be positive!\n";
        return;
    }

    for (const Sale& sale : sales) {
        if (sale.getId() == saleId) {
            cout << "Error: Sale ID already exists!\n";
            return;
        }
    }

    if (quantity <= 0) {
        cout << "Error: Quantity must be positive!\n";
        return;
    }

    bool customerFound = false;

    for (const Customer& customer : customers) {
        if (customer.getId() == customerId) {
            customerFound = true;
            break;
        }
    }

    if (!customerFound) {
        cout << "Error: Customer not found!\n";
        return;
    }

    for (Album& album : albums) {
        if (album.getId() == albumId) {
            if (quantity > album.getStock()) {
                cout << "Error: Insufficient stock!\n";
                return;
            }

            double totalAmount = album.getPrice() * quantity;

            if (!album.sellStock(quantity)) {
                cout << "Error: Sale could not be completed!\n";
                return;
            }

            sales.emplace_back(
                saleId, customerId, albumId,
                quantity, totalAmount
            );

            cout << "\nSale completed successfully!\n";
            cout << "Quantity: " << quantity << "\n";
            cout << "Total Amount: " << totalAmount << "\n";
            cout << "Remaining Stock: " << album.getStock() << "\n";
            return;
        }
    }

    cout << "Error: Album not found!\n";
}

// Save and load albums
void MusicStore::saveData() const {
    FileManager::saveAlbums(albums);
}

void MusicStore::loadData() {
    albums = FileManager::loadAlbums();
    cout << albums.size() << " album(s) loaded.\n";
}

// Save and load artists
void MusicStore::saveArtists() const {
    FileManager::saveArtists(artists);
}

void MusicStore::loadArtists() {
    artists = FileManager::loadArtists();
    cout << artists.size() << " artist(s) loaded.\n";
}

// Save and load customers
void MusicStore::saveCustomers() const {
    FileManager::saveCustomers(customers);
}

void MusicStore::loadCustomers() {
    customers = FileManager::loadCustomers();
    cout << customers.size() << " customer(s) loaded.\n";
}

// Save and load sales
void MusicStore::saveSales() const {
    FileManager::saveSales(sales);
}

void MusicStore::loadSales() {
    sales = FileManager::loadSales();
    cout << sales.size() << " sale(s) loaded.\n";
}