#include "../IMunicipio.h"

IMunicipio::IMunicipio() {

};

void IMunicipio::reporteCentinelas(MMunicipio municipio) {
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
