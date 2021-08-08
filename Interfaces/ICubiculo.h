/*
 * ICubiculo.h
 *
 *  Created on: 29/06/2021
 *      Author: Usuario
 */

#ifndef ICUBICULO_H_
#define ICUBICULO_H_
#include "../Modelos/MCubiculo.h"
#include "../Modelos/MCentinela.h"
#include "../General/VGeneral.h"
#include "../Modelos/MCensoPersonas.h"
#include "../Modelos/MListaExpediente.h"

class ICubiculo {
private:
	VGeneral vGeneral;
public:
	ICubiculo();
	void reportarCedula(MCubiculo colacubiculo);
	void ImprimirListaCubiculo(MCentinela &centinela);
	void ReportarCubiculo(MCentinela &centinela);
	void obtenerCubiculo(MCentinela &centinela, MCubiculo &cubiculo);
	void reportarPersonasDelaCola(MCensoPersonas &listaPersonas,MCubiculo &cubiculo);
	void reportarPersonas0Dosis(MListaExpediente &listaExpedientes,MCensoPersonas &listaPersonas,MCubiculo &cubiculo);
	void reportarPersonas1Dosis(MListaExpediente &listaExpedientes,MCensoPersonas &listaPersonas,MCubiculo &cubiculo);
	void reportarPersonas2Dosis(MListaExpediente &listaExpedientes,MCensoPersonas &listaPersonas,MCubiculo &cubiculo);
};

#endif /* ICUBICULO_H_ */
