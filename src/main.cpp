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
	curso c(0);
	alumno a("a","a","a","a","a");
	//c.volcar_curso();
	//c.agregarCurso();
	//c.listarCursos();
	int opc;
	do{
		cout<<"ELIGE UNA OPCION\n";
		cout<<"0. Salir \n\n";
		cout<<"1. Agregar curso\n\n";
		cout<<"2. Listar cursos\n\n";
		cout<<"3. Registro alumno\n\n";
		cout<<"4. Iniciar sesion\n\n";
		cin>>opc;
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

		}

	}while(opc!=0);




}
