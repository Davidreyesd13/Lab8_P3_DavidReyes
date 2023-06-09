#pragma once
#include <string>
using namespace std;
class Cohetes
{
	string nombre,planeta;
	double alad, alaizq;
	int gasolina;
public:
	Cohetes(string nombre,double alad,double alaizq,int gasolina,string planeta);
	void setnombre(string name);
	void setplaneta(string planeta);
	void setalad(double Alad);
	void setalaizq(double Alaizq);
	void setgasolina(int Gasolina);
	string getnombre();
	double getalad();
	double getalaizq();
	int getgasolina();
	string getplaneta();
};

