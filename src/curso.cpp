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
	if(fecha_ini.size()!=10){
				cout<<"Fecha invalida, vuelva a intentarlo"<<endl;
				cout<<"Saliendo..."<<endl;
				fecha_ini_="error";

			}else
				fecha_ini_=fecha_ini;
	if(fecha_fin.size()!=10){
				cout<<"Fecha invalida, vuelva a intentarlo"<<endl;
				cout<<"Saliendo..."<<endl;
				fecha_fin_="error";

			}else
				fecha_fin_=fecha_fin;

	descripcion_=descripcion;
	estadistica_alcance_=estadistica_alcance;
	aforo_=aforo;
	alumnos_inscritos_=alumnos_inscritos;

}

void curso::setFechaIni(const string &fechaIni){
	if(fechaIni.size()!=10){
		cout<<"Fecha invalida, vuelva a intentarlo"<<endl;
		fecha_ini_="error";

	}else
		fecha_ini_=fechaIni;
}

void curso::setFechaFin(const string &fechaFin){
	if(fechaFin.size()!=10){
		cout<<"Fecha invalida, vuelva a intentarlo"<<endl;
		fecha_fin_="error";

	}else
		fecha_fin_=fechaFin;
}



void curso::mostrar_informacion(int id_curso){
	//select * from curso where id=id_curso


}


bool curso::volcar_curso(curso c){
	ofstream escritura;
	ifstream verificador;

	bool encontrado=false;
	string id=to_string(c.getIdCurso());
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

		string auxID=id;

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
					return false;

				}
				getline(verificador,id);
			}
			if(verificador.eof()&&auxID!=id){
				encontrado=false;
			}
		}while(encontrado==true);
		id=auxID;


		if(cont==0)
			escritura<<id<<"\n"<<c.getNombre()<<"\n"<<c.getFechaIni()<<"\n"<<c.getFechaFin()<<"\n"<<c.getDescripcion()<<"\n"<<stats<<"\n"<<c.getAforo()<<"\n"<<inscr;
		else
			escritura<<"\n"<<id<<"\n"<<c.getNombre()<<"\n"<<c.getFechaIni()<<"\n"<<c.getFechaFin()<<"\n"<<c.getDescripcion()<<"\n"<<stats<<"\n"<<c.getAforo()<<"\n"<<inscr;

	}else{
		cout<<"ERROR DE FICHERO"<<endl;
		return false;
	}
	//cout<<id<<endl;
	cout<<"Se ha añadido correctamente el curso"<<endl;
	escritura.close();
	verificador.close();
	return true;


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

