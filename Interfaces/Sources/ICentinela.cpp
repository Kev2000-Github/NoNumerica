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

