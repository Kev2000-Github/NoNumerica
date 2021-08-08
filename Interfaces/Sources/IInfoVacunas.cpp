/*
 * IInfoVacunas.cpp
 *
 *  Created on: 27/07/2021
 *      Author: Dazzlin
 */

#include "../IInfoVacunas.h"

IInfoVacunas::IInfoVacunas() {
	// TODO Auto-generated constructor stub

}

void IInfoVacunas::ImprimirListaDosis(MEstado &estado)
{
	    Lista<MInfoVacunas> auxinfo;
	    MInfoVacunas infoActual;
	    VGeneral vg;
	    string marca;
	    vg.ImprimirMensaje("\n Informacion de vacunas:\n");

	    while(!estado.infVacio()) {
	    	estado.removerPrimerInfo(infoActual);

            vg.ImprimirString4_("Marca:  ",infoActual.getMarca()," Dosis:",infoActual.getNroDosis());
	        auxinfo.InsComienzo(infoActual);
	    }
	    while(!auxinfo.Vacia()) {
	    	auxinfo.EliComienzo(infoActual);
	    	estado.agregarInfoVacunas(infoActual);
	    }
}
