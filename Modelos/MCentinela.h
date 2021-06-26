/*
 * MCentinela.h
 *
 *  Created on: 25 jun. 2021
 *      Author: Kloux
 */

#ifndef MCENTINELA_H_
#define MCENTINELA_H_
#include "../General/Pila.h"
#include "../General/Cola.h"
#include "MAlmacenVacuna.h"
#include "MCubiculo.h"

class MCentinela {

private:
	string codigo;
	Pila<MAlmacenVacuna> vacunas;
	Cola<MCubiculo> Cubiculo;
public:
	MCentinela();
	bool actualizarVacuna(string marca, int n);
	bool agregarCubiculo(MCubiculo cubiculo);
	bool removerCubiculo(string codigo);
	bool agregarVacuna(MAlmacenVacuna vacunas);
	bool removerVacuna(string marca);
	int totalCubiculos();
};

#endif /* MCENTINELA_H_ */
