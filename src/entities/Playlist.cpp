#include <iostream>
#include <Playlist.h>

using std::cout;

Playlist::Playlist()
{
    this->name = nullptr;
    this->currentNode = nullptr;
}

Playlist::~Playlist()
{
}

Playlist::Playlist(string name)
{
    this->name = new string(name);
}

string Playlist::getName()
{

    if (this->name == nullptr)
    {
        return "You didn't name this playlist";
    }
    return *this->name;
}

void Playlist::setName(string name)
{
    delete this->name;
    this->name = new string(name);
}

List<Music *> *Playlist::getPlaylist()
{
    return this->musics;
}

void Playlist::addMusic(Music *music)
{
    musics->add(music);
}

Music *Playlist::nextMusic()
{
    if (musics->getHead() == nullptr)
    {
        return nullptr;
    }

    if (currentNode == nullptr)
    {
        currentNode = musics->getHead();
    }
    else
    {
        currentNode = currentNode->getNext();
    }

    if (currentNode == nullptr)
    {
        return nullptr;
    }

    return currentNode->getData();
}

int Playlist::getSize()
{
    return musics->getSize();
}

void Playlist::printMusics()
{
    cout << musics;
}

void Playlist::remove(Music *value)
{
    musics->remove(value);
}

Music *Playlist::searchByName(string name)
{
    Node<Music *> *current = musics->getHead();
    while (current != nullptr)
    {
        if (current->getData()->getName() == name)
        {
            return current->getData();
        }
        current = current->getNext();
    }
    return nullptr;
}
ostream &operator<<(ostream &os, Playlist *playlist)
{
    os << "Nome: " << playlist->getName() << endl;

    return os;
}