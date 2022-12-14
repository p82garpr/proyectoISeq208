
#ifndef CURSO_H_
#define CURSO_H_
#define CHAR_SIZE 50
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

	curso(int id_curso=0, string nombre="empty", string fecha_ini="00/00/0000", string fecha_fin="00/00/0000", string descripcion="empty", float estadistica_alcance=0.0,int aforo=100, int alumnos_inscritos=0);

	virtual ~curso();

	//GETTERS Y SETTERS
	inline void setId(int id){id_curso_=id;}
	inline int getAlumnosInscritos() const {return alumnos_inscritos_;}

	inline void setAlumnosInscritos(int alumnosInscritos) {alumnos_inscritos_ = alumnosInscritos;}

	inline const string& getDescripcion() const {return descripcion_;}

	inline void setDescripcion(const string &descripcion) {descripcion_ = descripcion;}

	inline float getEstadisticaAlcance() const {return estadistica_alcance_;}

	inline void setEstadisticaAlcance(float estadisticaAlcance) {estadistica_alcance_ = estadisticaAlcance;}

	inline const string& getFechaFin() const {return fecha_fin_;}

	void setFechaFin(const string &fechaFin);

	inline const string& getFechaIni() const {return fecha_ini_;}

	void setFechaIni(const string &fechaIni);

	inline int getIdCurso() const {return id_curso_;}

	inline void setIdCurso(int idCurso) {id_curso_ = idCurso;}

	inline const string& getNombre() const {return nombre_;}

	inline void setNombre(const string &nombre) {nombre_ = nombre;}

	inline void setAforo(int aforo){aforo_=aforo;}
	inline int getAforo(){return aforo_;}

	void mostrar(curso c);

	bool volcar_curso(curso c);

	void listarCursos();

	bool buscar_curso(string id);

	int get_numero_cursos();


};

#endif /* CURSO_H_ */
