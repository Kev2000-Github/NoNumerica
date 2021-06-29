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

class MExpedienteVacunacion {
private:
	string cedula, vacunaTomada;
	Pila<Date> DosisTomada;
public:
	MExpedienteVacunacion();
	void setcedula(string c);
	string getcedula();
	void setVacunaTomada(string vt);
	string getVacunaTomada();

	int contDosisTomadas();
	bool AgregarNuevaDosis(Date DosisTomada);


};

#endif /* MEXPEDIENTEVACUNACION_H_ */
