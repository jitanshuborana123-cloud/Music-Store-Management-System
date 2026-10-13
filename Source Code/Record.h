#ifndef RECORD_H
#define RECORD_H

class Record {
protected:
    int id;

public:
    Record();
    Record(int recordId);
    virtual ~Record();

    int getId() const;

    virtual void display() const = 0;
};

#endif