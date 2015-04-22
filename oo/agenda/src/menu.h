/*
 * menu.h
 *
 *  Created on: Apr 17, 2015
 *      Author: gian
 */

#ifndef MENU_H_
#define MENU_H_

#include "menu_item.h"

namespace trabalho2 {

class Menu {
public:
	Menu();
	~Menu();
	//
	void mostra();
	int consulta_opcao();
	bool executa_opcao(Agenda& p_agenda, int p_opcao);
	//
	static const int ITEMS=10;
private:
	void monta();
	void adiciona_item(Menu_Item* p_item);
	int _q_items;
	Menu_Item* _items[ITEMS];
};

} /* namespace trabalho2 */

#endif /* MENU_H_ */
