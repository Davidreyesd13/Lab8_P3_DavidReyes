#include <iostream>
#include <vector>
#include<fstream>
#include <sstream>
#include "Cohetes.h"
#include<ctime>
using namespace std;
void leerarchivo(vector<Cohetes*>vuelos) {
	string n_archivo = "spaceZ.txt";
	ifstream archivo(n_archivo.c_str());
	string linea,nombre,nombre_planeta,flag;
	int ala1=0, ala2=0,cont;
	double gasolina=0;
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
				ala1 = std::atoi(flag.c_str());
				break;
			case 2:
				ala2 = std::atoi(flag.c_str());
				break;
			case 3:
				gasolina = std::stod(flag);
				break;
			case 4:
				nombre_planeta = flag;
				break;
			default:
				break;
			}
			cont++;
		}
		vuelos.push_back(new Cohetes(nombre, ala1, ala2, gasolina, nombre_planeta));
	}
}
void viaje(vector<Cohetes*>vuelos) {
	ofstream bitacora("Bitacora.txt");
	int lluvia,prob,ruta;
	srand(time(NULL));
	for (int i = 0; i < vuelos.size(); i++)
	{
		if (vuelos.at(i)->getplaneta()=="Marte") {
			
			lluvia = 20;
			prob = 1 + rand()%20;
			if (lluvia==prob) {
				vuelos.at(i)->setalad(vuelos.at(i)->getalad()-40);
				vuelos.at(i)->setalaizq(vuelos.at(i)->getalaizq() - 40);
				if (vuelos.at(i)->getgasolina()>400000&& vuelos.at(i)->getalad()>0&& vuelos.at(i)->getalaizq()>0) {
					bitacora << i<<vuelos.at(i)->getnombre() << "Llego con exito"<<vuelos.at(i)->getplaneta()<<"\n";
				}
				else if(vuelos.at(i)->getgasolina() < 400000){
					bitacora << i << vuelos.at(i)->getnombre() << "se quedo sin gasolina y no pudo llegar" << vuelos.at(i)->getplaneta();
				}
				else if (vuelos.at(i)->getalad() < 0) {
					bitacora << i << vuelos.at(i)->getnombre() << "Perdio la ala derecha y no pudo llegar" << vuelos.at(i)->getplaneta();
				}
				else if(vuelos.at(i)->getalaizq() < 0){
					bitacora << i << vuelos.at(i)->getnombre() << "Perdio la ala izquierda y no pudo llegar" << vuelos.at(i)->getplaneta();
				}
			}
			else {
				if (vuelos.at(i)->getgasolina() > 400000 && vuelos.at(i)->getalad() > 0 && vuelos.at(i)->getalaizq() > 0) {
					bitacora << i << vuelos.at(i)->getnombre() << "Llego con exito" << vuelos.at(i)->getplaneta();
				}
				else if (vuelos.at(i)->getgasolina() < 400000) {
					bitacora << i << vuelos.at(i)->getnombre() << "se quedo sin gasolina y no pudo llegar" << vuelos.at(i)->getplaneta();
				}
				else if (vuelos.at(i)->getalad() < 0) {
					bitacora << i << vuelos.at(i)->getnombre() << "Perdio la ala derecha y no pudo llegar" << vuelos.at(i)->getplaneta();
				}
				else if (vuelos.at(i)->getalaizq() < 0) {
					bitacora << i << vuelos.at(i)->getnombre() << "Perdio la ala izquierda y no pudo llegar" << vuelos.at(i)->getplaneta();
				}
			}

		}
		else if(vuelos.at(i)->getplaneta() == "Saturno"){
			lluvia = 50;
			prob = 1 + rand() % 50;
			if (lluvia == prob) {
				vuelos.at(i)->setalad(vuelos.at(i)->getalad() - 40);
				vuelos.at(i)->setalaizq(vuelos.at(i)->getalaizq() - 40);
				vuelos.at(i)->setalad(vuelos.at(i)->getalad() - 30);
				vuelos.at(i)->setalaizq(vuelos.at(i)->getalaizq() - 30);
				if (vuelos.at(i)->getgasolina() > 400000 && vuelos.at(i)->getalad() > 0 && vuelos.at(i)->getalaizq() > 0) {
					bitacora << i << vuelos.at(i)->getnombre() << "Llego con exito" << vuelos.at(i)->getplaneta();
				}
				else if (vuelos.at(i)->getgasolina() < 400000) {
					bitacora << i << vuelos.at(i)->getnombre() << "se quedo sin gasolina y no pudo llegar" << vuelos.at(i)->getplaneta();
				}
				else if (vuelos.at(i)->getalad() < 0) {
					bitacora << i << vuelos.at(i)->getnombre() << "Perdio la ala derecha y no pudo llegar" << vuelos.at(i)->getplaneta();
				}
				else if (vuelos.at(i)->getalaizq() < 0) {
					bitacora << i << vuelos.at(i)->getnombre() << "Perdio la ala izquierda y no pudo llegar" << vuelos.at(i)->getplaneta();
				}
			}
			else {
				vuelos.at(i)->setalad(vuelos.at(i)->getalad() - 30);
				vuelos.at(i)->setalaizq(vuelos.at(i)->getalaizq() - 30);
				if (vuelos.at(i)->getgasolina() > 400000 && vuelos.at(i)->getalad() > 0 && vuelos.at(i)->getalaizq() > 0) {
					bitacora << i << vuelos.at(i)->getnombre() << "Llego con exito" << vuelos.at(i)->getplaneta();
				}
				else if (vuelos.at(i)->getgasolina() < 400000) {
					bitacora << i << vuelos.at(i)->getnombre() << "se quedo sin gasolina y no pudo llegar" << vuelos.at(i)->getplaneta();
				}
				else if (vuelos.at(i)->getalad() < 0) {
					bitacora << i << vuelos.at(i)->getnombre() << "Perdio la ala derecha y no pudo llegar" << vuelos.at(i)->getplaneta();
				}
				else if (vuelos.at(i)->getalaizq() < 0) {
					bitacora << i << vuelos.at(i)->getnombre() << "Perdio la ala izquierda y no pudo llegar" << vuelos.at(i)->getplaneta();
				}
			}
		}
		else {
			ruta = 1 + rand() % 3;
			if (ruta==2) {
				lluvia = 90;
				prob = 1 + rand() % 90;
				if (lluvia == prob) {
					vuelos.at(i)->setalad(vuelos.at(i)->getalad() - 40);
					vuelos.at(i)->setalaizq(vuelos.at(i)->getalaizq() - 40);
					if (vuelos.at(i)->getgasolina() > 400000 && vuelos.at(i)->getalad() > 0 && vuelos.at(i)->getalaizq() > 0) {
						bitacora << i << vuelos.at(i)->getnombre() << "de manera milagrosa logró llegar a " << vuelos.at(i)->getplaneta();
					}
					else if (vuelos.at(i)->getgasolina() < 400000) {
						bitacora << i << vuelos.at(i)->getnombre() << "se quedo sin gasolina y no pudo llegar" << vuelos.at(i)->getplaneta();
					}
					else if (vuelos.at(i)->getalad() < 0) {
						bitacora << i << vuelos.at(i)->getnombre() << "Perdio la ala derecha y no pudo llegar" << vuelos.at(i)->getplaneta();
					}
					else if (vuelos.at(i)->getalaizq() < 0) {
						bitacora << i << vuelos.at(i)->getnombre() << "Perdio la ala izquierda y no pudo llegar" << vuelos.at(i)->getplaneta();
					}
				}
				else {
					if (vuelos.at(i)->getgasolina() > 400000 && vuelos.at(i)->getalad() > 0 && vuelos.at(i)->getalaizq() > 0) {
						bitacora << i << vuelos.at(i)->getnombre() << "de manera milagrosa logró llegar a " << vuelos.at(i)->getplaneta();
					}
					else if (vuelos.at(i)->getgasolina() < 400000) {
						bitacora << i << vuelos.at(i)->getnombre() << "se quedo sin gasolina y no pudo llegar" << vuelos.at(i)->getplaneta();
					}
					else if (vuelos.at(i)->getalad() < 0) {
						bitacora << i << vuelos.at(i)->getnombre() << "Perdio la ala derecha y no pudo llegar" << vuelos.at(i)->getplaneta();
					}
					else if (vuelos.at(i)->getalaizq() < 0) {
						bitacora << i << vuelos.at(i)->getnombre() << "Perdio la ala izquierda y no pudo llegar" << vuelos.at(i)->getplaneta();
					}
				}
			}
			else {
				bitacora << i << vuelos.at(i)->getnombre() << "se perdio en el silencioso espacio tratando dellegar a " << vuelos.at(i)->getplaneta();
			}
		}
	}
}
void eliminarbitacora() {
	remove("Bitacora.txt");
}
void menu() {
	int opcion = 0;
	vector<Cohetes*> vuelos;
	while (opcion != 4) {
		cout << "1.Leer archivo\n2.Guardar Bitacora\n3.Eliminar Bitacora\n4.Salir" << endl;
		cin >> opcion;
		switch (opcion) {
		case 1:
			leerarchivo(vuelos);
			break;
		case 2:
			viaje(vuelos);
			break;
		case 3:
			eliminarbitacora();
				break;
		case 4:
			cout << "Buen Dia";
			vuelos.clear();
			break;
		default:
			cout << "Opcion no valida";
		}
	}
}
int main(){
	menu();
}