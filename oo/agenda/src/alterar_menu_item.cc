/*
 * alterar_menu_item.cc
 *
 *  Created on: Apr 20, 2015
 *      Author: gian
 */

#include "alterar_menu_item.h"
#include <iostream>
#include "util.h"

namespace trabalho2 {

bool Alterar_Menu_Item::execute(Agenda& p_agenda) const {
	std::string nome, confirma;
	std::cout
			<< "Opção de alteração de contato.\nInforme o nome para a alteração: ";
	std::getline(std::cin, nome);
	if (p_agenda.existe_contato(nome)) {
		p_agenda.imprimir_contato(nome);
		std::cout << "Alterar esse contato? (s/n) : ";
		std::cin >> confirma;
		nome = p_agenda.consulta_contato(nome);
		confirma = Util::tolower(confirma);
		if (confirma == "s") {
			std::string escolha, twitter, facebook;
			int dia=0, mes=0;
			long celular=0;
			Contato::Campo tipo_alteracao = Contato::Campo::CELULAR;
			std::cout
					<< "O que deseja alterar?\n- (T)witter\n- (F)acebook\n- (D)ia do aniversário\n- (M)es do aniversario\n- (C)elular\nEscolha: ";
			std::cin >> escolha;
			std::cin.ignore(100,'\n');
			escolha = Util::tolower(escolha);
			if (escolha == "t") {
				std::cout << "Qual novo twitter: ";
				std::getline(std::cin, twitter);
				tipo_alteracao = Contato::Campo::TWITTER;
			} else if (escolha == "f") {
				std::cout << "Qual novo facebook: ";
				std::getline(std::cin, facebook);
				tipo_alteracao = Contato::Campo::FACEBOOK;
			} else if (escolha == "d") {
				std::cout << "Qual novo dia: ";
				dia=Util::ler_int(1,31);
				tipo_alteracao = Contato::Campo::DIA;
			} else if (escolha == "m") {
				std::cout << "Qual novo mes: ";
				mes=Util::ler_int(1,12);
				tipo_alteracao = Contato::Campo::MES;
			} else {
				std::cout << "Qual novo celular (apenas numeros): ";
				celular=Util::ler_long();
				tipo_alteracao = Contato::Campo::CELULAR;
			}
			if (p_agenda.atualizar_contato(tipo_alteracao,nome,twitter, facebook,dia,mes,celular)) {
				std::cout << ">> Contato alterado!" << std::endl;
			} else {
				std::cout << ">> Não foi possível alterar o contato!"
						<< std::endl;
			}
		}
	} else {
		std::cout << ">> Não foi possível alterar o contato!" << std::endl;
		return false;
	}
	return true;
}

Alterar_Menu_Item::~Alterar_Menu_Item() {
}

} /* namespace trabalho2 */
