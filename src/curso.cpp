/*
 * curso.cpp
 *
 *  Created on: 29 nov 2022
 *      Author: Rafa
 */


#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif


#include "curso.h"
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <errno.h>
using namespace std;


void curso::mostrar(curso c){
	cout<<"ID----------:"<<c.id_curso_<<endl;
	cout<<"Nombre----------:"<<c.nombre_<<endl;
	cout<<"Fecha ini----------:"<<c.fecha_ini_<<endl;
	cout<<"Fecha fin----------:"<<c.fecha_fin_<<endl;
	cout<<"Descripcion----------:"<<c.descripcion_<<endl;
	cout<<"Aforo----------:"<<c.aforo_<<endl;
	cout<<"___________________________________________"<<endl;
}


int getInt(string msj){
	int n;
	cout<<msj<<endl;
	cin>>n;
	return n;
}


string getString(string msj){
	string s;
	cout<<msj<<endl;
	getline(cin,s);
	return s;
}




//#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h"
curso::curso(int id_curso, string nombre, string fecha_ini, string fecha_fin, string descripcion, float estadistica_alcance,int aforo, int alumnos_inscritos) {
	id_curso_=id_curso;
	nombre_=nombre;
	fecha_ini_=fecha_ini;
	descripcion_=descripcion;
	estadistica_alcance_=estadistica_alcance;
	aforo_=aforo;
	alumnos_inscritos_=alumnos_inscritos;

}

void curso::mostrar_informacion(int id_curso){
	//select * from curso where id=id_curso


}

/*
void curso::volcar_curso(){
	ofstream escritura;
	ifstream verificador;

	string id;
	string nombre;
	string fechaIni;
	string fechaFin;
	string desc;
	string aforo;
	verificador.open("cursos.txt",ios::in);
	escritura.open("cursos.txt",ios::app);
	if(escritura.is_open() && verificador.is_open()){
		cout<<"\t ***Crear Curso***\t\n\n";
		fflush(stdin);
		cout<<"Ingresa el id del curso: ";
		getline(cin,id);
		cout<<endl;



		do{
			verificador.seekg(0);
			getline(verificador,)

		}while();








		fflush(stdin);
		cout<<"Ingresa el nombre del curso: ";
		getline(cin,nombre);
		cout<<endl;

		fflush(stdin);
		cout<<"Ingresa la fecha inicio del curso: ";
		getline(cin,fechaIni);
		cout<<endl;

		fflush(stdin);
		cout<<"Ingresa la fecha fin del curso: ";
		getline(cin,fechaFin);
		cout<<endl;

		fflush(stdin);
		cout<<"Introduce una breve descripcion del curso: ";
		getline(cin,desc);
		cout<<endl;

		fflush(stdin);
		cout<<"Ingresa el id del curso: ";
		getline(cin,aforo);
		cout<<endl;



	}


}*/

// 00:24


curso curso::getCurso(int id){
	fstream e("Cursos.txt", ios::out | ios::in | ios::binary);
	curso aux(id);
	if(e.is_open()){
		e.seekp(((id)-1)*sizeof(curso));
		e.write((char*)&aux,sizeof(curso));
		e.close();
	}
	return aux;
}


void curso::agregarCurso(){
	int idd,aforo;
	char nombre[50];
	char fecha_ini[12];
	char fecha_fin[12];
	char desc[200];
	//cin.ignore();
	idd=getInt("Introduce ID del curso: ");
	curso aux(idd);
	//cout<<"Introduce el nombre del curso: ";
	fflush(stdin);
	strcpy(nombre,getString("Introduce el nombre del curso: ").c_str());
	strcpy(fecha_ini,getString("Introduce la fecha de inicio del curso: ").c_str());
	strcpy(fecha_fin,getString("Introduce la fecha de fin del curso ").c_str());
	strcpy(desc,getString("Introduce la descripcion del cruso:  ").c_str());

	aforo=getInt("Introduce el aforo del curso: ");
	//aux.setIdCurso(idd);
	aux.setNombre(nombre);
	aux.setFechaIni(fecha_ini);
	aux.setFechaFin(fecha_fin);
	aux.setAforo(aforo);
	curso auxx = getCurso(aux.id_curso_);
	//if(auxx.id_curso_!=0){
		//cout<<"El registro ya existe!!"<<endl;
	//}else{
		fstream e("Cursos.txt", ios::out | ios::in | ios::binary);
		if(e.is_open()){
			cout<<"HOLAAAA";
			e.seekp(((aux.id_curso_)-1)*sizeof(curso));
			e.write((char*)&aux,sizeof(curso));
			e.close();
		}else{
			cout<<"Error"<<strerror(errno);
		}
	//}
}

void curso::listarCursos(){
	fstream e("Cursos.txt", ios::out | ios::in | ios::binary);
	curso aux(0);
	if(e.is_open()){
		e.read((char *)&aux, sizeof(curso));
		while(!e.eof()){
			if(aux.id_curso_ !=0){
			mostrar(aux);
			}
			e.read((char *)&aux, sizeof(curso));
			}
			e.close();
		}
}






curso::~curso() {
	// TODO Auto-generated destructor stub
}

