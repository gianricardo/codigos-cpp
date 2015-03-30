/**
 * @file livros.cpp
 * @brief Programa principal do exercício 02 da lista 01.
 *
 * Enunciado:
 *
 * Implemente uma estrutura para descrever os livros de uma biblioteca. A estrutura deverá conter os
 * seguintes campos: título (string de tamanho 30), autor (string de tamanho 25), área (string de
 * tamanho 15), código (inteiro de dois digitos) e estado de empréstimo ( 0=disponível, 1=emprestado).
 * Implemente um programa com uma função de cadastro de livros, uma de consulta de livros (pode ser
 * pelo código!), uma de empréstimo de livros e outra de devolução de livros. A biblioteca poderá
 * conter até 50 livros.
 * O que você deseja fazer:
 * -# Cadastrar um livro?
 * -# Consultar um titulo?
 * -# Empréstimo de livro?
 * -# Devolução de livro?
 * -# Sair
 *
 * <HR>
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

