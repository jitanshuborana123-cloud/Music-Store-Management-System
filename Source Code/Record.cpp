#include "Record.h"

// Default constructor
Record::Record() {
    id = 0;
}

// Parameterized constructor
Record::Record(int recordId) {
    id = recordId;
}

// Virtual destructor
Record::~Record() {
}

// Function to return the ID
int Record::getId() const {
    return id;
}