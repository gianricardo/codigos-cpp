/**
 * @file livros.cpp
 * @brief Programa principal do exercício 02 da lista 01.
 *
 * Implementação da função principal do segundo exercício da primeira lista.
 * Nessa função é criado o vetor principal que irá guardar os livros cadastrados.
 *
 *  Created on: Mar 26, 2015
 *      Author: gian
 */

#include "funcoes.h"

/**
 * @fn int main()
 * @brief Função principal do programa.
 *
 * @return Status de fim do programa.
 */
int main() {
	ELivro biblioteca[TOTAL_LIVROS];
	int opcao = 0;
	for (int l = 0; l < TOTAL_LIVROS; l++) {/*Inicializando os códigos com uma constante para um código indefinido.*/
		biblioteca[l].codigo = SEM_CODIGO;
	}

	do {
		opcao = menu();
		acao(biblioteca, opcao);
	} while (opcao != 5);

	return 0;
}

