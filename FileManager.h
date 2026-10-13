#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include "Album.h"
#include "Artist.h"
#include "Customer.h"
#include "Sale.h"

class FileManager {
public:
    static void saveAlbums(const std::vector<Album>& albums);
    static std::vector<Album> loadAlbums();

    static void saveArtists(const std::vector<Artist>& artists);
    static std::vector<Artist> loadArtists();

    static void saveCustomers(const std::vector<Customer>& customers);
    static std::vector<Customer> loadCustomers();

    static void saveSales(const std::vector<Sale>& sales);
    static std::vector<Sale> loadSales();
};

#endif