//============================================================================
// Name        : proyecto.cpp
// Author      : rafag
// Version     :
// Copyright   : Your copyright notice
// Description : Main menu of our fancy program
//============================================================================

/*
#ifdef _wIN32
#define CLEAR "cls"
#elif  defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#endif
*/

#include <iostream>
#include <string>
#include <list>
#include <conio.h>
#include <stdlib.h>
#include "usuario.h"
#include "curso.h"
#include "alumno.h"
using namespace std;

void enter();
int menu_inicio(string &dni,string &pass);
void menu_admin();
void menu_visitante();
void menu_alumno(string &dni);

int main() {
	curso c;
	alumno a;
	string dni, pass;
	//int vuelve;
	//int mode;
	//usuario u;
	//int opc;
	/*
	do{
		if(menu_inicio(dni,pass)==1){
			//Contraseña validada como alumno
			mode=1;
			vuelve=0;
		}else if (menu_inicio(dni,pass)==2){
			//Contraseña validada como administrador
			mode =2;
			vuelve=0;
		}else if (menu_inicio(dni,pass)==0){
			//Contraseña incorrecta
		}else if (menu_inicio(dni,pass)==3){
			mode=3;
		}
	}while(vuelve!=0);
	enter();
	//cout<<"Tu DNI es: "<<dni<<endl;
	//cout<<"Tu pass es: "<<pass<<endl;
	if(mode==2){
		//menu_admin();
		cout<<"ADMIN"<<endl;
	}else if(mode ==3){
		//menu_visitante();
		cout<<"VISITANTE"<<endl;
	}else{
		//menu_alumno();
		cout<<"ALUMNO"<<endl;
	}
*/

		int opcion,modo,vuelve;
		//string dni,pass;
		//alumno a;
		do{
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
				vuelve=1;
				break;
			case 2:
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

		//system("cls");
		if(modo==2){
				//menu_admin();
				menu_admin();
				//cout<<"ADMIN"<<endl;
			}else if(modo ==3){
				//menu_visitante();
				menu_visitante();
				//cout<<"VISITANTE"<<endl;
			}else{
				//menu_alumno();
				menu_alumno(dni);
				//cout<<"ALUMNO"<<endl;
			}

		//TODO NO METE UN BARRA N AL METER EL PUTO USUARIO






	/*
	string x,y;
	curso c(0);
	alumno a("a","a","a","a","a");
	alumno b;
	int opc;
	do{
		system("clear");
		cout<<"ELIGE UNA OPCION\n";
		cout<<"0. Salir \n\n";
		cout<<"1. Agregar curso\n\n";
		cout<<"2. Listar cursos\n\n";
		cout<<"3. Registro alumno\n\n";
		cout<<"4. Iniciar sesion\n\n";
		cout<<"5. Mis datos\n\n";
		cout<<"6. Buscar curso\n\n";
		cout<<"7. Inscribir curso\n\n";

		cin>>opc;
		//cin.get(opc);
		switch(opc){
		case 0:
			break;
		case 1:
			fflush(stdin);
			c.volcar_curso();
			break;
		case 2:
			c.listarCursos();
			break;
		case 3:
			fflush(stdin);
			a.registro();
			break;
		case 4:
			fflush(stdin);
			a.inicio_sesion_bbdd();
			break;
		case 5:
			fflush(stdin);
			cout<<"Introduce el DNI de su perfil: "<<endl;
			cin>>x;
			a.Perfil(x);
			fflush(stdin);
			cout<<endl;
			enter();
			break;
		case 6:
			cout<<"Introduce el ID del curso que quieres buscar: ";
			cin>>x;
			if(c.buscar_curso(x)){
				cout<<"ENCONTRADO!!"<<endl;
			}else{
				cout<<"NO ENCONTRADO!!"<<endl;
			}
			fflush(stdin);
			enter();
			break;
		case 7:
			fflush(stdin);
			cout<<"Introduce tu DNI: ";
			cin>>x;
			cout<<endl;
			fflush(stdin);
			cout<<"Introduce el curso al que quieres registrarte: ";
			cin>>y;
			a.inscribir_curso(y, x); //IDCURSO, DNI
		}

	}while(opc!=0);*/

	return 0;
}


void enter(){
	cout<<"Presiona Enter para continuar...";
	getchar();
}


int menu_inicio(string &dni, string &pass){
	int opcion,res,vuelve;
	//string dni,pass;
	alumno a;
	do{
		cout<<"\t\t\t ***Bienvenido al sistema, seleccione una opción***\t\t\t\n\n"<<endl;
		cout<<"1. Registrarme"<<endl;
		cout<<"2. Iniciar sesion"<<endl;
		cout<<"3. Entrar como visitante"<<endl;
		cout<<"4. Salir del sistema"<<endl;
		cin>>opcion;
		switch(opcion){
		case 1:
			//fflsuh(stdin);
			a.registro();
			vuelve=1;
			break;
		case 2:
			//fflush(stdin);
			cout<<"Introduce el DNI: "<<endl;
			cin>>dni;
			//fflush(stdin);
			cout<<"Introduce la contrasenaa: "<<endl;
			cin>>pass;
			if(dni=="root" && pass=="root"){
				//MENU DE ADMINISTRADOR
				res=2;
				vuelve=1;
			}else{
				if(a.inicio_sesion_bbdd(dni,pass)){
					res=1;
					vuelve =1;
				}else{
					return 0;
				}
			}
			break;
		case 3:
			res=3;
			opcion=4;
			break;
		case 4:
			break;
		}

	}while(opcion!=4);
	return res;
}

void menu_admin(){

	int opcion;
	curso c;
	alumno a;
	cout<<"\t\t\t***BIENVENIDO AL MENU DE ADMINISTRADOR***\t\t\t\n\n";
	do{
		cout<<"\n1. Crear curso"<<endl;
		cout<<"2. Listar cursos"<<endl;
		cout<<"3. Crear usuario"<<endl;
		cout<<"4. Salir "<<endl;
		cin>>opcion;
		switch(opcion){
		case 1:
			fflush(stdin);
			c.volcar_curso();
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
	cout<<"\t\t\t***BIENVENIDO AL MENU DE VISITANTE***\t\t\t\n\n";
	do{
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
	cout<<"\t\t\t***BIENVENIDO AL MENU DE ALUMNO***\t\t\t\n\n";
	do{
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
			c.listarCursos();
			break;
		case 2:
			fflush(stdin);
			cout<<"Introduce el ID del curso al que te quieres inscribir: "<<endl;
			cin>>aux;
			a.inscribir_curso(aux, dni);
			break;
		case 3:
			a.Perfil(dni);
			break;
		case 4:
			return;
			break;
		}
	}while(opc!=4);

}

