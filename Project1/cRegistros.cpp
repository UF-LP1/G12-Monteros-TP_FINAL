#include "cRegistros.h"



cRegistros::cRegistros(string Hospital_, string Medico_, tm Fecha_sol_, tm Fecha_Entrega_, unsigned int Estimacion_, Organo_Extremidad_Reemplazada Pieza_, string Paciente_, string Nombre_Fuente_):Hospital(Hospital_), Medico(Medico_), Fecha_Sol(Fecha_sol_), Fecha_Entrega(Fecha_Entrega_), Estimacion(Estimacion_), Pieza(Pieza_), Paciente(Paciente_), Nombre_Fuente(Nombre_Fuente_)
{
}

cRegistros::~cRegistros()
{

}

string cRegistros::to_string_registros() const
{
    stringstream Salida;
    Salida << ", Fecha de entrega: " << this->Fecha_Entrega.tm_mday << "/" << this->Fecha_Entrega.tm_mon << "/" << this->Fecha_Entrega.tm_year+1900
        << ", Estimacion: " << this->Estimacion
        << ", Fecha de Solicitud: " << this->Fecha_Sol.tm_mday << "/" << this->Fecha_Sol.tm_mon << "/" << this->Fecha_Sol.tm_year+1900
        << ", Hospital: " << this->Hospital
        << ", Medico: " << this->Medico
        << ", Pieza Quirurgica: " << this->Pieza
        << ", Nombre del paciente: " << this->Paciente
        << ", Fuente de la pieza: " << this->Nombre_Fuente << endl;
       
    return Salida.str();
}
//Hospital , medico , Fecha_Solicitud , Fecha_Entrega , Estimacion , Pieza , Paciente , Fuente
//Brazo = 1, Pierna, Mano, Dedo, Pie, Hombro, Cadera, Clavicula, Placa_Metalica, Implante_Dental
string cRegistros::to_string_registros_csv() const
{
    string Pieza_;
    switch (this->Pieza)
    {
    case 1:Pieza_ = "Brazo"; break;
    case 2:Pieza_ = "Pierna"; break;
    case 3:Pieza_ = "Mano"; break;
    case 4:Pieza_ = "Dedo"; break;
    case 5:Pieza_ = "Pie"; break;
    case 6:Pieza_ = "Hombro"; break;
    case 7:Pieza_ = "Cadera"; break;
    case 8:Pieza_ = "Clavicula"; break;
    case 9:Pieza_ = "Placa Metalica"; break;
    case 10:Pieza_ = "Implante dental"; break;
    default: Pieza_ = "NN"; break;
    }

    stringstream Salida;
    Salida << this->Hospital << " , "
        << this->Medico << " , "
        << this->Fecha_Sol.tm_mday << "/" << this->Fecha_Sol.tm_mon << "/" << this->Fecha_Sol.tm_year + 1900 << " , "
        << this->Fecha_Entrega.tm_mday << "/" << this->Fecha_Entrega.tm_mon << "/" << this->Fecha_Entrega.tm_year + 1900 << " , "
        << this->Estimacion << " , "
        << Pieza_ << " , "
        << this->Paciente << " , "
        << this->Nombre_Fuente << endl;

    return Salida.str();
}

ostream& operator<<(ostream& out, const cRegistros& Registro)
{
    out << Registro.to_string_registros() << endl;
    return out;
}
