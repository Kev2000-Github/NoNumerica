

#include "../IAlmacen.h"

IAlmacen::IAlmacen() {}

void IAlmacen::ImprimirVacunas(MCentinela & centinela)
{
	Pila<MAlmacenVacuna> auxvacuna;
	MAlmacenVacuna vacunaActual;
	VGeneral vg;
	int i=1;
	vg.ImprimirMensaje("\n Lista de Vacunas:\n");
	    while(!centinela.PVacia()) {
	    	centinela.removerPrimeraVacuna(vacunaActual);
	        vg.ImprimirString3("Marca  Nro",i++,": "+vacunaActual.getMarca());
	        auxvacuna.Insertar(vacunaActual);
	    }
	    while(!auxvacuna.Vacia()) {
	        auxvacuna.Remover(vacunaActual);
	        centinela.agregarVacuna(vacunaActual);
	    }

}

void IAlmacen::ImprimirCantidadVacunas(MCentinela & centinela)
{
		Pila<MAlmacenVacuna> auxvacuna;
		MAlmacenVacuna vacunaActual;

		VGeneral vg;
		int acum=0, cantidad;
		string cant;
		vg.ImprimirMensaje("\n ==========   L I S T A     D E    V A C U N A S ==========\n\n\n");

		    while(!centinela.PVacia()) {
		    	centinela.removerPrimeraVacuna(vacunaActual);
		    	cantidad=vacunaActual.getCantidad();
		    	cant = vg.toString(cantidad);
		    	vg.ImprimirString2("Marca:"+vacunaActual.getMarca(), " Cantidad:  "+cant);
		        auxvacuna.Insertar(vacunaActual);
		        acum=acum+vacunaActual.getCantidad();
		    }
		    while(!auxvacuna.Vacia()) {
		        auxvacuna.Remover(vacunaActual);
		        centinela.agregarVacuna(vacunaActual);
		    }
             vg.ImprimirNro("Cantidad Total:  ",acum);


}


