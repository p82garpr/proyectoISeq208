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


	verificador.open("AlumnosRegistrados.txt",ios::in);
	escritura.open("AlumnosRegistrados.txt",ios::app);

	if(escritura.is_open() && verificador.is_open()){

		string auxID=dni;

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
				getline(verificador,CURSOS);
				cont++;//LISTA DE CURSOS
				//getline(verificador,inscrr);

				if(dni==auxID){
					encontrado=true;
					cout<<"YA EXISTE UN USUARIO CON ESE DNI \n";
					//cout<<"Introduce un código válido"<<endl;
					//getline(cin,id);
					//break;

					cout<<"saliendo..."<<endl; //ENTRA EN BUCLE CUANDO PIDO OTRO
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
		//string x;
		//fflush(stdin);
		//METER /N Y COMPROBRAR QUE EL PRIMER REGISTRO NO TENGA /N
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
	//cout<<id<<endl;
	cout<<"Se ha añadido correctamente el usuario"<<endl;
	escritura.close();
	verificador.close();
	return true;
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


void alumno::inscribir_curso(string IDCurso, string DNI){
	curso c;
	if(!c.buscar_curso(IDCurso)){
		cout<<"Curso no disponible o no encontrado, saliendo..."<<endl;
		return;
	}
/*
 * LA ESTRUCTURA DEL FICHERO REGUSTROCRUSO, SERÁ:
 * DNI --solo se almacena el dni que esta registrado.
 * */
	ofstream escritura,escaux;
	ifstream verificador;
	fstream escritura2;
	bool encontrado=false;
	int contaux=0;
	string dniAux;
	string aux;
	string documento=IDCurso + "Registrados.txt";
	string nombreCompleto;
	string fechaNac;
	string usuarioUCO;
	string pass;
	verificador.open(documento,ios::in);
	escritura.open(documento,ios::app);
	escritura2.open("AlumnosRegistrados.txt",ios::app);
	//escritura3.close();
	escritura2.close();
	escritura.close();
	verificador.close();
	verificador.open(documento,ios::in);
	escritura.open(documento,ios::app);
	escritura2.open("AlumnosRegistrados.txt", fstream::in |fstream::out | fstream::binary);
	escaux.open("auxiliar.txt",ios::app);



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
					//escritura3.close();
					return;
				}
				getline(verificador,dniAux);
			}
			if(verificador.eof()&&dniAux!=DNI){
				encontrado=false;
			}
		}while(encontrado==true);
		escritura<<DNI<<"\n";

		//LECTURA
		do{
			escritura2.seekg(0);
			getline(escritura2,dniAux);
			//nregistro++;
			while(!escritura2.eof())
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

				getline(escritura2,nombreCompleto);
				getline(escritura2,fechaNac);
				getline(escritura2,usuarioUCO);
				getline(escritura2,pass);
				//pos=read.tellg();
				getline(escritura2,aux); //NUMERO DE CURSOS REGISTRADOS DEL ALUMNO X
				//cout<<"EL DNI DEL FICHERO ES...:"<<dni<<endl;
				//cout<<"LA PASS DEL FICHERO ES...:"<<pass<<endl;

				if(DNI==dniAux){
					aux=aux+IDCurso+", ";


				}
				if(contaux==0)
					escaux<<dniAux<<"\n"<<nombreCompleto<<"\n"<<fechaNac<<"\n"<<usuarioUCO<<"\n"<<pass<<"\n"<<aux;
				else
					escaux<<"\n"<<dniAux<<"\n"<<nombreCompleto<<"\n"<<fechaNac<<"\n"<<usuarioUCO<<"\n"<<pass<<"\n"<<aux;

				contaux++;
				getline(escritura2,dniAux);
				//nregistro++;
			}
			if(escritura2.eof()&&dniAux!=DNI){
					  encontrado=false;

			}
		}while(encontrado==true);




			/*
			//ESCRIBIR
			cout<<buscar_alumno(DNI,aux);
			//escritura2.seekp(buscar_alumno(DNI,aux)*6);
			escritura2.seekp(buscar_alumno(DNI,aux));
			aux=aux+IDCurso+", ";
			//cout<<escritura.tellp()<<endl;
			escritura2<<"\n"<<aux;
			escritura2.seekg(-1,ios::cur);
			cout<<"si";
			escritura2<<"\n";

			*/



		}


		if(buscar_curso(IDCurso)>0){
			//escritura3.seekp(buscar_curso(IDCurso)*8);
			//escritura3<<cuenta_alumnos(IDCurso);

			modificar_inscritos(cuenta_alumnos(IDCurso),buscar_curso(IDCurso));



		}



	cout<<"Te has registrado correctamente"<<endl;
	escritura.close();
	escritura2.close();
	//escritura3.close();
	verificador.close();
	escaux.close();
	remove("AlumnosRegistrados.txt");
	rename("auxiliar.txt","AlumnosRegistrados.txt");
}

