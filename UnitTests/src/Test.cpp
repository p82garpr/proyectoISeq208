#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "usuario.h"
#include "alumno.h"
#include "curso.h"



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

void testvolcarcurso(){
	/*PRE-CONDITIONS: FILE NAMED cursos.txt CREATED ON $PROJ_DIR AND THE COURSE MUSTN'T BE ON IT.*/
	//THIS TEST IS DONE TO CHECK IF THE COURSE IS WRITTEN IN THE FILE.
	curso c;
	c.setId(1);
	c.setAlumnosInscritos(2);
	c.setFechaIni("02-08-2022");
	c.setFechaFin("09-08-2022");
	c.setDescripcion("Prueba de curso");
	c.setEstadisticaAlcance(2.5);
	c.setAforo(20);
	bool fileCourseWritten;
	fileCourseWritten=c.volcar_curso(c);
	ASSERT(fileCourseWritten == true);

	curso c2;
	c2.setId(1);
	fileCourseWritten=c2.volcar_curso(c2);
	ASSERT(fileCourseWritten == false);

	curso c3;
	c3.setId(2);
	fileCourseWritten=c3.volcar_curso(c3);
	ASSERT(fileCourseWritten == true);

	curso aux;
	aux.setId(3);
	aux.setFechaIni("12/8");
	fileCourseWritten=aux.volcar_curso(aux);
	ASSERT(fileCourseWritten == false);

	curso aux2;
	aux2.setId(4);
	aux2.setFechaFin("15/09/09");
	fileCourseWritten=aux2.volcar_curso(aux2);
	ASSERT(fileCourseWritten == false);


}

void testbuscarcurso(){
	/*PRE-CONDITIONS: FILE NAMED cursos.txt CREATED ON $PROJ_DIR AND THE COURSE MUST BE ON IT.*/
	//THIS TEST IS DONE TO CHECK IF THE COURSE IS IN THE BBDD AND RETURNS THE NUMBER OF REGISTER.
	alumno a;
	a.setDni("31030157Y");
	curso c;
	c.setId(5);
	bool fileCourseWritten=c.volcar_curso(c);
	ASSERT(fileCourseWritten == true);
	ASSERT_EQUAL(3,a.buscar_curso(to_string(c.getIdCurso())));
	curso c2;
	c2.setId(6);
	fileCourseWritten=c2.volcar_curso(c2);
	ASSERT(fileCourseWritten == true);
	ASSERT_EQUAL(4,a.buscar_curso(to_string(c2.getIdCurso())));
	curso c3;
	c3.setId(7);
	ASSERT_EQUAL(0,a.buscar_curso(to_string(c3.getIdCurso())));

}

void testRegistro(){
	//THIS TEST IS USED TO VERIFY IF A USER IS ABLE TO REGISTER IN THE SYSTEM CORRECTLY, IT HAS NOT PRECONDITIONS
	bool result=false;
	alumno a("i12hurel","Laura Huertes","01/12/2003","54589209C","holis");
	result=a.registro(a);
	ASSERT(result==true);

	alumno b;
	b.setDni("54589209C");
	result=b.registro(b);
	ASSERT(result==false);
	//error ya esta registrado

	alumno c;
	c.setDni("33");
	result=c.registro(c);
	ASSERT(result==false);
	//error dni

	alumno x("p28ceali","Isaac Cejudo","19/09/2000","30131057Y","buenasss");
	result=x.registro(x);
	ASSERT(result==true);


	alumno d("i34lola","Lola","19/9","20245894Y","buenasss");
	result=d.registro(d);
	ASSERT(result==false);
	//error fecha

}

void testInscribirCurso(){
	/*PRE-CONDITION: FILE NAMED cursos.txt CREATED ON $PROJ_DIR WITH
	 THE COURSES WITH ID 1 AND 2 SETTED.*/
	//THIS TEST IS TO CHECK IF A STUDENT HAVE BEEN REGISTERED IN A COURSE CORRECTLY

	bool result=false;

	alumno a("i12hurel","Laura Huertes","01/12/2003","54589209C","holis");
	result=a.inscribir_curso("IDrandom","DNIrandom");
	ASSERT(result==false);
	//inscribimos a un alumno en un curso que no existe

	result=a.inscribir_curso("1",a.getDni());
	ASSERT(result==true);

	result=a.inscribir_curso("1",a.getDni());
	ASSERT(result==false);
	//insertamos un alumno ya insertado
	alumno auxili;


	alumno b("p28ceali","Isaac Cejudo","19/09/2000","30131057Y","buenasss");
	result=b.inscribir_curso("1",b.getDni());
	ASSERT(result==true);

	string aux=a.getListaCursos();
	ASSERT_EQUAL("1,",aux);
	//vemos si actualiza el curso

	result=a.inscribir_curso("2",a.getDni());
	ASSERT(result==true);

	aux=a.getListaCursos();
	ASSERT_EQUAL("1,2,",aux);

	int inscritos=auxili.cuenta_alumnos("1");
	ASSERT_EQUAL(2,inscritos);


}









bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here
	//s.push_back(CUTE(thisIsATest));

	//HACER UN PUSHBACK PARA CADA PRUEBA
	s.push_back(CUTE(testInicioSesion1));
	s.push_back(CUTE(testInicioSesion2));
	s.push_back(CUTE(testvolcarcurso));
	s.push_back(CUTE(testbuscarcurso));
	s.push_back(CUTE(testRegistro));
	s.push_back(CUTE(testInscribirCurso));






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

