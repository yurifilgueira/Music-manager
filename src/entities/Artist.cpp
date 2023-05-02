#include <Artist.h>

#include <iostream>

using std::cout;

using std::endl;

Artist::Artist()
{
}

Artist::~Artist()
{
}

Artist::Artist(string name)
{
    this->name = name;
}

string Artist::getName()
{
    return this->name;
}

void Artist::setName(string name)
{
    this->name = name;
}
ostream &operator<<(ostream &os, Artist *artist)
{
    os << artist->getName() << endl;

    return os;
}