#ifndef IESTADO_H_
#define IESTADO_H_
#include "../Modelos/MEstado.h"

class IEstado
{
private:
public:
    IEstado();
    void reportarMunicipios(MEstado &estado);
};

#endif
