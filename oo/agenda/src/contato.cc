/*
 * contato.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: gian
 */

#include <sstream>
#include "contato.h"

namespace trabalho2 {

const std::string Contato::VAZIO("--");

Contato::Contato():_nome(VAZIO),_twitter(),_facebook(),_dia_aniversario(),_celular(0){
}

Contato::Contato(std::string nnome,std::string ntwitter, std::string nfacebook, int ndia, int nmes,long ncelular)
:_nome(nnome),_twitter(ntwitter),_facebook(nfacebook),_dia_aniversario(ndia,nmes),_celular(ncelular){
}

//gets
std::string Contato::nome()const{
	return _nome;
}

std::string Contato::twitter()const{
	return _twitter;
}

std::string Contato::facebook()const{
	return _facebook;
}

int Contato::dia()const{
	return _dia_aniversario.dia();
}

int Contato::mes()const{
	return _dia_aniversario.mes();
}

long Contato::celular()const{
	return _celular;
}

Data_Aniversario& Contato::aniversario(){
	return _dia_aniversario;
}

//sets
void Contato::nome(std::string nnome){
	_nome=nnome;
}

void Contato::twitter(std::string ntwitter){
	_twitter=ntwitter;
}

void Contato::facebook(std::string nfacebook){
	_facebook=nfacebook;
}

void Contato::dia(int ndia){
	_dia_aniversario.dia(ndia);
}

void Contato::mes(int nmes){
	_dia_aniversario.mes(nmes);
}

void Contato::celular(long ncelular){
	_celular=ncelular;
}

std::string Contato::to_string(){
	std::stringstream ss;
	ss << _nome << "\t("<< _dia_aniversario.dia()<<"/"<<_dia_aniversario.mes() << ") \n"
		<< "\t T: "<<_twitter<<"\tF: "<<_facebook
		<< "\n\t Celular: "<<_celular<<"\n";
	return ss.str();

}

} /* namespace trabalho2 */
