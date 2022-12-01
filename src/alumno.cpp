/*
 * alumno.cpp
 *
 *  Created on: 30 nov 2022
 *      Author: rafag
 */

#include "alumno.h"
#include <list>
#include <string>


void alumno::listar_cursos(){
	list<string>::iterator it;
	for(it=lista_cursos_.begin();it!=lista_cursos_.end();it++){
		cout<<*it<<endl;
	}
}


/*
alumno::alumno() {
	// TODO Auto-generated constructor stub

}

alumno::~alumno() {
	// TODO Auto-generated destructor stub
}
*/
