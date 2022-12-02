/*
 * curso.cpp
 *
 *  Created on: 29 nov 2022
 *      Author: Rafa
 */

#include "curso.h"
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <errno.h>
#include <stdio.h>
using namespace std;

void enter(){
	cout<<"Presiona Enter para continuar...";
	getchar();
}
void curso::mostrar(curso c){
	cout<<"ID----------:"<<c.id_curso_<<endl;
	cout<<"Nombre----------:"<<c.nombre_<<endl;
	cout<<"Fecha ini----------:"<<c.fecha_ini_<<endl;
	cout<<"Fecha fin----------:"<<c.fecha_fin_<<endl;
	cout<<"Descripcion----------:"<<c.descripcion_<<endl;
	cout<<"Alcance----------:"<<c.estadistica_alcance_<<endl;
	cout<<"Aforo----------:"<<c.aforo_<<endl;
	cout<<"N inscritos----------:"<<c.alumnos_inscritos_<<endl;
	cout<<"___________________________________________"<<endl;
}

/*
void limpiarLinea(){
	int ch;
	while((ch= fgetc(stdin))!= EOF){
		if(ch == '\n') break;
	}
}*/

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


void curso::volcar_curso(){
	ofstream escritura;
	ifstream verificador;

	bool encontrado=false;
	string id;
	string nombre;
	string fechaIni;
	string fechaFin;
	string desc;
	string aforo;
	string statss;
	string inscrr;
	int inscr=0;
	float stats=0.0;

	verificador.open("cursos.txt",ios::in);
	escritura.open("cursos.txt",ios::app);
	if(escritura.is_open() && verificador.is_open()){
		cout<<"\t ***Crear Curso***\t\n\n";
		//fflush(stdin);
		cout<<"Ingresa el id del curso: ";
		getline(cin,id);
		string auxID=id;
		cout<<endl;
		do{
			verificador.seekg(0);
			getline(verificador,id);
			while(!verificador.eof())
			{
				getline(verificador,nombre);
				getline(verificador,fechaIni);
				getline(verificador,fechaFin);
				getline(verificador,desc);
				getline(verificador,statss);
				getline(verificador,aforo);
				getline(verificador,inscrr);
				if(id==auxID){
					encontrado=true;
					cout<<"YA EXISTE UN CURSO CON ESE CODIGO \n";
					break;
				}
				getline(verificador,id);
			}
			if(verificador.eof()&&auxID!=id){
				encontrado=false;
			}
		}while(encontrado==true);
		id=auxID;
		//fflush(stdin);
		cout<<"Ingresa el nombre del curso: ";
		getline(cin,nombre);
		cout<<endl;

		//fflush(stdin);
		cout<<"Ingresa la fecha inicio del curso: ";
		getline(cin,fechaIni);
		cout<<endl;

		//fflush(stdin);
		cout<<"Ingresa la fecha fin del curso: ";
		getline(cin,fechaFin);
		cout<<endl;

		//fflush(stdin);
		cout<<"Introduce una breve descripcion del curso: ";
		getline(cin,desc);
		cout<<endl;

		//fflush(stdin);
		cout<<"Ingresa el aforo del curso: ";
		getline(cin,aforo);
		cout<<endl;

		escritura<<id<<"\n"<<nombre<<"\n"<<fechaIni<<"\n"<<fechaFin<<"\n"<<desc<<"\n"<<stats<<"\n"<<aforo<<"\n"<<inscr<<"\n";

	}
	//cout<<id<<endl;
	cout<<"Se ha añadido correctamente el curso"<<endl;
	escritura.close();
	verificador.close();


}

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
	/*char nombre[50];
	char fecha_ini[12];
	char fecha_fin[12];
	char desc[200];*/


	string nombre;
	string fecha_ini;
	string fecha_fin;
	string desc;

	//cin.ignore();
	idd=getInt("Introduce ID del curso: ");
	curso aux;
	//cout<<"Introduce el nombre del curso: ";
	//fflush(stdin);
	/*
	strcpy(nombre,getString("Introduce el nombre del curso: ").c_str());
	strcpy(fecha_ini,getString("Introduce la fecha de inicio del curso: ").c_str());
	strcpy(fecha_fin,getString("Introduce la fecha de fin del curso ").c_str());
	strcpy(desc,getString("Introduce la descripcion del cruso:  ").c_str());
	*/
	aux.setId(idd);
	cin.ignore();
	cout<<"\n Introduce el nombre del curso: ";
	getline(cin,nombre);
	cout<<"\n Introduce la fecha de inicio del curso: ";
	getline(cin,fecha_ini);
	cout<<"\n Introduce la fecha de fin del curso: ";
	getline(cin,fecha_fin);
	cout<<"\n Introduce la descripcion del cruso: ";
	getline(cin,desc);
	nombre=nombre.c_str();
	aforo=getInt("Introduce el aforo del curso: ");
	aux.setNombre(nombre);
	aux.setFechaIni("12-12-12");
	aux.setFechaFin(fecha_fin);
	aux.setDescripcion(desc);
	aux.setAforo(aforo);
	aux.setEstadisticaAlcance(0.0);
	aux.setAlumnosInscritos(0);
	fstream e("Cursos.txt", ios::out | ios::in | ios::binary);
	e.seekp(0,ios::end);
	mostrar(aux);
	e.write((char*)&aux,sizeof(curso));
	e.close();

	/*
	curso auxx = getCurso(aux.id_curso_);
	//if(auxx.id_curso_!=0){
		//cout<<"El registro ya existe!!"<<endl;
	//}else{
		fstream e("Cursos.txt", ios::out | ios::in | ios::binary);
		if(e.is_open()){
			//cout<<"HOLAAAA";
			//e.seekp(((aux.id_curso_)-1)*sizeof(curso));
			e.seekp(0,ios::end);
			e.write((char*)&aux,sizeof(curso));
			e.close();
		}else{
			cout<<"Error"<<strerror(errno);
		}
	//}
	 */
}

void curso::listarCursos(){
	//fstream e("Cursos.txt", fstream::in | fstream::binary);
	fstream e("Cursos.txt", ios::out | ios::in | ios::binary);
	curso aux;
	//e.seek(0,ios::)
/*
	if(e.is_open()){
		e.read((char *)&aux, sizeof(curso));
		while(!e.eof()){
			mostrar(aux);
			e.read((char *)&aux, sizeof(curso));
			}
		e.close();
		}
*/
	e.read((char *)&aux, sizeof(curso));
	mostrar(aux);
	e.close();


	//e.read((char *)&aux.id_curso_, sizeof(aux.id_curso_));
	//e.read((char *)&aux.nombre_, sizeof(aux.nombre_));
	//e.read((char *)&aux.fecha_ini_, sizeof(aux.fecha_ini_));
	//e.read((char *)&aux.fecha_fin_, sizeof(aux.fecha_fin_));
	//e.read((char *)&aux.descripcion_, sizeof(aux.descripcion_));
	//e.read((char *)&aux.estadistica_alcance_, sizeof(aux.estadistica_alcance_));
	//e.read((char *)&aux.aforo_, sizeof(aux.aforo_));
	//e.read((char *)&aux.alumnos_inscritos_, sizeof(aux.alumnos_inscritos_));
	//e.read((char *)&aux, sizeof(curso));

}

curso::~curso() {
	// TODO Auto-generated destructor stub
}

