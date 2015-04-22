/*
 * excluir_menu_item.cc
 *
 *  Created on: Apr 20, 2015
 *      Author: gian
 */

#include "excluir_menu_item.h"
#include <iostream>

namespace trabalho2 {

bool Excluir_Menu_Item::execute(Agenda& p_agenda) const {
	std::string nome, confirma;
	std::cout
			<< "Opção de Exclusão de contato.\nInforme o nome para a exclusão: ";
	std::getline(std::cin, nome);
	if (p_agenda.existe_contato(nome)) {
		p_agenda.imprimir_contato(nome);
		std::cout << "Excluir esse contato? (s/n) : ";
		std::cin >> confirma;
		nome = p_agenda.consulta_contato(nome);
		if (confirma == "s" || confirma == "S") {
			if (p_agenda.excluir_contato(nome)) {
				std::cout << ">> Contato excluído!" << std::endl;
			} else {
				std::cout << ">> Não foi possível excluir o contato!"
						<< std::endl;
			}
		}
	} else {
		std::cout << ">> Não foi possível excluir o contato!" << std::endl;
		return false;
	}
	return true;
}

Excluir_Menu_Item::~Excluir_Menu_Item() {
}

} /* namespace trabalho2 */
