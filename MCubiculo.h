/*
 * MCubiculo.h
 *
 *  Created on: 25/06/2021
 *      Author: Usuario
 */

#ifndef MCUBICULO_H_
#define MCUBICULO_H_
#include "Cola.h"

class MCubiculo {
private:
	string codigo;
	Cola<string> cedulaPaciente;
public:
	MCubiculo();
	bool removerPaciente(string cedula);
	bool agregarpaciente(string cedula);
};

#endif /* MCUBICULO_H_ */
