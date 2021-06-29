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
	Lista<MMunicipio> municipios;
public:
	MEstado();
	MEstado(string nombre);

	string getNombre();
	void setNombre(string n);

	int totalMunicipio();
	bool agregarMunicipio(MMunicipio municipio);
	bool removerMunicipio (string codigo, MMunicipio &municipio);
};

#endif /* MESTADO_H_ */
