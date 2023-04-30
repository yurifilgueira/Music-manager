#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <List.h>
#include <Music.h>

class Playlist
{

private:
    string *name;
    List<Music *> *musics = new List<Music *>();

public:
    Playlist();
    string getName();
    void setName(string name);
    List<Music *> *getPlaylist();
    void addMusic(Music *music);
    Music *nextMusic();
    void printMusics();
};

#endif