/*
 * mostrar_nome_menu_item.cc
 *
 *  Created on: Apr 20, 2015
 *      Author: gian
 */

#include "mostrar_nome_menu_item.h"

namespace trabalho2 {

bool Mostrar_Nome_Menu_Item::execute(Agenda& p_agenda) const {
	p_agenda.imprimir(Agenda::Ordem::NOME);
	return true;
}

Mostrar_Nome_Menu_Item::~Mostrar_Nome_Menu_Item() {
}

} /* namespace trabalho2 */
