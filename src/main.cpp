//============================================================================
// Name        : proyecto.cpp
// Author      : rafag
// Version     :
// Copyright   : Your copyright notice
// Description : Main menu of our fancy program
//============================================================================


#ifdef _WIN32
#define CLEAR "cls"
#elif  defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#error "EL sistema no acepta CLEAR como orden para limpiar pantalla"
#endif


#include <iostream>
#include <string>
#include <list>
#include <conio.h>
#include <stdlib.h>
#include "usuario.h"
#include "curso.h"
#include "alumno.h"
//#include "visitante.h"

using namespace std;

void enter();
void menu_admin();
void menu_visitante();
void menu_alumno(string &dni);

int main() {
	curso c;
	alumno a;
	//visitante v;
	string dni, pass;

		int opcion,modo,vuelve;
		system(CLEAR);
		do{
			system(CLEAR);
			cout<<"\t\t\t****Bienvenido al sistema, seleccione una opcion****\t\t\t\n\n"<<endl;
			cout<<"1. Registrarme"<<endl;
			cout<<"2. Iniciar sesion"<<endl;
			cout<<"3. Entrar como visitante"<<endl;
			cout<<"4. Salir del sistema"<<endl;
			cin>>opcion;
			switch(opcion){
			case 1:
				fflush(stdin);
				a.registro();
				enter();
				vuelve=1;
				break;
			case 2:
				system(CLEAR);
				fflush(stdin);
				cout<<"Introduce el DNI: "<<endl;
				cin>>dni;
				fflush(stdin);
				cout<<"Introduce la contrasena: "<<endl;
				cin>>pass;
				if(dni=="root" && pass=="root"){
					//MENU DE ADMINISTRADOR
					modo=2;
					vuelve =0;
					//vuelve=1;
				}else{
					if(a.inicio_sesion_bbdd(dni,pass)){
						modo=1;
						vuelve =0;
					}else{
						vuelve =1;
						//return 0;
					}
				}
				break;
			case 3:
				modo=3;
				opcion=4;
				break;
			case 4:
				return 0;
				break;
			}

		}while(opcion!=4 && vuelve==1);

		if(modo==2){
				//menu_admin();
				system(CLEAR);
				menu_admin();
				//cout<<"ADMIN"<<endl;
			}else if(modo ==3){
				//menu_visitante();
				system(CLEAR);
				menu_visitante();
				//cout<<"VISITANTE"<<endl;
			}else{
				//menu_alumno();
				system(CLEAR);
				menu_alumno(dni);
				//cout<<"ALUMNO"<<endl;
			}

	return 0;
}


void enter(){
	cout<<"Presiona Enter para continuar...";
	getchar();
}

void menu_admin(){

	int opcion;
	curso c;
	alumno a;
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
	system(CLEAR);
	cout<<"\t\t\t***BIENVENIDO AL MENU DE ADMINISTRADOR***\t\t\t\n\n";
	do{
		system(CLEAR);
		cout<<"\n1. Crear curso"<<endl;
		cout<<"2. Listar cursos"<<endl;
		cout<<"3. Crear usuario"<<endl;
		cout<<"4. Salir "<<endl;
		cin>>opcion;
		switch(opcion){
		case 1:
			fflush(stdin);
			cout<<"\t ***Crear Curso***\t\n\n";
			//fflush(stdin);
			cout<<"Ingresa el id del curso: ";
			getline(cin,id);
			c.setId(stoi(id));
			cout<<endl;
			cout<<"Ingresa el nombre del curso: ";
			getline(cin,nombre);
			c.setNombre(nombre);
			cout<<endl;

			//fflush(stdin);
			cout<<"Ingresa la fecha de inicio del curso (con el siguiente formato: DD/MM/YYYY): ";
			getline(cin,fechaIni);
			if(fechaIni.size()!=10){
				cout<<"No es un carácter válido, saliendo..."<<endl;
				return;
			}
			c.setFechaIni(fechaIni);
			cout<<endl;

			//fflush(stdin);
			cout<<"Ingresa la fecha de fin del curso (con el siguiente formato: DD/MM/YYYY): ";
			getline(cin,fechaFin);
			if(fechaFin.size()!=10){
				cout<<"No es un carácter válido, saliendo..."<<endl;
				return;
			}
			c.setFechaFin(fechaFin);
			cout<<endl;

			//fflush(stdin);
			cout<<"Introduce una breve descripcion del curso: ";
			getline(cin,desc);
			c.setFechaFin(fechaFin);
			cout<<endl;

			//fflush(stdin);
			cout<<"Ingresa el aforo del curso: ";
			getline(cin,aforo);
			c.setAforo(stoi(aforo));
			cout<<endl;
			c.volcar_curso(c);
			enter();
			break;
		case 2:
			fflush(stdin);
			c.listarCursos();
			enter();
			break;
		case 3:
			fflush(stdin);
			a.registro();
			enter();
			break;
		case 4:
			cout<<"Saliendo..."<<endl;
			return;
		}
	}while (opcion!=4);

}
void menu_visitante(){
	int opc;
	curso c;
	system(CLEAR);
	cout<<"\t\t\t***BIENVENIDO AL MENU DE VISITANTE***\t\t\t\n\n";
	do{
		system(CLEAR);
		cout<<"\n1. Listar cursos."<<endl;
		cout<<"2. Inscribir curso."<<endl;
		cout<<"3. Salir"<<endl;
		cin>>opc;
		switch(opc){
		default:
			cout<<"\nIntroduce una opcion valida(1-3)\n"<<endl;
			break;
		case 1:
			c.listarCursos();
			break;
		case 2:
			cout<<"Para inscribirse a un curso, ha de tener una cuenta creada."<<endl;
			break;
		case 3:
			return;
			break;
		}
	}while(opc!=3);
}

void menu_alumno(string &dni){
	int opc;
	curso c;
	alumno a;
	string aux;
	system(CLEAR);
	cout<<"\t\t\t***BIENVENIDO AL MENU DE ALUMNO***\t\t\t\n\n";
	do{
		system(CLEAR);
		cout<<"\n1. Listar cursos."<<endl;
		cout<<"2. Inscribir curso."<<endl;
		cout<<"3. Ver mi Perfil"<<endl;
		cout<<"4. Salir"<<endl;
		cin>>opc;
		switch(opc){
		default:
			cout<<"\nIntroduce una opcion valida(1-3)\n"<<endl;
			break;
		case 1:
			system(CLEAR);
			c.listarCursos();
			break;
		case 2:
			system(CLEAR);
			fflush(stdin);
			cout<<"Introduce el ID del curso al que te quieres inscribir: "<<endl;
			cin>>aux;
			a.inscribir_curso(aux, dni);
			break;
		case 3:
			fflush(stdin);
			system(CLEAR);
			a.Perfil(dni);
			enter();
			break;
		case 4:
			return;
			break;
		}
	}while(opc!=4);
}