//FUNCION QUE DEVUELVE EL NUMERO DE REGISTRO DONDE SE ENCUENTRA EL ALUMNO
long alumno::buscar_alumno(string DNI,string &aux){
		bool encontrado=false;
		//int nregistro=0;
		long pos=0;
		int cont=0;
			string dniAux;
			string nombreCompleto;
			string fechaNac;
			string usuarioUCO;
			string pass;
			//string aux; // CRUSOS REGISTRADOS
			ifstream read;
			string auxx;
			read.open("AlumnosRegistrados.txt",ios::in);
			cout<<endl;
			if(read.is_open()){
				do{
					read.seekg(0);
					getline(read,dniAux);
					//nregistro++;
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
						//pos=read.tellg();
						getline(read,aux); //NUMERO DE CURSOS REGISTRADOS DEL ALUMNO X
						//cout<<"EL DNI DEL FICHERO ES...:"<<dni<<endl;
						//cout<<"LA PASS DEL FICHERO ES...:"<<pass<<endl;
						cont++;
						if(cont>1)
							auxx+=dniAux+"\n"+nombreCompleto+"\n"+fechaNac+"\n"+usuarioUCO+"\n"+pass+"\n"+aux+"\n";
						if(DNI==dniAux){
							auxx=dniAux+"\n"+nombreCompleto+"\n"+fechaNac+"\n"+usuarioUCO+"\n"+pass+"\n"+aux+"\n";
							encontrado=true;
							read.close();
							pos=auxx.size();
							return pos;
							//return nregistro;
						}
						getline(read,dniAux);
						//nregistro++;
					}
					if(read.eof()&&dniAux!=DNI){
							  encontrado=false;

					}
				}while(encontrado==true);
			}
			read.close();
			return 0;
			//return 0;


}

//MODIFICAR ESTA FUNCION PARA PONER EL NUMERO DE INSCRITOS BIEN
int alumno::cuenta_alumnos(string IDcurso){
			bool encontrado=false;
			string linea;
			string documento=IDcurso+"Registrados.txt";
			int cont=0;
			//string aux; // CRUSOS REGISTRADOS
			ifstream read;
			read.open(documento,ios::in);
			cout<<endl;
			if(read.is_open()){
				do{
					read.seekg(0);
					getline(read,linea);
					cont++;
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
			//return 0;


}

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

void alumno::modificar_inscritos(int inscritos, int nregistro){

	string id;
	string nombre;
	string fechaIni;
	string fechaFin;
	string desc;
	string stats;
	string aforo;
	string inscr;
	//int inscrr;
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
			//inscrr=stoi(inscr);
			cont++;
			if(cont==nregistro){
				//if(inscrr!=inscritos){

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
/*
alumno::alumno() {
	// TODO Auto-generated constructor stub
}

alumno::~alumno() {
	// TODO Auto-generated destructor stub
}
*/
