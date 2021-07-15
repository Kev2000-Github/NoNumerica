#ifndef IMUNICIPIO_H_
#define IMUNICIPIO_H_
#include "../Modelos/MMunicipio.h"

class IMunicipio
{
private:
public:
    IMunicipio();
    void reportarCentinelas(MMunicipio municipio);
    void ImprimirListaMunicipio(MEstado estado);
};

#endif
