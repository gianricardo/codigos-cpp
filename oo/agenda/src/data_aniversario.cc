/*
 * data_aniversario.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: gian
 */

#include "data_aniversario.h"

namespace trabalho2 {

Data_Aniversario::Data_Aniversario():_dia(0),_mes(0) {
}

Data_Aniversario::Data_Aniversario(int ddia, int mmes):_dia(ddia),_mes(mmes){
}

bool Data_Aniversario::operator==(Data_Aniversario const& outra) const {
	return ((_dia==outra.dia())&&(_mes==outra.mes()));
}

int Data_Aniversario::dia() const {
	return _dia;
}

void Data_Aniversario::dia(int ndia){
	_dia=ndia;
}

int Data_Aniversario::mes() const {
	return _mes;
}

void Data_Aniversario::mes(int nmes){
	_mes=nmes;
}

} /* namespace trabalho2 */
