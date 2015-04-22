/*
 * consultar_mes_menu_item.cc
 *
 *  Created on: Apr 20, 2015
 *      Author: gian
 */

#include "consultar_mes_menu_item.h"
#include "util.h"
#include <iostream>

namespace trabalho2 {

bool Consultar_Mes_Menu_Item::execute(Agenda& p_agenda) const{
	std::string dm;
	int mes;
	std::cout
			<< "\nOpção de consulta de aniversariantes por mes.\nInforme o mes desejado: ";
	//std::getline(std::cin, dm);
	mes = Util::ler_int(1,12);
	std::cout << "Aniversariantes para o mes " << mes << std::endl;
	p_agenda.mostrar_aniversariante_mes(mes);
	//std::cout << ">> Final " << std::endl;
	return true;
}

Consultar_Mes_Menu_Item::~Consultar_Mes_Menu_Item() {
}

} /* namespace trabalho2 */
