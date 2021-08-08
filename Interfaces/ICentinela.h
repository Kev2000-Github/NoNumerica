#ifndef ICENTINELA_H
#define ICENTINELA_H
#include "../General/Lista.h"
#include "../General/VGeneral.h"
#include "../Modelos/MCentinela.h"
#include "../Modelos/MMunicipio.h"

class ICentinela {
private:
	VGeneral vGeneral;
public:
    ICentinela();
    void reporteCubiculos(MCentinela &centinela);
    void ImprimirListaCentinela(MMunicipio &municipio);
    void ImprimirListaCentinelaLote(MMunicipio &municipio);
    void ConsultarCentinela(MMunicipio &municipio);
    void obtenerCentinela(MMunicipio &municipio, MCentinela &centinela);

};

#endif
