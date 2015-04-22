/*
 * excluir_menu_item.h
 *
 *  Created on: Apr 20, 2015
 *      Author: gian
 */

#ifndef EXCLUIR_MENU_ITEM_H_
#define EXCLUIR_MENU_ITEM_H_

#include "menu_item.h"

namespace trabalho2 {

class Excluir_Menu_Item: public Menu_Item {
public:
	Excluir_Menu_Item(int p_opcao):Menu_Item(p_opcao,"Excluir um contato."){}
	virtual ~Excluir_Menu_Item();
	bool execute(Agenda& p_agenda) const override;
};

} /* namespace trabalho2 */

#endif /* EXCLUIR_MENU_ITEM_H_ */
