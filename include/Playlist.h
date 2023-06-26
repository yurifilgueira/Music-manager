#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <List.h>
#include <Music.h>

using std::ostream;

/**
 * @class Playlist
 * @brief Classe que representa uma playlist.
 */
class Playlist
{

private:
    string name; /**< Nome da playlist. */
    Node<Music *> *currentNode; /**< Nó atual da playlist. */
    List<Music *> *musics = new List<Music *>; /**< Lista de músicas da playlist. */

public:
    /**
     * @brief Construtor padrão da classe Playlist.
     */
    Playlist();

    /**
     * @brief Construtor da classe Playlist.
     * @param name Nome da playlist.
     */
    Playlist(string name);

    /**
     * @brief Construtor da classe Playlist.
     * @param name Nome da playlist.
     * @param musics Referência para outra playlist de músicas a serem adicionadas.
     */
    Playlist(string name, Playlist &musics);

    /**
     * @brief Construtor de cópia da classe Playlist.
     * @param musics Referência para outra playlist a ser copiada.
     */
    Playlist(Playlist &musics);

    /**
     * @brief Destrutor da classe Playlist.
     */
    ~Playlist();

    /**
     * @brief Obtém o nome da playlist.
     * @return Nome da playlist.
     */
    string getName();

    /**
     * @brief Define o nome da playlist.
     * @param name Nome da playlist.
     */
    void setName(string name);

    /**
     * @brief Obtém a lista de músicas da playlist.
     * @return Ponteiro para a lista de músicas.
     */
    List<Music *> *getPlaylist();

    /**
     * @brief Adiciona uma música à playlist.
     * @param music Ponteiro para o objeto Music a ser adicionado.
     */
    void addMusic(Music *music);

    /**
     * @brief Obtém a próxima música da playlist.
     * @return Ponteiro para o próximo objeto Music da playlist.
     */
    Music *nextMusic();

    /**
     * @brief Imprime as músicas da playlist.
     */
    void printMusics();

    /**
     * @brief Obtém o tamanho da playlist.
     * @return Tamanho da playlist.
     */
    int getSize();

    /**
     * @brief Remove uma música da playlist.
     * @param music Ponteiro para o objeto Music a ser removido.
     */
    void remove(Music *music);

    /**
     * @brief Procura uma música pelo nome na playlist.
     * @param name Nome da música a ser procurada.
     * @return Ponteiro para o objeto Music encontrado ou nullptr se não encontrado.
     */
    Music *searchByName(string name);

    /**
     * @brief Adiciona as músicas de outra playlist à playlist atual.
     * @param musics Referência para a outra playlist a ser adicionada.
     */
    void addMusic(Playlist &musics);

    /**
     * @brief Remove as músicas de outra playlist da playlist atual.
     * @param musics Referência para a outra playlist a ser removida.
     */
    void remove(Playlist &musics);

    /**
     * @brief Obtém o último nó da lista de músicas da playlist.
     * @return Ponteiro para o último nó da lista.
     */
    Node<Music *> *getLastMusic();

    /**
     * @brief Sobrecarga do operador de inserção para impressão da playlist.
     * @param os Referência para o fluxo de saída.
     * @param Playlist Ponteiro para a playlist a ser impressa.
     * @return Referência para o fluxo de saída.
     */
    friend ostream &operator<<(ostream &os, Playlist *Playlist);

    /**
     * @brief Sobrecarga do operador de adição para união de playlists.
     * @param playlist Referência para a playlist a ser adicionada.
     * @return Ponteiro para uma nova playlist contendo a união das playlists.
     */
    Playlist *operator+(Playlist &playlist);

    /**
     * @brief Sobrecarga do operador de adição para adicionar uma música à playlist.
     * @param music Ponteiro para a música a ser adicionada.
     * @return Ponteiro para uma nova playlist contendo a música adicionada.
     */
    Playlist *operator+(Music *music);

    /**
     * @brief Sobrecarga do operador de subtração para diferença de playlists.
     * @param playlist Referência para a playlist a ser removida.
     * @return Ponteiro para uma nova playlist contendo a diferença das playlists.
     */
    Playlist *operator-(Playlist &playlist);

    /**
     * @brief Sobrecarga do operador de subtração para remover uma música da playlist.
     * @param music Ponteiro para a música a ser removida.
     * @return Ponteiro para uma nova playlist contendo a música removida.
     */
    Playlist *operator-(Music *music);

    /**
     * @brief Sobrecarga do operador de extração para extrair a próxima música da playlist.
     * @param music Referência para o objeto Music que receberá a próxima música.
     */
    void operator>>(Music &music);

    /**
     * @brief Sobrecarga do operador de inserção para adicionar uma música à playlist.
     * @param music Ponteiro para a música a ser adicionada.
     */
    void operator<<(Music *music);
};

#endif
