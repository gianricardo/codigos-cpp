/*
 * tela.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: gian
 */

#include "tela.h"
#include <iostream>

namespace trabalho2 {

Tela::Tela() {
}

void Tela::executa() {
	bool fim = false;
	int opcao = 99;
	if (_agenda.carregar_arquivo()) {
		std::cout << ">> Arquivo lido com sucesso!\n";
	} else {
		std::cout << ">> Arquivo não lido.\n";
	}
	do {
		_menu.mostra();
		opcao = _menu.consulta_opcao();
		fim = _menu.executa_opcao(_agenda, opcao);
		if (!fim) {
			std::cout << "========================================="
					<< std::endl << "Aperte ENTER para continuar." << std::endl;
			std::cin.get();
		}
	} while (!fim);
	std::cout << "========================================="
						<< std::endl << "       FIM             " << std::endl;
	_agenda.salvar_arquivo();
}

} /* namespace trabalho2 */
