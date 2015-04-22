/*
 * Util.cc
 *
 *  Created on: Apr 20, 2015
 *      Author: gian
 */

#include <iostream>
#include <stdexcept>
#include "util.h"

namespace trabalho2 {

std::string Util::tolower(std::string p_st) {
	std::string lower;
	for (char c : p_st) {
		lower += std::tolower(c);
	}
	return lower;
}

std::string* Util::separa(std::string p_st, std::string separador, int qtd) {
	std::string *partes;
	int pos=0;
	partes = new std::string[qtd];
	p_st+=";";
	auto start = 0U;
	auto end = p_st.find(separador);
	while (end != std::string::npos) {
		partes[pos++]=p_st.substr(start, end - start);
		start = end + separador.length();
		end = p_st.find(separador, start);
	}
	return partes;
}

int Util::ler_int(int limite_inf,int limite_sup){
	int lido,lido_x=limite_inf-1;
	std::string texto_lido;
	std::getline(std::cin, texto_lido);
	try {
		lido = std::stoi(texto_lido);
	} catch (std::invalid_argument e) {	lido = lido_x;}
	if(limite_inf!=0 && limite_sup!=0){
		while(limite_inf>lido||limite_sup<lido){//fora do limite
			std::cout << "Valor fora do limite ["<<limite_inf<<","<<limite_sup<<"] !\nInforme o valor novamente: ";
			std::getline(std::cin, texto_lido);
			try {
				lido = std::stoi(texto_lido);
			} catch (std::invalid_argument e) {	lido = lido_x;}
		}
	}
	return lido;
}

long Util::ler_long(int limite_inf,int limite_sup){
	long lido,lido_x=limite_inf-1;
	std::string texto_lido;
	std::getline(std::cin, texto_lido);
	try {
		lido = std::stol(texto_lido);
	} catch (std::invalid_argument e) {	lido = lido_x;}
	if(limite_inf!=0 && limite_sup!=0){
		while(limite_inf>lido||limite_sup<lido){//fora do limite
			std::cout << "Valor fora do limite ["<<limite_inf<<","<<limite_sup<<"] !\nInforme o valor novamente: ";
			std::getline(std::cin, texto_lido);
			try {
				lido = std::stol(texto_lido);
			} catch (std::invalid_argument e) {	lido = lido_x;}
		}
	}
	return lido;
}

} /* namespace trabalho2 */
