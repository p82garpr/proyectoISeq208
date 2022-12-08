/*
 * visitante.h
 *
 *  Created on: 3 dic 2022
 *      Author: rafag
 */

#ifndef SRC_VISITANTE_H_
#define SRC_VISITANTE_H_
#include <string>

//#include "alumno.h"

using namespace std;


class visitante {
	private:
		string id_;

	public:
		inline visitante(string id="empty"){id_=id;}
		virtual ~visitante();
};


#endif /* SRC_VISITANTE_H_ */
