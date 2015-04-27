/*
 * arc.h
 *
 *  Created on: Apr 27, 2015
 *      Author: gian
 */

#ifndef ARC_H_
#define ARC_H_

#include "edge.h"

namespace graphlib {

template<class Tipo_Info_Arc>
class Arc: public Edge<Tipo_Info_Arc> {
public:
    Arc(){
    }
    Arc(std::string from,std::string to) : Edge<Tipo_Info_Arc>(from, to) {
     }
    virtual ~Arc() {
    }
    //
    std::string from() const {
        return Edge<Tipo_Info_Arc>::v0();
    }
    std::string to() const {
        return Edge<Tipo_Info_Arc>::v1();
    }
    void from(std::string f){
        Edge<Tipo_Info_Arc>::v0(f);
    }
    void to(std::string f){
        Edge<Tipo_Info_Arc>::v1(f);
    }
};

} /* namespace graphlib */

#endif /* ARC_H_ */
