/*
 * vertex.h
 *
 *  Created on: Apr 27, 2015
 *      Author: gian
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include "vertexbase.h"
#include "arc.h"

namespace graphlib {

template<class Tipo_Info_Vertex, class Tipo_Info_Arc = Tipo_Info_Vertex>
class Vertex: public VertexBase<Tipo_Info_Vertex, Tipo_Info_Arc> {
public:
    Vertex() {
    }
    Vertex(std::string name) :
            VertexBase<Tipo_Info_Vertex, Tipo_Info_Arc>(name) {
    }
    virtual ~Vertex() {
    }
    //
    void add_from_arc(Arc<Tipo_Info_Arc> *arc) {
        VertexBase<Tipo_Info_Vertex, Tipo_Info_Arc>::add_v0_edge(arc);
    }
    void add_to_arc(Arc<Tipo_Info_Arc> *arc) {
        VertexBase<Tipo_Info_Vertex, Tipo_Info_Arc>::add_v1_edge(arc);
    }
    void remove_from_arc(Arc<Tipo_Info_Arc> *arc) {
        VertexBase<Tipo_Info_Vertex, Tipo_Info_Arc>::remove_v0_edge(arc);
    }
    void remove_to_arc(Arc<Tipo_Info_Arc> *arc) {
        VertexBase<Tipo_Info_Vertex, Tipo_Info_Arc>::remove_v1_edge(arc);
    }
    const std::list<std::string> to_vertex_list() const {
        return VertexBase<Tipo_Info_Vertex, Tipo_Info_Arc>::list_to_v1();
    }
    Arc<Tipo_Info_Arc>* arc_to(std::string v) {
        return  VertexBase<Tipo_Info_Vertex, Tipo_Info_Arc>::edge_to(v);
    }
    int degree_out()const {
        return VertexBase<Tipo_Info_Vertex, Tipo_Info_Arc>::degree_v0();
    }

    int degree_in()const{
        return VertexBase<Tipo_Info_Vertex, Tipo_Info_Arc>::degree_v1();
    }

    int degree()const{
        return (degree_out()+degree_in());
    }

    const std::list<Arc<Tipo_Info_Arc> *> out_arc_list()const{
        return VertexBase<Tipo_Info_Vertex, Tipo_Info_Arc>::list_edge_v0();
    }

    const std::list<Arc<Tipo_Info_Arc> *> in_arc_list()const{
        return VertexBase<Tipo_Info_Vertex, Tipo_Info_Arc>::list_edge_v1();
    }
};

} /* namespace graphlib */

#endif /* VERTEX_H_ */
