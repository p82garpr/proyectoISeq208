#include "usuario.h"
#include <iostream>

using namespace std;

//CONSTRUCTOR
usuario::usuario(string usuario_uco,
		string nombre_completo,
		string fecha_nacimiento,
		string dni,
		string contrasena) {
	usuario_uco_=usuario_uco;
	nombre_completo_=nombre_completo;

	if(fecha_nacimiento.size()!=10){

		cout<<"Fecha invalida, vuelva a intentarlo"<<endl;

		fecha_nacimiento_="error";

		}else

			fecha_nacimiento_=fecha_nacimiento;

	if(dni.size()!=9){

		cout<<"Dni invalido, vuelva a intentarlo"<<endl;

		dni_="error";

	}else

		dni_=dni;
		contrasena_=contrasena;

}

//SETTER
void usuario::setDni(const string &dni){

	if(dni.size()!=9){
		cout<<"Dni invalido, vuelva a intentarlo"<<endl;
		dni_="error";

	}else
		dni_=dni;
}

//SETTER
void usuario::setFechaNacimiento(const string &fechaNacimiento){
	if(fechaNacimiento.size()!=10){

		cout<<"Fecha invalida, vuelva a intentarlo"<<endl;

		fecha_nacimiento_="error";

	}else
		fecha_nacimiento_=fechaNacimiento;
}

//FUNCION PARA INICIAR SESION
bool usuario::iniciar_sesion(string id, string pass){

	if((id==dni_ || id==usuario_uco_ ) && pass==contrasena_){

		return true;

	}else{

		return false;
	}
}




