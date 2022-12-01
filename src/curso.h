/*
 * curso.h
 *
 *  Created on: 29 nov 2022
 *      Author: Isaac
 */

#ifndef CURSO_H_
#define CURSO_H_
#include <iostream>
#include <string>
using namespace std;

class curso {
private:
	int id_curso_;
	string nombre_;
	string fecha_ini_;
	string fecha_fin_;
	string descripcion_;
	float estadistica_alcance_;
	int aforo_;
	int alumnos_inscritos_;
public:


	curso(int id_curso, string nombre="empty", string fecha_ini="00/00/00", string fecha_fin="00/00/00", string descripcion="empty", float estadistica_alcance=0.0,int aforo=100, int alumnos_inscritos=0);
	virtual ~curso();

	//GETTERS Y SETTERS
	inline int getAlumnosInscritos() const {return alumnos_inscritos_;}

	inline void setAlumnosInscritos(int alumnosInscritos) {alumnos_inscritos_ = alumnosInscritos;}

	inline const string& getDescripcion() const {return descripcion_;}

	inline void setDescripcion(const string &descripcion) {descripcion_ = descripcion;}

	inline float getEstadisticaAlcance() const {return estadistica_alcance_;}

	inline void setEstadisticaAlcance(float estadisticaAlcance) {estadistica_alcance_ = estadisticaAlcance;}

	inline const string& getFechaFin() const {return fecha_fin_;}

	inline void setFechaFin(const string &fechaFin) {fecha_fin_ = fechaFin;}

	inline const string& getFechaIni() const {return fecha_ini_;}

	inline void setFechaIni(const string &fechaIni) {fecha_ini_ = fechaIni;}

	inline int getIdCurso() const {return id_curso_;}

	inline void setIdCurso(int idCurso) {id_curso_ = idCurso;}

	inline const string& getNombre() const {return nombre_;}

	inline void setNombre(const string &nombre) {nombre_ = nombre;}

	inline void setAforo(int aforo){aforo_=aforo;}
	inline int getAforo(){return aforo_;}
	curso getCurso(int id);

	void mostrar_informacion(int id_curso);

	//void volcar_curso();
	void agregarCurso();
	void mostrar(curso c);
	void listarCursos();


};

int getInt(string msj);
string getString(string msj);




#endif /* CURSO_H_ */
