/*
 * IInfoVacunas.h
 *
 *  Created on: 27/07/2021
 *      Author: Dazzlin
 */

#ifndef IINFOVACUNAS_H_
#define IINFOVACUNAS_H_

#include "../General/Lista.h"
#include "../General/VGeneral.h"
#include "../Modelos/MInfoVacunas.h"
#include "../Modelos/MEstado.h"

class IInfoVacunas {
public:
	IInfoVacunas();

	void ImprimirListaDosis(MEstado &estado);
};

#endif /* IINFOVACUNAS_H_ */
