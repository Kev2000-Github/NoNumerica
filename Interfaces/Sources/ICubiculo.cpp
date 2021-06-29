/*
 * ICubiculo.cpp
 *
 *  Created on: 29/06/2021
 *      Author: Usuario
 */

#include "../ICubiculo.h"
#include <iostream>
using namespace std;

ICubiculo::ICubiculo() {}

void ICubiculo::reportarCedula(Cola<string> cedula){
	string ced,punto="fin";
	bool final=false;

	if(cedula.Vacia())
		cout<< "No Hay Personas en la Cola"<< endl<< endl;
	else{
		cedula.Insertar(punto);
		cout<< "Listado de Personas en Espera"<< endl<< endl;
		while(!(final)){
			cedula.Remover(ced);
			if(ced==punto)
				final=true;
			else{
				cout << "Cedula: " << ced << endl;
				cedula.Insertar(ced);
			};
		};
	};
}
