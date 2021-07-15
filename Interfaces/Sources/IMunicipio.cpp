#include "../IMunicipio.h"

IMunicipio::IMunicipio() {

};

void IMunicipio::reportarCentinelas(MMunicipio municipio) {
    Lista<MCentinela> auxCentinela;
    MCentinela centinelaActual;

    for(int i = 0; i < municipio.totalCentinelas(); i++) {
        municipio.removerPrimerCentinela(centinelaActual);
        cout<<centinelaActual.getCodigo()<<endl;
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
	        vg.ImprimirString2("Municipio:",municipioactual.getNombre(),municipioactual.getCodigo());
	        auxmunicipio.InsComienzo(municipioactual);
	    }
	    while(!auxmunicipio.Vacia()) {
	    	auxmunicipio.EliComienzo(municipioactual);
	    	estado.agregarMunicipio(municipioactual);
	    }
};
