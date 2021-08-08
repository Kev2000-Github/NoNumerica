#include "../IMunicipio.h"

IMunicipio::IMunicipio() {

};

void IMunicipio::reportarCentinelas(MMunicipio &municipio) {
    Lista<MCentinela> auxCentinela;
    MCentinela centinelaActual;
    VGeneral vg;

    for(int i = 0; i < municipio.totalCentinelas(); i++) {
        municipio.removerPrimerCentinela(centinelaActual);
        vg.ImprimirString3("Centinela Nro",i,centinelaActual.getCodigo());
        auxCentinela.InsComienzo(centinelaActual);
    }
    while(!auxCentinela.Vacia()) {
        auxCentinela.EliComienzo(centinelaActual);
        municipio.agregarCentinela(centinelaActual);
    }
};

void IMunicipio::ImprimirListaMunicipio(MEstado &estado){
		Lista<MMunicipio> auxmunicipio;
		MMunicipio municipioactual;
	    VGeneral vg;
	    int i=1;
	    vg.ImprimirMensaje("\n Lista de Municipios:\n");
	    while(!estado.esVacio()) {
	    	estado.removerPrimerMunicipio(municipioactual);
	        vg.ImprimirString3("Municipio Nro",i++,": "+municipioactual.getCodigo());
	        auxmunicipio.InsComienzo(municipioactual);
	    }
	    while(!auxmunicipio.Vacia()) {
	    	auxmunicipio.EliComienzo(municipioactual);
	    	estado.agregarMunicipio(municipioactual);
	    }
}

void IMunicipio::ConsultaMunicipio(MEstado &estado){
	Lista<MMunicipio> auxmunicipio;
			MMunicipio municipioactual;
		    VGeneral vg;
		    vg.ImprimirMensaje("\n Reportar Informacion de los Municipios\n");
		    vg.ImprimirMensaje("\n --------------------------------------------\n");
		    while(!estado.esVacio()) {
		    	    	estado.removerPrimerMunicipio(municipioactual);
		    	    	vg.ImprimirString2("Municipio Codigo: ",municipioactual.getCodigo());
		    	    	vg.ImprimirString2("Nombre: ",municipioactual.getNombre());
		    	         vg.ImprimirNro("Cantidad de personas: ",municipioactual.PersonasMunicipio(municipioactual));
		    	         vg.ImprimirMensaje("\n -----\n");
		    	        auxmunicipio.InsComienzo(municipioactual);
		    	    }
		    	    while(!auxmunicipio.Vacia()) {
		    	    	auxmunicipio.EliComienzo(municipioactual);
		    	    	estado.agregarMunicipio(municipioactual);
		    	    }
}

void IMunicipio::obtenerMunicipio(MEstado &estado, MMunicipio &municipio) {
	vGeneral.Limpiar();
	ImprimirListaMunicipio(estado);
	string codigoMunicipio = vGeneral.LeerString("\n Codigo del Municipio: ");

	while(!estado.removerMunicipio(codigoMunicipio, municipio)) {
		vGeneral.ImprimirMensaje("\n ERROR: El municipio solicitado no existe");
		vGeneral.Pausa();
		vGeneral.Limpiar();

		ImprimirListaMunicipio(estado);
		codigoMunicipio = vGeneral.LeerString("\n Codigo del municipio: ");
	}
}
