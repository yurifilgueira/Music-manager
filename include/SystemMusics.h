#ifndef SYSTEMMUSICS_H
#define SYSTEMMUSICS_H

#include <List.h>
#include <SystemPlaylists.h>
#include <Music.h>

/**
 * @class SystemMusics
 * @brief Classe que representa o sistema de músicas.
 */
class SystemMusics
{

private:
    List<Music *> *musics = new List<Music *>; /**< Lista de músicas do sistema. */

public:
    /**
     * @brief Construtor da classe SystemMusics.
     */
    SystemMusics();

    /**
     * @brief Destrutor da classe SystemMusics.
     */
    ~SystemMusics();

    /**
     * @brief Obtém a lista de músicas do sistema.
     * @return Ponteiro para a lista de músicas.
     */
    List<Music *> *getMusics();

    /**
     * @brief Adiciona uma música ao sistema.
     * @param music Ponteiro para o objeto Music a ser adicionado.
     */
    void addMusicToSystem(Music *music);

    /**
     * @brief Verifica se uma música já está no sistema.
     * @param music Ponteiro para o objeto Music a ser verificado.
     * @return true se a música já está no sistema, false caso contrário.
     */
    bool isMusicInSystem(Music *music);

    /**
     * @brief Imprime as músicas do sistema.
     */
    void printSystemMusics();
};

#endif
