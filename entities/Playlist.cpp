#include <iostream>
#include <Playlist.h>

using std::cout;

Playlist::Playlist()
{
    this->name = nullptr;
}

string Playlist::getName()
{
    return *this->name;
}

void Playlist::setName(string name)
{
    this->name = &name;
}

List<Music *> *Playlist::getPlaylist()
{
    return this->musics;
}

void Playlist::addMusic(Music *music)
{
    musics->add(music);
    cout << "\nMusic added successfuly\n"
         << endl;
}

Music *Playlist::nextMusic()
{

    if (musics->getHead() == nullptr)
    {
        return nullptr;
    }

    static Node<Music *> *next = new Node<Music *>();
    static bool noNext = false;
    static bool hasHead = false;
    Node<Music *> *music = new Node<Music *>();

    if (!hasHead)
    {
        music = musics->getHead();
        if (music->getNext() != nullptr)
        {
            next = music->getNext();
        }
        hasHead = true;
    }
    else if (!noNext)
    {
        music = next;
        if (music->getNext() != nullptr)
        {
            next = music->getNext();
        }
        else
        {
            next = music->getNext();
            noNext = true;
        }
    }
    else
    {
        return nullptr;
    }

    return music->getData();
}

void Playlist::printMusics()
{
    cout << musics;
}