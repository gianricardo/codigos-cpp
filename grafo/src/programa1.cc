/*
 * programa1.cc
 *
 *  Created on: Apr 24, 2015
 *      Author: gian
 */

#include "base/graph.h"
#include <iostream>
#include <iomanip>

int main(int argc, char **argv) {
    graphlib::Graph<int> grafo;
    grafo.add_edge("1","2");
    grafo.add_edge("1","1");
    grafo.add_edge("3","2");
    grafo.add_edge("2","3");
    grafo.erase_edge("4","2");
    std::cout << "Grafo\n";
    grafo.print(std::cout);
    auto t=grafo.depthFirst("3");
    for(auto v:t ){
        std::cout << std::setw(4) << v;
    }
    std::cout << std::endl;
    auto tt=grafo.breadthFirst("2");
    for(auto v:tt ){
        std::cout << std::setw(4) << v;
    }
    return 0;
    //file:///home/gian/Downloads/roadnet/roadnet.edge
}

