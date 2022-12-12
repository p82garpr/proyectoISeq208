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

void usuario::setDni(const string &dni){
	if(dni.size()!=10){
		cout<<"Dni invalido, vuelva a intentarlo"<<endl;
		cout<<"Saliendo..."<<endl;
		dni_="error";

	}else
		dni_=dni;
}

void usuario::setFechaNacimiento(const string &fechaNacimiento){
	if(fechaNacimiento.size()!=10){
		cout<<"Dni invalido, vuelva a intentarlo"<<endl;
		cout<<"Saliendo..."<<endl;
		fecha_nacimiento_="error";

	}else
		fecha_nacimiento_=fechaNacimiento;
}

bool usuario::iniciar_sesion(string id, string pass){
	if((id==dni_ || id==usuario_uco_ ) && pass==contrasena_){
		return true;
	}else{
		return false;
	}
}




/*
bool usuario::iniciar_sesion(string usuario, string pass){
	if(usuario==usuario_uco_ && pass=contrasena_){
		return true;
	}else{
		return false;
	}
}
*/



