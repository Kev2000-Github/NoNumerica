/*
 * MExpedienteVacunacion.cpp
 *
 *  Created on: 28 jun. 2021
 *      Author: Usuario
 */

#include "../MExpedienteVacunacion.h"

MExpedienteVacunacion::MExpedienteVacunacion() {
}
MExpedienteVacunacion::MExpedienteVacunacion(string _cedula){
	cedula = _cedula;
}

void MExpedienteVacunacion::setCedula(string c){
	cedula=c;
}

string MExpedienteVacunacion::getCedula(){
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

Date MExpedienteVacunacion::getSigFechaEstipulada(){

}


