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

class ICubiculo {
public:
	ICubiculo();
	void reportarCedula(MCubiculo colacubiculo);
	void ImprimirListaCubiculo(MCentinela &centinela);
	void ReportarCubiculo(MCentinela &centinela);
};

#endif /* ICUBICULO_H_ */
