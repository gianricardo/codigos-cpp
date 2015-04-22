/*
 * alterar_menu_item.h
 *
 *  Created on: Apr 20, 2015
 *      Author: gian
 */

#ifndef ALTERAR_MENU_ITEM_H_
#define ALTERAR_MENU_ITEM_H_

#include "menu_item.h"

namespace trabalho2 {

class Alterar_Menu_Item: public Menu_Item {
public:
	Alterar_Menu_Item(int p_opcao):Menu_Item(p_opcao,"Alterar dados a partir do nome."){}//
	bool execute(Agenda& p_agenda) const override;
	virtual ~Alterar_Menu_Item();
};

} /* namespace trabalho2 */

#endif /* ALTERAR_MENU_ITEM_H_ */
