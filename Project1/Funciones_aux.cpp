#include "Funciones_aux.h"

bool operator==(list<cProtesis*>::iterator original, cProt_No_Quirurgica comparado)
{

	if ((*original)->get_largo() == comparado.get_largo()&& (*original)->get_ancho() == comparado.get_ancho()&& (*original)->get_nombre() == comparado.get_nombre()&& (*original)->get_Radio() == comparado.get_Radio())
		return true;
	else
	return false;
}

bool operator==(list<cProtesis*>::iterator original, cProt_Quirurgica comparado)
{
	if ((*original)->get_Articulacion() == comparado.get_Articulacion() && (*original)->get_nombre() == comparado.get_nombre() && (*original)->get_material() == comparado.get_material())
		return true;
	else
		return false;
}

bool operator==(list<cOrtopedia*>::iterator izquierda, list<cOrtopedia*>::iterator Derecha)
{
	if ((*izquierda)->get_Nombre() == (*Derecha)->get_Nombre()&& (*izquierda)->get_Direccion() == (*Derecha)->get_Direccion())
	return true;
	else
	return false;
}

bool operator!=(list<cOrtopedia*>::iterator Total, list<cOrtopedia*> Convenida)
{
	list<cOrtopedia*>::iterator it = Convenida.begin();

	while (it != Convenida.end())
	{
		if (Total == it)
			return false;
		it++;
	}
	return true;
}

list<cProtesis*>::iterator operator+(list<cProtesis*>::iterator corrido, unsigned int corrimiento)
{
	for (unsigned int i = 0; i < corrimiento; i++)
		corrido++;
	return corrido;
}
list<cOrtopedia*>::iterator operator+(list<cOrtopedia*>::iterator corrido, unsigned int corrimiento)
{
	for (unsigned int i = 0; i < corrimiento; i++)
		corrido++;
	return corrido;
}
list<cPaciente*>::iterator operator+(list<cPaciente*>::iterator corrido, unsigned int corrimiento)
{
	for (unsigned int i = 0; i < corrimiento; i++)
		corrido++;
	return corrido;
}
list<cMedico*>::iterator operator+(list<cMedico*>::iterator corrido, unsigned int corrimiento)
{
	for (unsigned int i = 0; i < corrimiento; i++)
		corrido++;
	return corrido;
}

list<cProtesis*> Armar_lista_random_de_Protesis()
{
	list<cProtesis*> aux;
	aux.clear();

	try {
		aux = leer_protesis();
	}
	catch (exception* e)
	{
		cout << e->what() << endl;
		delete e;
	}

	list<cProtesis*>::iterator it_prot = aux.begin();

	list<cProtesis*> Retorno;
	Retorno.clear();
	int i;
	
	unsigned int seleccionador;

	for (i = 0; i < 5; i++)
	{
		srand(time(0));
		seleccionador = (rand() % aux.size());           //un numero random que va entre 0 y la cantidad de ojetos
		it_prot =it_prot + seleccionador;              // almacenados en la lista

		Retorno.push_back(*it_prot);                     //se agregan 5 elementos aleatorios de la pool de protesis
		                                                 //que es el archivo

		aux.remove(*it_prot );      //sacamos de la lista aux los elementos que devolvemos para que al
		                           //liberar memoria no se borren los que queremos
		it_prot = aux.begin();
	}
	
	for (list<cProtesis*>::iterator it_aux = aux.begin(); it_aux != aux.end(); it_aux++)
		delete* it_aux;

	return Retorno;
}

