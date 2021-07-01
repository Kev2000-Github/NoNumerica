/*
 * Controlador.h
 *
 *  Created on: 29/06/2021
 *      Author: Admin
 */

#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_
#include "Modelos/MListaExpediente.h"
#include "Modelos/MCensoPersonas.h"

class Controlador {
private:
	MListaExpediente listaExpedientes;
	MCensoPersonas listaPersonas;
	bool estanDatosCargados;
public:
	Controlador();
	void cargarDatos();
	void recibirVacunas();
	void agregarMunicipio();
	void agregarCentinela();

	void procesar();
	void procesar2();

	void consultarPersona();
	void consultarMunicipios();
	void consultarCentinelas();
	void consultarCubiculos();
	void consultarColas();
	void consultarVacunas();
	void incluirPacienteACola();
	void SacarPacienteDeCola();
	void procesarPaciente();

};


#endif /* CONTROLADOR_H_ */
