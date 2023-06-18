#pragma once
#include "cANPA.h"
#include "cProt_No_Quirurgica.h"
#include "cProt_Quirurgica.h"
#include <fstream>
#include "Custom_Exceptions.h"
#include <iostream>

bool operator==(list<cProtesis*>::iterator original, cProt_No_Quirurgica comparado);
bool operator==(list<cProtesis*>::iterator original, cProt_Quirurgica comparado);
bool operator==(list<cOrtopedia*>::iterator izquierda, list<cOrtopedia*>::iterator Derecha);
bool operator!=(list<cOrtopedia*>::iterator Total, list<cOrtopedia*> Convenida);

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
