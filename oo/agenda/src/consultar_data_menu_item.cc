/*
 * consultar_data_menu_item.cc
 *
 *  Created on: Apr 20, 2015
 *      Author: gian
 */

#include "consultar_data_menu_item.h"
#include <iostream>

namespace trabalho2 {

bool Consultar_Data_Menu_Item::execute(Agenda& p_agenda) const {
	std::string dm;
	int dia, mes;
	std::cout
			<< "\nOpção de consulta de aniversariantes por dia e mes.\nInforme o dia e o mes (dd/mm): ";
	std::getline(std::cin, dm, '/');
	dia = std::stoi(dm);
	std::getline(std::cin, dm);
	mes = std::stoi(dm);
	std::cout << "Aniversariantes para o " << dia << "/" << mes << std::endl;
	p_agenda.mostrar_aniversariante_data(dia, mes);
	return true;
}

Consultar_Data_Menu_Item::~Consultar_Data_Menu_Item() {
}

} /* namespace trabalho2 */
