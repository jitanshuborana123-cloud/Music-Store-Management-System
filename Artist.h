#ifndef ARTIST_H
#define ARTIST_H

#include <string>
#include "Record.h"

class FileManager;

class Artist : public Record {
private:
    std::string name;
    std::string genre;

    friend class FileManager;

public:
    Artist(int id, std::string name, std::string genre);

    void display() const override;
};

#endif