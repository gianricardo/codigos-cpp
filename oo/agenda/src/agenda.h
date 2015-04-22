/*
 * agenda.h
 *
 *  Created on: Apr 17, 2015
 *      Author: gian
 */

#ifndef AGENDA_H_
#define AGENDA_H_

#include "contato.h"

namespace trabalho2 {

class Agenda {
public:
	enum class Ordem {NOME,MES};
	Agenda();
	bool incluir_contato(std::string nnome,std::string ntwitter, std::string nfacebook, int ndia, int nmes,long ncelular);
	bool excluir_contato(std::string pnome);
	bool atualizar_contato(Contato::Campo pcampo,std::string nnome,std::string ntwitter, std::string nfacebook, int ndia, int nmes,long ncelular);
	void mostrar_aniversariante_data(int dia, int mes)const;
	void mostrar_aniversariante_mes(int pmes)const;
	void mostrar_aniversariante_letra(char pletra)const;
	void imprimir(Ordem ordem);
	void imprimir_contato(std::string p_nome_inicio);
	std::string consulta_contato(std::string p_nome_inicio);
	bool existe_contato(std::string p_nome_inicio);
	bool carregar_arquivo();
	void salvar_arquivo()const;
private:
	void ordenar_mes();
	void ordenar_nome();
	int procurar_lugar(std::string nnome);
	bool atualiza_contato(std::string nnome,std::string ntwitter, std::string nfacebook, int ndia, int nmes,long ncelular,int posicao);
private:
	static const int QTD_TOTAL=30;
	Contato _contatos[QTD_TOTAL];
	int _quantidade;

};

} /* namespace trabalho2 */

#endif /* AGENDA_H_ */
