#ifndef LIST_H
#define LIST_H

#include <Node.h>
#include <ostream>
#include <iostream>

using std::cout;
using std::endl;

using std::ostream;


/**
 * @class List
 * @brief Classe que representa uma lista encadeada.
 * @tparam T O tipo de dado armazenado na lista.
 */
template <typename T>
class List
{
private:
    Node<T> *head; /**< Ponteiro para o primeiro nó da lista. */
    Node<T> *tail; /**< Ponteiro para o último nó da lista. */
    int size; /**< Tamanho da lista. */

public:
    /**
     * @brief Construtor padrão da classe List.
     */
    List()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    /**
     * @brief Construtor de cópia da classe List.
     * @param obj Lista a ser copiada.
     */
    List(List<T> &obj)
    {
        head = nullptr;
        tail = nullptr;
        size = 0;

        Node<T> *current = obj.getHead();
        while(current != nullptr){
            add(current->getData());
            current = current->getNext();
        } 
    }
    
    /**
     * @brief Obtém o ponteiro para o primeiro nó da lista.
     * @return O ponteiro para o primeiro nó da lista.
     */
    Node<T> *getHead()
    {
        return this->head;
    }
    
    /**
     * @brief Obtém o ponteiro para o último nó da lista.
     * @return O ponteiro para o último nó da lista.
     */
    Node<T> *getTail()
    {
        return this->tail;
    }
    
    /**
     * @brief Obtém o tamanho da lista.
     * @return O tamanho da lista.
     */
    int getSize()
    {
        return size;
    }
    
    /**
     * @brief Destrutor da classe List.
     */
    ~List()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            Node<T> *next = current->getNext();
            delete current;
            current = next;
        }
    }
    
    /**
     * @brief Adiciona um elemento à lista.
     * @param value O valor a ser adicionado à lista.
     */
    void add(T value)
    {
        Node<T> *temp = new Node<T>(value);
        if (head == nullptr)
        {
            head = temp;
            head->setNext(temp);
            tail = temp;
            tail->setNext(nullptr);
        }
        else
        {
            tail->setNext(temp);
            tail = tail->getNext();
        }
        size++;
    }
    
    /**
     * @brief Remove um elemento da lista.
     * @param data O valor a ser removido da lista.
     */
    void remove(T data)
    {
        Node<T> *current = head;
        Node<T> *previous = nullptr;
        while (current != nullptr)
        {
            if (current->getData() == data)
            {
                if (previous != nullptr)
                {
                    previous->setNext(current->getNext());
                }
                if (current == head)
                {
                    head = current->getNext();
                }
                if (current == tail)
                {
                    tail = previous;
                }
                delete current;
                size--;
                return;
            }
            previous = current;
            current = current->getNext();
        }
    }
    
    /**
     * @brief Adiciona os elementos de outra lista à lista atual.
     * @param linkedlist A lista a ser adicionada.
     */
    void addLinked(List<T> &linkedlist)
    {
        Node<T> *current = linkedlist.head;
        while (current != nullptr)
        {
            add(current->getData());
            current = current->getNext();
        }
    }
    
    /**
     * @brief Remove os elementos de outra lista da lista atual.
     * @param linkedlist A lista a ser removida.
     */
    void removeLinked(List<T> &linkedlist)
    {
        Node<T> *current = linkedlist.head;
        while (current != nullptr)
        {
            remove(current->getData());
            current = current->getNext();
        }
    }
    
    /**
     * @brief Sobrecarga do operador de inserção em stream para imprimir a lista.
     * @param os Stream de saída.
     * @param list Ponteiro para a lista a ser impressa.
     * @return A stream de saída.
     */
    friend ostream &operator<<(ostream &os, List *list)
    {
        os << list->getHead();

        return os;
    }
    
    /**
     * @brief Sobrecarga do operador de soma para mesclar duas listas.
     * @param linkedList A lista a ser mesclada.
     * @return Um ponteiro para uma nova lista contendo os elementos mesclados.
     */
    List<T> *operator+(List<T> &linkedList)
    {
        List<T> *merge = new List<T>(*this);
        merge->addLinked(linkedList);
        
        return merge;
    }
    
    /**
     * @brief Sobrecarga do operador de extração para remover o último elemento da lista e armazená-lo em um nó.
     * @param no O nó que irá armazenar o último elemento da lista.
     */
    void operator>>(Node<T> &no)
    {
        if (getHead() == nullptr)
        {
            no = nullptr;
        }
        else
        {
            no = *getTail();
        } 
    }
    
    /**
     * @brief Sobrecarga do operador de inserção para adicionar o conteúdo de um nó à lista.
     * @param no O nó contendo o elemento a ser adicionado à lista.
     */
    void operator<<(Node<T> &no)
    {
        if (no.getData()!=nullptr)
        {
            add(no.getData());
        }
    }
};

#endif
