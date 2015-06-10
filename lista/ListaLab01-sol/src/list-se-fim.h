/*
 * lista-se-fim.h
 *
 *  Created on: May 22, 2015
 *      Author: gian
 */

#ifndef LIST_SE_FIM_H_
#define LIST_SE_FIM_H_

#include "node.h"
#include "list-se.h"

/**
 * Complete a implementação da lista simplesmente encadeada com referências para inicio e fim.
 */

template<class Tipo_info>
class ListaSE_Fim: public ListaSE<Tipo_info> {
    Node<Tipo_info> *_fim;
    typedef ListaSE<Tipo_info> base;
    using base::fora_intervalo;
    using base::inicio;
    using base::quantidade;

    Node<Tipo_info>* set_pos(long pos) {
        Node<Tipo_info> *ptrpos;
        ptrpos = inicio();
        for (long k = 0; k < pos; k++) {
            ptrpos = ptrpos->next();
        }
        return ptrpos;
    }
public:
    ListaSE_Fim() :
            base() {
        _fim = nullptr;
    }
    virtual ~ListaSE_Fim() {
    }

    virtual Codigo_erro remove(long posicao, Tipo_info &x) override {
        if (fora_intervalo(posicao)) {
            return Codigo_erro::erro_intervalo;
        }
        Node<Tipo_info> *excluido, *anterior = nullptr, *seguinte;
        if (posicao > 0) {
            anterior = set_pos(posicao - 1);
            excluido = anterior->next();
        } else {
            excluido = inicio();
        }
        seguinte = excluido->next();
        if (posicao == 0) {
            inicio(seguinte);
        } else {
            anterior->next(seguinte);
            if (seguinte == nullptr) {
                _fim = anterior;
            }
        }
        x = excluido->info();
        quantidade()--;delete
excluido        ;
        return Codigo_erro::sucesso;
    }

    virtual Codigo_erro insere(long posicao, const Tipo_info& x) {
        if (fora_intervalo(posicao)) {
            return Codigo_erro::erro_intervalo;
        }
        Node<Tipo_info> *novo, *anterior = nullptr, *seguinte;
        long& quant = quantidade();

        if (posicao > 0) {
            if (posicao >= quant) {
                anterior = _fim;
            } else {
                anterior = set_pos(posicao - 1);
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
            if (seguinte == nullptr) {
                _fim = novo;
            }
        }
        if (_fim == nullptr) {
            _fim = novo;
        }
        quant++;
        return Codigo_erro::sucesso;
    }

protected:
    Node<Tipo_info> *fim() {
        return _fim;
    }

};

#endif /* LIST_SE_FIM_H_ */
