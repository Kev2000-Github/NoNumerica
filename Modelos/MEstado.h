/*
 * MEstado.h
 *
 *  Created on: 25/06/2021
 *      Author: Usuario
 */

#ifndef MESTADO_H_
#define MESTADO_H_
#include "../General/Lista.h"
#include "MMunicipio.h"

class MEstado {
private:
	string nombre;
	Lista<MMunicipio> municipio;
public:
	MEstado();
	int totalMunicipio();
	bool agregarMunicipio(MMunicipio municipio);
	bool removerMunicipio (string codigo);
	bool buscarMunicipio (string codigo);
};

#endif /* MESTADO_H_ */
