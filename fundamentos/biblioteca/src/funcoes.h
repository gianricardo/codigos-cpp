/**
 * @file funcoes.h
 * @brief Estrutura e funções disponíveis
 *
 *  Created on: Mar 30, 2015
 *      Author: gian
 */

#ifndef FUNCOES_H_
#define FUNCOES_H_

#include "constantes.h"
#include <iostream>

//definição da estrutura de um livro
/**
 * @struct livro
 * Definição de estrutura de um livro.
 */
struct livro {
	std::string /*! Titulo do livro de tipo @c string. */titulo,
	/*! Autor do livro de tipo @c string. */autor,
	/*! Area do livro de tipo @c string. */area,
	/*! Código do livro de tipo @c string. Ele é gerado automaticamente.*/codigo;
	bool /*! Status do livro de tipo @c booleano.*/emprestado;
};

/**
 *@typedef typedef struct livro ELivro
 *@brief Tipo definido a partir da estrutura de livro.
 */
typedef struct livro ELivro;

//funções disponíveis
/**
 * @fn int menu()
 * @brief Responsável pela apresentação do menu ao usuário.
 *
 * Essa função apresenta ao usuário um menu com as seguintes opções:
 *
 * -# Cadastrar um livro?
 * -# Consultar um titulo?
 * -# Empréstimo de livro?
 * -# Devolução de livro?
 * -# Sair
 *
 * Após solicita ao usuário a opção desejada.
 *
 * @return Opção escolhida pelo usuário.
 */
int menu();

/**
 * @fn void acao(ELivro livros[], int opcao_menu)
 * Função para executar a opção escolhida pelo usuário.
 *
 * @param livros Vetor com os livros disponíveis no programa.
 * @param opcao_menu Opção de @c menu que o usuário escolheu.
 */
void acao(ELivro livros[], int opcao_menu);

/**
 * @fn std::string solicitar_codigo()
 * Função que questiona o usuário para fornecer um código. Esse código será usado para buscar o livro relacionado
 * com ele.
 *
 * @return Código de um livro fornecido pelo usuário.
 */
std::string solicitar_codigo();

/**
 * @fn int procurarLivro(std::string codigoParaProcurar, ELivro livros[])
 * Função que busca no vetor, o livro com o respectivo código fornecido.
 *
 * @param codigoParaProcurar Código de identificação de um livro
 * @param livros Vetor com os livros disponíveis no programa.
 * @return Posição onde encontra-se o livro com o respectivo código. Retorna -1 se não encontrar o livro com o código.
 */
int procurarLivro(std::string codigoParaProcurar, ELivro livros[]);

/**
 * @fn void cadastrar(ELivro livros[])
 * Realiza o cadastro de um livro. Solicita do usuário informações necessárias para cadastrar um livro no programa.
 * O código do livro é gerado automaticamente e o estado inicial do livro é disponível para empréstimo.
 *
 * @callgraph
 *
 * @param livros Vetor com os livros disponíveis no programa.
 */
void cadastrar(ELivro livros[]);

/**
 * @fn void consultar(ELivro livros[])
 * Consulta os dados do livro e apresenta ao usuário. Nessa função é solicitado um código de dois dígitos ao usuário.
 * Com esse código uma busca é feita no vetor. Caso o livro seja encontrado, seus dados são apresentados.
 * Caso contrário, uma mensagem é apresentada.
 *
 * @param livros Vetor com os livros disponíveis no programa.
 */
void consultar(ELivro livros[]);

/**
 * @fn void devolver(ELivro livros[])
 * Realiza a devolução de um livro emprestado. Nessa função é solicitado um código de dois dígitos ao usuário.
 * Com esse código uma busca é feita no vetor.
 * Caso o livro seja encontrado, será realizado a devolução do livro (emprestado = @c false).
 * Caso contrário, uma mensagem é apresentada.
 *
 * @param livros Vetor com os livros disponíveis no programa.
 */
void devolver(ELivro livros[]);

/**
 * @fn void emprestar(ELivro livros[])
 * Realiza o empréstimo de um livro emprestado. Nessa função é solicitado um código de dois dígitos ao usuário.
 * Com esse código uma busca é feita no vetor.
 * Caso o livro seja encontrado, será realizado o empréstimo (emprestado = @c true).
 * Caso contrário, uma mensagem é apresentada.
 *
 * @param livros Vetor com os livros disponíveis no programa.
 */
void emprestar(ELivro livros[]);


#endif /* FUNCOES_H_ */
