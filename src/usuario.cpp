/*
 * usuario.cpp
 *
 *  Created on: 29 nov 2022
 *      Author: Lau
 */

#include "usuario.h"
#include <iostream>

using namespace std;

usuario::usuario(string usuario_uco,
		string nombre_completo,
		string fecha_nacimiento,
		string dni,
		string contrasena) {
	usuario_uco_=usuario_uco;
	nombre_completo_=nombre_completo;
	fecha_nacimiento_=fecha_nacimiento;
	dni_=dni;
	contrasena_=contrasena;

}



