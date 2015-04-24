/*
 * graph.h
 *
 *  Created on: Apr 24, 2015
 *      Author: gian
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <map>
#include <utility>
#include <string>
#include "vertex.h"

namespace graphlib {

template<class Tipo_Info_Vertex, class Tipo_Info_Edge = Tipo_Info_Vertex>
class Graph {
public:
    Graph() :
            _name("Graph untitled") {
    }
    Graph(std::string name) :
            _name(name) {
    }
    virtual ~Graph() {
        for (auto vertex : _vertices) {
            delete vertex.second;
        }
    }
    void add_edge(std::string v0, std::string v1) {
        Vertex<Tipo_Info_Vertex, Tipo_Info_Edge> *v_0, *v_1;
        if (!exist_vertex(v0)) {
            v_0 = new Vertex<Tipo_Info_Vertex, Tipo_Info_Edge>(v0);
            _vertices.insert(std::make_pair(v0,v_0));
        } else {
            v_0 = _vertices[v0];
        }
        if (!exist_vertex(v1)) {
            v_1 = new Vertex<Tipo_Info_Vertex, Tipo_Info_Edge>(v1);
            _vertices.insert(std::make_pair(v1,v_1));
        } else {
            v_1 = _vertices[v1];
        }
        Edge<Tipo_Info_Edge> *n_edge=new Edge<Tipo_Info_Edge>(v0,v1);
        v_0->add_v0_edge(n_edge);
        v_1->add_v1_edge(n_edge);
    }

    void erase_edge(std::string v0, std::string v1){
        Vertex<Tipo_Info_Vertex, Tipo_Info_Edge> *v_0, *v_1;
        if (exist_vertex(v0)&&exist_vertex(v1)) {
            v_0 = _vertices[v0];
            if(v_0->exist_edge_to(v1)){
                v_1 = _vertices[v1];
                auto edge_erase = v_0->edge_to(v1);
                v_0->remove_v0_edge(edge_erase);
                v_1->remove_v1_edge(edge_erase);
            }
        }
    }

    int number_vertices() {
        return _vertices.size();
    }

    bool exist_vertex(std::string sv) {
        auto i_search = _vertices.find(sv);
        return (i_search != _vertices.end());
    }

private:
    std::map<std::string, Vertex<Tipo_Info_Vertex, Tipo_Info_Edge> *> _vertices;
    std::string _name;
};

} /* namespace graphlib */

#endif /* GRAPH_H_ */
