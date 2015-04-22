/*
 * menu_item.h
 *
 *  Created on: Apr 17, 2015
 *      Author: gian
 */

#ifndef MENU_ITEM_H_
#define MENU_ITEM_H_

#include <string>
#include "agenda.h"

namespace trabalho2 {

class Menu_Item {
public:
	/**
	 * Retorna se p_opcao é igual ao valor da opcao do item de menu.
	 */
	bool comp_opcao(int p_opcao) const;
	std::string textoOpcao() const;
	virtual bool execute(Agenda& p_agenda) const =0;
	virtual bool fim()					   const {return false;}
	virtual ~Menu_Item(){}
	Menu_Item(int op,std::string texto_menu):_opcao(op),_texto_opcao(texto_menu){}
	/**
	 * Retorna o valor de opção do item de menu.
	 *
	 */
	int opcao()const{return _opcao;}
protected:
	void opcao(int op){_opcao=op;}
private:
	int _opcao;
	std::string _texto_opcao;
};

} /* namespace trabalho2 */

#endif /* MENU_ITEM_H_ */
