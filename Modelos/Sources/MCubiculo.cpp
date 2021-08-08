/*
 * MCubiculo.cpp
 *
 *  Created on: 25/06/2021
 *      Author: Usuario
 */

#include "../MCubiculo.h"

MCubiculo::MCubiculo(string _codigo)
{
	codigo = _codigo;
}
MCubiculo::MCubiculo()
{
}

string MCubiculo::getCodigo()
{
	return codigo;
}
void MCubiculo::setCodigo(string _codigo)
{
	codigo = _codigo;
}

bool MCubiculo::agregarPaciente(string cedula)
{
	return cedulaPaciente.Insertar(cedula);
}

bool MCubiculo::removerPrimerPaciente(string &cedula)
{
	return cedulaPaciente.Remover(cedula);
}

bool MCubiculo::removerPaciente(string &cedula)
{
	Cola<string> colaAux;
	string auxced;
	bool encontrado = false;
	while (!cedulaPaciente.Vacia())
	{
		cedulaPaciente.Remover(auxced);
		if (auxced == cedula)
		{
			cedula = auxced;
			encontrado = true;

			//break;
		}
		else

		{
			colaAux.Insertar(auxced);
		}
	}
	while (!colaAux.Vacia())
	{
		colaAux.Remover(auxced);
		cedulaPaciente.Insertar(auxced);
	}
	return encontrado;
}

bool MCubiculo::esVacia()
{
	return cedulaPaciente.Vacia();
}

int MCubiculo::total()
{
	string ced, punto = "fin";
	int cont = 0;
	agregarPaciente(punto);
	removerPrimerPaciente(ced);
	while(ced != punto)
	{
		cont++;
		agregarPaciente(ced);
		removerPrimerPaciente(ced);
	}
	return cont;
}

bool MCubiculo::buscarPaciente(string &cedula){
	Cola<string> colaAux;
	string auxced;
		bool encontrado = false;
		while(!cedulaPaciente.Vacia()){
			cedulaPaciente.Remover(auxced);
			if(auxced == cedula){
				encontrado = true;
			}
			colaAux.Insertar(auxced);
		}
		while(!colaAux.Vacia()){
			colaAux.Remover(auxced);
			cedulaPaciente.Insertar(auxced);
		}
		return encontrado;
	}
