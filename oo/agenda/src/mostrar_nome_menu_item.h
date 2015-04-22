/*
 * mostrar_nome_menu_item.h
 *
 *  Created on: Apr 20, 2015
 *      Author: gian
 */

#ifndef MOSTRAR_NOME_MENU_ITEM_H_
#define MOSTRAR_NOME_MENU_ITEM_H_

#include "menu_item.h"

namespace trabalho2 {

class Mostrar_Nome_Menu_Item: public Menu_Item {
public:
	Mostrar_Nome_Menu_Item(int p_opcao):Menu_Item(p_opcao,"Mostrar toda a agenda ordenada pelo nome."){}
	bool execute(Agenda& p_agenda) const override;
	virtual ~Mostrar_Nome_Menu_Item();
};

} /* namespace trabalho2 */

#endif /* MOSTRAR_NOME_MENU_ITEM_H_ */
