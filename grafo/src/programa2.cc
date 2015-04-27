/*
 * programa1.cc
 *
 *  Created on: Apr 24, 2015
 *      Author: gian
 */

#include "base/graph.h"
#include <iostream>
#include <iomanip>

/*
 * TODO Digrafo
 * TODO Multigrafo
 * TODO Grafo ponderado
 *
 */

int main(int argc, char **argv) {
    graphlib::Graph<int> grafo("Roadnet");
    std::cout << "Loading...";
    std::cout.flush();
    grafo.load_from_file("roadnet.edge");
    std::cout << "Done!\nGrafo\n"<<grafo.number_vertices()<<std::endl;
    //grafo.generate_dot_file("roadnet.dot",5000);
    //grafo.print(std::cout);

    std::cout << "First Traverse. "<<std::endl;
    auto t=grafo.depthFirst("0");
    std::cout << "Size: " << t.size() << std::endl;
    std::cout << "END First Traverse. "<<std::endl;
    /*
    int q=0;
    for(auto v:t ){
        std::cout << std::setw(9) << v;
        if(q++>10){
            std::cout <<std::endl;
            q=0;
        }
    }*/
    std::cout << std::endl;
    std::cout << "Second Traverse. "<<std::endl;
    auto tt=grafo.breadthFirst("0");
    std::cout << "Size: " << tt.size() << std::endl;
    std::cout << "END Second Traverse. "<<std::endl;
    /*
    q=0;
    for(auto v:tt ){
        std::cout << std::setw(9) << v;
        if(q++>10){
            std::cout <<std::endl;
            q=0;
        }
    }*/
    return 0;
}

