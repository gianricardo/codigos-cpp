/*
 * carro.cc
 *
 *  Created on: May 21, 2015
 *      Author: gian
 */

#include "carro.h"


Carro::Carro() {
    _placa="";
    _manobras=0;
}

Carro::~Carro() {
}

Carro::Carro(std::string placa):_placa(placa){
    _manobras=0;
}
std::string Carro::placa(void)const{
    return _placa;
}
void Carro::manobrou(void){
    _manobras++;
}

int Carro::manobras(void)const{
    return _manobras;
}


