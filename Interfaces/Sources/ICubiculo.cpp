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

void ICubiculo::reportarPersonasDelaCola(MCensoPersonas &listaPersonas,MCubiculo &cubiculo){
  	Lista<MPersona> auxpersonas;
	Cola<string> cedulaPaciente;

    string cedulaActual;
    MPersona personaActual;

  	VGeneral vg;
  		vg.ImprimirMensaje("\n Lista de Pacietes en Cola:\n");
  		vg.ImprimirLineasBlanco(1);
  		while(!cubiculo.esVacia() and !listaPersonas.esVacia()) {
  			    	cubiculo.removerPrimerPaciente(cedulaActual);
  			    	listaPersonas.removerPersona(cedulaActual,personaActual);
                    if(personaActual.getcedula()==cedulaActual){
                    	cout<<"Paciete:"<<personaActual.getnombre()<<" "<<personaActual.getapellido()<<" "<<personaActual.getcedula();
                    	vg.ImprimirLineasBlanco(1);
                    }

  			        cedulaPaciente.Insertar(cedulaActual);
  			        auxpersonas.InsComienzo(personaActual);
  			    }
  			    while(!cedulaPaciente.Vacia() and !auxpersonas.Vacia()) {
  			    	cedulaPaciente.Remover(cedulaActual);
  			        cubiculo.agregarPaciente(cedulaActual);
  			        auxpersonas.EliComienzo(personaActual);
  			        listaPersonas.agregarPersona(personaActual);
                   }



}



void ICubiculo::reportarPersonas1Dosis(MListaExpediente &listaExpedientes,MCensoPersonas &listaPersonas,MCubiculo &cubiculo){

  	Lista<MPersona> auxPersonas;
	Cola<string> cedulaPaciente;
	Lista<MExpedienteVacunacion> auxExpedientes;

    string cedulaActual;
    MPersona personaActual;
    MExpedienteVacunacion expActual;

  	VGeneral vg;

  		vg.ImprimirMensaje("\n Lista de Pacietes en Cola con 1 Dosis:\n");
  		vg.ImprimirLineasBlanco(1);
  		while(!cubiculo.esVacia() and !listaPersonas.esVacia() and !listaExpedientes.estaVacia()) {
  			    	cubiculo.removerPrimerPaciente(cedulaActual);
  			    	listaPersonas.removerPersona(cedulaActual,personaActual);
  			    	listaExpedientes.removerExpediente(cedulaActual,expActual);
                    if( expActual.getCedula()==cedulaActual and expActual.contarTotalDosis()==1){
                    	cout<<"Paciete:"<<personaActual.getnombre()<<" "<<personaActual.getapellido()<<"- "<<cedulaActual;
                    	vg.ImprimirLineasBlanco(1);
                    }

  			        cedulaPaciente.Insertar(cedulaActual);
  			        auxPersonas.InsComienzo(personaActual);
  			        auxExpedientes.InsComienzo(expActual);

  			    }
  			    while(!cedulaPaciente.Vacia() and !auxPersonas.Vacia()) {
  			    	cedulaPaciente.Remover(cedulaActual);
  			        cubiculo.agregarPaciente(cedulaActual);
  			        auxPersonas.EliComienzo(personaActual);
  			        listaPersonas.agregarPersona(personaActual);
  			        auxExpedientes.EliComienzo(expActual);
  			        listaExpedientes.agregarExpediente(expActual);

                   }





}

