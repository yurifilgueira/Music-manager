#include <SystemMusics.h>
#include <Playlist.h>
#include <SystemPlaylists.h>

SystemMusics::SystemMusics()
{
}

SystemMusics::~SystemMusics()
{
}

void SystemMusics::addMusicToSystem(Music *music)
{
    if (!isMusicInSystem(music))
    {
        musics->add(music);
    }
}

bool SystemMusics::isMusicInSystem(Music *music)
{
    Node<Music *> *current = musics->getHead();
    while (current != nullptr)
    {
        if (current->getData()->getName() == music->getName() && current->getData()->getNameArtist() == music->getNameArtist())
        {
            return true;
        }
        current = current->getNext();
    }
    return false;
}


List<Music *> *SystemMusics::getMusics()
{
    return musics;
}

void SystemMusics::printSystemMusics()
{
    cout << musics->getHead();
}