/*
 * list-de.h
 *
 *  Created on: May 25, 2015
 *      Author: gian
 */

#ifndef LIST_DE_H_
#define LIST_DE_H_

#include "ilist.h"
#include "node-de.h"

/**
 * Complete a implementação da Lista Duplamente Encadeada.
 */

template<class Tipo_info>
class ListaDE: public IList<Tipo_info, NodeDE<Tipo_info> > {
    long _quantidade_lista;
    NodeDE<Tipo_info> *_inicio;
public:
    ListaDE() {
        _quantidade_lista = (0);
        _inicio = (nullptr);
    }
    virtual ~ListaDE() {
        clear();
    }
    virtual long tamanho() const {
        return _quantidade_lista;
    }

    virtual bool empty() const {
        return (_quantidade_lista == 0 && _inicio == nullptr);
    }

    virtual void clear() {
        NodeDE<Tipo_info> *ptrpos = _inicio;
        for (long k = 0; k < _quantidade_lista; k++) {
            NodeDE<Tipo_info> *temp = ptrpos;
            ptrpos = ptrpos->next();
            delete temp;
        }
        _inicio = nullptr;
        _quantidade_lista = 0;
    }

    virtual void traverse(Visitor<Tipo_info>& visitor) {
        NodeDE<Tipo_info> *tra = _inicio;
        for (long k = 0; k < _quantidade_lista; k++) {
            visitor.visit(tra->info());
            tra = tra->next();
        }
    }

    virtual Codigo_erro busca(long posicao, Tipo_info &x) {
        if (fora_intervalo(posicao)) {
            return Codigo_erro::erro_intervalo;
        }
        NodeDE<Tipo_info> *no_p;
        no_p = get_position(posicao);
        x = no_p->info();
        return Codigo_erro::sucesso;
    }

    virtual Codigo_erro substitui(long posicao, const Tipo_info &x) {
        if (fora_intervalo(posicao)) {
            return Codigo_erro::erro_intervalo;
        }
        NodeDE<Tipo_info> *no_p;
        no_p = get_position(posicao);
        no_p->info(x);
        return Codigo_erro::sucesso;
    }

    virtual Codigo_erro remove(long posicao, Tipo_info &x) {
        throw Codigo_erro::sem_comportamento;
    }

    virtual Codigo_erro remove(Tipo_info x) {
        throw Codigo_erro::sem_comportamento;
    }

    virtual Codigo_erro insere(long posicao, const Tipo_info& x) {
        throw Codigo_erro::sem_comportamento;
    }

    virtual NodeDE<Tipo_info>* node(long posicao) {
        return get_position(posicao);
    }

    virtual NodeDE<Tipo_info>* prev(NodeDE<Tipo_info>* node) {
        throw Codigo_erro::sem_comportamento;
    }

    virtual NodeDE<Tipo_info>* next(NodeDE<Tipo_info>* node) {
        throw Codigo_erro::sem_comportamento;
    }

    virtual Codigo_erro push_front(const Tipo_info& x) {
        throw Codigo_erro::sem_comportamento;
    }

    virtual Codigo_erro push_back(const Tipo_info& x) {
        throw Codigo_erro::sem_comportamento;
    }

    virtual Codigo_erro pop_front(Tipo_info& x) {
        throw Codigo_erro::sem_comportamento;
    }

    virtual Codigo_erro pop_back(Tipo_info& x) {
        throw Codigo_erro::sem_comportamento;
    }
private:
    /**
     * Pre:  posicao é uma posição válida na lista; 0 <= posicao < _quantidade_lista.
     * Pos:  Retorna um ponteiro para o Nó na posição.
     */
    NodeDE<Tipo_info>* get_position(long pos) {
        if (fora_intervalo(pos)) {
            return nullptr;
        }
        NodeDE<Tipo_info> *ptrpos = _inicio;
        for (long k = 0; k < pos; k++) {
            ptrpos = ptrpos->next();
        }
        return ptrpos;
    }

protected:
    long& quantidade() {
        return _quantidade_lista;
    }
    Node<Tipo_info> *inicio() {
        return _inicio;
    }
    void inicio(Node<Tipo_info> *n_inicio) {
        _inicio=n_inicio;
    }
    /**
     * Pós-condição: Verdadeiro se a posição está fora do intervalo (0 <= posicao < _quantidade_lista) e,
     * caso contrário, falso.
     *
     * @param posicao uma posição na lista
     * @return se a posição é inválida
     */
    bool fora_intervalo(long posicao) {
        return ((posicao < 0) || (posicao > _quantidade_lista));
    }
};

#endif /* LIST_DE_H_ */
