/*
 * MExpedienteVacunacion.cpp
 *
 *  Created on: 28 jun. 2021
 *      Author: Usuario
 */

#include "MExpedienteVacunacion.h"

MExpedienteVacunacion::MExpedienteVacunacion() {
	// TODO Auto-generated constructor stub
cedula=vacunaTomada="";
}

void MExpedienteVacunacion::setcedula(string c){
	cedula=c;
}

string MExpedienteVacunacion::getcedula(){
	return cedula;
}

void MExpedienteVacunacion::setVacunaTomada(string vt){
	vacunaTomada=vt;
}

string MExpedienteVacunacion::getVacunaTomada(){
	return vacunaTomada;
}

int MExpedienteVacunacion::contDosisTomadas(){

}

bool MExpedienteVacunacion::AgregarNuevaDosis(Date DosisTomada){

}

