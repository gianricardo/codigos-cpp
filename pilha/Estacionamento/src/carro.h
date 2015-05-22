/*
 * carro.h
 *
 *  Created on: May 21, 2015
 *      Author: gian
 */

#ifndef CARRO_H_
#define CARRO_H_

#include <string>

class Carro {
public:
    Carro();
    Carro(std::string placa);
    std::string placa(void)const;
    void manobrou(void);
    int manobras(void)const;
    virtual ~Carro();
private:
    int _manobras;
    std::string _placa;
};

#endif /* CARRO_H_ */