list<cOrtopedia*> Armar_random_ortopedia()
{
	list<cOrtopedia*> aux;
	aux.clear();

	try {
		aux=Leer_Ortopedias();
	} 
	catch (exception* e)
	{
		cout << e->what();
		delete e;
	}

	list<cOrtopedia*>::iterator it_ort = aux.begin();
	int i;
	
	unsigned int seleccionador;

	list<cOrtopedia*> Retorno;
	Retorno.clear();

	for (i = 0; i < 5; i++)
	{
		srand(time(0));
		seleccionador = (rand() % aux.size());

		it_ort = it_ort + seleccionador;

		Retorno.push_back(*it_ort);          //se guarda una ortopedia aleatoria de la lista y el iterador
		                                     //vuelve al principio
		aux.remove(*it_ort);                 //sacamos de la lista aux los elementos que devolvemos para que al
		                                     //liberar memoria no se borren los que queremos
		it_ort = aux.begin();
	}

	for (list<cOrtopedia*>::iterator it_aux = aux.begin(); it_aux != aux.end(); it_aux++)
		delete* it_aux;

	return Retorno;
}

list<string*> Generar_Alergias()
{
	srand(time(0));
	list<string*> Retorno;
	Retorno.clear();     // chequeo que este vacia
	
	unsigned int Cantidad= (rand()%6); // puede tener un maximo de 5 alergias y un minimo de 0
	unsigned int Eleccion;

	for (unsigned int i = 0; i < Cantidad; i++)
	{
		string* agregado = new string;
		srand(time(0));
		Eleccion = (rand() % 5 + 1); // se elijen alergias al azar en el switch

		switch (Eleccion)
		{
			
		case 1: {*agregado = "Mani";
			Retorno.push_back(agregado);
			break;
			}

		
		case 2: {*agregado = "Hierro";
			Retorno.push_back(agregado);
			break;
		}

		case 3: {*agregado = "Titanio";
			Retorno.push_back(agregado);
			break;
		}
		case 4: {
			*agregado = "Oricalco";
			Retorno.push_back(agregado);
			break;
		}
		case 5: {
			*agregado = "Platino";
			Retorno.push_back(agregado);
			break;
		}

		default: {
			break;
		}
		}
	}

	return Retorno;
}

queue<cPaciente*> Armar_random_Pacientes()
{
	queue<cPaciente*> Retorno;
	list<cPaciente*>aux;
	aux.clear();

	try
	{
		aux = leer_Pacientes();
	}
	catch (exception* e)
	{
		cout << e->what() << endl;
		delete e;
	}

	list<cPaciente*>::iterator it_Pac = aux.begin();

	unsigned int seleccionador;

	for (int i = 0; i < 5; i++)
	{
		srand(time(0));
		seleccionador = (rand() % aux.size());
		it_Pac = it_Pac + seleccionador;

		Retorno.push(*it_Pac);
		aux.remove(*it_Pac);           // de esta forma cuando liberemos memoria de la lista aux no borraremos
		                               //las instancias que devolvemos
		it_Pac = aux.begin();
	}

	for (list<cPaciente*>::iterator it_aux=aux.begin(); it_aux != aux.end(); it_aux++)
		delete* it_aux;                                           //liberamos memoria de los elementos de la lista que no usamos

	return Retorno;
}

list<cMedico*> Armar_random_Medicos()
{
	list<cMedico*> Retorno;
	Retorno.clear();
	list<cMedico*> aux;
	aux.clear();

	try
	{
		aux = leer_Medicos();
	}
	catch (exception* e)
	{
		cout << e->what() << endl;
		delete e;
	}

	list<cMedico*>::iterator it_med = aux.begin();
	unsigned int seleccionador;

	for (int i = 0; i < 5; i++)
	{
		srand(time(0));
		seleccionador = (rand() % aux.size());
		it_med = it_med + seleccionador;

		Retorno.push_back(*it_med);
		aux.remove(*it_med);

		it_med = aux.begin();
	}

	for (list<cMedico*>::iterator it_aux = aux.begin(); it_aux != aux.end(); it_aux++)
		delete* it_aux;

	return Retorno;
}

