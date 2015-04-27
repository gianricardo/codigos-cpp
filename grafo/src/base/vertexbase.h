/*
 * vertex.h
 *
 *  Created on: Apr 24, 2015
 *      Author: gian
 */

#ifndef VERTEXBASE_H_
#define VERTEXBASE_H_

#include <string>
#include <list>
#include "edge.h"

namespace graphlib {

template<class Tipo_Info_Vertex, class Tipo_Info_Edge = Tipo_Info_Vertex>
class VertexBase {
public:
    VertexBase() :
            _name("") {
    }
    VertexBase(std::string name) :
            _name(name) {
    }
    virtual ~VertexBase() {
        erase_out_edges();
    }
    //
    Tipo_Info_Vertex info() const {
        return _info;
    }
    void info(Tipo_Info_Vertex i) {
        _info = i;
    }
    std::string name() const {
        return _name;
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
    bool exist_edge_to(std::string v) const {
        bool exist_edge = false;
        for (auto vv : _edge_v0) {
            if (vv->v1() == v) {
                exist_edge = true;
                break;
            }
        }
        return exist_edge;
    }

    Edge<Tipo_Info_Edge>* edge_to(std::string v) {
        Edge<Tipo_Info_Edge>* edge_to_v1 = nullptr;
        for (auto vv : _edge_v0) {
            if (vv->v1() == v) {
                edge_to_v1 = vv;
                break;
            }
        }
        return edge_to_v1;
    }

    const std::list<std::string> list_to_v1() const {
        std::list<std::string> list_2_v1;
        for (auto vv : _edge_v0) {
            list_2_v1.push_back(vv->v1());
        }
        list_2_v1.sort();
        return list_2_v1;

    }

    void erase_out_edges() {
        /*
         * Releasing the out-edges' memory.
         * It does not need to release the in-edges' memory, because other vertices will release them as out-edges.
         */
        for (auto edge : _edge_v0) {
            delete edge;
        }
    }

    int degree_v0()const {
        return _edge_v0.size();
    }

    int degree_v1()const{
        return _edge_v1.size();
    }

    int degree()const{
        return (degree_v0()+degree_v1());
    }

    const std::list<Edge<Tipo_Info_Edge> *> list_edge_v0()const{
        return _edge_v0;
    }

    const std::list<Edge<Tipo_Info_Edge> *> list_edge_v1()const{
        return _edge_v1;
    }

private:
    Tipo_Info_Vertex _info;
    std::string _name;
    std::list<Edge<Tipo_Info_Edge> *> _edge_v0, _edge_v1;

};

} /* namespace graphlib */

#endif /* VERTEX_H_ */
