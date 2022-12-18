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

//FUNCION PARA REGISTRAR A UN ALUMNO ESCRIBIENDOLO EN EL FICHERO AlumnosRegistrados.txt
bool alumno::registro(alumno alumno){

	ofstream escritura;
	ifstream verificador;

	bool encontrado=false;

	string usuarioUCO;
	string nombre;
	string fechaNac;
	string dni=alumno.getDni();
	string pass;
	string pass2;
	string CURSOS;

	int cont=0;

	/*
	 * LA FORMA DE GUARDAR LOS REGISTROS ES:
	 * 			DNI
	 * 			NOMBRE COMPLETO
	 * 			FECHA NAC
	 * 			USUARIO UCO
	 * 			CONTRASEÑA
	 *			¿CURSOS REGISTRADOS?
	 */

	//CONTROL DE ERRORES
	if(dni=="error" || alumno.getFechaNacimiento()=="error"){

		cout<<"No se ha podido registrar"<<endl;
		cout<<"Saliendo..."<<endl;

		return false;
	}

	verificador.open("AlumnosRegistrados.txt",ios::in);
	escritura.open("AlumnosRegistrados.txt",ios::app);

	if(escritura.is_open() && verificador.is_open()){

		string auxID=dni;

		do{

			verificador.seekg(0);

			getline(verificador,dni);

			while(!verificador.eof())
			{
				getline(verificador,nombre);
				getline(verificador,fechaNac);
				getline(verificador,usuarioUCO);
				getline(verificador,pass);
				getline(verificador,CURSOS);

				cont++;//LISTA DE CURSOS

				if(dni==auxID){

					encontrado=true;

					cout<<"YA EXISTE UN USUARIO CON ESE DNI \n";
					cout<<"saliendo..."<<endl;

					return false;

				}

				getline(verificador,dni);
			}

			if(verificador.eof()&&auxID!=dni){
				encontrado=false;
			}

		}while(encontrado==true);

		dni=auxID;

		verificador.seekg(0);

		if(cont==0)
			escritura<<alumno.getDni()<<"\n"<<alumno.getNombreCompleto()<<"\n"<<alumno.getFechaNacimiento()<<"\n"<<alumno.getUsuarioUco()<<"\n"<<alumno.getContrasena()<<"\n";
		else
			escritura<<"\n"<<alumno.getDni()<<"\n"<<alumno.getNombreCompleto()<<"\n"<<alumno.getFechaNacimiento()<<"\n"<<alumno.getUsuarioUco()<<"\n"<<alumno.getContrasena()<<"\n";

	}
	else{

		cout<<"No se ha podido registrar"<<endl;
		cout<<"Saliendo..."<<endl;

		return false;
	}

	cout<<"Se ha añadido correctamente el usuario"<<endl;

	escritura.close();
	verificador.close();

	return true;
}


//FUNCION QUE COMPRUEBA QUE EXISTE DICHO DNI Y CONTRASEÑA EN EL FICHERO AlumnosRegistrados.txt
bool alumno::inicio_sesion_bbdd(string dni, string pass){

	bool encontrado=false;

	string aux;
	string usuarioUCO;
	string auxDNI=dni;
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

			if(dni==auxDNI){

				encontrado=true;

				if(pass!=passAux){

					cout<<"Contraseña Incorrecta, saliendo.."<<endl;

					read.close();

					return 0;
				}else{

					cout<<"Contraseña validada, bienvenido "<<usuarioUCO<<endl;

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

//FUNCION PARA OBTENER UN ALUMNO A TRAVES DE UN ID PASADO POR ARGUMENTOS DEL FICHERO AlumnonRegistrados.txt
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

					return NotFound;
		}
	}while(encontrado==true);

	read.close();

	return NotFound;
}

//FUNCION PARA VISUALIZAR TODOS LOS ATRIBUTOS DE UN ALUMNO EN CONCRETO
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

