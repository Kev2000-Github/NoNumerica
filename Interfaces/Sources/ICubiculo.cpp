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
		vista.ImprimirString("Cubiculo de Codigo: ",cubiculo.getCodigo());
		vista.ImprimirEncabezado("Listado de Personas en Espera ","=========================================");
		while(!(final)){
			cubiculo.removerPrimerPaciente(ced);
			if(ced==punto)
				final=true;
			else{
				vista.ImprimirString("Cedula del Paciente: ", ced );
				cubiculo.agregarPaciente(ced);
			};
		};
	};
}
void ICubiculo::ImprimirListaCubiculo(MCentinela &centinela){
    Lista<MCubiculo> auxCubiculos;
    MCubiculo cubiculoActual;
    VGeneral vg;

    for(int i = 0; i < centinela.totalCubiculos(); i++) {
        centinela.removerPrimerCubiculo(cubiculoActual);
        vg.ImprimirString3("Codigo del Cubiculo Nro ",i,cubiculoActual.getCodigo());
        auxCubiculos.InsComienzo(cubiculoActual);
    }
    while(!auxCubiculos.Vacia()) {
        auxCubiculos.EliComienzo(cubiculoActual);
        centinela.agregarCubiculo(cubiculoActual);
    }
}
void ICubiculo::ReportarCubiculo(MCentinela &centinela){
    Lista<MCubiculo>auxCubiculos;
    MCubiculo cubiculoActual;
    VGeneral vg;
    int i=1;
    while(!centinela.esVacia()){

        centinela.removerPrimerCubiculo(cubiculoActual);
        vg.ImprimirString4("Cubiculo Nro ",i++,": Cod: "+cubiculoActual.getCodigo()+ " Total: ",cubiculoActual.total());
        auxCubiculos.InsComienzo(cubiculoActual);
    }
    while(!auxCubiculos.Vacia()) {
        auxCubiculos.EliComienzo(cubiculoActual);
        centinela.agregarCubiculo(cubiculoActual);
    }
}

