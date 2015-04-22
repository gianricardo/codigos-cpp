/*
 * contato.h
 *
 *  Created on: Apr 17, 2015
 *      Author: gian
 */

#ifndef CONTATO_H_
#define CONTATO_H_

#include <string>
#include "data_aniversario.h"

namespace trabalho2 {

class Contato {
public:
	Contato();
	Contato(std::string nnome,std::string ntwitter, std::string nfacebook, int ndia, int nmes,long ncelular);
	//gets
	std::string nome()const;
	std::string twitter()const;
	std::string facebook()const;
	int dia()const;
	int mes()const;
	long celular()const;
	Data_Aniversario& aniversario();
	//sets
	void nome(std::string nnome);
	void twitter(std::string ntwitter);
	void facebook(std::string nfacebook);
	void dia(int ndia);
	void mes(int nmes);
	void celular(long ncelular);
	//outros
	std::string to_string();
	//constantes
	//static constexpr const char* VAZIO = "--"; //outro modo de criar uma constante
	static const std::string VAZIO;
	enum class Campo {NOME,TWITTER,FACEBOOK, DIA, MES, CELULAR};
private:
	std::string _nome,_twitter,_facebook;
	Data_Aniversario _dia_aniversario;
	long _celular;

};

} /* namespace trabalho2 */

#endif /* CONTATO_H_ */
