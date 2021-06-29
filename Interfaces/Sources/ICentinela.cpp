#include "../ICentinela.h"

ICentinela::ICentinela() {

};

void ICentinela::reporteCubiculos(MCentinela centinela) {
    Lista<MCubiculo> auxCubiculos;
    MCubiculo cubiculoActual;

    for(int i = 0; i < centinela.totalCubiculos(); i++) {
        centinela.removerPrimerCubiculo(cubiculoActual);
        cout<<cubiculoActual.getCodigo()<<endl;
        auxCubiculos.InsComienzo(cubiculoActual);
    }
    while(!auxCubiculos.Vacia()) {
        auxCubiculos.EliComienzo(cubiculoActual);
        centinela.agregarCubiculo(cubiculoActual);
    }
};
