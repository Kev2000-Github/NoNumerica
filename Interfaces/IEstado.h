#ifndef IESTADO_H_
#define IESTADO_H_
#include "../Modelos/MEstado.h"
#include "../Modelos/MInfoVacunas.h"

class IEstado
{
private:
public:
    IEstado();
    void reportarMunicipios(MEstado &estado);
    void ImprimirListaDosis(MEstado &estado);
};

#endif
