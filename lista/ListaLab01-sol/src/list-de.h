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
    virtual ~ListaDE(){}
    virtual long tamanho() const {
        return _quantidade_lista;
    }

    virtual bool empty() const {
        throw Codigo_erro::sem_comportamento;
    }

    virtual void clear() {
        throw Codigo_erro::sem_comportamento;
    }

    virtual void traverse(Visitor<Tipo_info>& visitor){
        throw Codigo_erro::sem_comportamento;
    }

    virtual Codigo_erro busca(long posicao, Tipo_info &x) const {
        throw Codigo_erro::sem_comportamento;
    }

    virtual Codigo_erro substitui(long posicao, const Tipo_info &x){
        throw Codigo_erro::sem_comportamento;
    }

    virtual Codigo_erro remove(long posicao, Tipo_info &x){
        throw Codigo_erro::sem_comportamento;
    }

    virtual Codigo_erro remove(Tipo_info x) {
        throw Codigo_erro::sem_comportamento;
    }

    virtual Codigo_erro insere(long posicao, const Tipo_info& x){
        throw Codigo_erro::sem_comportamento;
    }

    virtual NodeDE<Tipo_info>* node(long posicao){
        throw Codigo_erro::sem_comportamento;
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

    virtual Codigo_erro push_back(const Tipo_info& x){
        throw Codigo_erro::sem_comportamento;
    }

    virtual Codigo_erro pop_front(Tipo_info& x) {
        throw Codigo_erro::sem_comportamento;
    }

    virtual Codigo_erro pop_back(Tipo_info& x){
        throw Codigo_erro::sem_comportamento;
    }

};

#endif /* LIST_DE_H_ */