//FUNCION PARA INSCRIBIRSE EN UN CURSO
bool alumno::inscribir_curso(string IDCurso, string DNI){

	curso c;

	//CONTROL DE ERRORES
	if(!c.buscar_curso(IDCurso)){
		cout<<"Curso no disponible o no encontrado, saliendo..."<<endl;
		return false;
	}
/*
 * LA ESTRUCTURA DEL FICHERO REGUSTROCRUSO, SERÁ:
 * DNI --solo se almacena el dni que esta registrado.
 * */
	ofstream escritura;
	ifstream verificador;

	bool encontrado=false;

	string dniAux;
	string aux;
	string documento=IDCurso + "Registrados.txt";

	verificador.open(documento,ios::in);
	escritura.open(documento,ios::app);
	escritura.close();
	verificador.close();
	verificador.open(documento,ios::in);
	escritura.open(documento,ios::app);

	if(escritura.is_open() && verificador.is_open() ){

		do{

			verificador.seekg(0);

			getline(verificador,dniAux);

			while(!verificador.eof())
			{

				if(DNI==dniAux){

					encontrado=true;

					cout<<"YA ESTAS REGISTRADO EN ESTE CURSO \n";
					cout<<"saliendo..."<<endl;

					escritura.close();
					verificador.close();

					return false;
				 }

				getline(verificador,dniAux);
			}

			if(verificador.eof()&&dniAux!=DNI){

				encontrado=false;
			}

		}while(encontrado==true);

		escritura<<DNI<<"\n"; //ESCRIBE EL DNI DEL ALUMNO QUE SE HA INSCRITO

		//COMPROBACION QUE EXISTE MAS DE UN ALUMNO EN AlumnosRegistrados.txt
		if(buscar_alumno(DNI,aux)>0){

			string x="";

			x=IDCurso+","; //CADENA CON LOS CURSOS REGISTRADOS

			setListaCursos(x);

			cout<<x<<endl;

			modificar_listacursos(x,DNI);
		}

		//COMPROBACION QUE EXISTE MAS DE UN CURSO EN cursos.txt
		if(buscar_curso(IDCurso)>0){

			modificar_inscritos(cuenta_alumnos(IDCurso)+1,buscar_curso(IDCurso));

		}

	}

	else{

		cout<<"No se ha podido crear"<<endl;
		cout<<"Saliendo..."<<endl;

		escritura.close();
		verificador.close();

		return false;
	}

	cout<<"Te has registrado correctamente"<<endl;

	escritura.close();
	verificador.close();

	return true;
}

//FUNCION PARA ACTUALIZAR LA LISTA DE CURSOS DEL ALUMNO X
void alumno::modificar_listacursos(string cadaux, string Dni){

	string dniaux;
	string nombre;
	string fechaNac;
	string usuarioUCO;
	string pass;
	string listacursos="";

	int cont=0;
	int contaux=0;

	ifstream is;

	is.open("AlumnosRegistrados.txt", ios::in);

	ofstream aux;

	aux.open("pepe.txt",ios::out);
	aux.close();
	aux.open("pepe.txt",ios::out);

	if(is.is_open() && aux.is_open()){
		is.seekg(0);

		while(!is.eof()){
			getline(is,dniaux);
			//cout<<dniaux<<endl;
			getline(is,nombre);
			//cout<<nombre<<endl;
			getline(is,fechaNac);
			//cout<<fechaNac<<endl;
			getline(is,usuarioUCO);
			//cout<<usuarioUCO<<endl;
			getline(is,pass);
			//cout<<pass<<endl;
			getline(is,listacursos);
			//cout<<listacursos<<endl;

			cont++;

			if(dniaux==Dni){

				setListaCursos(listacursos+cadaux);

				if(contaux==0)
						aux<<dniaux<<"\n"<<nombre<<"\n"<<fechaNac<<"\n"<<usuarioUCO<<"\n"<<pass<<"\n"<<listacursos+cadaux;
					else
						aux<<"\n"<<dniaux<<"\n"<<nombre<<"\n"<<fechaNac<<"\n"<<usuarioUCO<<"\n"<<pass<<"\n"<<listacursos+cadaux;

					contaux++;


			}else{

				if(contaux==0)
					aux<<dniaux<<"\n"<<nombre<<"\n"<<fechaNac<<"\n"<<usuarioUCO<<"\n"<<pass<<"\n"<<listacursos;
				else
					aux<<"\n"<<dniaux<<"\n"<<nombre<<"\n"<<fechaNac<<"\n"<<usuarioUCO<<"\n"<<pass<<"\n"<<listacursos;

				contaux++;

			}


		}
	}else

		cout<<"ERROR DE FICHERO"<<endl;

	is.close();
	aux.close();

	remove("AlumnosRegistrados.txt");
	rename("pepe.txt","AlumnosRegistrados.txt");





}

