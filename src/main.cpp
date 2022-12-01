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
	string user,pass;
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
	curso c(5);
}
