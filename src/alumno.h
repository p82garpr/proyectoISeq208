/*
 * alumno.h
 *
 *  Created on: 30 nov 2022
 *      Author: rafag
 */


#ifndef SRC_ALUMNO_H_
#define SRC_ALUMNO_H_

#include <list>
#include <string>
#include "usuario.h"
using namespace std;

class alumno: public usuario{
	private:
		list <string> lista_cursos_;
	public:
		/*alumno(list<string> listacursos={ }){lista_cursos_=listacursos;}*/
		inline alumno(string usuario_uco,
				string nombre_completo,
				string fecha_nacimiento,
				string dni,
				string contrasena,
				list <string> lista_cursos={}):usuario(usuario_uco,nombre_completo,fecha_nacimiento,dni,contrasena){lista_cursos_=lista_cursos;}
		//virtual ~alumno();
		void listar_cursos();
		void registro();
		void inscribir_curso();
		bool inicio_sesion_bbdd();
};

#endif /* SRC_ALUMNO_H_ */
