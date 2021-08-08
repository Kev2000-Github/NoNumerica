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

	bool agregarCubiculo(MCubiculo &cubiculo);
	bool removerCubiculo(string codigo, MCubiculo &cubiculo);
	bool removerPrimerCubiculo(MCubiculo &cubiculo);
	int totalCubiculos();

	int ConsultarCantidadPorMarca(string marca);
	bool aumentarVacunas(string marca,string lote, int cantidad);
	bool agregarVacuna(MAlmacenVacuna &vacunas);
	bool removerVacuna(string marca, MAlmacenVacuna &vacunas);

	bool agregarLoteaVacuna(string marca,string lote,MAlmacenVacuna &vacunas);
    bool agregarlote(string marca,MAlmacenVacuna &vacunas);
    bool removerVacunaLote(string marca,string lote,MAlmacenVacuna &vacunas);
	bool removerPrimeraVacuna(MAlmacenVacuna &vacunas);
	bool usarVacunas(string marca,int dosis);

	bool sinvacunas(string marca,string lote, MAlmacenVacuna & vacunas);
	int PersonasCentinela(MCentinela &centinela);
	bool esVacia();
	bool PVacia();
	bool buscarPaciente(string cedula);

};

#endif /* MCENTINELA_H_ */
