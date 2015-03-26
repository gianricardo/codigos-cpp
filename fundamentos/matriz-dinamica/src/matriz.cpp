/*
 * matriz.cpp
 *
 *  Created on: Mar 26, 2015
 *      Author: gian
 */

#include <iostream>
#include <iomanip> /*setw */
#include <cstdlib> /* srand, rand */
#include <ctime>   /* time */

using namespace std;

int main()
{
    int nr_linha=4,nr_coluna=4,i,y;
    srand (time(NULL));//reinicia a gerador de número aleatório
    //cria a matriz dinamicamente
    int** matrix = new int*[nr_linha];
    for (i = 0; i < nr_linha; ++i)
        matrix[i] = new int[nr_coluna];

    //preencher com numeros aleatorios
    for (i=0; i<nr_linha; i++)
    {
        for (y=0; y<nr_coluna; y++)
        {
            matrix[i][y]=rand()%100+1;
        }
    }
    //imprimir matriz
    for (i=0; i<nr_linha; i++)
    {
        for (y=0; y<nr_coluna; y++)
        {
            cout << setw(4)<<matrix[i][y];
        }
        cout << endl;
    }
    //libera a memória da matriz
    for (i = 0; i < nr_linha; ++i)
        delete [] matrix[i];
    delete [] matrix;

    cin.get();
    return 0;
}



