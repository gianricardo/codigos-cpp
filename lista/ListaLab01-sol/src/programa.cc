/*
 * programa.cc
 *
 *  Created on: May 22, 2015
 *      Author: gian
 */

#include <iostream>
#include <iomanip>
#include "list-se.h"
#include "visitor.h"

class VisitorOut : public Visitor<int>{
public:
    virtual ~VisitorOut(){}
    void visit(int w){
        std::cout << std::setw(4) << w;
    }
};

int main(int argc, char **argv) {

    ListaSE<int> lista1;
    VisitorOut vo;
    int removido;
    std::cout << "Listas" << std::endl;
    lista1.insere(0,1);
    lista1.insere(1,2);
    lista1.insere(2,3);
    lista1.insere(3,4);
    lista1.traverse(vo);
    lista1.pop_back(removido);
    std::cout <<std::endl << removido << std::endl;
    //lista1.clear();
    //std::cout << "\nApagou" << std::endl;
    lista1.traverse(vo);
}

//todo SE com ref no inicio
//todo SE com ref no inicio e no fim
//todo SE com ref para uma posição corrente e no inicio e fim
//todo DE com ref no inicio
//todo DE com ref no inicio e no fim
//todo DE com ref para uma posição corrente e no inicio e fim
//todo SE-Circular com ref para uma posição corrente e no inicio e fim
//todo DE-Circular com ref para uma posição corrente e no inicio e fim

