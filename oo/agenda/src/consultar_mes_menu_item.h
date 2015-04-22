/*
 * consultar_mes_menu_item.h
 *
 *  Created on: Apr 20, 2015
 *      Author: gian
 */

#ifndef CONSULTAR_MES_MENU_ITEM_H_
#define CONSULTAR_MES_MENU_ITEM_H_

#include "menu_item.h"

namespace trabalho2 {

class Consultar_Mes_Menu_Item: public Menu_Item {
public:
	Consultar_Mes_Menu_Item(int p_opcao):Menu_Item(p_opcao,"Consultar aniversariantes por mês."){}//
	bool execute(Agenda& p_agenda) const override;
	virtual ~Consultar_Mes_Menu_Item();
};

} /* namespace trabalho2 */

#endif /* CONSULTAR_MES_MENU_ITEM_H_ */
