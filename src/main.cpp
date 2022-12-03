//============================================================================
// Name        : proyecto.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <list>
#include "usuario.h"
#include "curso.h"
#include "alumno.h"
using namespace std;

void enter();

int main() {
	//PARA CONSTRUIR USUARIO NOMBRE FECHA DNI CONTRASEÑA
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	/*string user,pass;
	list <string> lista={"curso1","curso2"};
	alumno u("p82","Rafa Garcia Perez","Rafa","3188","puta",lista);
	cout<<u.getContrasena()<<endl;
	u.listar_cursos();
	cout<<"Introduce nombre para inicio de sesion: "<<endl;
	cin>>user;
	cout<<"introduce contrasenia: "<<endl;
	cin>>pass;
	if(u.iniciar_sesion(user,pass)){
		cout<<"Contaseña correcta"<<endl;
		exit(EXIT_SUCCESS);
	}else{
		cout<<"Contraseña incorrecta"<<endl;
		exit(EXIT_FAILURE);
	}
	//cout<<"holis"<< endl;

	*/
	string x;
	curso c(0);
	alumno a("a","a","a","a","a");
	alumno b;
	//c.volcar_curso();
	//c.agregarCurso();
	//c.listarCursos();
	int opc;
	do{
		system("cls");
		cout<<"ELIGE UNA OPCION\n";
		cout<<"0. Salir \n\n";
		cout<<"1. Agregar curso\n\n";
		cout<<"2. Listar cursos\n\n";
		cout<<"3. Registro alumno\n\n";
		cout<<"4. Iniciar sesion\n\n";
		cout<<"5. Mis datos\n\n";
		cout<<"6. Buscar curso\n\n";

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
			break;
			fflush(stdin);
			enter();
		}

	}while(opc!=0);





}


void enter(){
	cout<<"Presiona Enter para continuar...";
	getchar();
}
