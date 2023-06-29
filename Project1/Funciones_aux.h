#pragma once
#include "cANPA.h"
#include "cProt_No_Quirurgica.h"
#include "cProt_Quirurgica.h"
#include <fstream>
#include "Custom_Exceptions.h"
#include <sstream>
#include <iostream>


bool operator==(list<cProtesis*>::iterator original, cProt_No_Quirurgica comparado);
bool operator==(list<cProtesis*>::iterator original, cProt_Quirurgica comparado);
bool operator==(list<cOrtopedia*>::iterator izquierda, list<cOrtopedia*>::iterator Derecha);
bool operator!=(list<cOrtopedia*>::iterator Total, list<cOrtopedia*> Convenida);

list<cProtesis*>::iterator operator+(list<cProtesis*>::iterator corrido, unsigned int corrimiento);  //estas sobrecargas de operadores se usan
list<cOrtopedia*>::iterator operator+(list<cOrtopedia*>::iterator corrido, unsigned int corrimiento); //en las funciones de armar listas random
list<cPaciente*>::iterator operator+(list<cPaciente*>::iterator corrido, unsigned int corrimiento);
list<cMedico*>::iterator operator+(list<cMedico*>::iterator corrido, unsigned int corrimiento);


list<cProtesis*> Armar_lista_random_de_Protesis();
list<cOrtopedia*> Armar_random_ortopedia();
list<string*> Generar_Alergias();
queue<cPaciente*> Armar_random_Pacientes();
list<cMedico*> Armar_random_Medicos();


list<cHospital*> leer_Hospitales();
list<cProtesis*> leer_protesis();
list<cOrtopedia*> Leer_Ortopedias();
list<cPaciente*>leer_Pacientes();
list<cMedico*> leer_Medicos();
list<cFabricante*> leer_Fabricantes();
