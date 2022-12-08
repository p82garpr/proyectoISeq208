/*
 * alumno.cpp
 *
 *  Created on: 30 nov 2022
 *      Author: rafag
 */

#include "alumno.h"
#include "curso.h"
#include <list>
#include <string>
#include <fstream>



void alumno::listar_cursos(){
	/*list<string>::iterator it;
	for(it=lista_cursos_.begin();it!=lista_cursos_.end();it++){
		cout<<*it<<endl;
	}*/
}

void alumno::registro(){

	ofstream escritura;
	ifstream verificador;

	bool encontrado=false;
	string usuarioUCO;
	string nombre;
	string fechaNac;
	string dni;
	string pass;
	string pass2;
	string CURSOS;

	/*
	 * LA FORMA DE GUARDAR LOS REGISTROS ES:
	 * 			DNI
	 * 			NOMBRE COMPLETO
	 * 			FECHA NAC
	 * 			USUARIO UCO
	 * 			CONTRASEÑA
	 *			¿CURSOS REGISTRADOS?
	 */


	verificador.open("AlumnosRegistrados.txt",ios::in);
	escritura.open("AlumnosRegistrados.txt",ios::app);

	if(escritura.is_open() && verificador.is_open()){
		cout<<"\t ***Registro de usuario ***\t\n\n";
		//fflush(stdin);
		cout<<"Ingresa dni : ";
		getline(cin,dni);
		string auxID=dni;
		cout<<endl;
		do{
			verificador.seekg(0);
			getline(verificador,dni);
			while(!verificador.eof())
			{
				//getline(verificador,usuarioUCO);
				getline(verificador,nombre);
				getline(verificador,fechaNac);
				getline(verificador,usuarioUCO);
				getline(verificador,pass);
				getline(verificador,CURSOS); //LISTA DE CURSOS
				//getline(verificador,inscrr);
				if(dni==auxID){
					encontrado=true;
					cout<<"YA EXISTE UN USUARIO CON ESE DNI \n";
					//cout<<"Introduce un código válido"<<endl;
					//getline(cin,id);
					//break;

					cout<<"saliendo..."<<endl; //ENTRA EN BUCLE CUANDO PIDO OTRO
					return;

				}
				getline(verificador,dni);
			}
			if(verificador.eof()&&auxID!=dni){
				encontrado=false;
			}
		}while(encontrado==true);
		dni=auxID;
		//fflush(stdin);
		cout<<"Ingresa el nombre de usuario UCO: ";
		getline(cin,usuarioUCO);
		cout<<endl;

		cout<<"Ingresa el nombre completo: ";
		getline(cin,nombre);
		cout<<endl;

		//fflush(stdin);
		cout<<"Ingresa la fecha de nacimiento: ";
		getline(cin,fechaNac);
		cout<<endl;

		//fflush(stdin);
		/*
		cout<<"Ingresa el DNI: ";
		getline(cin,dni);
		cout<<endl;*/

		//fflush(stdin);
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


		//fflush(stdin);
		//METER /N Y COMPROBRAR QUE EL PRIMER REGISTRO NO TENGA /N
		escritura<<dni<<"\n"<<nombre<<"\n"<<fechaNac<<"\n"<<usuarioUCO<<"\n"<<pass<<"\n";

	}
	//cout<<id<<endl;
	cout<<"Se ha añadido correctamente el usuario"<<endl;
	escritura.close();
	verificador.close();
}


