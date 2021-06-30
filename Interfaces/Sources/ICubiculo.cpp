/*
 * ICubiculo.cpp
 *
 *  Created on: 29/06/2021
 *      Author: Usuario
 */

#include "../ICubiculo.h"

ICubiculo::ICubiculo() {}

void ICubiculo::reportarCedula(MCubiculo cubiculo){
	VGeneral vista;
	string ced,punto="fin";
	bool final=false;

	if(cubiculo.esVacia())
		cout<< "No Hay Personas en la Cola"<< endl<< endl;
	else{
		cubiculo.agregarPaciente(punto);
		vista.ImprimirString("Cubiculo de Codigo:",cubiculo.getCodigo());
		vista.ImprimirEncabezado("Listado de Personas en Espera","=========================================");
		while(!(final)){
			cubiculo.removerPrimerPaciente(ced);
			if(ced==punto)
				final=true;
			else{
				vista.ImprimirString("Cedula del Paciente:", ced );
				cubiculo.agregarPaciente(ced);
			};
		};
	};
}
