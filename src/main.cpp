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
#include <clocale>
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
	setlocale(LC_CTYPE,"Spanish");
	curso c;
	alumno a;
	//visitante v;
	string dni="error", pass;
	string userUco;
	string nombre;
	string fechaNac="error";
	string pass2;
		int opcion,modo,vuelve;
		system(CLEAR);
		do{
			//system(CLEAR);
			cout<<"\t\t\t****Bienvenido al sistema, seleccione una opcion****\t\t\t\n\n"<<endl;
			cout<<"1. Registro"<<endl;
			cout<<"2. Iniciar sesion"<<endl;
			cout<<"3. Entrar como visitante"<<endl;
			cout<<"4. Salir del sistema"<<endl;
			cin>>opcion;
			switch(opcion){
				default:
					cout<<"Introduzca una opción válida (1-4)"<<endl;
					fflush(stdin);
					break;

				case 1:
					fflush(stdin);
					cout<<"\t Registro de usuario \t\n\n";
					//fflush(stdin);
					while(dni=="error"){
						cout<<"Ingresa dni : ";
						getline(cin,dni);
						cout<<endl;

						a.setDni(dni);
						dni=a.getDni();
					}


					cout<<"Ingresa el nombre de usuario UCO: "<<endl;
					getline(cin,userUco);
					a.setUsuarioUco(userUco);
					cout<<endl;

					cout<<"Ingresa el nombre completo: ";
					getline(cin,nombre);
					a.setNombreCompleto(nombre);
					cout<<endl;
					while(fechaNac=="error"){
						cout<<"Ingresa la fecha de nacimiento (con el siguiente formato: DD/MM/YYYY): ";
						getline(cin,fechaNac);


						a.setFechaNacimiento(fechaNac);
						cout<<endl;
						fechaNac=a.getFechaNacimiento();
					}


					cout<<"Introduce una contrasena: ";
					getline(cin,pass);
					cout<<endl;
					cout<<"Introduce de nuevo una contrasena: ";
					getline(cin,pass2);
					cout<<endl;
					if(pass!=pass2){
						do{
							cout<<"Las contrasenas no coinciden, insertela de nuevo: "<<endl;
							getline(cin,pass2);
						}while(pass!=pass2);
					}
					a.setContrasena(pass);
					a.registro(a);
					dni="error";
					fechaNac="error";
					fflush(stdin);
					enter();
					vuelve=1;

					break;

			case 2:
				system(CLEAR);
				fflush(stdin);
				cout<<"Introduce el DNI: "<<endl;
				cin>>dni;
				fflush(stdin);
				cout<<"Introduce la contraseña: "<<endl;
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
						//cout<<"Contraseña incorrecta"<<endl;
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
			}else if (modo==1){
				//menu_alumno();
				system(CLEAR);
				menu_alumno(dni);
				//cout<<"ALUMNO"<<endl;
			}else{
				cout<<"Error del sistema"<<endl;
			}

	return 0;
}


void enter(){
	cout<<"Presiona Enter para continuar...";
	getchar();
	//system(CLEAR);
}

void menu_admin(){

	int opcion;
	curso c;
	alumno a;
	string id;
	string nombre;
	string fechaIni="error";
	string fechaFin="error";
	string desc;
	string aforo;
	string statss;
	string inscrr;
	//int inscr=0;
	//float stats=0.0;
	string dni, pass;
	string userUco;
	string fechaNac;
	string pass2;
	system(CLEAR);
	cout<<"\t\t\t***BIENVENIDO AL MENU DE ADMINISTRADOR***\t\t\t\n\n";
	do{
		//system(CLEAR);
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
			while(fechaIni=="error"){
				cout<<"Ingresa la fecha de inicio del curso (con el siguiente formato: DD/MM/YYYY): ";
				getline(cin,fechaIni);

				c.setFechaIni(fechaIni);

				cout<<endl;
				fechaIni=c.getFechaIni();
			}

			//fflush(stdin);
			while(fechaFin=="error"){
				cout<<"Ingresa la fecha de fin del curso (con el siguiente formato: DD/MM/YYYY): ";
				getline(cin,fechaFin);

				c.setFechaFin(fechaFin);

				cout<<endl;
				fechaFin=c.getFechaFin();
			}

			//fflush(stdin);
			cout<<"Introduce una breve descripcion del curso: ";
			getline(cin,desc);
			c.setDescripcion(desc);
			cout<<endl;

			//fflush(stdin);
			cout<<"Ingresa el aforo del curso: ";
			getline(cin,aforo);
			c.setAforo(stoi(aforo));
			cout<<endl;
			c.volcar_curso(c);
			fechaIni="error";
			fechaFin="error";
			fflush(stdin);
			enter();
			break;
		case 2:
			fflush(stdin);
			c.listarCursos();
			enter();
			break;
		case 3:
			fflush(stdin);
			cout<<"\t Registro de usuario \t\n\n";
			//fflush(stdin);
			while(dni=="error"){
				cout<<"Ingresa dni : ";
				getline(cin,dni);
				cout<<endl;

				a.setDni(dni);
				dni=a.getDni();
			}


			cout<<"Ingresa el nombre de usuario UCO: "<<endl;
			getline(cin,userUco);
			a.setUsuarioUco(userUco);
			cout<<endl;

			cout<<"Ingresa el nombre completo: ";
			getline(cin,nombre);
			a.setNombreCompleto(nombre);
			cout<<endl;
			while(fechaNac=="error"){
				cout<<"Ingresa la fecha de nacimiento (con el siguiente formato: DD/MM/YYYY): ";
				getline(cin,fechaNac);


				a.setFechaNacimiento(fechaNac);
				cout<<endl;
				fechaNac=a.getFechaNacimiento();
			}


			cout<<"Introduce una contrasena: ";
			getline(cin,pass);
			cout<<endl;
			cout<<"Introduce de nuevo una contrasena: ";
			getline(cin,pass2);
			cout<<endl;
			if(pass!=pass2){
				do{
					cout<<"Las contrasenas no coinciden, insertela de nuevo: "<<endl;
					getline(cin,pass2);
				}while(pass!=pass2);
			}
			a.setContrasena(pass);
			a.registro(a);
			dni="error";
			fechaNac="error";
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
			fflush(stdin);
			break;
		case 1:
			c.listarCursos();
			fflush(stdin);
			enter();
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
		//system(CLEAR);
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
			//system(CLEAR);
			c.listarCursos();
			fflush(stdin);
			enter();
			break;
		case 2:
			system(CLEAR);
			c.listarCursos();
			fflush(stdin);
			cout<<"Introduce el ID del curso al que te quieres inscribir: "<<endl;
			cin>>aux;
			if(a.inscribir_curso(aux, dni)){
				system(CLEAR);
				cout<<"Te has inscrito corretcamente"<<endl;
			}else{
				cout<<"No has podido inscribirte"<<endl;
			}


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

