#ifndef SYSTEMPLAYLISTS_H
#define SYSTEMPLAYLISTS_H

#include <List.h>
#include <Playlist.h>

/**
 * @class SystemPlaylists
 * @brief Classe que representa o sistema de playlists.
 */
class SystemPlaylists
{

private:
    List<Playlist *> *playlists = new List<Playlist *>; /**< Lista de playlists do sistema. */

public:
    /**
     * @brief Construtor padrão da classe SystemPlaylists.
     */
    SystemPlaylists();

    /**
     * @brief Destrutor da classe SystemPlaylists.
     */
    ~SystemPlaylists();

    /**
     * @brief Obtém a lista de playlists do sistema.
     * @return Ponteiro para a lista de playlists.
     */
    List<Playlist *> *getPlaylists();

    /**
     * @brief Adiciona uma playlist ao sistema.
     * @param playlist Ponteiro para a playlist a ser adicionada.
     */
    void addPlaylistToSystem(Playlist *playlist);

    /**
     * @brief Imprime as playlists do sistema.
     */
    void printSystemPlaylists();

    /**
     * @brief Procura uma playlist pelo nome no sistema.
     * @param name Nome da playlist a ser procurada.
     * @return Ponteiro para a playlist encontrada ou nullptr se não encontrada.
     */
    Playlist *searchPlaylist(string name);
};

#endif
