#include <iostream>
#include <limits>
#include <ios>
#include <List.h>
#include <Music.h>
#include <Artist.h>

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

    List<Music *> *test = new List<Music *>();

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

        cout << endl;

        // test.add(new Music(new Artist(nameArtist), nameMusic));

        test->add(new Music(new Artist(nameArtist), nameMusic));
    }

    cout << test;

    return 0;
}