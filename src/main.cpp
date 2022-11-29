//============================================================================
// Name        : proyecto.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <mysql.h>
#include "curso.h"

using namespace std;

int main() {

	MYSQL* conectar;
	conectar=mysql_init(0);
	conectar= mysql_real_connect(conectar,"localhost","root","root","prueba",3307,NULL,0);

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
