/*
 * consultar_data_menu_item.h
 *
 *  Created on: Apr 20, 2015
 *      Author: gian
 */

#ifndef CONSULTAR_DATA_MENU_ITEM_H_
#define CONSULTAR_DATA_MENU_ITEM_H_

#include "menu_item.h"

namespace trabalho2 {

class Consultar_Data_Menu_Item: public Menu_Item {
public:
	Consultar_Data_Menu_Item(int p_opcao):Menu_Item(p_opcao,"Consultar aniversariantes de uma data (dia e mês)."){}//
	bool execute(Agenda& p_agenda) const override;
	virtual ~Consultar_Data_Menu_Item();
};

} /* namespace trabalho2 */

#endif /* CONSULTAR_DATA_MENU_ITEM_H_ */
