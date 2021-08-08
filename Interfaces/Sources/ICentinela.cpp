#include "../ICentinela.h"

ICentinela::ICentinela() {

};

void ICentinela::reporteCubiculos(MCentinela &centinela) {
    Lista<MCubiculo> auxCubiculos;
    MCubiculo cubiculoActual;
    VGeneral vg;

    for(int i = 0; i < centinela.totalCubiculos(); i++) {
        centinela.removerPrimerCubiculo(cubiculoActual);
        vg.ImprimirString3("Codigo del Cubiculo ",i,cubiculoActual.getCodigo());
        auxCubiculos.InsComienzo(cubiculoActual);
    }
    while(!auxCubiculos.Vacia()) {
        auxCubiculos.EliComienzo(cubiculoActual);
        centinela.agregarCubiculo(cubiculoActual);
    }
};
void ICentinela::ImprimirListaCentinela(MMunicipio &municipio){
    Lista<MCentinela> auxCentinela;
    MCentinela centinelaActual;
    VGeneral vg;
    int i=1;
    vg.ImprimirMensaje("\n Lista de Centinelas:\n");
    while(!municipio.esVacio()) {
        municipio.removerPrimerCentinela(centinelaActual);

        vg.ImprimirString3("Centinela Nro",i++,": "+centinelaActual.getCodigo());
        auxCentinela.InsComienzo(centinelaActual);
    }
    while(!auxCentinela.Vacia()) {
        auxCentinela.EliComienzo(centinelaActual);
        municipio.agregarCentinela(centinelaActual);
    }

}

void ICentinela::ConsultarCentinela(MMunicipio &municipio){
          Lista<MCentinela> auxCentinela;
      MCentinela centinelaActual;
        VGeneral vg;
        int i=1;
        vg.ImprimirMensaje("\n Reportar Informacion de los Centinelas\n");
        vg.ImprimirMensaje("\n --------------------------------------------\n");
        while(!municipio.esVacio()) {
            municipio.removerPrimerCentinela(centinelaActual);

            vg.ImprimirString3("Centinela Nro",i++,": "+centinelaActual.getCodigo());

            vg.ImprimirNro("Cantidad de personas: ",centinelaActual.PersonasCentinela(centinelaActual));
            vg.ImprimirMensaje("\n -----\n");
            auxCentinela.InsComienzo(centinelaActual);
              }
              while(!auxCentinela.Vacia()) {
                auxCentinela.EliComienzo(centinelaActual);
                municipio.agregarCentinela(centinelaActual);
              }
}

void ICentinela::obtenerCentinela(MMunicipio &municipio, MCentinela &centinela) {
	vGeneral.Limpiar();
	ImprimirListaCentinela(municipio);
	string codigoMunicipio = vGeneral.LeerString("\n Codigo del centinela: ");

	while(!municipio.removerCentinela(codigoMunicipio, centinela)) {
		vGeneral.ImprimirMensaje("\n ERROR: El centinela solicitado no existe");
		vGeneral.Pausa();
		vGeneral.Limpiar();
		ImprimirListaCentinela(municipio);
		codigoMunicipio = vGeneral.LeerString("\n Codigo del centinela: ");
	}
}
