/*
 * multigraph.h
 *
 *  Created on: Apr 27, 2015
 *      Author: gian
 */

#ifndef MULTIGRAPH_H_
#define MULTIGRAPH_H_

#include "digraph.h"

namespace graphlib {

template<class Tipo_Info_Vertex, class Tipo_Info_Arc = Tipo_Info_Vertex>
class MultiGraph: public Digraph<Tipo_Info_Vertex,Tipo_Info_Arc> {
public:
    MultiGraph(){}
    virtual ~MultiGraph(){}
};

} /* namespace graphlib */

#endif /* MULTIGRAPH_H_ */
