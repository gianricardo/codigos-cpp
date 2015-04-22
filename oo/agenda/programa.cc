/**
 * @file programa.cc
 * @brief Programa principal do Controle de Agenda.
 *
 *  Created on: Apr 17, 2015
 *      Author: gian
 *
 * <HR>
 *
 * Enunciado:
 *
 * Faça um programa que apresente o menu de opções a seguir:
 * -# Cadastrar pessoa na agenda de contato (Nome, Dia de aniversário, Celular, Twitter e Facebook).
 * -# Excluir pessoa a partir do nome.
 * -# Alterar dados a partir do nome.
 * -# Consultar aniversariantes de uma data (dia e mês).
 * -# Consultar aniversariantes por mês.
 * -# Consultar aniversariantes pela letra inicial do nome.
 * -# Mostar toda a agenda ordenada pelo nome.
 * -# Mostar toda a agenda ordenada por mês.
 * -# Sair.
 *
 * A agenda tem que suportar no máximo 30 pessoas e as informações devem ser armazenadas em arquivo.
 * Se exitir pessoas cadastradas, eles devem estar disponível ao executar o programa.
 *
 * <HR>
 *
 * Implementação da função principal do segundo trabalho.
 * Nessa função é criado o objeto do tipo Tela e, em seguida, o método executa é invocado/chamado.
 *
 */

#include "src/tela.h"

/**
 * @fn int main()
 * @brief Função principal do programa.
 *
 * @return Status de fim do programa.
 */
int main(int argc, char **argv) {
	trabalho2::Tela programa; /*objeto automatico do tipo Tela*/
	programa.executa();/*chamada para executar o programa*/
	return 0;
}



