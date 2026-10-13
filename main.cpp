#include <iostream>
#include <string>
#include <limits>
#include "MusicStore.h"
using namespace std;

int main() {
    MusicStore store;

    // Load previously saved data
    store.loadData();
    store.loadArtists();
    store.loadCustomers();
    store.loadSales();

    int choice=0;

    do {
        cout << "\n===== MUSIC STORE MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Album\n";
        cout << "2. Display All Albums\n";
        cout << "3. Search Album\n";
        cout << "4. Add Artist\n";
        cout << "5. Display Artists\n";
        cout << "6. Add Customer\n";
        cout << "7. Display Customers\n";
        cout << "8. Process Sale\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                int id, artistId, stock;
                string title, genre;
                double price;

                cout << "Enter Album ID: ";
                if (!(cin >> id)) {
                    cout << "Invalid input! Album ID must be a number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cout << "Enter Album Title: ";
                getline(cin >> ws, title);

                cout << "Enter Artist ID: ";
                if (!(cin >> artistId)) {
                    cout << "Invalid input! Artist ID must be a number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cout << "Enter Genre: ";
                getline(cin >> ws, genre);

                cout << "Enter Price: ";
                if (!(cin >> price)) {
                    cout << "Invalid input! Price must be a number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cout << "Enter Stock: ";
                if (!(cin >> stock)) {
                    cout << "Invalid input! Stock must be a number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                Album album(id, title, artistId, genre, price, stock);
                store.addAlbum(album);
                break;
            }

            case 2:
                store.displayAlbums();
                break;

            case 3: {
                int id;

                cout << "Enter Album ID to search: ";
                if (!(cin >> id)) {
                    cout << "Invalid input! Album ID must be a number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                store.searchAlbum(id);
                break;
            }

            case 4: {
                int id;
                string name, genre;

                cout << "Enter Artist ID: ";
                if (!(cin >> id)) {
                    cout << "Invalid input! Artist ID must be a number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cout << "Enter Artist Name: ";
                getline(cin >> ws, name);

                cout << "Enter Artist Genre: ";
                getline(cin >> ws, genre);

                Artist artist(id, name, genre);
                store.addArtist(artist);
                break;
            }

            case 5:
                store.displayArtists();
                break;

            case 6: {
                int id;
                string name, phone;

                cout << "Enter Customer ID: ";
                if (!(cin >> id)) {
                    cout << "Invalid input! Customer ID must be a number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cout << "Enter Customer Name: ";
                getline(cin >> ws, name);

                cout << "Enter Customer Phone: ";
                getline(cin >> ws, phone);

                Customer customer(id, name, phone);
                store.addCustomer(customer);
                break;
            }

            case 7:
                store.displayCustomers();
                break;

            case 8: {
                int saleId, customerId, albumId, quantity;

                cout << "Enter Sale ID: ";
                if (!(cin >> saleId)) {
                    cout << "Invalid input! Sale ID must be a number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cout << "Enter Customer ID: ";
                if (!(cin >> customerId)) {
                    cout << "Invalid input! Customer ID must be a number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cout << "Enter Album ID: ";
                if (!(cin >> albumId)) {
                    cout << "Invalid input! Album ID must be a number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cout << "Enter Quantity: ";
                if (!(cin >> quantity)) {
                    cout << "Invalid input! Quantity must be a number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                store.processSale(saleId, customerId, albumId, quantity);
                break;
            }

            case 9:
                store.saveData();
                store.saveArtists();
                store.saveCustomers();
                store.saveSales();

                cout << "Data saved successfully.\n";
                cout << "Thank you for using Music Store!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}