/*
 * administrador.h
 *
 *  Created on: 5 dic 2022
 *      Author: Lau
 */

#ifndef SRC_ADMINISTRADOR_H_
#define SRC_ADMINISTRADOR_H_
#include <list>
#include <string>
#include "usuario.h"
#include "curso.h" //funcion ver curso(MOSTRAR) y buscar curso(BUSCAR CURSO)
using namespace std;

class administrador: public usuario{
	private:
	string id_ad_;

	public:
	inline administrador(string usuario_uco="",
					string nombre_completo="",
					string fecha_nacimiento="",
					string dni="",
					string contrasena="",
					string id_ad=""):usuario(usuario_uco,nombre_completo,fecha_nacimiento,dni,contrasena){id_ad_=id_ad;}


	const string& getIdAd() const {return id_ad_;}
	void setIdAd(const string &idAd) {id_ad_ = idAd;};
	//FUNCION INICIAR SESION


};

#endif /* SRC_ADMINISTRADOR_H_ */