list<cHospital*> leer_Hospitales()
{

	ifstream Arch_Hospital;
	Arch_Hospital.open("C:\\Users\\thmon\\OneDrive\\Documents\\Universidad\\Labo de programacion\\G12-Monteros-TP_FINAL\\Project1\\Input Data_files\\Hospitales.csv", ios::in);

	if (!Arch_Hospital.is_open())
	{
		throw new ARCH_NOT_OPENED;
	}

	list<cHospital*> Retorno;
	string headers;
	char coma;

	list<cOrtopedia*> aux_ort;
	queue<cPaciente*> aux_Pac;
	list<cMedico*> aux_med;
	
	string Nombre, Direccion, Especialidad;

	getline(Arch_Hospital, headers);

	Arch_Hospital >> Nombre >> coma >> Direccion >> coma >> Especialidad;

	while (Arch_Hospital)
	{
		aux_ort = Armar_random_ortopedia();
		aux_Pac = Armar_random_Pacientes();
		aux_med = Armar_random_Medicos();

		cHospital* aux_hosp = new cHospital(Nombre, Direccion, Especialidad, aux_med, aux_ort, aux_Pac);
		Retorno.push_back(aux_hosp);

		Arch_Hospital >> Nombre >> coma >> Direccion >> coma >> Especialidad;
	}
	Arch_Hospital.close();

	return Retorno;
}

list<cProtesis*> leer_protesis()
{
	fstream Arch_protesis;
	Arch_protesis.open("C:\\Users\\thmon\\OneDrive\\Documents\\Universidad\\Labo de programacion\\G12-Monteros-TP_FINAL\\Project1\\Input Data_files\\Protesis.csv", ios::in);

	if (!(Arch_protesis.is_open()))
	{
		throw new ARCH_NOT_OPENED;
	}
	
	list<cProtesis*>Retorno;		  //
	string headers;					  //variables basicas de lectura

	float Radio_amp, largo, ancho;
	Radio_amp = largo = ancho = 0;
	string fabricante;
	string articulacion;
	string material;
	unsigned int Nombre;                        // las protesis tienen una enumeracion para identificar su nombre
	bool sup_inf=true;							    // 
	tm fecha_fab;
	getline(Arch_protesis, headers);

	//Arch_protesis >> Radio_amp >> coma >> Nombre >> coma >> fecha_fab.tm_mday >> coma >> fecha_fab.tm_mon >> coma >> fecha_fab.tm_year >> coma >> fabricante >> coma >> sup_inf >> coma >> largo >> coma >> ancho >> coma >> articulacion >> coma >> material;
	getline(Arch_protesis,headers);
	stringstream lectura(headers);
	getline(lectura, headers, ',');
	stringstream(headers) >> Radio_amp;
	getline(lectura, headers, ',');
	stringstream(headers) >> Nombre;
	getline(lectura, headers, '/');
	stringstream(headers) >> fecha_fab.tm_mday;
	getline(lectura, headers, '/');
	stringstream(headers) >> fecha_fab.tm_mon;
	getline(lectura, headers, ',');
	stringstream(headers) >> fecha_fab.tm_year;
	getline(lectura, headers, ',');
	stringstream(headers) >> fabricante;
	getline(lectura, headers, ',');
	stringstream(headers) >> sup_inf;
	getline(lectura, headers, ',');
	stringstream(headers) >> largo;
	getline(lectura, headers, ',');
	stringstream(headers) >> ancho;
	getline(lectura, headers, ',');
	stringstream(headers) >> articulacion;
	getline(lectura, headers, ',');
	stringstream(headers) >> material;

	

	

	while (Arch_protesis)
	{
		

		if (Radio_amp > 0)
		{
			cProt_No_Quirurgica* aux_NQ = new cProt_No_Quirurgica((Organo_Extremidad_Reemplazada)Nombre, fecha_fab, fabricante, sup_inf, largo, ancho, Radio_amp);
			Retorno.push_back(aux_NQ);
		}
		else
		{
			cProt_Quirurgica* aux_Q = new cProt_Quirurgica(articulacion, material, (Organo_Extremidad_Reemplazada)Nombre, fecha_fab, fabricante, sup_inf);
			Retorno.push_back(aux_Q);
		}
		getline(Arch_protesis, headers);
		stringstream lectura(headers);
		getline(lectura, headers, ',');
		stringstream(headers) >> Radio_amp;
		getline(lectura, headers, ',');
		stringstream(headers) >> Nombre;
		getline(lectura, headers, '/');
		stringstream(headers) >> fecha_fab.tm_mday;
		getline(lectura, headers, '/');
		stringstream(headers) >> fecha_fab.tm_mon;
		getline(lectura, headers, ',');
		stringstream(headers) >> fecha_fab.tm_year;
		getline(lectura, headers, ',');
		stringstream(headers) >> fabricante;
		getline(lectura, headers, ',');
		stringstream(headers) >> sup_inf;
		getline(lectura, headers, ',');
		stringstream(headers) >> largo;
		getline(lectura, headers, ',');
		stringstream(headers) >> ancho;
		getline(lectura, headers, ',');
		stringstream(headers) >> articulacion;
		getline(lectura, headers, ',');
		stringstream(headers) >> material;
	}

	Arch_protesis.close();
	return Retorno;
}

