#include <Artist.h>

Artist::Artist()
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