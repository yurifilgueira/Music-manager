#include <SystemPlaylists.h>

SystemPlaylists::SystemPlaylists()
{
}

SystemPlaylists::~SystemPlaylists()
{
    delete playlists;
}

List<Playlist *> *SystemPlaylists::getPlaylists()
{
    return playlists;
}

void SystemPlaylists::addPlaylistToSystem(Playlist *playlist)
{
    playlists->add(playlist);
}

void SystemPlaylists::printSystemPlaylists()
{
    cout << playlists;
}

Playlist *SystemPlaylists::searchPlaylist(string name)
{
    Node<Playlist *> *current = playlists->getHead();
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