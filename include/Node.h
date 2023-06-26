#ifndef NODE_H
#define NODE_H

#include <ostream>
#include <iostream>

using std::cout;
using std::endl;

using std::ostream;

/**
 * @class Node
 * @brief Classe que representa um nó em uma lista encadeada.
 * @tparam T O tipo de dado armazenado no nó.
 */
template <typename T>
class Node
{
private:
    T data; /**< Dado armazenado no nó. */
    Node<T> *next; /**< Ponteiro para o próximo nó. */

public:
    /**
     * @brief Construtor padrão da classe Node.
     */
    Node()
    {
        this->data = NULL;
        this->next = nullptr;
    }

    /**
     * @brief Construtor da classe Node.
     * @param value O valor a ser armazenado no nó.
     */
    Node(T value)
    {
        data = value;
        next = nullptr;
    }

    /**
     * @brief Destrutor da classe Node.
     */
    ~Node()
    {
    }

    /**
     * @brief Obtém o dado armazenado no nó.
     * @return O dado armazenado no nó.
     */
    T getData()
    {
        return this->data;
    }

    /**
     * @brief Obtém o próximo nó na lista encadeada.
     * @return Ponteiro para o próximo nó.
     */
    Node<T> *getNext()
    {
        return this->next;
    }

    /**
     * @brief Define o próximo nó na lista encadeada.
     * @param next Ponteiro para o próximo nó.
     */
    void setNext(Node<T> *next)
    {
        this->next = next;
    }

    /**
     * @brief Sobrecarga do operador de inserção em stream para imprimir o nó.
     * @param os Stream de saída.
     * @param node Ponteiro para o nó a ser impresso.
     * @return A stream de saída.
     */
    friend ostream &operator<<(ostream &os, Node<T> *node)
    {
        os << node->getData();

        if (node->getNext() != nullptr)
        {
            os << node->getNext();
        }

        return os;
    }
};

#endif
