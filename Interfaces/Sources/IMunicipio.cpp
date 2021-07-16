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
