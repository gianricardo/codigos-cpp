#include <iostream>

#include "arvore.h"
#include "visitor.h"

using namespace std;

int main()
{
    typedef Arvore<double> DArvore;
    DArvore t;
    Visitor_Pre_Out<double> v_pre;
    Visitor_In_Out<double> v_in;
    Visitor_Pos_Out<double> v_pos;
//    Arvore<char> exp;
//    exp.add('+');
//    exp.insertLeft(exp.root(),'a');
//    exp.insertRight(exp.root(),'b');
//    exp.print1();
//    std::cout << std::endl;
//	int data[]={32,16,34,1,87,13,7,18,14,19,23,24,41,5,53};
	int data[]={6, 34, 17, 19, 16, 10, 23, 3};
	for(int i=0;i<8;i++)
		t.add(data[i]);
    t.caminho(v_pre);
    t.del(16);
    t.caminho(v_in);

    //t.del(41);
    //t.del(32);
    //t.caminho(Arvore::PRE);

    t.caminho(v_pos);
    return 0;
}
