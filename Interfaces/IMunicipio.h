#ifndef IMUNICIPIO_H_
#define IMUNICIPIO_H_
#include "../Modelos/MMunicipio.h"
#include "../Modelos/MEstado.h"
#include "../General/VGeneral.h"

class IMunicipio
{
private:
public:
    IMunicipio();
    void reportarCentinelas(MMunicipio &municipio);
    void ImprimirListaMunicipio(MEstado &estado);
    void ConsultaMunicipio(MEstado &estado);
};

#endif
