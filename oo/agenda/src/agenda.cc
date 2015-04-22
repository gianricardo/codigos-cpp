/*
 * agenda.cc
 *
 *  Created on: Apr 17, 2015
 *      Author: gian
 */
#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>

#include "agenda.h"
#include "util.h"

namespace trabalho2 {

Agenda::Agenda() :
		_quantidade(0) {
}

bool Agenda::incluir_contato(std::string nnome, std::string ntwitter,
		std::string nfacebook, int ndia, int nmes, long ncelular) {
	int pos = procurar_lugar(Contato::VAZIO);
	if (atualiza_contato(nnome, ntwitter, nfacebook, ndia, nmes, ncelular,
			pos)) {
		_quantidade++;
		return true;
	}
	return false;
}

bool Agenda::atualiza_contato(std::string nnome, std::string ntwitter,
		std::string nfacebook, int ndia, int nmes, long ncelular, int posicao) {
	if (posicao >= 0 && posicao < 30) {
		_contatos[posicao].nome(nnome);
		_contatos[posicao].twitter(ntwitter);
		_contatos[posicao].facebook(nfacebook);
		_contatos[posicao].dia(ndia);
		_contatos[posicao].mes(nmes);
		_contatos[posicao].celular(ncelular);
		return true;
	}
	return false;
}

int Agenda::procurar_lugar(std::string pnome) {
	int pos = 0;
	for (; pos < QTD_TOTAL; pos++) { //encontra onde tem o mesmo código
		if (_contatos[pos].nome().compare(pnome) == 0) {
			break;
		}
	}
	if (pos >= QTD_TOTAL) {
		return -1;
	} else {
		return pos;
	}
}

bool Agenda::excluir_contato(std::string pnome) {
	int pos = procurar_lugar(pnome);
	if (pos != -1) {
		_contatos[pos].nome(Contato::VAZIO);
		_quantidade--;
		return true;
	}
	return false;
}

bool Agenda::atualizar_contato(Contato::Campo pcampo, std::string nnome,
		std::string ntwitter, std::string nfacebook, int ndia, int nmes,
		long ncelular) {
	int pos = procurar_lugar(nnome);
	bool sucesso = false;
	if (pos != -1) {
		switch (pcampo) {
		case Contato::Campo::NOME: {
			_contatos[pos].nome(nnome);
			sucesso = true;
			break;
		}
		case Contato::Campo::TWITTER: {
			_contatos[pos].twitter(ntwitter);
			sucesso = true;
			break;
		}
		case Contato::Campo::FACEBOOK: {
			_contatos[pos].facebook(nfacebook);
			sucesso = true;
			break;
		}
		case Contato::Campo::DIA: {
			_contatos[pos].dia(ndia);
			sucesso = true;
			break;
		}
		case Contato::Campo::MES: {
			_contatos[pos].mes(nmes);
			sucesso = true;
			break;
		}
		case Contato::Campo::CELULAR: {
			_contatos[pos].celular(ncelular);
			sucesso = true;
			break;
		}
		}

	}
	return sucesso;
}

void Agenda::mostrar_aniversariante_data(int pdia, int pmes) const {
	Data_Aniversario da(pdia, pmes);
	for (Contato contato : _contatos) {
		if (contato.nome().compare(Contato::VAZIO) != 0) { //não vazio
			if (contato.aniversario() == da) { //se a data for igual imprime na tela
				std::cout << "Contato: " << contato.to_string();
			}
		}
	}
}

void Agenda::mostrar_aniversariante_mes(int pmes) const {
	for (Contato contato : _contatos) {
		if (contato.nome().compare(Contato::VAZIO) != 0) { //não vazio
			if (contato.mes() == pmes) { //se a data for igual imprime na tela
				std::cout << "Contato: " << contato.to_string();
			}
		}
	}
}

void Agenda::mostrar_aniversariante_letra(char pletra) const {
	for (Contato contato : _contatos) {
		if (contato.nome().compare(Contato::VAZIO) != 0) { //não vazio
			if (contato.nome().at(0) == pletra) { //se a data for igual imprime na tela
				std::cout << "Contato: " << contato.to_string();
			}
		}
	}
}

void Agenda::imprimir(Ordem ordem) {
	if (ordem == Ordem::MES) {
		ordenar_mes();
	} else {
		ordenar_nome();
	}
	for (Contato contato : _contatos) {
		if (contato.nome().compare(Contato::VAZIO) != 0) { //não vazio
			std::cout << "Contato: " << contato.to_string();
		}
	}
}

void Agenda::imprimir_contato(std::string p_nome_inicio) {
	std::string::size_type local;
	for (Contato contato : _contatos) {
		if (contato.nome().compare(Contato::VAZIO) != 0) { //não vazio
			local = contato.nome().find(p_nome_inicio);
			if ((local != std::string::npos) && (local == 0)) { //
				std::cout << "Contato: " << contato.to_string();
				break;
			}
		}
	}
}

std::string Agenda::consulta_contato(std::string p_nome_inicio) {
	std::string::size_type local;
	for (Contato contato : _contatos) {
		if (contato.nome().compare(Contato::VAZIO) != 0) { //não vazio
			local = contato.nome().find(p_nome_inicio);
			if ((local != std::string::npos) && (local == 0)) { //
				return contato.nome();
			}
		}
	}
	return p_nome_inicio;
}

bool Agenda::existe_contato(std::string p_nome_inicio) {
	std::string::size_type local;
	for (Contato contato : _contatos) {
		if (contato.nome().compare(Contato::VAZIO) != 0) { //não vazio
			local = contato.nome().find(p_nome_inicio);
			if ((local != std::string::npos) && (local == 0)) { //
				return true;
			}
		}
	}
	return false;
}
void Agenda::ordenar_mes() {
	Contato tmp;
	for (int atual = 0; atual < QTD_TOTAL - 1; atual++) {
		for (int proximo = atual + 1; proximo < QTD_TOTAL; proximo++) {
			if (_contatos[atual].mes() > _contatos[proximo].mes()) { //se for menor realiza a troca
				tmp.nome(_contatos[atual].nome());
				tmp.twitter(_contatos[atual].twitter());
				tmp.facebook(_contatos[atual].facebook());
				tmp.celular(_contatos[atual].celular());
				tmp.dia(_contatos[atual].dia());
				tmp.mes(_contatos[atual].mes());
				//
				atualiza_contato(_contatos[proximo].nome(),
						_contatos[proximo].twitter(),
						_contatos[proximo].facebook(), _contatos[proximo].dia(),
						_contatos[proximo].mes(), _contatos[proximo].celular(),
						atual);
				//
				atualiza_contato(tmp.nome(), tmp.twitter(), tmp.facebook(),
						tmp.dia(), tmp.mes(), tmp.celular(), proximo);
			}
		}
	}
}

void Agenda::ordenar_nome() {
	Contato tmp;
	for (int atual = 0; atual < QTD_TOTAL - 1; atual++) {
		for (int proximo = atual + 1; proximo < QTD_TOTAL; proximo++) {
			if (_contatos[atual].nome() > _contatos[proximo].nome()) { //se for menor realiza a troca
				tmp.nome(_contatos[atual].nome());
				tmp.twitter(_contatos[atual].twitter());
				tmp.facebook(_contatos[atual].facebook());
				tmp.celular(_contatos[atual].celular());
				tmp.dia(_contatos[atual].dia());
				tmp.mes(_contatos[atual].mes());
				//
				atualiza_contato(_contatos[proximo].nome(),
						_contatos[proximo].twitter(),
						_contatos[proximo].facebook(), _contatos[proximo].dia(),
						_contatos[proximo].mes(), _contatos[proximo].celular(),
						atual);
				//
				atualiza_contato(tmp.nome(), tmp.twitter(), tmp.facebook(),
						tmp.dia(), tmp.mes(), tmp.celular(), proximo);
			}
		}
	}
}

bool Agenda::carregar_arquivo() {
	std::ifstream arq_le("agenda.txt");
	int qtd;
	std::string linha, *partes;
	int dia, mes;
	long celular;
	if (arq_le.is_open()) {
		arq_le >> qtd;
		std::getline(arq_le, linha);//para ler o final de linha
		for (int l = 0; l < qtd; l++) {
			std::getline(arq_le, linha);
			partes = Util::separa(linha, ";", 6);
			dia = std::stoi(partes[3]);
			mes = std::stoi(partes[4]);
			celular = std::stol(partes[5]);
			incluir_contato(partes[0],partes[1],partes[2],dia,mes,celular);
			delete []partes;
		}
		arq_le.close();
		return true;
	}
	return false;
}

void Agenda::salvar_arquivo() const {
	std::ofstream arq_saida("agenda.txt");
	if (arq_saida.is_open()) {
		arq_saida << _quantidade << std::endl;
		for (Contato contato : _contatos) {
			if (contato.nome().compare(Contato::VAZIO) != 0) { //não vazio
				arq_saida << contato.nome() << ";" << contato.twitter() << ";"
						<< contato.facebook() << ";" << contato.dia() << ";"
						<< contato.mes() << ";" << contato.celular()
						<< std::endl;
			}
		}
		arq_saida.flush();
		arq_saida.close();
	}
}

} /* namespace trabalho2 */
