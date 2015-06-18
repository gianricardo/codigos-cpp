#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
#include "codigo_erro.h"
#include "noarv.h"
#include "visitor.h"

template<class TStorage>
class Arvore {
public:
//    enum ORDEM {
//        PRE, IN, POS
//    };
    Arvore() {
        _raiz = nullptr;
    }
    virtual ~Arvore() {
        destruir(_raiz);
        _raiz = nullptr;
    }
    Codigo_erro add(TStorage n) {
        bool achou;
        NoArv<TStorage> *t, *pai;
        encontrarPai(n, achou, pai);
        if (achou) {
            return Codigo_erro::erro_no_existente;
        } else {
            t = new NoArv<TStorage>(n);

            if (pai == nullptr) {
                _raiz = t;
            } else {
                pai->value() > n ? pai->left(t) : pai->right(t);
            }
        }
        return Codigo_erro::sucesso;

    }

    void caminho(Visitor<TStorage>& visitor) {
        visitor.begin();
        traverse(visitor, _raiz);
        visitor.end();
    }

//    void caminho(Visitor<TStorage>& visitor, ORDEM tipo) {
//        if (tipo == Arvore<TStorage>::IN) {
//            in(visitor, _raiz);
//            std::cout << std::endl;
//        } else if (tipo == Arvore<TStorage>::PRE) {
//            pre(visitor, _raiz);
//            std::cout << std::endl;
//        } else {
//            pos(visitor, _raiz);
//            std::cout << std::endl;
//        }
//    }

    Codigo_erro del(TStorage num) {
        NoArv<TStorage> *pai, *x, *xsucc;
        bool achou;

        // If EMPTY TREE
        if (_raiz == nullptr) {
            //std::cout<<"\nArvore esta vazia!";
            return Codigo_erro::nao_existe;
        }
        pai = x = nullptr;
        encontrarParaApagar(num, achou, pai, x);
        if (!achou) {
            //std::cout<<"\nNo nao encontrado!!";
            return Codigo_erro::no_nao_existe;
        }

        // Se o nó a apagar tiver duas subarvores
        if (x->left() != nullptr && x->right() != nullptr) {
            pai = x;
            xsucc = x->right();

            while (xsucc->left() != nullptr) {
                pai = xsucc;
                xsucc = xsucc->left();
            }
            x->value(xsucc->value());
            x = xsucc;
        }

        // Se o nó a apagar não tiver subarvores
        if (x->left() == nullptr && x->right() == nullptr) {
            if (pai->right() == x) {
                pai->right(nullptr);
            } else {
                pai->left(nullptr);
            }

            delete x;
            return Codigo_erro::sucesso;
        }

        // se o nó apenas tiver subarvore direita
        if (x->left() == nullptr && x->right() != nullptr) {
            if (pai->left() == x) {
                pai->left(x->right());
            } else {
                pai->right(x->right());
            }

            delete x;
            return Codigo_erro::sucesso;
        }

        // se o nó apenas tiver subarvore esquerda
        if (x->left() != nullptr && x->right() == nullptr) {
            if (pai->left() == x) {
                pai->left(x->left());
            } else {
                pai->right(x->left());
            }

            delete x;
            return Codigo_erro::sucesso;
        }
        return Codigo_erro::falha;
    }

//    void print1() {
//        print1pre(_raiz);
//    }
    NoArv<TStorage> * root() {
        return _raiz;
    }
    void insertLeft(NoArv<TStorage> *node, TStorage info) {
        NoArv<TStorage> *novo;
        if (node->left() == nullptr) {
            novo = new NoArv<TStorage>(info);
            node->left(novo);
        }
    }
    void insertRight(NoArv<TStorage> *node, TStorage info) {
        NoArv<TStorage> *novo;
        if (node->right() == nullptr) {
            novo = new NoArv<TStorage>(info);
            node->right(novo);
        }
    }
protected:
private:
//    void print1pre(NoArv<TStorage> *raiz) {
//        std::cout << "(";
//        if (raiz != nullptr) {
//            std::cout << raiz->value();
//        }
//        std::cout << ":";
//        if (raiz != nullptr) {
//            print1pre(raiz->left());
//        }
//        std::cout << ",";
//        if (raiz != nullptr) {
//            print1pre(raiz->right());
//        }
//        std::cout << ")";
//    }
    void traverse(Visitor<TStorage>& visitor, NoArv<TStorage> *raiz) {
        if (raiz != nullptr) {
            visitor.pre(raiz->value());
            traverse(visitor, raiz->left());
            visitor.in(raiz->value());
            traverse(visitor, raiz->right());
            visitor.pos(raiz->value());
        }
    }
//    void in(Visitor<TStorage>& visitor, NoArv<TStorage> *raiz) {
//        if (raiz != nullptr) {
//            in(visitor, raiz->left());
//            visitor.visit(raiz->value());
//            in(visitor, raiz->right());
//        }
//    }
//    void pre(Visitor<TStorage>& visitor, NoArv<TStorage> *raiz) {
//        if (raiz != nullptr) {
//            visitor.visit(raiz->value());
//            pre(visitor, raiz->left());
//            pre(visitor, raiz->right());
//        }
//    }
//    void pos(Visitor<TStorage>& visitor, NoArv<TStorage> *raiz) {
//        if (raiz != nullptr) {
//            pos(visitor, raiz->left());
//            pos(visitor, raiz->right());
//            visitor.visit(raiz->value());
//        }
//    }
    void encontrarPai(TStorage n, bool &encontrou, NoArv<TStorage>* &pai) {
        NoArv<TStorage> *q;
        encontrou = false;
        pai = nullptr;

        if (_raiz == nullptr)
            return;

        q = _raiz;
        while (q != nullptr) {
            if (q->value() == n) {
                encontrou = true;
                return;
            }
            if (q->value() > n) {
                pai = q;
                q = q->left();
            } else {
                pai = q;
                q = q->right();
            }
        }
    }
    void encontrarParaApagar(TStorage n, bool &encontrou, NoArv<TStorage> *&pai, NoArv<TStorage>* &x) {
        NoArv<TStorage> *q;
        encontrou = false;
        pai = nullptr;
        if (_raiz == nullptr)
            return;

        q = _raiz;
        while (q != nullptr) {
            if (q->value() == n) {
                encontrou = true;
                x = q;
                return;
            }
            if (q->value() > n) {
                pai = q;
                q = q->left();
            } else {
                pai = q;
                q = q->right();
            }
        }
    }
    void destruir(NoArv<TStorage> *raiz) {
        if (raiz != nullptr) {
            bool achou;
            NoArv<TStorage> *pai;
            destruir(raiz->left());
            destruir(raiz->right());
            encontrarPai(raiz->value(), achou, pai);
            if (achou) {
                if (pai != nullptr) {
                    if (pai->right() == raiz) {
                        pai->right(nullptr);
                    } else {
                        pai->left(nullptr);
                    }
                }
                delete raiz;
                raiz = nullptr;
            }
        }
    }
    NoArv<TStorage> *_raiz;
};

#endif // ARVORE_H
