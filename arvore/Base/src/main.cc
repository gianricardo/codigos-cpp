#include <iostream>

#include "arvore.h"

using namespace std;

int main()
{
    typedef Arvore<double> DArvore;
    DArvore t;
	//int data[]={32,16,34,1,87,13,7,18,14,19,23,24,41,5,53};
	int data[]={6, 34, 17, 19, 16, 10, 23, 3};
	for(int i=0;i<8;i++)
		t.add(data[i]);
    t.caminho(DArvore::IN);
    t.del(16);
    t.caminho(DArvore::PRE);
    //t.del(41);
    //t.del(32);
    //t.caminho(Arvore::PRE);

    t.caminho(DArvore::POS);
    return 0;
}
