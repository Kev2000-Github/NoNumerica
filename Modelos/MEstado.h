/*
 * MEstado.h
 *
 *  Created on: 25/06/2021
 *      Author: Usuario
 */

#ifndef MESTADO_H_
#define MESTADO_H_
#include "../General/Lista.h"
#include "../General/VGeneral.h"
#include "MMunicipio.h"
#include "MInfoVacunas.h"


class MEstado
{
private:
	string nombre;
	Lista<MMunicipio> municipios;
	Lista<MInfoVacunas> infoVacunas;

public:
	MEstado();
	MEstado(string nombre);

	string getNombre();
	void setNombre(string n);

	int totalMunicipio();
	bool agregarMunicipio(MMunicipio &municipio);
	bool removerMunicipio(string codigo, MMunicipio &municipio);
	bool removerPrimerMunicipio(MMunicipio &municipio);
	bool esVacio();





	//INFOVACUNAS

		bool agregarInfoVacunas(MInfoVacunas & infoVacuna);
		bool removerInfoVacunas(string marca, MInfoVacunas &infoVacuna);
		bool removerPrimerInfo(MInfoVacunas & infoVacuna);

		bool infVacio();

	bool buscarPaciente(string cedula);

};

#endif /* MESTADO_H_ */
