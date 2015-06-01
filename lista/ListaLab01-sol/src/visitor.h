/*
 * visitor.h
 *
 *  Created on: Jun 1, 2015
 *      Author: gian
 */

#ifndef VISITOR_H_
#define VISITOR_H_

template<class Tipo>
class Visitor{
public:
    virtual ~Visitor(){}
    virtual void visit(Tipo)=0;
};


#endif /* VISITOR_H_ */
