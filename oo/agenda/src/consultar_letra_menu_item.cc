/*
 * consultar_letra_menu_item.cc
 *
 *  Created on: Apr 20, 2015
 *      Author: gian
 */

#include "consultar_letra_menu_item.h"
#include <iostream>

namespace trabalho2 {

bool Consultar_Letra_Menu_Item::execute(Agenda& p_agenda) const{
	std::string dm;
	std::cout
			<< "\nOpção de consulta de aniversariantes por letra inicial.\nInforme a letra inicial: ";
	std::getline(std::cin, dm);
	std::cout << "Aniversariantes para a letra " << dm.at(0) << std::endl;
	p_agenda.mostrar_aniversariante_letra(dm.at(0));
	//std::cout << ">> Final " << std::endl;
	return true;
}

Consultar_Letra_Menu_Item::~Consultar_Letra_Menu_Item() {
}

} /* namespace trabalho2 */
