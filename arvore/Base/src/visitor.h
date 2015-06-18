/*
 * visitor.h
 *
 *  Created on: Jun 1, 2015
 *      Author: gian
 */

#ifndef VISITOR_H_
#define VISITOR_H_

#include <iomanip>
#include <iostream>

template<class Tipo>
class Visitor{
public:
    virtual ~Visitor(){}
    virtual void visit(Tipo){}
    virtual void pre(Tipo){}
    virtual void in(Tipo){}
    virtual void pos(Tipo){}
    virtual void begin(){}
    virtual void end(){}
};

template<class Tipo>
class Visitor_Out : public Visitor<Tipo>{
public:
    virtual ~Visitor_Out(){}
    void visit(Tipo w){
        std::cout << std::setw(4) << w;
    }
};

template<class Tipo>
class Visitor_Pre_Out : public Visitor<Tipo>{
public:

    virtual ~Visitor_Pre_Out(){}
    virtual void begin(){
        std::cout << std::endl << "Pre: ";
    }
    void pre(Tipo w){
        std::cout << std::setw(4) << w;
    }
    virtual void end(){
        std::cout << std::endl;
    }
};

template<class Tipo>
class Visitor_In_Out : public Visitor<Tipo>{
public:
    virtual ~Visitor_In_Out(){}
    void in(Tipo w){
        std::cout << std::setw(4) << w;
    }
    virtual void end(){
        std::cout << std::endl;
    }
    virtual void begin(){
            std::cout << std::endl << "In : ";
        }
};

template<class Tipo>
class Visitor_Pos_Out : public Visitor<Tipo>{
public:
    virtual ~Visitor_Pos_Out(){}
    void pos(Tipo w){
        std::cout << std::setw(4) << w;
    }
    virtual void end(){
        std::cout << std::endl;
    }
    virtual void begin(){
            std::cout << std::endl << "Pos: ";
        }
};

#endif /* VISITOR_H_ */
