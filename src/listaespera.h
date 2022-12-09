/*
 * listaespera.h
 *
 *  Created on: 5 dic 2022
 *      Author: Lau
 */

#ifndef SRC_LISTAESPERA_H_
#define SRC_LISTAESPERA_H_

class listaespera {
	private:
	int id_lista_;
	int posicion_;
	string usuario_uco_;
public:
	inline listaespera(int id_lista,
	int posicion,
	string usuario_uco) {
		id_lista_ = id_lista;
		posicion_ = posicion;
		usuario_uco_ = usuario_uco;
	}
	inline int getIdLista() const {return id_lista_;};

	inline void setIdLista(int idLista) {id_lista_ = idLista;};

	inline int getPosicion() const {return posicion_;};

	inline void setPosicion(int posicion) {posicion_ = posicion;};

	inline string getUsuarioUco() const {return usuario_uco_;};

	inline void setUsuarioUco(string usuarioUco) {usuario_uco_ = usuarioUco;};

	bool insertar_alumno_listaespera(int id_curso,string dni);
	bool eliminar_alumno_listaespera(int id_curso,string dni);


};

#endif /* SRC_LISTAESPERA_H_ */
