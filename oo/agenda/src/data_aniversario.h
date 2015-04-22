/*
 * data_aniversario.h
 *
 *  Created on: Apr 17, 2015
 *      Author: gian
 */

#ifndef DATA_ANIVERSARIO_H_
#define DATA_ANIVERSARIO_H_

namespace trabalho2 {

class Data_Aniversario {
public:
	Data_Aniversario();
	Data_Aniversario(int ddia, int mmes);
	int dia() const ;
	void dia(int ndia);
	int mes() const ;
	void mes(int nmes);
	bool operator==(Data_Aniversario const& outra) const ;
private:
	int _dia,_mes;
};

} /* namespace trabalho2 */

#endif /* DATA_ANIVERSARIO_H_ */
