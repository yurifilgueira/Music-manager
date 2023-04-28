#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <Artist.h>
#include <ostream>

using std::ostream;
using std::string;

class Music
{

private:
    Artist *artist;
    string name;

public:
    Music();
    Music(Artist *artist, string name);
    string getName();
    void setName(string name);
    Artist *getArtist();
    void setArtist(Artist *artist);
    friend ostream &operator<<(ostream &os, Music *music);
};

#endif