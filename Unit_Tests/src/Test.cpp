#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "usuario.h"
#include "alumno.h"
#include "curso.h"

void thisIsATest() {
	ASSERTM("start writing tests", false);
}

void testInicioSesion1(){
	usuario user1("a","b","c","d","e");
	user1.setDni("31885866Z");
	user1.setContrasena("123?321_");
	bool iniciarSesion= user1.iniciar_sesion(user1.getDni(), user1.getContrasena());
	ASSERT(iniciarSesion == true);
	iniciarSesion= user1.iniciar_sesion(user1.getDni(),"RandomPassword");
	ASSERT(iniciarSesion == false);
	user1.setContrasena("123");
	ASSERT(iniciarSesion == false);
	iniciarSesion= user1.iniciar_sesion(user1.getDni(),"123");
	ASSERT(iniciarSesion == true);
	iniciarSesion= user1.iniciar_sesion(user1.getDni(), user1.getContrasena());
	ASSERT(iniciarSesion == true);
	usuario user2("a","b","c","d","e");
	user2.setDni("31885867Y");
	user2.setContrasena("1234");
	iniciarSesion= user2.iniciar_sesion(user2.getDni(), user1.getContrasena());
	ASSERT(iniciarSesion == false);
	iniciarSesion= user2.iniciar_sesion(user2.getDni(), user2.getContrasena());
	ASSERT(iniciarSesion == true);
}

void testInicioSesion2(){
	/*PRE-CONDITION: FILE NAMED AlumnosRegistrados.txt CREATED ON $PROJ_DIR WITH
	 THE USER 31885866Z AND PASS 1223?321_ SETTED.*/
	//THIS TEST IS DONE TO CHECK IF FILES BBDD SYSTEM WORKS AS EXPECTED.
	alumno a;
	a.setDni("31885866Z");
	a.setContrasena("123?321_");
	bool fileSignIn= a.inicio_sesion_bbdd(a.getDni(),a.getContrasena());
	ASSERT(fileSignIn == true);
    fileSignIn= a.inicio_sesion_bbdd(a.getDni(),"RandomPassword");
	ASSERT(fileSignIn == false);
	alumno b;
	b.setDni("31885867S");
	b.setContrasena("123123");
	fileSignIn= b.inicio_sesion_bbdd(b.getDni(),b.getContrasena());
	ASSERT(fileSignIn == true);
	fileSignIn= b.inicio_sesion_bbdd("RandomDNI",b.getContrasena());
	ASSERT(fileSignIn == false);

}

void testmostrarcurso(){

	//THIS TEST IS DONE TO CHECK IF THE COURSE IS DISPLAYED CORRECTLY.
	curso c;
	c.setId(1);
	c.setAlumnosInscritos(2);
	c.setFechaIni("02-08-2022");
	c.setFechaFin("09-08-2022");
	c.setDescripcion("Prueba de curso");
	c.setEstadisticaAlcance(2.5);
	c.setAforo(20);

	c.mostrar(c);

}


void testagregarcurso(){
	/*PRE-CONDITION: FILE NAMED cursos.txt CREATED ON $PROJ_DIR */
	//THIS TEST IS DONE TO CHECK IF FILES BBDD SYSTEM WORKS AS EXPECTED.
	curso c;
	c.setId(1);
	c.setAlumnosInscritos(2);
	c.setFechaIni("02-08-2022");
	c.setFechaFin("09-08-2022");
	c.setDescripcion("Prueba de curso");
	c.setEstadisticaAlcance(2.5);
	c.setAforo(20);

	bool fileFindCourse= c.buscar_curso(to_string(c.getIdCurso()));
	ASSERT(fileFindCourse== false);
	c.volcar_curso();


}






bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here
	//s.push_back(CUTE(thisIsATest));

	//HACER UN PUSHBACK PARA CADA PRUEBA
	s.push_back(CUTE(testInicioSesion1));
	s.push_back(CUTE(testInicioSesion2));
	s.push_back(CUTE(testmostrarcurso));





	//NO TOCAR
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}

