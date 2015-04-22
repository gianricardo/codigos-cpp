/*
 * sair_menu_item.cc
 *
 *  Created on: Apr 19, 2015
 *      Author: gian
 */

#include "sair_menu_item.h"

namespace trabalho2 {

Sair_Menu_Item::Sair_Menu_Item(int op): Menu_Item(op,"Sair.") {
}

Sair_Menu_Item::~Sair_Menu_Item() {
}

bool Sair_Menu_Item::execute(Agenda& p_agenda) const{
	return true;
}

} /* namespace trabalho2 */
