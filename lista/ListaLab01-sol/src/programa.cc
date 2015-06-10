/*
 * programa.cc
 *
 *  Created on: May 22, 2015
 *      Author: gian
 */

#include <iostream>
#include <iomanip>
#include "list-de.h"
#include "list-se.h"
#include "list-se-fim.h"
#include "list-se-cur.h"
#include "list-sec.h"
#include "visitor.h"

class VisitorOut : public Visitor<int>{
public:
    virtual ~VisitorOut(){}
    void visit(int w){
        std::cout << std::setw(4) << w;
    }
};

int main(int argc, char **argv) {

    IList<int>* lista1;
    lista1 = new ListaSEC<int>();
    VisitorOut vo;
    int removido;
    std::cout << "Listas" << std::endl;
    lista1->insere(0,1);std::cout << "  " << lista1->tamanho() << std::endl;
    lista1->insere(0,1);std::cout << "  " << lista1->tamanho() << std::endl;
    lista1->insere(2,2);std::cout << "  " << lista1->tamanho() << std::endl;
    lista1->insere(3,3);std::cout << "  " << lista1->tamanho() << std::endl;
    lista1->insere(4,4);std::cout << "  " << lista1->tamanho() << std::endl;
    lista1->insere(4,1);std::cout << "  " << lista1->tamanho() << std::endl;
    lista1->traverse(vo);
    lista1->pop_back(removido);
    lista1->remove(5);
    std::cout <<std::endl << removido << std::endl;
    //lista1.clear();
    //std::cout << "\nApagou" << std::endl;
    lista1->traverse(vo); std::cout<< "\nantes remove 3"  << " : tam= " << lista1->tamanho()<<std::endl ;
    lista1->remove(3);
    lista1->traverse(vo); std::cout<< "\ndepois remove 3" << " : tam= " << lista1->tamanho() <<std::endl ;
    lista1->remove(1);
    lista1->traverse(vo); std::cout<< "\ndepois remove 1" << " : tam= " << lista1->tamanho() <<std::endl ;
    lista1->remove(2);
    lista1->traverse(vo); std::cout<< "\ndepois remove 2"  << " : tam= " << lista1->tamanho()<<std::endl ;
    delete lista1;
}

