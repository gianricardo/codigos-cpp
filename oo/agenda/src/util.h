/*
 * Util.h
 *
 *  Created on: Apr 20, 2015
 *      Author: gian
 */

#ifndef UTIL_H_
#define UTIL_H_

namespace trabalho2 {

class Util {
public:
	static std::string tolower(std::string p_st);
	static std::string* separa(std::string p_st,std::string separador, int qtd);
	static int ler_int(int limite_inf=0,int limite_sup=0);
	static long ler_long(int limite_inf=0,int limite_sup=0);
};

} /* namespace trabalho2 */

#endif /* UTIL_H_ */
