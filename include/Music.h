#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <ostream>

using std::ostream;
using std::string;

/**
 * @class Music
 * @brief Classe que representa uma música.
 */
class Music
{

private:
    string nameArtist; /**< Nome do artista/banda da música. */
    string name; /**< Nome da música. */

public:
    /**
     * @brief Construtor padrão da classe Music.
     */
    Music();

    /**
     * @brief Destrutor da classe Music.
     */
    ~Music();

    /**
     * @brief Construtor da classe Music.
     * @param nameArtist Nome do artista/banda da música.
     * @param name Nome da música.
     */
    Music(string nameArtist, string name);

    /**
     * @brief Obtém o nome da música.
     * @return O nome da música.
     */
    string getName();

    /**
     * @brief Define o nome da música.
     * @param name O nome da música.
     */
    void setName(string name);

    /**
     * @brief Obtém o nome do artista/banda da música.
     * @return O nome do artista/banda da música.
     */
    string getNameArtist();

    /**
     * @brief Define o nome do artista/banda da música.
     * @param nameArtist O nome do artista/banda da música.
     */
    void setNameArtist(string nameArtist);

    /**
     * @brief Sobrecarga do operador de inserção em stream para imprimir a música.
     * @param os Stream de saída.
     * @param music Ponteiro para a música a ser impressa.
     * @return A stream de saída.
     */
    friend ostream &operator<<(ostream &os, Music *music);
};

#endif
