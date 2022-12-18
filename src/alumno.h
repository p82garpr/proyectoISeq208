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
		//CONSTRUCTOR
		inline alumno(string usuario_uco="",
				string nombre_completo="",
				string fecha_nacimiento="00/00/0000",
				string dni="00000000X",
				string contrasena="",
				string lista_cursos=""):usuario(usuario_uco,nombre_completo,fecha_nacimiento,dni,contrasena){lista_cursos_=lista_cursos;}

		//SETTERS Y GETTERS
		inline void setListaCursos(string lista){lista_cursos_=lista;}
		inline string& getListaCursos(){return lista_cursos_;}

		bool registro(alumno a);

		bool inicio_sesion_bbdd(string dni, string pass);

		alumno get_alumno(string ID); //receives DNI and get a "struct" of the user found, if not, returns struct with USER "empty"

		void Perfil(string DNI);

		bool inscribir_curso(string IDCurso,string DNI);

		void modificar_listacursos(string cadaux, string Dni);

		long buscar_alumno(string DNI, string &aux);

		int cuenta_alumnos(string IDcurso);

		int buscar_curso(string IDcurso);

		void modificar_inscritos(int inscritos, int nregistro);
};

#endif /* SRC_ALUMNO_H_ */
