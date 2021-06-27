/*
 * MCentinela.h
 *
 *  Created on: 25 jun. 2021
 *      Author: Kloux
 */

#ifndef MCENTINELA_H_
#define MCENTINELA_H_
#include "../General/Pila.h"
#include "../General/Lista.h"
#include "MAlmacenVacuna.h"
#include "MCubiculo.h"

class MCentinela {
typedef nodo<MCubiculo> Apuntador;
private:
	string codigo;
	Pila<MAlmacenVacuna> vacunas;
	Lista<MCubiculo> cubiculos;
public:
	MCentinela(string _codigo);
	MCentinela();
	string getCodigo();
	void setCodigo(string _codigo);
	bool actualizarVacuna(string marca, int n);
	bool agregarCubiculo(MCubiculo cubiculo);
	bool removerCubiculo(string codigo, MCubiculo &cubiculo);
	bool removerPrimerCubiculo(MCubiculo &cubiculo);
	bool agregarVacuna(MAlmacenVacuna vacunas);
	bool removerVacuna(string marca, MAlmacenVacuna &vacunas);
	int totalCubiculos();
	bool esVacia();
};

#endif /* MCENTINELA_H_ */
