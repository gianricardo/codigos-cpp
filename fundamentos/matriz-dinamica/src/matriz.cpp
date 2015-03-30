/**
 * @file matriz.cpp
 *
 *  Created on: Mar 26, 2015
 *      Author: gian
 *
 * Enunciado:
 *
 *  Leia uma matriz 4x4 de um arquivo e escreva em outro arquivo a transposta da matriz. O conteúdo
 *  do arquivo deve seguir o exemplo abaixo. A matriz deve ser dinâmica.
 *
 *  2 4 5 8
 *  1 6 2 9
 *  3 7 6 5
 *  1 3 5 7
 *
 * <HR>
 *
 */

#include <iostream>
#include <iomanip> /* setw */
#include <cstdlib> /* srand, rand */
#include <fstream>

using namespace std;

int main()
{
    int nr_linha=4,nr_coluna=4,i,x,y;
    ifstream matriz("m2.txt");
    ofstream matriztransposta("m2.transposta.txt");

    //cria a matriz dinamicamente
    int** matrix = new int*[nr_linha];
    for (i = 0; i < nr_linha; ++i)
        matrix[i] = new int[nr_coluna];

    //ler a matriz
    if (matriz.is_open()) {
    	for(x=0;x<nr_linha;x++){
    		for(y=0;y<nr_coluna;y++){
    			matriz >> matrix[x][y];
    		}
    	}
    }else {
      cout << "Não foi possivel abrir o arquivo de entrada.";
    }
    matriz.close();
    //transpor a matriz
    if (matriztransposta.is_open()) {
    	for(y=0;y<nr_coluna;y++){
    		for(x=0;x<nr_linha;x++){
    			matriztransposta << matrix[x][y]<<" ";
    		}
    		matriztransposta<<std::endl;
    	}
    }else {
      cout << "Não foi possivel abrir o arquivo de saida.";
    }
    matriztransposta.close();
    //libera a memória da matriz
    for (i = 0; i < nr_linha; ++i)
        delete [] matrix[i];
    delete [] matrix;
    return (0);
}



