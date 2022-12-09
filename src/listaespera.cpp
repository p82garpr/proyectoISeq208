/*
 * listaespera.cpp
 *
 *  Created on: 5 dic 2022
 *      Author: Lau
 */

#include "listaespera.h"
#include "curso.h"
#include <list>
#include <string>
#include <fstream>



bool listaespera::insertar_alumno_listaespera(int id_curso,string dni){

	ofstream escribelista;
	ifstream leelista;
	bool encontrado=false;
	string dniAux;
	int posaux;


	/* ESTRUCTURA FICHERO
	 * dni alumno
	 * posicion
	 *
	 *
	 */
	string docu="ListaEspera_curso"+id_curso;
	leelista.open(docu,ios::in);
	escribelista.open(docu,ios::app);
	escribelista.close();
	leelista.close();
	leelista.open(docu,ios::in);
	escribelista.open(docu,ios::app);//fichero abierto con dos variables
	if(escribelista.is_open() && leelista.is_open()){
		leelista.seekg(0);

		while(!leelista.eof()) {
		getline(leelista,dniAux);

			if(dni==dniAux){
				encontrado=true;
				cout<<"YA ESTAS REGISTRADO EN ESTA LISTA \n";
				cout<<"saliendo..."<<endl; //ENTRA EN BUCLE CUANDO PIDO OTRO
				escribelista.close();
				leelista.close();
				return 0;
			}
			getline(leelista,posaux);
		}
		if(encontrado==false){
		escribelista<<dni<<"\n";
		escribelista<<posaux+1<<"\n";
		}
		cout<<"Te has registrado correctamente"<<endl;
			escribelista.close();
			leelista.close();
			return 1;

		//if(dniAux!=dni){
			//encontrado=false;
		//}
	}
}


bool listaespera::eliminar_alumno_listaespera(int id_curso,string dni){
	ofstream escribelista;
		ifstream leelista;
		bool encontrado=false;
		string dniAux;
		int posaux;


		/* ESTRUCTURA FICHERO
		 * dni alumno
		 * posicion
		 *
		 *
		 */
		string docu="ListaEspera_curso"+id_curso;
		leelista.open(docu,ios::in);
		escribelista.open(docu,ios::app);
		escribelista.close();
		leelista.close();
		leelista.open(docu,ios::in);
		escribelista.open(docu,ios::app);//fichero abierto con dos variables
		if(escribelista.is_open() && leelista.is_open()){
			leelista.seekg(0);

			while(!leelista.eof()) {
			getline(leelista,dniAux);

				if(dni==dniAux){


					return 1;
				}
				getline(leelista,posaux);
			}

			cout<<"No se ha encontrado dni para eliminar"<<endl;
				escribelista.close();
				leelista.close();
				return 0;

			//if(dniAux!=dni){
				//encontrado=false;
			//}
		}
}
