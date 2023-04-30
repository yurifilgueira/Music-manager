#include <iostream>
#include <limits>
#include <ios>
#include <List.h>
#include <Music.h>
#include <Artist.h>
#include <Playlist.h>

using std::cin;
using std::string;

void flush()
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
    }
}

int main()
{

    Playlist *playlist = new Playlist();

    int x;

    cin >> x;
    flush();
    int y = 0;
    string nameArtist;
    string nameMusic;
    for (int i = 0; i < x; i++)
    {
        cout << "Artist: ";
        getline(cin, nameArtist);

        cout << "Music: ";
        getline(cin, nameMusic);

        Music *music = new Music(new Artist(nameArtist), nameMusic);

        playlist->addMusic(music);
    }

    // system("clear");
    char keep;
    do
    {
        cout << playlist->nextMusic();
        cin >> keep;
    } while (keep == 's');

    return 0;
}