/*
 * MCubiculo.cpp
 *
 *  Created on: 25/06/2021
 *      Author: Usuario
 */

#include "../MCubiculo.h"

MCubiculo::MCubiculo(string _codigo) {
	codigo = _codigo;
}
MCubiculo::MCubiculo(){

}

string MCubiculo::getCodigo(){
	return codigo;
}
void MCubiculo::setCodigo(string _codigo){
	codigo = _codigo;
}

bool MCubiculo::agregarPaciente(string cedula){
	return cedulaPaciente.Insertar(cedula);
}

bool MCubiculo::removerPaciente(string &cedulaBuscada){
	string ancla = "-1";
	string cedulaActual;
	bool encontrado = false;
	cedulaPaciente.Insertar(ancla);
	cedulaPaciente.Remover(cedulaActual);
	while(cedulaActual != ancla){
		if(cedulaActual != cedulaBuscada){
			cedulaPaciente.Insertar(cedulaActual);
		}
		else encontrado = true;
		cedulaPaciente.Remover(cedulaActual);
	}
	return encontrado;
}

bool MCubiculo::removerPrimerPaciente(string &cedula){
	return cedulaPaciente.Remover(cedula);
}

bool MCubiculo::esVacia(){
	return cedulaPaciente.Vacia();
}
