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
		string lista_cursos_;
	public:
		/*alumno(list<string> listacursos={ }){lista_cursos_=listacursos;}*/
		inline alumno(string usuario_uco="",
				string nombre_completo="",
				string fecha_nacimiento="",
				string dni="",
				string contrasena="",
				string lista_cursos=""):usuario(usuario_uco,nombre_completo,fecha_nacimiento,dni,contrasena){lista_cursos_=lista_cursos;}
		//virtual ~alumno();

		inline void setListaCursos(string lista){lista_cursos_=lista;}
		inline string& getListaCursos(){return lista_cursos_;}
		void listar_cursos();
		void registro();
		//void inscribir_curso();
		bool inicio_sesion_bbdd();
		alumno get_alumno(string ID); //receives DNI and get a "struct" of the user found, if not, returns struct with USER "empty"
		void Perfil(string DNI);
		void inscribir_curso(string IDCurso,string DNI);
		int buscar_alumno(string DNI, string &aux);
		int cuenta_alumnos(string IDcurso);
		int buscar_curso(string IDcurso);
		void modificar_inscritos(int inscritos, int nregistro);
};

#endif /* SRC_ALUMNO_H_ */
