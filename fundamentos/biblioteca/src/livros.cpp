/*
 * livros.cpp
 *
 *  Created on: Mar 26, 2015
 *      Author: gian
 */

#include <iostream>

const int TOTAL_LIVROS = 50;

struct livro {
	std::string titulo, autor, area, codigo;
	bool emprestado;
};

typedef struct livro ELivro;

int menu();
void acao(ELivro livros[], int opcao_menu);
std::string solicitar_codigo();
void cadastrar(ELivro livros[]);
void consultar(ELivro livros[]);
void devolver(ELivro livros[]);
void emprestar(ELivro livros[]);

int main() {
	ELivro biblioteca[TOTAL_LIVROS];
	int opcao=0;
	for(ELivro livro: biblioteca){
		livro.codigo="--";
		std::cout << ++opcao<<std::endl;
	}

	do {
		opcao = menu();
		acao(biblioteca, opcao);
	} while (opcao != 5);

	return 0;
}

int menu() {
	int escolheu;
	std::cout
			<< "1 - Cadastrar um livro?\n2 - Consultar um titulo?\n3 - Empréstimo de livro?\n4 - Devolução de livro?\n5 - Sair\n";
	std::cout << "Opcao: ";
	std::cin >> escolheu;
	std::cin.ignore(1000, '\n');
	return escolheu;
}

void acao(ELivro livros[], int opcao_menu) {
	switch (opcao_menu) {
	case 1:
		cadastrar(livros);
		break;
	case 2:
		//consultar
		break;
	case 3:
		//emprestar
		break;
	case 4:
		//devolver
		break;
	case 5:
		//sair
		std::cout << "Saindo ... "<<std::endl;
		break;
	default:
		break;
	}
}

std::string solicitar_codigo(){
	std::string codigo;
	std::cout << "Qual o codigo do livro: ";
	std::cin >> codigo;
	std::cin.ignore(1000, '\n');
	return codigo;
}

void cadastrar(ELivro livros[]){
	int pos=0;
	for(;pos<TOTAL_LIVROS;pos++){//encontra onde cadastrar
		if(livros[pos].codigo.compare("--")==0){
			break;
		}
	}
	std::cout << "                CADASTRO                                         " <<std::endl;
	std::cout << "=================================================================" <<std::endl;
	std::cout << "Codigo : ";
	livros[pos].codigo=std::to_string(pos);
	if(pos<10){
		livros[pos].codigo="0"+std::to_string(pos);
	}
	std::cout << "Titulo : ";
	std::getline(std::cin,livros[pos].titulo);
    std::cout << "Autor  : ";
    std::getline(std::cin,livros[pos].autor);
    std::cout << "Area   : ";
    std::getline(std::cin,livros[pos].area);
    livros[pos].emprestado=false;
    std::cout << "=================================================================" <<std::endl;
}