void ICubiculo::reportarPersonas2Dosis(MListaExpediente &listaExpedientes,MCensoPersonas &listaPersonas,MCubiculo &cubiculo){

  	Lista<MPersona> auxPersonas;
	Cola<string> cedulaPaciente;
	Lista<MExpedienteVacunacion> auxExpedientes;

    string cedulaActual;
    MPersona personaActual;
    MExpedienteVacunacion expActual;

  	VGeneral vg;

  		vg.ImprimirMensaje("\n Lista de Pacietes en Cola con 2 Dosis:\n");
  		vg.ImprimirLineasBlanco(1);
  		while(!cubiculo.esVacia() and !listaPersonas.esVacia() and !listaExpedientes.estaVacia()) {
  			    	cubiculo.removerPrimerPaciente(cedulaActual);
  			    	listaPersonas.removerPersona(cedulaActual,personaActual);
  			    	listaExpedientes.removerExpediente(cedulaActual,expActual);
                    if( expActual.getCedula()==cedulaActual and expActual.contarTotalDosis()==2){
                    	cout<<"Paciete:"<<personaActual.getnombre()<<" "<<personaActual.getapellido()<<"- "<<cedulaActual;
                    	vg.ImprimirLineasBlanco(1);
                    }

  			        cedulaPaciente.Insertar(cedulaActual);
  			        auxPersonas.InsComienzo(personaActual);
  			        auxExpedientes.InsComienzo(expActual);

  			    }
  			    while(!cedulaPaciente.Vacia() and !auxPersonas.Vacia()) {
  			    	cedulaPaciente.Remover(cedulaActual);
  			        cubiculo.agregarPaciente(cedulaActual);
  			        auxPersonas.EliComienzo(personaActual);
  			        listaPersonas.agregarPersona(personaActual);
  			        auxExpedientes.EliComienzo(expActual);
  			        listaExpedientes.agregarExpediente(expActual);

                   }
}

void ICubiculo::reportarPersonas0Dosis(MListaExpediente &listaExpedientes,MCensoPersonas &listaPersonas,MCubiculo &cubiculo){

  	Lista<MPersona> auxPersonas;
	Cola<string> cedulaPaciente;
	Lista<MExpedienteVacunacion> auxExpedientes;

    string cedulaActual;
    MPersona personaActual;
    MExpedienteVacunacion expActual;

  	VGeneral vg;

  		vg.ImprimirMensaje("\n Lista de Pacietes en Cola con 0 Dosis:\n");
  		vg.ImprimirLineasBlanco(1);
  		while(!cubiculo.esVacia() and !listaPersonas.esVacia() and !listaExpedientes.estaVacia()) {
  			    	cubiculo.removerPrimerPaciente(cedulaActual);
  			    	listaPersonas.removerPersona(cedulaActual,personaActual);
  			    	listaExpedientes.removerExpediente(cedulaActual,expActual);
                    if( expActual.getCedula()==cedulaActual and expActual.contarTotalDosis()==0){
                    	cout<<"Paciete:"<<personaActual.getnombre()<<" "<<personaActual.getapellido()<<"- "<<cedulaActual;
                    	vg.ImprimirLineasBlanco(1);
                    }
  			        cedulaPaciente.Insertar(cedulaActual);
  			        auxPersonas.InsComienzo(personaActual);
  			        auxExpedientes.InsComienzo(expActual);

  			    }
  			    while(!cedulaPaciente.Vacia() and !auxPersonas.Vacia() ) {
  			    	cedulaPaciente.Remover(cedulaActual);
  			        cubiculo.agregarPaciente(cedulaActual);
  			        auxPersonas.EliComienzo(personaActual);
  			        listaPersonas.agregarPersona(personaActual);
  			        auxExpedientes.EliComienzo(expActual);
  			        listaExpedientes.agregarExpediente(expActual);


                   }



}

void ICubiculo::obtenerCubiculo(MCentinela &centinela, MCubiculo &cubiculo) {
	vGeneral.Limpiar();
	ImprimirListaCubiculo(centinela);
	string codigoMunicipio = vGeneral.LeerString("\n Codigo del cubiculo: ");

	while(!centinela.removerCubiculo(codigoMunicipio, cubiculo)) {
		vGeneral.ImprimirMensaje("\n ERROR: El cubiculo solicitado no existe");
		vGeneral.Pausa();
		vGeneral.Limpiar();

		ImprimirListaCubiculo(centinela);
		codigoMunicipio = vGeneral.LeerString("\n Codigo del cubiculo: ");
	}
}
