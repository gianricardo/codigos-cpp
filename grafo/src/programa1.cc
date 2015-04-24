/*
 * programa1.cc
 *
 *  Created on: Apr 24, 2015
 *      Author: gian
 */

#include "base/graph.h"
#include <iostream>

int main(int argc, char **argv) {
    graphlib::Graph<int> grafo;
    grafo.add_edge("1","2");
    grafo.add_edge("1","2");
    grafo.add_edge("3","2");
    grafo.add_edge("2","3");
    std::cout << "Grafo\n";
    return 0;
}

