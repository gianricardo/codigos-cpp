/*
 * ilist.h
 *
 *  Created on: Jun 1, 2015
 *      Author: gian
 */

#ifndef ILIST_H_
#define ILIST_H_

#include "codigo_erro.h"
#include "node.h"
#include "visitor.h"

/**
 * Complete a implementação da Lista Simplesmente Encadeada.
 * Onde não está definido a pré-condição é a lista estar criada.
 */
template<class Tipo_info, class Node_class=Node<Tipo_info> >
class IList {

public:
    virtual ~IList() {
    }
    /**
     * Pós-condição: returna a quantidade de nós/entradas/células presente na lista.
     */
    virtual long tamanho() const = 0;

    /**
     * Pós-condição: retorna verdadeiro se a lista está vazia, caso contrário, retorna falso.
     * @return o estado da lista
     */
    virtual bool empty() const =0;

    /**
     * Pós-condição: Todos os nós da lista devem ser removidos. A lista está vazia.
     *
     */
    virtual void clear() = 0;
    /**
     * Pós-condição: A ação especificada pela função *visit foi realizada em cada Nó da lista.
     * Comçou na posição 0 da lista e seguiu até o final dela, em ordem.
     *
     * @param visit ponteiro para uma função
     */
    virtual void traverse(Visitor<Tipo_info>& visitor) =0;

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
    virtual Codigo_erro busca(long posicao, Tipo_info &x) =0;

    /**
     *  Pós-condição: Se posição válida, a função segue:
     *  A informação na posição é trocada por x; todos os outros nós se manterão inalterados.
     *  Senão: A função falha com um código de erro para diagnóstico.
     *
     * @param posicao Posição válida de interesse na lista
     * @param x Conteúdo da posição para troca
     * @return Código de erro para diagnóstico
     */
    virtual Codigo_erro substitui(long posicao, const Tipo_info &x) =0;

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
    virtual Codigo_erro remove(long posicao, Tipo_info &x) =0;

    /**
     * Pós-condição: Se posição válida, a função segue:
     * Todos os k nódos com a informação x serão removidos da lista e todos os outros nós se manterão inalterados.
     * A lista tem k nódos a menos.
     * Senão: A função falha com um código de erro para diagnóstico.
     *
     * @param x Conteúdo da posição removida
     * @return Código de erro para diagnóstico
     */
    virtual Codigo_erro remove(Tipo_info x) =0;

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
    virtual Codigo_erro insere(long posicao, const Tipo_info& x)=0;

    /**
     * Pre:  posicao é uma posição válida na lista; 0 <= posicao < _quantidade_lista.
     * Pos:  Returna um ponteiro para o Nó na posição ou nullptr caso contrário.
     *
     * @param posicao uma posição na lista
     * @return um ponteiro para o nó ou nulo se não estiver na lista.
     */
    virtual Node_class* node(long posicao) =0;

    /**
     * Retorna o nó anterior ao node.
     *
     * @param node ponteiro válido para um nó da lista
     * @return um ponteiro para o anterior ou nullptr caso não seja possível encontrá-lo.
     */
    virtual Node_class* prev(Node_class* node) =0;

    /**
     * Retorna o nó seguinte ao node.
     *
     * @param node ponteiro válido para um nó da lista
     * @return um ponteiro para o seguinte ou nullptr caso não seja possível encontrá-lo.
     */
    virtual Node_class* next(Node_class* node) =0;

    /**
     *
     * @param x
     * @return
     */
    virtual Codigo_erro push_front(const Tipo_info& x) =0;

    /**
     *
     * @param x
     * @return
     */
    virtual Codigo_erro push_back(const Tipo_info& x) =0;

    /**
     *
     * @param x
     * @return
     */
    virtual Codigo_erro pop_front(Tipo_info& x) =0;

    /**
     *
     * @param x
     * @return
     */
    virtual Codigo_erro pop_back(Tipo_info& x) =0;

};

#endif /* ILIST_H_ */
