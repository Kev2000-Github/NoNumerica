/*
 * MCubiculo.h
 *
 *  Created on: 25/06/2021
 *      Author: Usuario
 */

#ifndef MCUBICULO_H_
#define MCUBICULO_H_
#include "../General/Cola.h"

class MCubiculo {
private:
	string codigo;
	Cola<string> cedulaPaciente;
public:
	MCubiculo(string codigo);
	MCubiculo();

	string getCodigo();
	void setCodigo(string _codigo);

	bool agregarPaciente(string cedula);
	bool removerPrimerPaciente(string &cedula);
	bool removerPaciente(string &cedula);
	bool esVacia();
	int total();
	bool buscarPaciente(string &cedula);
};

#endif /* MCUBICULO_H_ */

