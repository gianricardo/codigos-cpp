/*
 * graph.h
 *
 *  Created on: Apr 24, 2015
 *      Author: gian
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <map>
#include <queue>
#include <list>
#include <utility>
#include <string>
#include <iostream>
#include <fstream>
#include "vertexbase.h"

#define _GRAPH_DEBUG false

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
        erase();
    }
    virtual void add_edge(std::string v0, std::string v1) {
        VertexBase<Tipo_Info_Vertex, Tipo_Info_Edge> *v_0;
        if (!exist_vertex(v0)) {
            v_0 = new VertexBase<Tipo_Info_Vertex, Tipo_Info_Edge>(v0);
            _vertices.insert(std::make_pair(v0, v_0));
        } else {
            v_0 = _vertices[v0];
        }
        if (!v_0->exist_edge_to(v1)) {
            VertexBase<Tipo_Info_Vertex, Tipo_Info_Edge> *v_1;
            if (!exist_vertex(v1)) {
                v_1 = new VertexBase<Tipo_Info_Vertex, Tipo_Info_Edge>(v1);
                _vertices.insert(std::make_pair(v1, v_1));
            } else {
                v_1 = _vertices[v1];
            }
            Edge<Tipo_Info_Edge> *n_edge = new Edge<Tipo_Info_Edge>(v0, v1);
            Edge<Tipo_Info_Edge> *n_edge_inv = new Edge<Tipo_Info_Edge>(v1, v0);
            v_0->add_v0_edge(n_edge);
            v_1->add_v1_edge(n_edge);
            //
            v_0->add_v1_edge(n_edge_inv);
            v_1->add_v0_edge(n_edge_inv);
        }
    }

    virtual void erase_edge(std::string v0, std::string v1) {
        VertexBase<Tipo_Info_Vertex, Tipo_Info_Edge> *v_0;
        if (exist_vertex(v0) && exist_vertex(v1)) {
            v_0 = _vertices[v0];
            if (v_0->exist_edge_to(v1)) {
                VertexBase<Tipo_Info_Vertex, Tipo_Info_Edge> *v_1;
                v_1 = _vertices[v1];
                auto edge_erase = v_0->edge_to(v1);
                v_0->remove_v0_edge(edge_erase);
                v_1->remove_v1_edge(edge_erase);
            }
        }
    }

    int number_vertices() const {
        return _vertices.size();
    }

    bool exist_vertex(std::string sv) const {
        auto i_search = _vertices.find(sv);
        return (i_search != _vertices.end());
    }

    /**
     * Removes all edges and vertices from the graph.
     */
    void erase() {
        for (auto position : _vertices) {
            delete position.second;
        }
    }

    /**
     * Removes all edges from the graph.
     */
    void clear() {
        for (auto position : _vertices) {
            position.second->erase_out_edges();
        }
    }

    void print(std::ostream &output, std::string separator = " ", bool named = false) const {
        if (named) {
            output << _name << "\n";
        }
        for (auto position : _vertices) {
            std::list<std::string> to_v1 = position.second->list_to_v1();
            output << position.second->name();
            for (auto v1 : to_v1) {
                output << separator << v1;
            }
            output << "\n";
        }
    }

    /**
     * Return the vertex's degree or -1 otherwise.
     *
     * @param vertex the vertex's name
     * @return degree
     */
    int vertex_degree(std::string vertex) const {

        if (exist_vertex(vertex)) {
            VertexBase<Tipo_Info_Vertex, Tipo_Info_Edge> *v;
            v = _vertices[vertex];
            return v->degree();
        }
        return -1;
    }

    std::list<std::string> breadthFirst(std::string vertex_source) const {
        std::queue<std::string> queue_adj;
        std::list<std::string> traverse_path;
        std::map<std::string, bool> visited;

        //initializing
        for (auto position : _vertices) {
            if (_GRAPH_DEBUG)
                std::cout << "ini: " << position.second->name() << "\n";
            visited[position.second->name()] = false;
        }
        //looking for the initial vertex
        auto v_current = _vertices.begin();
        for (; v_current != _vertices.end(); v_current = next(v_current)) {
            if (v_current->second->name() == vertex_source) {
                if (_GRAPH_DEBUG)
                    std::cout << "found: " << v_current->second->name() << "\n";
                break;
            }
        }
        //traversing
        if (v_current != _vertices.end()) { //only traverse if there is the initial vertex in the graph
            int visit_count = 0;
            if (_GRAPH_DEBUG)
                std::cout << "# vertices: " << number_vertices() << "\n";
            for (; visit_count < number_vertices(); visit_count++) {
                if (!visited[v_current->second->name()]) {
                    queue_adj.push(v_current->second->name());
                    do {
                        std::string v2 = queue_adj.front();
                        queue_adj.pop();

                        if (!visited[v2]) {
                            visited[v2] = true;
                            if (_GRAPH_DEBUG)
                                std::cout << "visiting: " << v_current->second->name() << " - " << std::boolalpha << visited[v_current->second->name()] << "\n";
                            //std::cout << std::setw(3) << v2;
                            traverse_path.push_back(v2);
                        }
                        auto edges = v_current->second->list_edge_v0();
                        for (auto edge : edges) {
                            if (!visited[edge->v1()]) {
                                if (_GRAPH_DEBUG)
                                    std::cout << "filling queue: " << v_current->second->name() << " - " << edge->v1() << " - " << std::boolalpha
                                            << visited[edge->v1()] << "\n";
                                queue_adj.push(edge->v1());
                            }
                        }
                    } while (!queue_adj.empty());
                } //end if
                v_current = next(v_current);
                if (v_current == _vertices.end()) { //reach the end of the map
                    v_current = _vertices.begin();
                }
            } //end for
        }

        return traverse_path;
    }

    std::list<std::string> adjacent_vertices_list(std::string vertex) const {
        std::list<std::string> adjacent;
        if (exist_vertex(vertex)) {
            adjacent = _vertices[vertex]->list_to_v1();
        }
        return adjacent;
    }

    std::list<std::string> depthFirst(std::string vertex_source) const {
        std::map<std::string, bool> visited;
        std::list<std::string> traverse_path;

        //initializing
        for (auto position : _vertices) {
            if (_GRAPH_DEBUG)
                std::cout << "ini: " << position.second->name() << "\n";
            visited[position.second->name()] = false;
        }
        //looking for the initial vertex
        auto v_current = _vertices.begin();
        for (; v_current != _vertices.end(); v_current = next(v_current)) {
            if (v_current->second->name() == vertex_source) {
                if (_GRAPH_DEBUG)
                    std::cout << "found: " << v_current->second->name() << "\n";
                break;
            }
        }
        //traversing
        if (v_current != _vertices.end()) { //only traverse if there is the initial vertex in the graph
            int visit_count = 0;
            if (_GRAPH_DEBUG)
                std::cout << "# vertices: " << number_vertices() << "\n";
            for (; visit_count < number_vertices(); visit_count++) {
                if (_GRAPH_DEBUG)
                    std::cout << "visiting: " << v_current->second->name() << " - " << std::boolalpha << visited[v_current->second->name()] << "\n";
                if (!visited[v_current->second->name()]) {
                    traverse(v_current->second->name(), visited, traverse_path, v_current->second);
                }
                v_current = next(v_current);
                if (v_current == _vertices.end()) { //reach the end of the map
                    v_current = _vertices.begin();
                }
            }
        }
        return traverse_path;
    }

    void load_from_file(std::string file) {
        std::ifstream to_load(file);
        if (to_load.is_open()) {
            std::string v0, v1;
            while (true) {
                std::getline(to_load, v0, ' ');
                std::getline(to_load, v1);
                //std::cin >> v0;
                //std::cin >> v1;
                if (_GRAPH_DEBUG)
                    std::cout << "Read: " << v0 << " - " << v1 << std::endl;
                if (v0.size() > 0 && v1.size() > 0) { //read two values
                    add_edge(v0, v1);
                } else {
                    if (!to_load.eof()) {
                        std::cout << "File bad formatted!" << std::endl;
                    }
                    break;
                }
                if (to_load.eof()) {
                    break;
                }
            }
            to_load.close();
        }
    }

    void generate_dot_file(std::string dotfile, long upper_vertex_limit = 0) const {
        std::ofstream to_write(dotfile);
        if (to_write.is_open()) {
            long vertex_count = 0;
            to_write << "graph " << _name << " { \n";
            for (auto position : _vertices) {
                auto edges = position.second->list_edge_v0();
                for (auto edge : edges) {
                    to_write << "    " << edge->v0() << "--" << edge->v1() << ";\n";
                }
                vertex_count++;
                if ((upper_vertex_limit != 0) && (vertex_count >= upper_vertex_limit)) {
                    break;
                }
            }
            to_write << "}\n";
            to_write.flush();
            to_write.close();
        }
    }

private:
    void traverse(std::string vertex_source, std::map<std::string, bool>& vb, std::list<std::string>& traverse_path,
            VertexBase<Tipo_Info_Vertex, Tipo_Info_Edge> *v_cur) const {
        vb[vertex_source] = true;
        traverse_path.push_back(vertex_source);
        //std::cout << std::setw(4) << vertex_source;
        //std::list<std::string> la = adjacent_vertices_list(vertex_source);
        auto edges = v_cur->list_edge_v0();
        for (auto edge : edges) {
            if (_GRAPH_DEBUG)
                std::cout << "traverse: " << edge->v1() << " - " << std::boolalpha << vb[edge->v1()] << "\n";
            if (!vb[edge->v1()]) {
                if (_GRAPH_DEBUG)
                    std::cout << "traversing: " << edge->v1() << " - " << std::boolalpha << vb[edge->v1()] << "\n";
                traverse(edge->v1(), vb, traverse_path, v_cur);
            }
        }
    }
    //
    std::map<std::string, VertexBase<Tipo_Info_Vertex, Tipo_Info_Edge> *> _vertices;
    std::string _name;
};

} /* namespace graphlib */

#endif /* GRAPH_H_ */