list<cOrtopedia*> Leer_Ortopedias()
{
	fstream Arch_Ortopedias;
	Arch_Ortopedias.open("C:\\Users\\thmon\\OneDrive\\Documents\\Universidad\\Labo de programacion\\G12-Monteros-TP_FINAL\\Project1\\Input Data_files\\Ortopedias.csv", ios::in);

	if (!(Arch_Ortopedias.is_open()))
	{
		throw new ARCH_NOT_OPENED;
	}

	string nombre, direccion;
	list <cOrtopedia*> Retorno_ortopedias;	   //
	string headers;				   //variables basicas de lectura
	char coma;			           //
	
	getline(Arch_Ortopedias, headers);

	Arch_Ortopedias >> nombre >> coma >> direccion;
	list<cProtesis*> aux;
	
	while (Arch_Ortopedias)
	{
		try {
			aux = Armar_lista_random_de_Protesis(); // le generamos una lista de protesis randomizada a cada ortopedia
		}											//la lista en si la creo afuera del try porque sino el codigo la considera
		catch (exception* e)						//como no existente al crear el objeto de paciente
		{
			cout << e->what() << endl;
			delete e;
		}

		cOrtopedia* Auxiliar = new cOrtopedia(nombre, direccion, aux);
		Retorno_ortopedias.push_back(Auxiliar);

		Arch_Ortopedias >> nombre >> coma >> direccion;
	}
	Arch_Ortopedias.close();

	return Retorno_ortopedias;
}

list<cPaciente*> leer_Pacientes()
{
	ifstream Arch_Pacientes;
	Arch_Pacientes.open("C:\\Users\\thmon\\OneDrive\\Documents\\Universidad\\Labo de programacion\\G12-Monteros-TP_FINAL\\Project1\\Input Data_files\\Pacientes.csv", ios::in);

	if (!(Arch_Pacientes.is_open()))
	{
		throw new ARCH_NOT_OPENED();
	}

	list <cPaciente*> Retorno;	   //
	string headers;				   //variables basicas de lectura
	char coma;			           //

	//Nombre , Fecha_Nac , Telefono , Radio_Amp

	string Nombre, Telefono;
	float Radio_amp;
	tm Fecha_nac;

	getline(Arch_Pacientes, headers);

	list<string*> Alergias;

	Arch_Pacientes >> Nombre >> coma >> Fecha_nac.tm_mday >> coma >> Fecha_nac.tm_mon >> coma >> Fecha_nac.tm_year >> coma >> Telefono >> coma >> Radio_amp;

	while (Arch_Pacientes)
	{
		
		Alergias = Generar_Alergias();   // le generamos una lista de alergias randomizada a cada paciente

		cPaciente* Pac = new cPaciente(Nombre, Fecha_nac, Telefono, Alergias, Radio_amp);
		Retorno.push_back(Pac);

		Arch_Pacientes >> Nombre >> coma >> Fecha_nac.tm_mday >> coma >> Fecha_nac.tm_mon >> coma >> Fecha_nac.tm_year >> coma >> Telefono >> coma >> Radio_amp;

	}
	Arch_Pacientes.close();
	return Retorno;
}

