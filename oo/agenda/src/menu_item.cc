/*
 * menu_item.cc
 *
 *  Created on: Apr 17, 2015
 *      Author: gian
 */

#include "menu_item.h"

namespace trabalho2 {

bool Menu_Item::comp_opcao(int p_opcao)const{
	return (p_opcao==_opcao);
}

std::string Menu_Item::textoOpcao()const{
	return std::to_string(opcao())+" - "+_texto_opcao;
}

} /* namespace trabalho2 */
