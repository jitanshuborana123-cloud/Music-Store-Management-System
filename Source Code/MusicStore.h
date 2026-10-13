#ifndef MUSICSTORE_H
#define MUSICSTORE_H

#include <vector>
#include "Album.h"
#include "Artist.h"
#include "Customer.h"
#include "Sale.h"

class MusicStore {
private:
    std::vector<Album> albums;
    std::vector<Artist> artists;
    std::vector<Customer> customers;
    std::vector<Sale> sales;

public:
    void addAlbum(const Album& album);
    void displayAlbums() const;
    void searchAlbum(int albumId) const;

    void addArtist(const Artist& artist);
    void displayArtists() const;

    void addCustomer(const Customer& customer);
    void displayCustomers() const;

    void processSale(int saleId, int customerId,
                     int albumId, int quantity);

    void saveData() const;
    void loadData();

    void saveArtists() const;
    void loadArtists();

    void saveCustomers() const;
    void loadCustomers();

    void saveSales() const;
    void loadSales();
};

#endif