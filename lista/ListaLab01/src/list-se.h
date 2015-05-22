/*
 * list-se.h
 *
 *  Created on: May 22, 2015
 *      Author: gian
 */

#ifndef LIST_SE_H_
#define LIST_SE_H_

#include "node.h"

/**
 * Complete a implementação da Lista Simplesmente Encadeada.
 * Onde não está definido a pré-condição é a lista estar criada.
 */

template<class Tipo_info>
class ListaSE {
    Node<Tipo_info> *_inicio; //referencia para o nó que inicia a lista
    long _quantidade_lista;  //quantidade de nós na lista
public:
    ListaSE() :
            _quantidade_lista(0), _inicio(nullptr) {
    }
    ~ListaSE() {
        //precisa limpar algo?
    }
    /**
     * Pós-condição: returna a quantidade de nós/entradas/células presente na lista.
     */
    long tamanho() const {
        throw Codigo_erro::sem_comportamento;
    }
    /**
     * Pós-condição: retorna verdadeiro se a lista está vazia, caso contrário, retorna falso.
     * @return o estado da lista
     */
    bool empty() const {
        throw Codigo_erro::sem_comportamento;
    }
    /**
     * Pós-condição: Todos os nós da lista devem ser removidos. A lista está vazia.
     *
     */
    void clear() {
        throw Codigo_erro::sem_comportamento;
    }
    /**
     * Pós-condição: A ação especificada pela função *visit foi realizada em cada Nó da lista.
     * Comçou na posição 0 da lista e seguiu até o final dela, em ordem.
     *
     * @param visit ponteiro para uma função
     */
    void traverse(void (*visit)(Tipo_info &)) {
        throw Codigo_erro::sem_comportamento;
    }

    /**
     *
     * Pós-condição: Se posição válida, a função segue:
     * A informação na posição é copiada para x; todos os nós se manterão inalterados.
     * Senão: A função falha com um código de erro para diagnóstico.
     *
     * @param posicao Posição válida de interesse na lista
     * @param x Conteúdo da posição
     * @return Código de erro para diagnóstico
     */
    Codigo_erro busca(int posicao, Tipo_info &x) const {
        throw Codigo_erro::sem_comportamento;
    }

    /**
     *  Pós-condição: Se posição válida, a função segue:
     *  A informação na posição é trocada por x; todos os outros nós se manterão inalterados.
     *  Senão: A função falha com um código de erro para diagnóstico.
     *
     * @param posicao Posição válida de interesse na lista
     * @param x Conteúdo da posição para troca
     * @return Código de erro para diagnóstico
     */
    Codigo_erro substitui(int posicao, const Tipo_info &x) {
        throw Codigo_erro::sem_comportamento;
    }

    /**
     * Pós-condição: Se posição válida, a função segue:
     * O nó na posicao é removido da lista e todos os outros nós se manterão inalterados.
     * O parâmetro x mantêm uma cópia da informação do nó que estava a posicao esperada.
     * A lista tem um nó a menos.
     * Senão: A função falha com um código de erro para diagnóstico.
     *
     * @param posicao Posição válida de interesse na lista
     * @param x Conteúdo da posição removida
     * @return Código de erro para diagnóstico
     */
    Codigo_erro remove(int posicao, Tipo_info &x) {
        throw Codigo_erro::sem_comportamento;
    }

    /**
     * Pós-condição: Se posição válida, a função segue:
     * Todos os k nódos com a informação x serão removidos da lista e todos os outros nós se manterão inalterados.
     * A lista tem k nódos a menos.
     * Senão: A função falha com um código de erro para diagnóstico.
     *
     * @param x Conteúdo da posição removida
     * @return Código de erro para diagnóstico
     */
    Codigo_erro remove(Tipo_info x) {
        throw Codigo_erro::sem_comportamento;
    }
    /**
     *  Pós-condição: Se posição válida, a função segue:
     *  Um novo nó é criado com a informação x e posicionado no local posicao; todos os outros nós se manterão inalterados.
     *  A lista tem um nó a mais.
     *  Senão: A função falha com um código de erro para diagnóstico.
     *
     * @param posicao Posição válida de interesse na lista
     * @param x Conteúdo da posição para inserção
     * @return Código de erro para diagnóstico
     */
    Codigo_erro insere(int posicao, const Tipo_info &x) {
        throw Codigo_erro::sem_comportamento;
    }
protected:
    /**
     * Pre:  posicao é uma posição válida na lista; 0 <= posicao < _quantidade_lista.
     * Pos:  Returna um ponteiro para o Nó na posição.
     */
    Node<Tipo_info> *set_position(int posicao) const {
        throw Codigo_erro::sem_comportamento;
    }
    long& quantidade() {
        return _quantidade_lista;
    }
    Node<Tipo_info> *inicio() {
        return _inicio;
    }
    /**
     * Pós-condição: Verdadeiro se a posição está fora do intervalo (0 <= posicao < _quantidade_lista) e,
     * caso contrário, falso.
     *
     * @param posicao uma posição na lista
     * @return se a posição é inválida
     */
    bool fora_intervalo(int posicao) {
        return (posicao < 0 || posicao > _quantidade_lista);
    }
};

#endif /* LIST_SE_H_ */