list<cMedico*> leer_Medicos()
{
	ifstream Arch_Medicos;
	Arch_Medicos.open("C:\\Users\\thmon\\OneDrive\\Documents\\Universidad\\Labo de programacion\\G12-Monteros-TP_FINAL\\Project1\\Input Data_files\\Medicos.csv", ios::in);

	if (!Arch_Medicos.is_open())
	{
		throw new ARCH_NOT_OPENED;
	}

	string Nombre, headers ;
	unsigned int Matricula=0;
	char coma;
	list<cMedico*> Retorno;

	getline(Arch_Medicos, headers);
	Arch_Medicos >> Nombre>> coma>> Matricula;

	while (Arch_Medicos)
	{
		srand(time(0));
		cMedico* Actual = new cMedico(Nombre, Matricula);
		Retorno.push_back(Actual);
		Arch_Medicos >> Nombre>> coma>> Matricula;
	}
	Arch_Medicos.close();

	return Retorno;
}

list<cFabricante*> leer_Fabricantes()
{
	fstream Arch_Fabricantes;

	Arch_Fabricantes.open("C:\\Users\\thmon\\OneDrive\\Documents\\Universidad\\Labo de programacion\\G12-Monteros-TP_FINAL\\Project1\\Input Data_files\\Fabricantes.csv", ios::in);

	if (!Arch_Fabricantes.is_open())
	{
		throw new ARCH_NOT_OPENED;
	}
	list<cFabricante*> Retorno;		 //
	string headers;					 //variables basicas de lectura
	char coma;						 //

	string Nombre, Direccion;
	unsigned int Num_Habilitacion;
	getline(Arch_Fabricantes, headers);

	Arch_Fabricantes >> Nombre >> coma >> Direccion >> coma >> Num_Habilitacion;

	while (Arch_Fabricantes)
	{
		cFabricante* Nuevo = new cFabricante(Nombre, Direccion, Num_Habilitacion);
		Retorno.push_back(Nuevo);
		Arch_Fabricantes >> Nombre >> coma >> Direccion >> coma >> Num_Habilitacion;

	}
	Arch_Fabricantes.close();

	return Retorno;
}

list<cHospital*> Hospitales_Predeterminados()
{
	list<cHospital*> Retorno;
	Retorno.clear();
	
	cMedico* Medico1 = new cMedico("Juan_Juan", 45598355, false);
	cMedico* Medico2 = new cMedico("Antonio_Perez", 34524256, true);
	cMedico* Medico3 = new cMedico("Osvaldo_Gutierrez", 409842092, false);
	cMedico* Medico4 = new cMedico("Mateo_Pilomini", 45527890, true);
	cMedico* Medico5 = new cMedico("Juan_NoJuan", 37124035, true);
	list<cMedico*> Lista_Medicos;
	Lista_Medicos.push_back(Medico1);
	Lista_Medicos.push_back(Medico2);
	Lista_Medicos.push_back(Medico3);
	Lista_Medicos.push_back(Medico4);
	Lista_Medicos.push_back(Medico5);

	list<cProtesis*> aux;
	aux.clear();
	cOrtopedia* Ortopedia1 = new cOrtopedia("San_Juan", "Dorrego_999", aux);//no es necesario que estos objetos de Ortopedia tengan un stock declarado porque solo se compararan los nombres en las funciones
	cOrtopedia* Ortopedia2 = new cOrtopedia("Alexander_Chaparri", "Brasil_547", aux);
	list<cOrtopedia*> Convenidas;
	Convenidas.push_back(Ortopedia1);
	Convenidas.push_back(Ortopedia2);

	tm aux_f;
	aux_f.tm_mday = 05; aux_f.tm_mon = 10; aux_f.tm_year = 2000;
	cPaciente* Paciente1 = new cPaciente("Lucia_Quintana", aux_f, "1144227740", Generar_Alergias(), 2.9);
	aux_f.tm_mday = 27; aux_f.tm_mon = 12; aux_f.tm_year = 2004;
	cPaciente* Paciente2 = new cPaciente("Eric_Gadea",  aux_f , "1169035382", Generar_Alergias(), 0);
	aux_f.tm_mday = 15; aux_f.tm_mon = 04; aux_f.tm_year = 2004;
	cPaciente* Paciente3 = new cPaciente("Ariana_Ordonyez", aux_f, "1162569077",Generar_Alergias(), 0);
	aux_f.tm_mday = 8; aux_f.tm_mon = 02; aux_f.tm_year = 2004;
	cPaciente* Paciente4 = new cPaciente("Alma_Maiolino", aux_f , "1146738292", Generar_Alergias(), 6.2);
	aux_f.tm_mday = 03; aux_f.tm_mon = 06; aux_f.tm_year = 2004;
	cPaciente* Paciente5 = new cPaciente("Juan_Perez", aux_f, "1161197786", Generar_Alergias(), 0.9);

	queue<cPaciente*> Cola_pacientes;
	Cola_pacientes.push(Paciente1);
	Cola_pacientes.push(Paciente2);
	Cola_pacientes.push(Paciente3);
	Cola_pacientes.push(Paciente4);
	Cola_pacientes.push(Paciente5);

	cHospital* Hospitalito = new cHospital("San_Juan_De_Dios", "Brasil_959", "Cardiologia",Lista_Medicos,Convenidas,Cola_pacientes);
	Retorno.push_back(Hospitalito);

	return Retorno;
}

