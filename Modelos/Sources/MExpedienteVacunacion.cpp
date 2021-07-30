/*
 * MExpedienteVacunacion.cpp
 *
 *  Created on: 28 jun. 2021
 *      Author: Usuario
 */

#include "../MExpedienteVacunacion.h"

MExpedienteVacunacion::MExpedienteVacunacion()
{
}
MExpedienteVacunacion::MExpedienteVacunacion(string _cedula, string cod)
{
	cedula = _cedula;
	codCentinela = cod;
}

void MExpedienteVacunacion::setCedula(string c)
{
	cedula = c;
}

string MExpedienteVacunacion::getCedula()
{
	return cedula;
}

void MExpedienteVacunacion::setLote(string c)
{
	lote = c;
}

string MExpedienteVacunacion::getLote()
{
	return lote;
}

void MExpedienteVacunacion::setVacunaTomada(string vt)
{
	vacunaTomada = vt;
}

string MExpedienteVacunacion::getVacunaTomada()
{
	return vacunaTomada;
}

void MExpedienteVacunacion::setCodCentinela(string cod)
{
	codCentinela = cod;
}

string MExpedienteVacunacion::getCodCentinela()
{
	return codCentinela;
}

bool MExpedienteVacunacion::AgregarNuevaDosis(Date DosisTomada)
{
	return DosisTomadas.Insertar(DosisTomada);
}

Date MExpedienteVacunacion::getSigFechaEstipulada()
{
	Date d, newD;
	DosisTomadas.Remover(d);
	newD = d.avanzarFecha(90);
	DosisTomadas.Insertar(d);
	return newD;
}

bool MExpedienteVacunacion::removerTopeDosis(Date &fecha){
	return DosisTomadas.Remover(fecha);
}

int MExpedienteVacunacion::contarTotalDosis(){
	return DosisTomadas.Contar();
}
