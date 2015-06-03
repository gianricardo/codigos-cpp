/*
 * node-de.h
 *
 *  Created on: Jun 2, 2015
 *      Author: gian
 */

#ifndef NODE_DE_H_
#define NODE_DE_H_

#include "node.h"

template<class Tipo_Info>
class NodeDE : public Node<Tipo_Info>{
    NodeDE<Tipo_Info> *_next,*_prev;
public:
    NodeDE() :
        _next(nullptr),_prev(nullptr) {
    }
    NodeDE(NodeDE<Tipo_Info>* next) {
            _next=next;
            _prev=nullptr;
    }
    NodeDE(Tipo_Info info, NodeDE<Tipo_Info>* next) {
        _next=next;
        _prev=nullptr;
        info(info);
    }
    NodeDE(Tipo_Info info, NodeDE<Tipo_Info>* prev, NodeDE<Tipo_Info>* next) {
        _next=next;
        _prev=prev;
        info(info);
    }
    virtual ~NodeDE(){}

    void next(NodeDE<Tipo_Info>* nextNode) {
        _next = nextNode;
    }
    NodeDE<Tipo_Info>* next() {
        return _next;
    }
    void prev(NodeDE<Tipo_Info>* prev) {
        _prev = prev;
    }
    NodeDE<Tipo_Info>* prev() {
        return _prev;
    }
};



#endif /* NODE_DE_H_ */
