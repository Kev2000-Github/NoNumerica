
#ifndef IALMACEN_H_
#define IALMACEN_H_
#include <climits>
#include "../Modelos/MAlmacenVacuna.h"
#include "../Modelos/MCentinela.h"
#include "../General/VGeneral.h"


class IAlmacen {
public:
	IAlmacen();
	void ImprimirVacunas(MCentinela &centinela);
	void ImprimirLotes(string marca,MCentinela &centinela);
	void ImprimirCantidadVacunas(MCentinela &centinela);
};

#endif /* IALMACEN_H_ */
