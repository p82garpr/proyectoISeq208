/*
 * curso.h
 *
 *  Created on: 29 nov 2022
 *      Author: Isaac
 */

#ifndef CURSO_H_
#define CURSO_H_
#include <iostream>
using namespace std;

class curso {
private:
	int id_curso_;
	string nombre_;
	string fecha_ini_;
	string fecha_fin_;
	string descripcion_;
	float estadistica_alcance_;
	int alumnos_inscritos_;
public:


	curso(int id_curso, string nombre="empty", string fecha_ini="00/00/00", string fecha_fin="00/00/00", string descripcion="empty", float estadistica_alcance=0.0, int alumnos_inscritos=0);
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

	void mostrar_informacion(int id_curso);


};

#endif /* CURSO_H_ */
