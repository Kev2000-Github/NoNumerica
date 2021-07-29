/*
 * MExpedienteVacunacion.h
 *
 *  Created on: 28 jun. 2021
 *      Author: Usuario
 */

#ifndef MEXPEDIENTEVACUNACION_H_
#define MEXPEDIENTEVACUNACION_H_
#include <iostream>
#include <string>
#include "../General/Pila.h"
#include "../General/Date.h"

class MExpedienteVacunacion
{
private:
	string cedula, vacunaTomada, codCentinela, lote;
	Pila<Date> DosisTomadas;

public:
	MExpedienteVacunacion();
	MExpedienteVacunacion(string _cedula, string cod);

	void setCedula(string c);
	string getCedula();
	void setLote(string c);
	string getLote();
	void setVacunaTomada(string vt);
	string getVacunaTomada();

	void setCodCentinela(string cod);
	string getCodCentinela();

	bool AgregarNuevaDosis(Date DosisTomada);
    bool removerTopeDosis(Date &fecha);
	Date getSigFechaEstipulada();
	int contarTotalDosis();

};

#endif /* MEXPEDIENTEVACUNACION_H_ */
