#include "Artist.h"
#include <iostream>

using namespace std;

Artist::Artist(int id, string name, string genre)
    : Record(id), name(name), genre(genre) {
}

void Artist::display() const {
    cout << "\n--- Artist Details ---\n";
    cout << "Artist ID: " << id << "\n";
    cout << "Name: " << name << "\n";
    cout << "Genre: " << genre << "\n";
}