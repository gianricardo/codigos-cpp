/*
 * list-se.h
 *
 *  Created on: May 22, 2015
 *      Author: gian
 */

#ifndef LIST_SE_H_
#define LIST_SE_H_

#include "node.h"
#include "ilist.h"

/**
 * Complete a implementação da Lista Simplesmente Encadeada.
 * Onde não está definido a pré-condição é a lista estar criada.
 */

template<class Tipo_info>
class ListaSE: public IList<Tipo_info, Node<Tipo_info> > {
    Node<Tipo_info> *_inicio; //referencia para o nó que inicia a lista
    long _quantidade_lista;  //quantidade de nós na lista
public:
    ListaSE() {
        _quantidade_lista = (0);
        _inicio = (nullptr);
    }
    virtual ~ListaSE() {
        clear();
    }

    long tamanho() const {
        return _quantidade_lista;
    }

    bool empty() const {
        return (_quantidade_lista == 0 && _inicio == nullptr);
    }

    void clear() {
        Node<Tipo_info> *ptrpos = _inicio;
        for (long k = 0; k < _quantidade_lista; k++) {
            Node<Tipo_info> *temp = ptrpos;
            ptrpos = ptrpos->next();
            delete temp;
        }
        _inicio = nullptr;
        _quantidade_lista = 0;
    }

    void traverse(Visitor<Tipo_info>& visitor) {
        Node<Tipo_info> *tra = _inicio;
        for (long k = 0; k < _quantidade_lista; k++) {
            visitor.visit(tra->info());
            tra = tra->next();
        }
    }

    virtual Codigo_erro busca(long posicao, Tipo_info &x) {
        if (fora_intervalo(posicao)) {
            return Codigo_erro::erro_intervalo;
        }
        Node<Tipo_info> *no_p;
        no_p = set_position(posicao);
        x = no_p->info();
        return Codigo_erro::sucesso;
    }

    virtual Codigo_erro substitui(long posicao, const Tipo_info &x) {
        if (fora_intervalo(posicao)) {
            return Codigo_erro::erro_intervalo;
        }
        Node<Tipo_info> *no_p;
        no_p = set_position(posicao);
        no_p->info(x);
        return Codigo_erro::sucesso;
    }

    virtual Codigo_erro remove(long posicao, Tipo_info &x) {
        if (fora_intervalo(posicao)) {
            return Codigo_erro::erro_intervalo;
        }
        Node<Tipo_info> *excluido, *anterior = nullptr, *seguinte;
        if (posicao > 0) {
            anterior = set_position(posicao - 1);
            excluido = anterior->next();
        } else {
            excluido = _inicio;
        }
        seguinte = excluido->next();
        if (posicao == 0) {
            _inicio = seguinte;
        } else {
            anterior->next(seguinte);
        }
        x = excluido->info();
        _quantidade_lista--;
        if(_quantidade_lista==0){
            _inicio=nullptr;
        }
        delete excluido;
        return Codigo_erro::sucesso;
    }

    //todo esse remove precisa ser implementado para a lista se circular
    virtual Codigo_erro remove(Tipo_info x) {
        Node<Tipo_info> *prev = nullptr, *cur = nullptr;
        Tipo_info temp;
        cur = _inicio;
        long count = 1;
        while (cur != nullptr) {
            prev = cur;
            cur = cur->next();
            if (cur != nullptr) {
                if (cur->info() == x) {
                    remove(count, temp);
                    cur = prev->next();
                }
                count++;
            }
        }
        if (_inicio->info() == x) {
            remove(0, temp);
        }
        return Codigo_erro::sucesso;
    }

    virtual Codigo_erro insere(long posicao, const Tipo_info& x) {
        if (fora_intervalo(posicao)) {
            return Codigo_erro::erro_intervalo;
        }
        Node<Tipo_info> *novo, *anterior = nullptr, *seguinte;
        if (posicao > 0) {
            anterior = set_position(posicao - 1);
            seguinte = anterior->next();
        } else {
            seguinte = _inicio;
        }
        novo = new Node<Tipo_info>(x, seguinte);
        if (posicao == 0) {
            _inicio = novo;
        } else {
            anterior->next(novo);
        }
        _quantidade_lista++;
        return Codigo_erro::sucesso;
    }

    Node<Tipo_info>* node(long posicao) {
        return set_position(posicao);
    }

    virtual Node<Tipo_info>* prev(Node<Tipo_info>* node) {
        if (node == nullptr) {
            return nullptr;
        }
        Node<Tipo_info> *ptrpos = _inicio;
        if (node == _inicio) {
            return nullptr;
        }
        for (long k = 0; k < _quantidade_lista; k++) {
            if (ptrpos->next() == node) {
                break;
            }
            ptrpos = ptrpos->next();
        }
        return ptrpos;
    }

    Node<Tipo_info>* next(Node<Tipo_info>* node) {
        return node->next();
    }

    Codigo_erro push_front(const Tipo_info& x) {
        return insere(0, x);
    }

    Codigo_erro push_back(const Tipo_info& x) {
        return insere(_quantidade_lista, x);
    }

    Codigo_erro pop_front(Tipo_info& x) {
        return remove(0L, x);
    }

    Codigo_erro pop_back(Tipo_info& x) {
        return remove(_quantidade_lista - 1, x);
    }
private:
    /**
     * Pre:  posicao é uma posição válida na lista; 0 <= posicao < _quantidade_lista.
     * Pos:  Retorna um ponteiro para o Nó na posição.
     */
    Node<Tipo_info>* set_position(long pos) {
        if (fora_intervalo(pos)) {
            return nullptr;
        }
        Node<Tipo_info> *ptrpos = _inicio;
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

#endif /* LIST_SE_H_ */
