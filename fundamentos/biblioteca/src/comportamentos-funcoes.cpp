/*
 * comportamentos-funcoes.cpp
 *
 *  Created on: Mar 30, 2015
 *      Author: gian
 */

#include "funcoes.h"

int menu() {
	int escolheu;
	std::cout
			<< "1 - Cadastrar um livro?\n2 - Consultar um titulo?\n3 - Empréstimo de livro?\n4 - Devolução de livro?\n5 - Sair\n";
	std::cout << "Opcao: ";
	std::cin >> escolheu;
	std::cin.ignore(100, '\n');
	return escolheu;
}

void acao(ELivro livros[], int opcao_menu) {
	switch (opcao_menu) {
	case 1:
		cadastrar(livros);
		break;
	case 2:
		consultar(livros);
		break;
	case 3:
		emprestar(livros);
		break;
	case 4:
		devolver(livros);
		break;
	case 5:
		//sair
		std::cout << "Saindo ... " << std::endl;
		break;
	default:
		break;
	}
}

std::string solicitar_codigo() {
	std::string codigo;
	std::cout << "Qual o codigo do livro (2 digitos): ";
	std::cin >> codigo;
	std::cin.ignore(1000, '\n');
	return codigo;
}

void cadastrar(ELivro livros[]) {
	int pos = procurarLivro(SEM_CODIGO, livros);
	if (pos != -1) {
		std::cout
				<< "                CADASTRO                                         "
				<< std::endl;
		std::cout
				<< "================================================================="
				<< std::endl;
		std::cout << "Codigo : ";
		livros[pos].codigo = std::to_string(pos);
		if (pos < 10) {
			livros[pos].codigo = "0" + std::to_string(pos);
		}
		std::cout << livros[pos].codigo << std::endl;
		std::cout << "Titulo : ";
		std::getline(std::cin, livros[pos].titulo);
		if (livros[pos].titulo.length() > 30) { //limite do tamanho do titulo
			livros[pos].titulo = livros[pos].titulo.substr(0, 30);
		}
		std::cout << "Autor  : ";
		std::getline(std::cin, livros[pos].autor);
		if (livros[pos].autor.length() > 25) { //limite do tamanho do autor
			livros[pos].autor = livros[pos].autor.substr(0, 25);
		}
		std::cout << "Area   : ";
		std::getline(std::cin, livros[pos].area);
		if (livros[pos].area.length() > 15) { //limite do tamanho do area
			livros[pos].area = livros[pos].area.substr(0, 15);
		}
		livros[pos].emprestado = false;
		std::cout
				<< "================================================================="
				<< std::endl;
	}
}

int procurarLivro(std::string codigoParaProcurar, ELivro livros[]) {
	int pos = 0;
	for (; pos < TOTAL_LIVROS; pos++) { //encontra onde tem o mesmo código
		if (livros[pos].codigo.compare(codigoParaProcurar) == 0) {
			break;
		}
	}
	if (pos >= TOTAL_LIVROS) {
		return -1;
	} else {
		return pos;
	}
}

void consultar(ELivro livros[]) {
	std::string codigo = solicitar_codigo();
	int pos = procurarLivro(codigo, livros);
	if (pos != -1) {
		ELivro livro = livros[pos];
		std::cout
				<< "================================================================="
				<< std::endl;
		std::cout << "Livro " << livro.codigo << std::endl;
		std::cout << livro.titulo << " por " << livro.autor
				<< ",\n\tda area de " << livro.area << std::endl;
		if (livro.emprestado) {
			std::cout << "Esse livro encontra-se emprestado." << std::endl;
		} else {
			std::cout << "Esse livro encontra-se disponível." << std::endl;
		}
		std::cout
				<< "================================================================="
				<< std::endl << "Aperte ENTER para continuar." << std::endl;
		std::cin.get();
	} else {
		std::cout << ">> Livro não encontrado." << std::endl;
	}
}

void devolver(ELivro livros[]) {
	std::cout
			<< "                DEVOLUÇÃO                                         "
			<< std::endl;
	std::cout
			<< "================================================================="
			<< std::endl;
	std::string codigo = solicitar_codigo();
	int pos = procurarLivro(codigo, livros);
	if (pos != -1) {
		if (livros[pos].emprestado) {
			livros[pos].emprestado = false;
			std::cout << "Livro devolvido com sucesso." << std::endl;
		} else {
			std::cout << "Esse livro está disponível. Devolução não realizada." << std::endl;
		}
	} else {
		std::cout << ">> Livro não encontrado." << std::endl;
	}
	std::cout
			<< "================================================================="
			<< std::endl << "Aperte ENTER para continuar." << std::endl;
	std::cin.get();

}

void emprestar(ELivro livros[]) {
	std::cout
			<< "                EMPRÉSTIMO                                       "
			<< std::endl;
	std::cout
			<< "================================================================="
			<< std::endl;
	std::string codigo = solicitar_codigo();
	int pos = procurarLivro(codigo, livros);
	if (pos != -1) {
		if (!livros[pos].emprestado) {
			livros[pos].emprestado = true;
			std::cout << "Livro emprestado com sucesso." << std::endl;
		} else {
			std::cout << "Esse livro está emprestado. Empréstimo não realizado." << std::endl;
		}
	} else {
		std::cout << ">> Livro não encontrado." << std::endl;
	}
	std::cout
			<< "================================================================="
			<< std::endl << "Aperte ENTER para continuar." << std::endl;
	std::cin.get();
}

