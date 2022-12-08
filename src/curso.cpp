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
int numero_cursos=0;

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
	int cont=0;


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
				cont++;
				if(id==auxID){
					encontrado=true;
					cout<<"YA EXISTE UN CURSO CON ESE CODIGO \n";
					//cout<<"Introduce un código válido"<<endl;
					//getline(cin,id);
					//break;

					cout<<"saliendo..."<<endl; //ENTRA EN BUCLE CUANDO PIDO OTRO
					return;

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

		if(cont==0)
			escritura<<id<<"\n"<<nombre<<"\n"<<fechaIni<<"\n"<<fechaFin<<"\n"<<desc<<"\n"<<stats<<"\n"<<aforo<<"\n";
		else
			escritura<<"\n"<<id<<"\n"<<nombre<<"\n"<<fechaIni<<"\n"<<fechaFin<<"\n"<<desc<<"\n"<<stats<<"\n"<<aforo<<"\n";

	}
	//cout<<id<<endl;
	cout<<"Se ha añadido correctamente el curso"<<endl;
	escritura.close();
	verificador.close();


}

void curso::agregarCurso(){
	int idd,aforo;
	string nombre;
	string fecha_ini;
	string fecha_fin;
	string desc;


	idd=getInt("Introduce ID del curso: ");
	curso aux;
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

}

void curso::listarCursos(){
	curso CAux;
	int i=0;
	string vacio;
	vacio.clear();
	string aux;
	ifstream read;
	read.open("Cursos.txt",ios::in);
			if(read.is_open()){
				cout<<"\t\t***LISTADO DE TODOS LOS CURSOS DISPONIBLES***\t\t\n";
				getline(read,aux);
				id_curso_=stoi(aux);
				while(!read.eof()){
					i++;

					getline(read,nombre_);
					getline(read,fecha_ini_);
					getline(read,fecha_fin_);
					getline(read,descripcion_);
					getline(read,aux);
					estadistica_alcance_=stof(aux);
					getline(read,aux);
					aforo_=stoi(aux);
					getline(read,aux);
					alumnos_inscritos_=stoi(aux);
					CAux.mostrar(*this);
					cout<<"\n\n";
					aux.clear();
					getline(read,aux);
					if(aux==vacio){
						break;
					}
					//cout<<"LO QUE TIENE AUX ES: "<<aux<<endl;
					id_curso_=stoi(aux);
				}

			}

			read.close();
			cout<<"Hay un total de "<<i<<" cursos"<<endl;
			numero_cursos=i;
}

bool curso::buscar_curso(string id){
	curso busca;
	string id_linea;
	string aux;
	ifstream read;
	read.open("Cursos.txt",ios::in);
	cout<<endl;
	bool encontrado =false;
	do{
		read.seekg(0);
		getline(read,id_linea);
		while(!read.eof()){
			getline(read,aux);
			getline(read,aux);
			getline(read,aux);
			getline(read,aux);
			getline(read,aux);
			getline(read,aux);
			getline(read,aux);
			if(id_linea==id){
				encontrado=true;
				read.close();
				return encontrado;
			}
			getline(read,id_linea);

		}
		if(read.eof()&&id!=id_linea){
			encontrado=false;
		}
	}while(encontrado==true);
	read.close();
	return encontrado;
}


int curso::get_numero_cursos(){
	return numero_cursos;
}

curso::~curso() {
	// TODO Auto-generated destructor stub
}

