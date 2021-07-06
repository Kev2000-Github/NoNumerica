#include "../IMunicipio.h"

IMunicipio::IMunicipio() {

};

void IMunicipio::reportarCentinelas(MMunicipio municipio) {
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

void IMunicipio::ImprimirListaMunicipio(MEstado estado){
		Lista<MMunicipio> auxmunicipio;
		MMunicipio municipioactual;
	    VGeneral vg;

	    while(estado.totalMunicipio()!=0) {
	    	estado.removerPrimerMunicipio(municipioactual);
	        vg.ImprimirString2("Municipio:",municipioactual.getnombre(),municipioactual.getCodigo());
	        auxmunicipio.InsComienzo(municipioactual);
	    }
	    while(!auxmunicipio.Vacia()) {
	    	auxmunicipio.EliComienzo(municipioactual);
	    	estado.agregarMunicipio(municipioactual);
	    }
}