//FUNCION QUE DEVUELVE EL NUMERO DE REGISTRO DONDE SE ENCUENTRA EL ALUMNO
long alumno::buscar_alumno(string DNI,string &aux){
		bool encontrado=false;

		long pos=0;
		int cont=0;

		string dniAux;
		string nombreCompleto;
		string fechaNac;
		string usuarioUCO;
		string pass;
		string auxx;

		ifstream read;

		read.open("AlumnosRegistrados.txt",ios::in);

		cout<<endl;

		if(read.is_open()){

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

					cont++;
					if(cont>1)

						auxx+=dniAux+"\n"+nombreCompleto+"\n"+fechaNac+"\n"+usuarioUCO+"\n"+pass+"\n"+aux+"\n";

					if(DNI==dniAux){

						auxx=dniAux+"\n"+nombreCompleto+"\n"+fechaNac+"\n"+usuarioUCO+"\n"+pass+"\n"+aux+"\n";

						encontrado=true;

						read.close();

						pos=auxx.size();

						return pos;

					}

					getline(read,dniAux);
				}
				if(read.eof()&&dniAux!=DNI){

					encontrado=false;

				}
			}while(encontrado==true);
		}

		read.close();

		return 0;

}

//MODIFICAR ESTA FUNCION PARA PONER EL NUMERO DE INSCRITOS BIEN
int alumno::cuenta_alumnos(string IDcurso){

	bool encontrado=false;

	string linea;
	string documento=IDcurso+"Registrados.txt";

	int cont=0;

	ifstream read;

	read.open(documento,ios::in);
	cout<<endl;

	if(read.is_open()){

		do{
			read.seekg(0);
			getline(read,linea);

			while(!read.eof())
			{
				getline(read,linea);

				cont++;

			}
			if(read.eof()){

				encontrado=false;

			}
		}while(encontrado==true);
	}

	read.close();

	return cont;

}

//FUNCION QUE DEVUELVE EL NUMERO DE REGISTRO DONDE SE ENCUENTRA EL CURSO
int alumno::buscar_curso(string IDcurso){

	bool encontrado=false;
	int nregistro=0;

	string idAux;
	string nombre;
	string fechaini;
	string fechafin;
	string desc;
	string alcance;
	string aforo;
	string ninscritos;

	ifstream read;

	read.open("cursos.txt",ios::in);

	cout<<endl;

	if(read.is_open()){

		do{

			read.seekg(0);

			getline(read,idAux);

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

				getline(read,nombre);
				getline(read,fechaini);
				getline(read,fechafin);
				getline(read,desc);
				getline(read,alcance);
				getline(read,aforo);
				getline(read,ninscritos);

				nregistro++;

				if(IDcurso==idAux){
					encontrado=true;
					read.close();
					return nregistro;
				}

				getline(read,idAux);
			}

			if(read.eof()&&idAux!=IDcurso){
					  encontrado=false;

			}
		}while(encontrado==true);
	}

	read.close();

	return 0;
}

//FUNCION PARA MODIFICAR EL NUMERO DE INSCRITOS EN UN CURSO
void alumno::modificar_inscritos(int inscritos, int nregistro){

	string id;
	string nombre;
	string fechaIni;
	string fechaFin;
	string desc;
	string stats;
	string aforo;
	string inscr;

	int cont=0;
	int contaux=0;

	ifstream is;

	is.open("cursos.txt", ios::in);

	ofstream aux;

	aux.open("auxiliar.txt",ios::app);
	aux.close();
	aux.open("auxiliar.txt",ios::app);

	if(is.is_open() && aux.is_open()){

		is.seekg(0);

		while(!is.eof()){

			getline(is,id);
			getline(is,nombre);
			getline(is,fechaIni);
			getline(is,fechaFin);
			getline(is,desc);
			getline(is,stats);
			getline(is,aforo);
			getline(is,inscr);

			cont++;

			if(cont==nregistro){

				if(contaux==0)
					aux<<id<<"\n"<<nombre<<"\n"<<fechaIni<<"\n"<<fechaFin<<"\n"<<desc<<"\n"<<stats<<"\n"<<aforo<<"\n"<<inscritos;
				else
					aux<<"\n"<<id<<"\n"<<nombre<<"\n"<<fechaIni<<"\n"<<fechaFin<<"\n"<<desc<<"\n"<<stats<<"\n"<<aforo<<"\n"<<inscritos;

				contaux++;


			}else{
				if(contaux==0)
					aux<<id<<"\n"<<nombre<<"\n"<<fechaIni<<"\n"<<fechaFin<<"\n"<<desc<<"\n"<<stats<<"\n"<<aforo<<"\n"<<inscr;
				else
					aux<<"\n"<<id<<"\n"<<nombre<<"\n"<<fechaIni<<"\n"<<fechaFin<<"\n"<<desc<<"\n"<<stats<<"\n"<<aforo<<"\n"<<inscr;

				contaux++;

			}


		}
	}else

		cout<<"ERROR DE FICHERO"<<endl;

	is.close();
	aux.close();

	remove("cursos.txt");
	rename("auxiliar.txt","cursos.txt");





}