bool alumno::inicio_sesion_bbdd(string dni, string pass){
	//TODO CHECK CIN REMOVED AND NOW PASSED THROUG PARAM

	bool encontrado=false;
	//string dni;
	//string pass;

	string aux;
	string usuarioUCO;
	//cout<<"Introduce DNI: ";
	//getline(cin,dni);
	string auxDNI=dni;
	//cout<<"Introduce contrasenia: ";
	//getline(cin,pass);
	string passAux=pass;
	ifstream read;
	read.open("AlumnosRegistrados.txt",ios::in);
	cout<<endl;

	do{
		read.seekg(0);
		getline(read,dni);
		while(!read.eof())
		{
			/*
			 * LA FORMA DE GUARDAR LOS REGISTROS ES:
			 * 			DNI
			 * 			NOMBRE COMPLETO
			 * 			FECHA NAC
			 * 			USUARIO UCO
			 * 			CONTRASEÑA
			 *			¿CURSOS REGISTRADOS?
			 */

			getline(read,aux);
			getline(read,aux);
			getline(read,usuarioUCO);
			getline(read,pass);
			getline(read,aux);
			//cout<<"EL DNI DEL FICHERO ES...:"<<dni<<endl;
			//cout<<"LA PASS DEL FICHERO ES...:"<<pass<<endl;
			if(dni==auxDNI){
				encontrado=true;
				if(pass!=passAux){
					cout<<"Contrasenia Incorrecta, saliendo.."<<endl;
					read.close();
					return 0;
				}else{
					cout<<"Contrasenia validada, bienvenido "<<usuarioUCO<<endl;
					read.close();
					return 1;
					}
			}
			getline(read,dni);
		}
		if(read.eof()&&auxDNI!=dni){
		            encontrado=false;
		        }

		cout<<"El DNI introtucido no tiene una cuenta en nuestra base de datos, saliendo..."<<endl;
	}while(encontrado==true);

	read.close();
	return 0;
}

alumno alumno::get_alumno(string ID){
	alumno NotFound("empty");
	alumno get;
	get.setDni(ID);
	bool encontrado=false;
		string dniAux;
		string nombreCompleto;
		string fechaNac;
		string usuarioUCO;
		string pass;
		string aux; // CRUSOS REGISTRADOS
		ifstream read;
		read.open("AlumnosRegistrados.txt",ios::in);
		cout<<endl;
		do{
			read.seekg(0);
			getline(read,dniAux);
			while(!read.eof())
			{
				/*
				 * LA FORMA DE GUARDAR LOS REGISTROS ES:
				 * 			DNI
				 * 			NOMBRE COMPLETO
				 * 			FECHA NAC
				 * 			USUARIO UCO
				 * 			CONTRASEÑA
				 *			¿CURSOS REGISTRADOS?
				 */

				getline(read,nombreCompleto);
				getline(read,fechaNac);
				getline(read,usuarioUCO);
				getline(read,pass);
				getline(read,aux); //NUMERO DE CURSOS REGISTRADOS DEL ALUMNO X
				//cout<<"EL DNI DEL FICHERO ES...:"<<dni<<endl;
				//cout<<"LA PASS DEL FICHERO ES...:"<<pass<<endl;
				if(ID==dniAux){
					encontrado=true;
					get.setContrasena(pass);
					get.setFechaNacimiento(fechaNac);
					get.setNombreCompleto(nombreCompleto);
					get.setUsuarioUco(usuarioUCO);
					get.setListaCursos(aux);
					return get;
					read.close();
				}
				getline(read,dniAux);
			}
			if(read.eof()&&dniAux!=ID){
			            encontrado=false;
			            //return 0;
			            return NotFound;
			        }
		}while(encontrado==true);
		read.close();
		return NotFound;
		//return 0;
}


void alumno::Perfil(string DNI){
	alumno perfil;
	perfil.setDni(DNI);
	perfil=perfil.get_alumno(DNI);
	cout<<"DNI --------------------:"<<perfil.getDni()<<endl;
	cout<<"Nombre completo --------:"<<perfil.getNombreCompleto()<<endl;
	cout<<"Usuario UCO ------------:"<<perfil.getUsuarioUco()<<endl;
	cout<<"Fecha Nacimiento -------:"<<perfil.getFechaNacimiento()<<endl;
	cout<<"Cursos registrado ------:"<<perfil.getListaCursos()<<endl;
}


