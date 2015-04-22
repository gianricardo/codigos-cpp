/*
 * mostrar_mes_menu_item.h
 *
 *  Created on: Apr 20, 2015
 *      Author: gian
 */

#ifndef MOSTRAR_MES_MENU_ITEM_H_
#define MOSTRAR_MES_MENU_ITEM_H_

#include "menu_item.h"

namespace trabalho2 {

class Mostrar_Mes_Menu_Item: public Menu_Item {
public:
	Mostrar_Mes_Menu_Item(int p_opcao):Menu_Item(p_opcao,"Mostrar toda a agenda ordenada por mês."){}
	bool execute(Agenda& p_agenda) const override;
	virtual ~Mostrar_Mes_Menu_Item();

};

} /* namespace trabalho2 */

#endif /* MOSTRAR_MES_MENU_ITEM_H_ */
