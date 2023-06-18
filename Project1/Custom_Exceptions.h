#pragma once
#include <exception>

using namespace std;

class ARCH_NOT_OPENED: public exception {    // se lanza esta excepcion cuando hay un problema al abrir algun archivo

public:
	const char* what() const throw() {
		return "Error, no se pudo abrir el Archivo";
	}
};

class OBJECT_NOT_FOUND :public exception {     // se lanza esta exception cuando falla un metodo de busqueda
public:
	const char* what() const throw() {
		return "Error, no se encontro el elemento buscado";
	}
};

class RANDOM_CREATION_FAILED :public exception {  // en las "Funciones_aux" hay varias funciones que crean listas randomizadas
public:											  // con los contenidos de los archivos, si fallan se lanza esta exception
	const char* what() const throw() {
		return "Error al Crear una lista random";
	}
};