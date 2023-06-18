#pragma once
#include "cANPA.h"
#include "cProt_No_Quirurgica.h"
#include "cProt_Quirurgica.h"

bool operator==(list<cProtesis*>::iterator original, cProt_No_Quirurgica comparado);
bool operator==(list<cProtesis*>::iterator original, cProt_Quirurgica comparado);
bool operator==(list<cOrtopedia*>::iterator izquierda, list<cOrtopedia*>::iterator Derecha);
bool operator!=(list<cOrtopedia*>::iterator Total, list<cOrtopedia*> Convenida);
