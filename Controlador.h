/*
 * Controlador.h
 *
 *  Created on: 29/06/2021
 *      Author: Admin
 */

#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_
#include <climits>
#include "Modelos/MListaExpediente.h"
#include "Modelos/MCensoPersonas.h"
#include "Modelos/MInfoVacunas.h"
#include "Modelos/MEstado.h"
#include "General/VGeneral.h"
#include "Interfaces/IEstado.h"
#include "Interfaces/IMunicipio.h"
#include "Interfaces/ICubiculo.h"
#include "Interfaces/ICentinela.h"
#include "Interfaces/IAlmacen.h"
#include "Interfaces/IInfoVacunas.h"

class Controlador {
private:
	MEstado estado;
	MListaExpediente listaExpedientes;
	MCensoPersonas listaPersonas;
	VGeneral vGeneral;
	bool estanDatosCargados;
public:
	Controlador();
	void cargarDatos();
	void guardarDatos();

	void menuAgregar();
	void agregarMunicipio();
	void agregarCentinela();
	void AgregarInfoVacunas();
	void agregarCubiculo();
	void ModificarPersona();
	void recibirVacunas();

	void procesar();
	void procesar2();
	void procesarAdmin();




	void menuModificar();

	void menuEliminar();
	void eliminarCubiculo();
	void EliminarCentinela();
	void eliminarVacunas();



	void ModificarVacunas();

	void consultarPersona();
	void consultarMunicipios();
	void consultarCentinelas();
	void consultarCubiculos();
	void consultarColas();
	void consultarVacunas();

	void incluirPacienteACola();
	void SacarPacienteDeCola();

	void procesarPaciente();
	void modificarMunicipio();
	void eliminarMunicipio();
    void modificarExpediente();

};


#endif /* CONTROLADOR_H_ */
