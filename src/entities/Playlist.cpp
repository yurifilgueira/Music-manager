#include <iostream>
#include <Playlist.h>

using std::cout;

Playlist::Playlist()
{
    this->name = "NULL";
    this->currentNode = nullptr;
}

Playlist::Playlist(string name, Playlist &musics)
{
    this->name = name;
    this->musics = new List<Music *>(*musics.getPlaylist());
}

Playlist::Playlist(Playlist &musics)
{
    this->musics = new List<Music *>(*musics.getPlaylist());
}

Playlist::~Playlist()
{
    delete musics;
}

Playlist::Playlist(string name)
{
    this->name = name;
}

string Playlist::getName()
{

    if (this->name == "NULL")
    {
        return "You didn't name this playlist";
    }
    return this->name;
}

void Playlist::setName(string name)
{
    this->name = name;
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

void Playlist::addMusic(Playlist &musics)
{
    Node<Music *> *current = musics.getPlaylist()->getHead();

    while (current != nullptr)
    {
        addMusic(current->getData());
        current = current->getNext();
    }
}

void Playlist::remove(Playlist &musics)
{
    Node<Music *> *current = musics.getPlaylist()->getHead();
    
    while (current != nullptr)
    {
        if (searchByName(current->getData()->getName()) != nullptr){
            remove(searchByName(current->getData()->getName()));
            current = current->getNext();
        }
        else
        {
            current = current->getNext();
        }
    }
}

Node<Music *> *Playlist::getLastMusic()
{
    return musics->getTail();
}

ostream &operator<<(ostream &os, Playlist *playlist)
{
    if (playlist == nullptr)
    {
        os << "A playlist está vazia.";
    }
    else {
    os << "Nome: " << playlist->getName() << endl;
    }

    return os;
}

Playlist *Playlist::operator+(Playlist &playlist)
{   
    //playlist que será retornada
    Playlist *playlistn = new Playlist();
    //playlist temporaria com o valor da entrada
    Playlist *playlistt = new Playlist(playlist);

    //vamos fazer a interceção da duas playlists primeiro, já que os elementos não podem se repetir
    playlistt->remove(*this);

    //agora adicionamos os elementos de ambas na nova playlist criada
    playlistn->addMusic(*this);
    playlistn->addMusic(*playlistt);

    return playlistn;

}
Playlist *Playlist::operator+(Music *music)
{
    //playlist que será retornada
    Playlist *playlistn = new Playlist();

    //adiciona as musicas da playlist a que será retornada e depois adiciona a música ao final dela
    playlistn->addMusic(*this);
    playlistn->addMusic(music);

    return playlistn;

}
Playlist *Playlist::operator-(Playlist &playlist)
{
    //playlist que será retornada
    Playlist *playlistn = new Playlist();
    
    //diferença
    playlistn->addMusic(*this);
    playlistn->remove(playlist);

    return playlistn;

}
Playlist *Playlist::operator-(Music *music)
{
    //playlist que será retornada
    Playlist *playlistn = new Playlist();

    playlistn->addMusic(*this);
    playlistn->remove(playlistn->searchByName(music->getName()));

    return playlistn;

}

void Playlist::operator>>(Music &music)
{   
    //usando o método de extração pegamos o ultimo nó da playlist e atribuimos a music
    Node<Music *> *temp = new Node<Music *>();
    
    if (musics->getHead() != nullptr)
    {
        *musics >> *temp;
        music = *temp->getData();
        remove(searchByName(music.getName()));
    }
    else 
    {
        music.setName("null");
    }
}

void Playlist::operator<<(Music *music)
{
    if (music != nullptr){
        this->addMusic(music);
    }
}