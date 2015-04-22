/*
 * cadastrar_menu_item.cc
 *
 *  Created on: Apr 17, 2015
 *      Author: gian
 */

#include <iostream>
#include "cadastrar_menu_item.h"
#include "util.h"

namespace trabalho2 {

Cadastrar_Menu_Item::Cadastrar_Menu_Item(int p_opcao):Menu_Item(p_opcao,"Cadastrar um novo contato.") {
}

/*
std::string Cadastrar_Menu_Item::textoOpcao()const{
	return std::to_string(opcao())+" - Cadastrar um novo contato.";
}*/

bool Cadastrar_Menu_Item::execute(Agenda& p_agenda) const{
	std::string nome,twitter,facebook;
	int dia=0,mes=0;
	long celular=0;
	std::cout << "                CADASTRO                       "	<< std::endl;
	std::cout << "==============================================="	<< std::endl;
	//
	std::cout << "Nome     : ";
	std::getline(std::cin, nome);
	std::cout << "Twitter  : ";
	std::getline(std::cin, twitter);
	std::cout << "Facebook : ";
	std::getline(std::cin, facebook);
	std::cout << "Dia do aniversario : ";
	dia=Util::ler_int(1,31);
	std::cout << "Mes do aniversario : ";
	mes=Util::ler_int(1,12);
	std::cout << "Celular (apenas numeros) : ";
	celular=Util::ler_long();
	//
	std::cout << "==============================================="  << std::endl;

	return p_agenda.incluir_contato(nome,twitter,facebook,dia,mes,celular);
}


} /* namespace trabalho2 */