list<cOrtopedia*> Ortopedias_Predeterminadas()
{
	list<cOrtopedia*> Retorno;

	tm aux;
	aux.tm_mday = 23; aux.tm_mon = 02; aux.tm_year = 2019;
	cProt_No_Quirurgica* Protesis_NQ1 = new cProt_No_Quirurgica((Organo_Extremidad_Reemplazada)1, aux, "Stephano", true, 20.4, 19.1, 4.5);
	aux.tm_mday = 04; aux.tm_mon = 11; aux.tm_year = 2020;
	cProt_No_Quirurgica* Protesis_NQ2 = new cProt_No_Quirurgica((Organo_Extremidad_Reemplazada)2, aux, "Ariana_Pereyra", false, 90.0, 20.0, 9.2);
	aux.tm_mday = 03; aux.tm_mon = 01; aux.tm_year = 2023;
	cProt_No_Quirurgica* Protesis_NQ3 = new cProt_No_Quirurgica((Organo_Extremidad_Reemplazada)3, aux, "Agustina", true, 10.5, 8.0, 2.5);
	aux.tm_mday = 15; aux.tm_mon = 04; aux.tm_year = 2023;
	cProt_No_Quirurgica* Protesis_NQ4 = new cProt_No_Quirurgica((Organo_Extremidad_Reemplazada)4, aux, "Fernando_Oras", true, 8.3, 0.2, 0.3);
	aux.tm_mday = 30; aux.tm_mon = 8; aux.tm_year = 2020;
	cProt_No_Quirurgica* Protesis_NQ5 = new cProt_No_Quirurgica((Organo_Extremidad_Reemplazada)5, aux, "Juliana", false, 7.8, 8.9, 4.5);

	aux.tm_mday = 05; aux.tm_mon = 11; aux.tm_year = 2022;
	cProt_Quirurgica* Protesis_Q1 = new cProt_Quirurgica("Esternoclavicular", "Platino", (Organo_Extremidad_Reemplazada)6, aux, "Agustina", true);
	aux.tm_mday = 06; aux.tm_mon = 07; aux.tm_year = 2021;
	cProt_Quirurgica* Protesis_Q2 = new cProt_Quirurgica("Coxofemoral", "Titanio", (Organo_Extremidad_Reemplazada)7, aux, "Stephano", false);
	aux.tm_mday = 15; aux.tm_mon = 04; aux.tm_year = 2023;
	cProt_Quirurgica* Protesis_Q3 = new cProt_Quirurgica("Escapula", "Hierro", (Organo_Extremidad_Reemplazada)8, aux, "Ariana_Pereyra", true);
	aux.tm_mday = 20; aux.tm_mon = 9; aux.tm_year = 2022;
	cProt_Quirurgica* Protesis_Q4 = new cProt_Quirurgica("Tallo Femoral", "Platino", (Organo_Extremidad_Reemplazada)9, aux, "Agustina", false);
	aux.tm_mday = 25; aux.tm_mon = 04; aux.tm_year = 2023;
	cProt_Quirurgica* Protesis_Q5 = new cProt_Quirurgica("Mandibula", "Titanio", (Organo_Extremidad_Reemplazada)10, aux, "Stephano", true);

	list<cProtesis*> Protesis_ortopedia;
	Protesis_ortopedia.push_back(Protesis_NQ1);
	Protesis_ortopedia.push_back(Protesis_NQ5);
	Protesis_ortopedia.push_back(Protesis_Q3);
	Protesis_ortopedia.push_back(Protesis_Q5);
	Protesis_ortopedia.push_back(Protesis_Q4);
	cOrtopedia* Ortopedia1 = new cOrtopedia("San_Juan", "Dorrego_999", Protesis_ortopedia);

	Protesis_ortopedia.clear();
	Protesis_ortopedia.push_back(Protesis_NQ2);
	Protesis_ortopedia.push_back(Protesis_Q2);
	Protesis_ortopedia.push_back(Protesis_NQ3);
	Protesis_ortopedia.push_back(Protesis_Q1);
	Protesis_ortopedia.push_back(Protesis_NQ4);
	cOrtopedia* Ortopedia2 = new cOrtopedia("Alexander_Chaparri", "Brasil_547", Protesis_ortopedia);

	//
	//
	Protesis_ortopedia.clear();
	Protesis_ortopedia.push_back(Protesis_NQ1);
	Protesis_ortopedia.push_back(Protesis_Q2);
	Protesis_ortopedia.push_back(Protesis_NQ5);
	Protesis_ortopedia.push_back(Protesis_Q5);
	Protesis_ortopedia.push_back(Protesis_NQ4);
	cOrtopedia* Ortopedia3 = new cOrtopedia("Quintana_Pereyra", "Reconquista_567", Protesis_ortopedia);

	Protesis_ortopedia.clear();
	Protesis_ortopedia.push_back(Protesis_NQ3);
	Protesis_ortopedia.push_back(Protesis_Q5);
	Protesis_ortopedia.push_back(Protesis_NQ5);
	Protesis_ortopedia.push_back(Protesis_Q2);
	Protesis_ortopedia.push_back(Protesis_NQ2);
	cOrtopedia* Ortopedia4 = new cOrtopedia("Chilapri", "Callao_555", Protesis_ortopedia);

	Retorno.push_back(Ortopedia1);
	Retorno.push_back(Ortopedia2);
	Retorno.push_back(Ortopedia3);
	Retorno.push_back(Ortopedia4);
	return Retorno;
}

list<cFabricante*> Fabricantes_Predeterminados()
{


	cFabricante* Fabricante1 = new cFabricante("Stephano", "Federico_Alvear_457", 455324455);
	cFabricante* Fabricante2 = new cFabricante("Juliana", "Libetador_889", 455242557);
	cFabricante* Fabricante3 = new cFabricante("Ariana_Pereyra", "Brandy_876", 643557824);
	cFabricante* Fabricante4 = new cFabricante("Fernando_Oras", "Anubis_198", 543354476);
	cFabricante* Fabricante5 = new cFabricante("Fernando_Oras", "Anubis_198", 543354476);
	cFabricante* Fabricante6 = new cFabricante("Agustina", "Ordonyes_765", 123321345);
	list<cFabricante*> Retorno;
	Retorno.push_back(Fabricante1);
	Retorno.push_back(Fabricante2);
	Retorno.push_back(Fabricante3);
	Retorno.push_back(Fabricante4);
	Retorno.push_back(Fabricante5);
	Retorno.push_back(Fabricante6);

	return Retorno;
}
