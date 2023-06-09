#include <iostream>
#include <vector>
#include<fstream>
#include <sstream>
#include "Cohetes.h"
using namespace std;
void leerarchivo() {
	string n_archivo = "spaceZ.txt";
	ifstream archivo(n_archivo.c_str());
	string linea,nombre,nombre_planeta,flag;
	int ala1, ala2,cont;
	double gasolina;
	while (getline(archivo,linea)) {
		cont = 0;
		stringstream input_stringstream(linea);
		while (getline(input_stringstream, flag,',')) {
			switch (cont)
			{
			case 0:
				nombre = flag;
				break;
			case 1:
				ala1 = (int)flag;
				break;
			case 2:
				ala2 = (int)flag;
				break;
			case 3:
				gasolina = (double)flag;
				break;
			case 4:
				nombre_planeta = flag;
				break;
			default:
				break;
			}
			cont++;
		}
	}
}
void menu() {
	int opcion = 0;
	vector<Cohetes> vuelos;
	while (opcion != 4) {
		cout << "1.Leer archivo\n2.Guardar Bitacora\n3.Eliminar Bitacora\n4.Salir" << endl;
		cin >> opcion;
		switch (opcion) {
		case 1:
			leerarchivo();
			break;
		case 2:

			break;
		case 3:
			
			break;
		case 4:
			cout << "Buen Dia";
			break;
		default:
			cout << "Opcion no valida";
		}
	}
}
int main(){
	menu();
}