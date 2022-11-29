/*
 * curso.cpp
 *
 *  Created on: 29 nov 2022
 *      Author: Isaac
 */

#include "curso.h"
#include <mysql.h>

curso::curso(string id_curso, string nombre, string fecha_ini, string fecha_fin, string descripcion, float estadistica_alcance, int alumnos_inscritos) {
	id_curso_=id_curso;
	nombre_=nombre;
	fecha_ini_=fecha_ini;
	descripcion_=descripcion;
	estadistica_alcance_=estadistica_alcance;
	alumnos_inscritos_=alumnos_inscritos;

}

void curso::mostrar_informacion(int id_curso){
	//select * from curso where id=id_curso


}

curso::~curso() {
	// TODO Auto-generated destructor stub
}

