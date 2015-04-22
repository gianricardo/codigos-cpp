/*
 * cadastrar_menu_item.h
 *
 *  Created on: Apr 17, 2015
 *      Author: gian
 */

#ifndef CADASTRAR_MENU_ITEM_H_
#define CADASTRAR_MENU_ITEM_H_

#include "menu_item.h"

namespace trabalho2 {

class Cadastrar_Menu_Item: public Menu_Item {
public:
	Cadastrar_Menu_Item(int p_opcao);
	bool execute(Agenda& p_agenda) const override;
	virtual ~Cadastrar_Menu_Item(){}
};

} /* namespace trabalho2 */

#endif /* CADASTRAR_MENU_ITEM_H_ */
