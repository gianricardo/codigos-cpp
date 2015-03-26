/*
 * programa.cpp
 *
 *  Created on: Mar 26, 2015
 *      Author: gian
 */

/**
 * @file programa.cpp
 * @brief
 *
 *
 */

#include <iostream>
#include <iomanip>

#define TAM_ESTOQUE 30

using namespace std;

struct veiculo {
    string marca, modelo;
    int ano;
    float valor;
};

/**
 * @fn void cadastrar(struct veiculo ll[], int& pos)
 *
 * @param ll
 * @param pos
 */
void cadastrar(struct veiculo ll[], int& pos);
void listar(struct veiculo ll[], int qtd_cadastrada);

int main() {
    struct veiculo estoque[TAM_ESTOQUE];
    int opcao=0,posicao_cadastro=0;

    do {
        cout << "Exercicio 01"<<endl;
        cout << "1-Cadastrar\n2-Listar Estoque\n99-Sair\nOpcao: ";
        cin >> opcao;
        cin.ignore(1000, '\n');
        switch(opcao) {
        case 1:
            cadastrar(estoque,posicao_cadastro);
            break;
        case 2:
            listar(estoque,posicao_cadastro);
            break;
        case 99:
            cout << "SAINDO ... "<<endl;
            break;
        default:
            cout << "Opcao inválida!" << endl;
        }
    } while(opcao!=99);
    return 0;
}

void cadastrar(struct veiculo ll[], int& pos) {
    if(pos<TAM_ESTOQUE&&pos>=0) {
        cout << "                CADASTRO                                         " <<endl;
        cout << "=================================================================" <<endl;
        cout << "Marca : ";
        getline(cin,ll[pos].marca);
        cout << "Modelo: ";
        getline(cin,ll[pos].modelo);
        cout << "Ano   : ";
        cin >> ll[pos].ano;
        cout << "Valor : ";
        cin >> ll[pos].valor;
        cout << "=================================================================" <<endl;
        pos++;
    }
}

void listar(struct veiculo ll[], int qtd_cadastrada) {
    int pp;
    cout << "                   LISTA                                         " <<endl;
    cout << "=================================================================" <<endl;
    cout << "        Marca       =       Modelo       =   Ano     =   Valor   " <<endl;
    cout << "=================================================================" <<endl;
    for(pp=0; pp<qtd_cadastrada; pp++) {
        cout << setw(20) << ll[pp].marca << setw(20) << ll[pp].modelo <<
             setw(10) << ll[pp].ano <<   setw(10) << ll[pp].valor << endl;
    }
    cout << "=================================================================" <<endl;
}



