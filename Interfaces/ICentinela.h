#ifndef ICENTINELA_H
#define ICENTINELA_H
#include "../General/Lista.h"
#include "../General/VGeneral.h"
#include "../Modelos/MCentinela.h"
#include "../Modelos/MMunicipio.h"

class ICentinela {
public:
    ICentinela();
    void reporteCubiculos(MCentinela &centinela);
    void ImprimirListaCentinela(MMunicipio &municipio);
};

#endif
