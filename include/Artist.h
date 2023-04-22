#ifndef Artist_H
#define Artist_H

#include <iostream>

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
};

#endif