/*
 * tela.h
 *
 *  Created on: Apr 17, 2015
 *      Author: gian
 */

#ifndef TELA_H_
#define TELA_H_

#include "menu.h"
#include "agenda.h"

namespace trabalho2 {

class Tela {
public:
	Tela();
	//
	void executa();
	//
private:
	Menu _menu;
	Agenda _agenda;
};

} /* namespace trabalho2 */

#endif /* TELA_H_ */
