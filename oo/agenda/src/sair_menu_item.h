/*
 * sair_menu_item.h
 *
 *  Created on: Apr 19, 2015
 *      Author: gian
 */

#ifndef SAIR_MENU_ITEM_H_
#define SAIR_MENU_ITEM_H_

#include "menu_item.h"

namespace trabalho2 {

class Sair_Menu_Item: public Menu_Item {
public:
	Sair_Menu_Item(int op);
	virtual ~Sair_Menu_Item();
	bool execute(Agenda& p_agenda) const override;
	bool fim()					   const override{return true;}
};

} /* namespace trabalho2 */

#endif /* SAIR_MENU_ITEM_H_ */
