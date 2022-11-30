/*
 * usuario.h
 *
 *  Created on: 29 nov 2022
 *      Author: Lau
 */

#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>

using namespace std;

class usuario {
private:
	string usuario_uco_;
	string nombre_completo_;
	string fecha_nacimiento_;
	string dni_;
	string contrasena_;

public:
	usuario(string usuario_uco_,
	string nombre_completo_,
	string fecha_nacimiento_,
	string dni_,
	string contrasena_);


	//GETTERS Y SETTERS

	inline const string& getContrasena() const { return contrasena_;}

	inline void setContrasena(const string &contrasena) {contrasena_ = contrasena;}

	inline const string& getDni() const {return dni_;}

	inline void setDni(const string &dni) {	dni_ = dni;}

	inline const string& getFechaNacimiento() const {return fecha_nacimiento_;}

	inline void setFechaNacimiento(const string &fechaNacimiento) {fecha_nacimiento_ = fechaNacimiento;}

	inline const string& getNombreCompleto() const {return nombre_completo_;}

	inline void setNombreCompleto(const string &nombreCompleto) {nombre_completo_ = nombreCompleto;}

	inline const string& getUsuarioUco() const {return usuario_uco_;}

	inline void setUsuarioUco(const string &usuarioUco) {usuario_uco_ = usuarioUco;}

	//void iniciar_sesion();
	bool iniciar_sesion(string DNI, string pass);
	bool iniciar_sesion(string usuario, string pass);
};

#endif /* USUARIO_H_ */
