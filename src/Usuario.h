/*
 * Usuario.h
 *
 *  Created on: 30 nov 2022
 *      Author: rafag
 */
#include <string>
using namespace std;
#ifndef USUARIO_H_
#define USUARIO_H_

class Usuario {
private:
	string Usuario_Uco_,nombre_completo_,DNI_,password,fecha_nacimiento_;

public:
	Usuario( string DNI,string usuario_uco,string nombre_completo,string password, string fecha_nacimiento);
	virtual ~Usuario();
};

#endif /* USUARIO_H_ */
