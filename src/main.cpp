//============================================================================
// Name        : proyecto.cpp
// Author      : rafag
// Version     :
// Copyright   : Your copyright notice
// Description : Main menu of our fancy program
//============================================================================

#include <iostream>
#include <string>
#include <list>
#include "usuario.h"
#include "curso.h"
#include "alumno.h"
using namespace std;

void enter();
void menu_inicio();

int main() {
	curso c;
	alumno a;
	//usuario u;
	int opc;
	menu_inicio();




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

void menu_inicio(){
	int opcion;
	alumno a;
	do{
		cout<<"\t\t\t ***Bienvenido al sistema, seleccione una opción***\t\t\t\n\n"<<endl;
		cout<<"1. Registrarme"<<endl;
		cout<<"2. Iniciar sesion"<<endl;
		cout<<"3. Salir del sistema"<<endl;
		cin>>opcion;
		switch(opcion){
		case 1:
			fflush(stdin);
			a.registro();
			break;
		case 2:
			fflush(stdin);
			a.inicio_sesion_bbdd;
		}


	}while(opcion!=3);
}
