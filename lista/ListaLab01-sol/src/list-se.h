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
class ListaSE
{
    Node<Tipo_info> *_inicio; //referencia para o nó que inicia a lista
    long _quantidade_lista;  //quantidade de nós na lista
public:
    ListaSE() {
        _quantidade_lista=(0);
        _inicio=(nullptr);
    }
    ~ListaSE() {
        clear();
    }
    /**
     * Pós-condição: returna a quantidade de nós/entradas/células presente na lista.
     */
    long tamanho() const {
        return _quantidade_lista;
    }
    /**
     * Pós-condição: retorna verdadeiro se a lista está vazia, caso contrário, retorna falso.
     * @return o estado da lista
     */
    bool empty() const {
        return (_quantidade_lista==0 && _inicio==nullptr);
    }
    /**
     * Pós-condição: Todos os nós da lista devem ser removidos. A lista está vazia.
     *
     */
    void clear() {
        Node<Tipo_info> *ptrpos=_inicio;
        for(long k=0; k<_quantidade_lista; k++) {
            Node<Tipo_info> *temp=ptrpos;
            ptrpos=ptrpos->next();
            delete temp;
        }
        _inicio=nullptr;
        _quantidade_lista=0;
    }
    /**
     * Pós-condição: A ação especificada pela função *visit foi realizada em cada Nó da lista.
     * Comçou na posição 0 da lista e seguiu até o final dela, em ordem.
     *
     * @param visit ponteiro para uma função
     */
    void traverse(void (*visit)(Tipo_info)) {
        Node<Tipo_info> *tra=_inicio;
        for(long  k=0; k<_quantidade_lista; k++) {
            (*visit)(tra->info());
            tra=tra->next();
        }
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
    Codigo_erro busca(long posicao, Tipo_info &x) const {
        if(fora_intervalo(posicao)) {
            return Codigo_erro::erro_intervalo;
        }
        Node<Tipo_info> *no_p;
        no_p=set_position(posicao);
        x=no_p->info();
        return Codigo_erro::sucesso;
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
    Codigo_erro substitui(long posicao, const Tipo_info &x) {
        if(fora_intervalo(posicao)) {
            return Codigo_erro::erro_intervalo;
        }
        Node<Tipo_info> *no_p;
        no_p=set_position(posicao);
        no_p->info(x);
        return Codigo_erro::sucesso;
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
    Codigo_erro remove(long posicao, Tipo_info &x) {
        if(fora_intervalo(posicao)) {
            return Codigo_erro::erro_intervalo;
        }
        Node<Tipo_info> *excluido,*anterior=nullptr,*seguinte;
        if(posicao>0) {
            anterior=set_position(posicao-1);
            excluido=anterior->next();
        } else {
            excluido=_inicio;
        }
        seguinte=excluido->next();
        if(posicao==0) {
            _inicio=seguinte;
        } else {
            anterior->next(seguinte);
        }
        x=excluido->info();
        _quantidade_lista--;
        delete excluido;
        return Codigo_erro::sucesso;
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
        Node<Tipo_info> *excluido,*anterior=nullptr;//,*seguinte;
        anterior=_inicio;
        long count_ex=0;
        //seguinte=anterior->next();
        while(anterior!=nullptr){
            excluido=anterior;
            anterior=anterior->next();
            if(excluido->info()==x){
                if(excluido==_inicio){
                    _inicio=anterior;
                }
                count_ex++;
                delete excluido;
            }
            //seguinte=anterior->next();
        }

        x=excluido->info();
        _quantidade_lista--;
        delete excluido;
        return Codigo_erro::sucesso;
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
    Codigo_erro insere(long posicao,const Tipo_info& x) {
        if(fora_intervalo(posicao)) {
            return Codigo_erro::erro_intervalo;
        }
        Node<Tipo_info> *novo,*anterior=nullptr,*seguinte;
        if(posicao>0) {
            anterior=set_position(posicao-1);
            seguinte=anterior->next();
        } else {
            seguinte=_inicio;
        }
        novo = new Node<Tipo_info>(x,seguinte);
        if(posicao==0) {
            _inicio=novo;
        } else {
            anterior->next(novo);
        }
        _quantidade_lista++;
        return Codigo_erro::sucesso;
    }
    /**
     * Pre:  posicao é uma posição válida na lista; 0 <= posicao < _quantidade_lista.
     * Pos:  Returna um ponteiro para o Nó na posição ou nullptr caso contrário.
     *
     * @param posicao uma posição na lista
     * @return um ponteiro para o nó ou nulo se não estiver na lista.
     */
    Node<Tipo_info>* node(long posicao) {
        return set_position(posicao);
    }
    /**
     * Retorna o nó anterior ao node.
     *
     * @param node ponteiro válido para um nó da lista
     * @return um ponteiro para o anterior ou nullptr caso não seja possível encontrá-lo.
     */
    Node<Tipo_info>* prev(Node<Tipo_info>* node) {
        if(node==nullptr){
            return nullptr;
        }
        Node<Tipo_info> *ptrpos=_inicio;
        if(node==_inicio){
            return nullptr;
        }
        for(long k=0; k<_quantidade_lista; k++) {
            if(ptrpos->next()==node){
                break;
            }
            ptrpos=ptrpos->next();
        }
        return ptrpos;
    }

    /**
     * Retorna o nó seguinte ao node.
     *
     * @param node ponteiro válido para um nó da lista
     * @return um ponteiro para o seguinte ou nullptr caso não seja possível encontrá-lo.
     */
    Node<Tipo_info>* next(Node<Tipo_info>* node) {
        return node->next();
    }

    Codigo_erro push_front(const Tipo_info& x){
        return insere(0,x);
    }

    Codigo_erro push_back(const Tipo_info& x){
        return insere(_quantidade_lista,x);
    }

    Codigo_erro pop_front(Tipo_info& x){
        return remove(0L,x);
    }

    Codigo_erro pop_back(Tipo_info& x){
        return remove(_quantidade_lista-1,x);
    }
protected:
    /**
     * Pre:  posicao é uma posição válida na lista; 0 <= posicao < _quantidade_lista.
     * Pos:  Retorna um ponteiro para o Nó na posição.
     */
    Node<Tipo_info>* set_position(long pos) const {
        if(fora_intervalo(pos)) {
            return nullptr;
        }
        Node<Tipo_info> *ptrpos=_inicio;
        for(long k=0; k<pos; k++) {
            ptrpos=ptrpos->next();
        }
        return ptrpos;
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
    bool fora_intervalo(long posicao) const {
        return ((posicao < 0) || (posicao > _quantidade_lista));
    }
};

#endif /* LIST_SE_H_ */
