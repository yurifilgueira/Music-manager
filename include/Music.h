#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <Artist.h>

using std::string;

class Music
{

private:
    Artist artist;
    string name;

public:
    Music();
    Music(Artist artist, string name);
    string getName();
    void setName(string name);
    Artist getArtist();
    void setArtist(Artist artist);
};

#endif