/*
 * ICubiculo.h
 *
 *  Created on: 29/06/2021
 *      Author: Usuario
 */

#ifndef ICUBICULO_H_
#define ICUBICULO_H_
#include "../General/Cola.h"

class ICubiculo {
public:
	ICubiculo();
	void reportarCedula(Cola<string> cedula);
};

#endif /* ICUBICULO_H_ */
