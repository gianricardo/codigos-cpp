/*
 * list-se-cur.h
 *
 *  Created on: May 25, 2015
 *      Author: gian
 */

#ifndef LIST_SE_CUR_H_
#define LIST_SE_CUR_H_


#include "node.h"
#include "list-se-fim.h"

/**
 * Complete a implementação da lista simplesmente encadeada com referências para corrente, inicio e fim.
 */

template<class Tipo_info>
class ListaSE_Cur :public ListaSE_Fim<Tipo_info> {
    Node<Tipo_info> *_cursor;
    typedef ListaSE_Fim<Tipo_info> base;
protected:
    using base::fora_intervalo;
    using base::inicio;
    using base::quantidade;
    using base::fim;
    //todo revisar o comportamento desse método para melhorar sua eficiência.
    void set_position(long pos) {
        _cursor = inicio();
        for (long k = 0; k < pos; k++) {
            _cursor = _cursor->next();
        }
    }
    Node<Tipo_info> *cursor() {
        return _cursor;
    }
public:
    ListaSE_Cur(): base() {
        _cursor=nullptr;
    }
    virtual ~ListaSE_Cur()
    {
    }

    virtual Codigo_erro busca(long posicao, Tipo_info &x) override {
        if (fora_intervalo(posicao)) {
            return Codigo_erro::erro_intervalo;
        }
        set_position(posicao);
        x = _cursor->info();
        return Codigo_erro::sucesso;
    }

    virtual Codigo_erro substitui(long posicao, const Tipo_info &x) override {
        if (fora_intervalo(posicao)) {
            return Codigo_erro::erro_intervalo;
        }
        set_position(posicao);
        _cursor->info(x);
        return Codigo_erro::sucesso;
    }

    virtual Codigo_erro remove(long posicao, Tipo_info &x) override {
        if (fora_intervalo(posicao)) {
            return Codigo_erro::erro_intervalo;
        }
        Node<Tipo_info> *excluido, *anterior = nullptr, *seguinte;
        if (posicao > 0) {
            set_position(posicao - 1);
            anterior = _cursor;
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
                anterior = _cursor;
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
                fim(novo);
            }
        }
        if (fim() == nullptr) {
            fim(novo);
        }
        quant++;
        return Codigo_erro::sucesso;
    }
};


#endif /* LIST_SE_CUR_H_ */
