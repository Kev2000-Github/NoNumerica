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

    int i=1;
    vg.ImprimirMensaje("\n Lista de Cubiculos:\n");
    while(!centinela.esVacia()) {
        centinela.removerPrimerCubiculo(cubiculoActual);
        vg.ImprimirString3("Cubiculo Nro",i++,": "+cubiculoActual.getCodigo());
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
    vg.Limpiar();
    int i=1;
    vg.ImprimirMensaje("Reoporte de Cubiculos Existentes: \n");
    while(!centinela.esVacia()){
        centinela.removerPrimerCubiculo(cubiculoActual);
        vg.ImprimirString4("Cubiculo Nro ",i++,": Cod: "+cubiculoActual.getCodigo()+ " Total:",cubiculoActual.total());
        auxCubiculos.InsComienzo(cubiculoActual);
    }
    while(!auxCubiculos.Vacia()) {
        auxCubiculos.EliComienzo(cubiculoActual);
        centinela.agregarCubiculo(cubiculoActual);
    }
    vg.Pausa();
    vg.Limpiar();
}

void ICubiculo::reportarCedulasDelaCola(MCubiculo &cubiculo){
  	Cola<string> cedulaPaciente;
  	string cedulaActual;
  	VGeneral vg;
  		vg.ImprimirMensaje("\n Lista de Pacietes en Cola:\n");
  		vg.ImprimirLineasBlanco(1);
  		while(!cubiculo.esVacia()) {
  			    	cubiculo.removerPrimerPaciente(cedulaActual);
  			    	vg.ImprimirString("Cedula: ",cedulaActual);
  			    	vg.ImprimirLineasBlanco(1);
  			        cedulaPaciente.Insertar(cedulaActual);
  			    }
  			    while(!cedulaPaciente.Vacia()) {
  			    	cedulaPaciente.Remover(cedulaActual);
  			        cubiculo.agregarPaciente(cedulaActual);

    }
}
