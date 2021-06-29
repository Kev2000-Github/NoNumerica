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
	Pila<MAlmacenVacuna> vacuna;
	Lista<MCubiculo> cubiculos;
public:
	MCentinela(string _codigo);
	MCentinela();

	string getCodigo();
	void setCodigo(string _codigo);

	bool agregarCubiculo(MCubiculo cubiculo);
	bool removerCubiculo(string codigo, MCubiculo &cubiculo);
	bool removerPrimerCubiculo(MCubiculo &cubiculo);
	int totalCubiculos();

	int ConsultarCantidadPorMarca(string marca);
	bool aumentarVacunas(string marca, int cantidad);
	bool agregarVacuna(MAlmacenVacuna vacunas);
	bool removerVacuna(string marca, MAlmacenVacuna &vacunas);
	bool usarVacunas(string marca);
	bool esVacia();
};

#endif /* MCENTINELA_H_ */
