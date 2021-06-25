/*
 * MCentinela.h
 *
 *  Created on: 25 jun. 2021
 *      Author: Kloux
 */

#ifndef MCENTINELA_H_
#define MCENTINELA_H_
#include "Pila.h"
#include "Cola.h"
#include "AlmacenVacunas.h"

class MCentinela {

private:
	string codigo;
	Pila<AlmacenVacunas> vacunas;
	Cola<MCubiculo> Cubiculo;
public:
	MCentinela();
	bool actualizarVacuna(string marca, int n);
	bool agregarCubiculo();
	bool removerCubiculo();
	bool agregarVacuna();
	bool removerVacuna();
	int totalCubiculos();
};

#endif /* MCENTINELA_H_ */
