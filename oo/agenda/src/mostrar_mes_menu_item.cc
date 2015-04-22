/*
 * mostrar_mes_menu_item.cc
 *
 *  Created on: Apr 20, 2015
 *      Author: gian
 */

#include "mostrar_mes_menu_item.h"

namespace trabalho2 {

Mostrar_Mes_Menu_Item::~Mostrar_Mes_Menu_Item() {
}

bool Mostrar_Mes_Menu_Item::execute(Agenda& p_agenda) const {
	p_agenda.imprimir(Agenda::Ordem::MES);
	return true;
}

} /* namespace trabalho2 */