bool alumno::inscribir_curso(string IDCurso, string DNI){
	curso c;
	if(!c.buscar_curso(IDCurso)){
		cout<<"Curso no disponible o no encontrado, saliendo..."<<endl;
		return 0;
	}
/*
 * LA ESTRUCTURA DEL FICHERO REGUSTROCRUSO, SERÁ:
 * DNI --solo se almacena el dni que esta registrado.
 * */
	ofstream escritura, escritura2;
	ifstream verificador;
	bool encontrado=false;
	string dniAux;
	string aux;
	string documento=IDCurso + "Registrados.txt";
	verificador.open(documento,ios::in);
	escritura.open(documento,ios::app);
	escritura2.open("AlumnosRegistrados.txt",ios::app);
	escritura2.close();
	escritura.close();
	verificador.close();
	verificador.open(documento,ios::in);
	escritura.open(documento,ios::app);
	escritura2.open("AlumnosRegistrados.txt",ios::app);

	if(escritura.is_open() && verificador.is_open() && escritura2.is_open()){
		do{
			verificador.seekg(0);
			getline(verificador,dniAux);
			while(!verificador.eof())
			{
				if(DNI==dniAux){
					encontrado=true;
					cout<<"YA ESTAS REGISTRADO EN ESTE CURSO \n";
					cout<<"saliendo..."<<endl; //ENTRA EN BUCLE CUANDO PIDO OTRO
					escritura.close();
					verificador.close();
					escritura2.close();
					return 0;
				}
				getline(verificador,dniAux);
			}
			if(verificador.eof()&&dniAux!=DNI){
				encontrado=false;
			}
		}while(encontrado==true);
		escritura<<DNI<<"\n";
		//Posicion de lista de cursos de cada registro
		if(buscar_alumno(DNI,aux)>0){
			escritura2.seekp(buscar_alumno(DNI,aux)*6);

			aux+=IDCurso+",";
			//FALTA HACER PARA QUE HAYA MAS DE 1 CURSO ASIGNADO
			escritura2<<IDCurso+",";
		}


		//SE DEBE DE MODIFICAR EL ARCHIVO DE ALUMNOSREGISTRADOS.TXT Y ATUALIZAR EL VALOR DE LOS CURSOS
	}
	cout<<"Te has registrado correctamente"<<endl;
	escritura.close();
	escritura2.close();
	verificador.close();
	return 1;
}

//FUNCION QUE DEVUELVE EL NUMERO DE REGISTRO DONDE SE ENCUENTRA EL ALUMNO
int alumno::buscar_alumno(string DNI,string &aux){
		bool encontrado=false;
		int nregistro=0;
			string dniAux;
			string nombreCompleto;
			string fechaNac;
			string usuarioUCO;
			string pass;
			//string aux; // CRUSOS REGISTRADOS
			ifstream read;
			read.open("AlumnosRegistrados.txt",ios::in);
			cout<<endl;
			do{
				read.seekg(0);
				getline(read,dniAux);
				while(!read.eof())
				{
					/*
					 * LA FORMA DE GUARDAR LOS REGISTROS ES:
					 * 			DNI
					 * 			NOMBRE COMPLETO
					 * 			FECHA NAC
					 * 			USUARIO UCO
					 * 			CONTRASEÑA
					 *			¿CURSOS REGISTRADOS?
					 */

					getline(read,nombreCompleto);
					getline(read,fechaNac);
					getline(read,usuarioUCO);
					getline(read,pass);
					getline(read,aux); //NUMERO DE CURSOS REGISTRADOS DEL ALUMNO X
					//cout<<"EL DNI DEL FICHERO ES...:"<<dni<<endl;
					//cout<<"LA PASS DEL FICHERO ES...:"<<pass<<endl;
					nregistro++;
					if(DNI==dniAux){
						encontrado=true;
						read.close();
						return nregistro;
					}
					getline(read,dniAux);
				}
				if(read.eof()&&dniAux!=DNI){
				          encontrado=false;

				}
			}while(encontrado==true);
			read.close();
			return nregistro;
			//return 0;


}




/*
alumno::alumno() {
	// TODO Auto-generated constructor stub
}

alumno::~alumno() {
	// TODO Auto-generated destructor stub
}
*/
