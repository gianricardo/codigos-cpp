/*
 * vertex.h
 *
 *  Created on: Apr 24, 2015
 *      Author: gian
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include <string>
#include <list>
#include "edge.h"

namespace graphlib {

template<class Tipo_Info_Vertex, class Tipo_Info_Edge = Tipo_Info_Vertex>
class Vertex {
public:
    Vertex() :
            _name("") {
    }
    Vertex(std::string name) :
            _name(name) {
    }
    virtual ~Vertex() {
        /*
         * Releasing the out-edges' memory.
         * It does not need to release the in-edges' memory, because other vertices will release them as out-edges.
         */
        for (auto edge : _edge_v0) {
            delete edge;
        }
    }
    //
    Tipo_Info_Vertex info() {
        return _info;
    }
    void info(Tipo_Info_Vertex i) {
        _info = i;
    }
    //
    void add_v0_edge(Edge<Tipo_Info_Edge> *edge) {
        _edge_v0.push_back(edge);
    }
    void add_v1_edge(Edge<Tipo_Info_Edge> *edge) {
        _edge_v1.push_back(edge);
    }
    //
    void remove_v0_edge(Edge<Tipo_Info_Edge> *edge) {
        _edge_v0.remove(edge);
    }
    void remove_v1_edge(Edge<Tipo_Info_Edge> *edge) {
        _edge_v1.remove(edge);
    }
    //
    bool exist_edge_to(std::string v){
        bool exist_edge=false;
        for(auto vv:_edge_v0){
            if(vv->v1()==v){
                exist_edge=true;
                break;
            }
        }
        return exist_edge;
    }

    Edge<Tipo_Info_Edge>* edge_to(std::string v){
        Edge<Tipo_Info_Edge>* edge_to_v1=nullptr;
        for(auto vv:_edge_v0){
            if(vv->v1()==v){
                edge_to_v1=vv;
                break;
            }
        }
        return edge_to_v1;
    }

private:
    Tipo_Info_Vertex _info;
    std::string _name;
    std::list<Edge<Tipo_Info_Edge> *> _edge_v0, _edge_v1;

};

} /* namespace graphlib */

#endif /* VERTEX_H_ */
