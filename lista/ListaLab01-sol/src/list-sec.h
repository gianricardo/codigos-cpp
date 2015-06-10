/*
 * list-sec.h
 *
 *  Created on: May 25, 2015
 *      Author: gian
 */

#ifndef LIST_SEC_H_
#define LIST_SEC_H_


#include "node.h"
#include "list-se-cur.h"

/**
 * Complete a implementação da lista simplesmente encadeada circular com referências para corrente, inicio e fim.
 */

template<class Tipo_info>
class ListaSEC :public ListaSE_Cur<Tipo_info> {
    typedef ListaSE_Cur<Tipo_info> base;
protected:
    using base::fora_intervalo;
    using base::inicio;
    using base::quantidade;
    using base::fim;
    using base::prev;
    using base::cursor;
    using base::set_position;
public:
    ListaSEC():base() {
    }
    virtual ~ListaSEC() {
    }
    virtual Node<Tipo_info>* prev(Node<Tipo_info>* node) {
        if (node == inicio()) {
            return fim();
        }
        Node<Tipo_info> *ptrpos = base::prev(node);
        return ptrpos;
    }

    virtual Codigo_erro insere(long posicao, const Tipo_info& x) override {
        if (fora_intervalo(posicao)) {
            return Codigo_erro::erro_intervalo;
        }
        Node<Tipo_info> *novo, *anterior = nullptr, *seguinte;
        long& quant = quantidade();

        if (posicao > 0) {
            if (posicao >= quant) {
                anterior = fim();
            } else {
                set_position(posicao - 1);
                anterior = cursor();
            }
            seguinte = anterior->next();
        } else {
            seguinte = inicio();
        }
        novo = new Node<Tipo_info>(x, seguinte);
        if (posicao == 0) {
            inicio(novo);
        } else {
            anterior->next(novo);
            if (seguinte == inicio()) {
                fim(novo);
            }
        }
        if (fim() == nullptr) {
            novo->next(novo);
            fim(novo);
        }
        quant++;
        return Codigo_erro::sucesso;
    }

    virtual Codigo_erro remove(long posicao, Tipo_info &x) override {
        if (fora_intervalo(posicao)) {
            return Codigo_erro::erro_intervalo;
        }
        Node<Tipo_info> *excluido, *anterior = nullptr, *seguinte;
        if (posicao > 0) {
            set_position(posicao - 1);
            anterior = cursor();
            excluido = anterior->next();
        } else {
            excluido = inicio();
        }
        seguinte = excluido->next();
        if (posicao == 0) {
            inicio(seguinte);
        } else {
            anterior->next(seguinte);
            if (seguinte == inicio()) {
                fim(anterior);
            }
        }
        x = excluido->info();
        quantidade()--;
        if(quantidade()==0){
            inicio(nullptr);
            fim(nullptr);
        }
        delete excluido;
        return Codigo_erro::sucesso;
    }

};


#endif /* LIST_SEC_H_ */
