#ifndef Artist_H
#define Artist_H

#include <iostream>
#include <ostream>

using std::ostream;
using std::string;

class Artist
{
private:
    string name;

public:
    Artist();
    Artist(string name);
    string getName();
    void setName(string name);
    friend ostream &operator<<(ostream &os, Artist *artist);
};

#endif