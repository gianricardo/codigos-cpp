/*
 * node.h
 *
 *  Created on: May 22, 2015
 *      Author: gian
 */

#ifndef NODE_H_
#define NODE_H_

#include "codigo_erro.h"

/**
 * Complete a implementação do Nó/Entrada/Célula de uma Lista Simplesmente Encadeada.
 *
 */
template<class Tipo_Info>
class Node
{
    Tipo_Info _info;
    Node<Tipo_Info>* _nextNode;
public:
    Node() :
        _nextNode(nullptr) {
    }
    Node(Node<Tipo_Info>* nextNode)  {
            _nextNode=nextNode;
    }
    Node(Tipo_Info info, Node<Tipo_Info>* nextNode) {
        _nextNode=nextNode;
        _info=info;
    }
    virtual ~Node() {
    }
    void info(Tipo_Info info) {
        _info = info;
    }
    Tipo_Info info() {
        return _info;
    }
    void next(Node<Tipo_Info>* nextNode) {
        _nextNode = nextNode;
    }
    Node<Tipo_Info>* next() {
        return _nextNode;
    }
};

#endif /* NODE_H_ */
