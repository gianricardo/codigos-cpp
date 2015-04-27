/*
 * digraph.h
 *
 *  Created on: Apr 27, 2015
 *      Author: gian
 */

#ifndef DIGRAPH_H_
#define DIGRAPH_H_

#include "graph.h"

namespace graphlib {

template<class Tipo_Info_Vertex, class Tipo_Info_Arc = Tipo_Info_Vertex>
class Digraph: public Graph<Tipo_Info_Vertex,Tipo_Info_Arc> {
public:
    Digraph(){}
    virtual ~Digraph(){}
};

} /* namespace graphlib */

#endif /* DIGRAPH_H_ */
