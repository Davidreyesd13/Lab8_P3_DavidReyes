#include "Cohetes.h"

Cohetes::Cohetes(string Nombre, double Alad, double Alaizq, int Gasolina,string Planeta)
{
	nombre = Nombre;
	alad = Alad;
	alaizq = Alaizq;
	if (Gasolina<=900000) {
		gasolina = Gasolina;
	}
	planeta = Planeta;
}

void Cohetes::setnombre(string name)
{
	nombre =name;
}
void Cohetes::setplaneta(string Planeta) {
	planeta = Planeta;
}
void Cohetes::setalad(double Alad)
{
	alad = Alad;
}

void Cohetes::setalaizq(double Alaizq)
{
	alaizq = Alaizq;
}

void Cohetes::setgasolina(int Gasolina)
{
	gasolina = Gasolina;
}

string Cohetes::getnombre()
{
	return nombre;
}
string Cohetes::getplaneta() {
	return planeta;
}
double Cohetes::getalad()
{
	return alad;
}

double Cohetes::getalaizq()
{
	return alaizq;
}

int Cohetes::getgasolina()
{
	return gasolina;
}
