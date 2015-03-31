/**
 * @file programa.cpp
 *
 * Enunciado:
 *
 *  Implemente um programa de cadastro de veículos de uma loja (máximo 30). Use uma estrutura
 *  contendo: marca, modelo, ano e valor. Implemente uma função de cadastro e uma função que
 *  imprime na tela um relatório contendo o inventário do estoque.
 *
 * <HR>
 *
 */

#include <iostream>
#include <iomanip>

/**
 * @def TAM_ESTOQUE
 */
#define TAM_ESTOQUE 30

using namespace std;

/**
 * @struct veiculo
 * Estrutura que descreve o veículo de acordo com o enunciado.
 *
 */
struct veiculo {
    string marca, modelo;
    int ano;
    float valor;
};

/**
 * @fn void cadastrar(struct veiculo ll[], int& pos)
 *	Solicita ao usuário as informações do veículo. Armazena no vetor @c ll os dados do veículo na posição @c pos.
 *
 * @param ll vetor que contêm os veículos.
 * @param pos posição para cadastrar o veículo.
 */
void cadastrar(struct veiculo ll[], int& pos);

/**
 * @fn void listar(struct veiculo ll[], int qtd_cadastrada)
 * Lista na saída padrão todos os veículos cadastrados em @c ll.
 *
 * @param ll vetor que contêm os veículos.
 * @param qtd_cadastrada quantidade de carros no vetor.
 */
void listar(struct veiculo ll[], int qtd_cadastrada);

/**
 * @fn int main()
 * @brief Função principal do programa.
 *
 * @return Status de fim do programa.
 */
int main() {
    struct veiculo estoque[TAM_ESTOQUE];
    int opcao=0,posicao_cadastro=0;

    do {
        cout << "Exercicio 01"<<endl;
        cout << "1-Cadastrar\n2-Listar Estoque\n99-Sair\nOpcao: ";/*Imprime o menu.*/
        cin >> opcao;
        cin.ignore(1000, '\n');
        switch(opcao) {
        case 1:
            cadastrar(estoque,posicao_cadastro);/*chama a função cadastrar*/
            break;
        case 2:
            listar(estoque,posicao_cadastro);/*chama a função para listar o estoque*/
            break;
        case 99:
            cout << "SAINDO ... "<<endl;/*Acaba o programa*/
            break;
        default:
            cout << "Opcao inválida!" << endl;
        }
    } while(opcao!=99);
    return (0);
}

void cadastrar(struct veiculo ll[], int& pos) {
	//@ assert pos<TAM_ESTOQUE
    if(pos<TAM_ESTOQUE&&pos>=0) {/*Verifica se é uma posição válida*/
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



