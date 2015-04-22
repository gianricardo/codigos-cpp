/*
 * menu.cc
 *
 *  Created on: Apr 17, 2015
 *      Author: gian
 */

#include "menu.h"
#include "cadastrar_menu_item.h"
#include "mostrar_mes_menu_item.h"
#include "sair_menu_item.h"
#include "mostrar_nome_menu_item.h"
#include "excluir_menu_item.h"
#include "alterar_menu_item.h"
#include "consultar_data_menu_item.h"
#include "consultar_letra_menu_item.h"
#include "consultar_mes_menu_item.h"
#include "util.h"
#include <iostream>

namespace trabalho2 {

Menu::Menu() {
	for (int q = 0; q < ITEMS; q++) {
		_items[q] = nullptr;
	}
	_q_items = 0;
	monta();
}

Menu::~Menu() {
	for (int q = 0; q < ITEMS; q++) {
		if (_items[q] != nullptr) {
			delete _items[q];
		}
	}
}

void Menu::mostra() {
	for (Menu_Item* item : _items) {
		if (item != nullptr) {
			std::cout << item->textoOpcao() << "\n";
		}
	}
}

void Menu::adiciona_item(Menu_Item* p_item) {
	_items[_q_items++] = p_item;
}

bool Menu::executa_opcao(Agenda& p_agenda, int p_opcao) {
	bool fimExecucao = false, encontrou = false;
	for (Menu_Item* item : _items) {
		if (item != nullptr) {
			if (item->comp_opcao(p_opcao)) {
				if(!item->execute(p_agenda)){
					std::cout << ">> Erro na execução da opção. <<\n";
				}
				fimExecucao = item->fim();
				encontrou=true;
				break;
			}
		}
	}
	if(!encontrou) {
		std::cout << "== Opção incorreta. Tente Novamente. ==";
	}
	return fimExecucao;
}

void Menu::monta() {
	adiciona_item(new Cadastrar_Menu_Item(_q_items+1));
	adiciona_item(new Excluir_Menu_Item(_q_items+1));
	adiciona_item(new Alterar_Menu_Item(_q_items+1));
	adiciona_item(new Consultar_Data_Menu_Item(_q_items+1));
	adiciona_item(new Consultar_Mes_Menu_Item(_q_items+1));
	adiciona_item(new Consultar_Letra_Menu_Item(_q_items+1));
	adiciona_item(new Mostrar_Mes_Menu_Item(_q_items+1));
	adiciona_item(new Mostrar_Nome_Menu_Item(_q_items+1));
	adiciona_item(new Sair_Menu_Item(_q_items+1));
}

int Menu::consulta_opcao() {
	int opcao_consultada;
	std::cout << "Opcao: ";
	opcao_consultada = Util::ler_int(1,_q_items);
	//std::cin >> opcao_consultada;
	//std::cin.ignore(100,'\n');
	return (opcao_consultada);
}

} /* namespace trabalho2 */
