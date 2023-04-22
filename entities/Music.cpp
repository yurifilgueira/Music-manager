#include <Music.h>

Music::Music()
{
}

Music::Music(Artist artist, string name)
{
    this->artist = artist;
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

Artist Music::getArtist()
{
    return this->artist;
}

void Music::setArtist(Artist artist)
{
    this->artist = artist;
}