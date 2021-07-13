/*
 * MExpedienteVacunacion.cpp
 *
 *  Created on: 28 jun. 2021
 *      Author: Usuario
 */

#include "../MExpedienteVacunacion.h"

MExpedienteVacunacion::MExpedienteVacunacion() {
}
MExpedienteVacunacion::MExpedienteVacunacion(string _cedula, string cod){
	cedula = _cedula;
	codCentinela = cod;
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

void MExpedienteVacunacion::setCodCentinela(string cod){
	codCentinela=cod;
}

string MExpedienteVacunacion::getCodCentinela(){
	return codCentinela;
}

int MExpedienteVacunacion::contDosisTomadas(){

}

bool MExpedienteVacunacion::AgregarNuevaDosis(Date Dosis) {
}

Date MExpedienteVacunacion::getSigFechaEstipulada(){

}


