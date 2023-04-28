#include <Music.h>
#include <Artist.h>
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

Music::Music()
{
    this->artist = nullptr;
}

Music::Music(Artist *artist, string name)
{
    this->artist = new Artist(*artist);
    this->name = name;
}

string Music::getName()
{
    return this->name;
}

void Music::setName(string name)
{
    this->name = name;
}

Artist *Music::getArtist()
{
    return this->artist;
}

void Music::setArtist(Artist *artist)
{
    this->artist = artist;
}
ostream &operator<<(ostream &os, Music *music)
{
    os << "Music: " << music->getName() << endl;
    os << "Artist: " << music->getArtist() << endl;

    return os;
}