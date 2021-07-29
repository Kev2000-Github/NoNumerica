

#include "../IAlmacen.h"

IAlmacen::IAlmacen() {}

void IAlmacen::ImprimirVacunas(MCentinela & centinela)
{
		Pila<MAlmacenVacuna> auxvacuna, vacunasUnicas, vacunasUnicasAux;
		MAlmacenVacuna vacunaActual, vacunaActualUnica;
		VGeneral vg;
		bool encontrado = false;
	    while(!centinela.PVacia()) {
	    	centinela.removerPrimeraVacuna(vacunaActual);
	        auxvacuna.Insertar(vacunaActual);
	    	while(!vacunasUnicas.Vacia())
	    	{
	    		vacunasUnicas.Remover(vacunaActualUnica);
	    		vacunasUnicasAux.Insertar(vacunaActualUnica);
	    		if(vacunaActualUnica.getMarca() == vacunaActual.getMarca())
	    		{
	    			encontrado = true;
	    			break;
	    		}
	    	}
		    while(!vacunasUnicasAux.Vacia()) {
		    	vacunasUnicasAux.Remover(vacunaActualUnica);
		    	vacunasUnicas.Insertar(vacunaActualUnica);
		    }
	    	if(!encontrado) vacunasUnicas.Insertar(vacunaActual);
	    	encontrado = false;
	    }
	    while(!auxvacuna.Vacia()) {
	        auxvacuna.Remover(vacunaActual);
	        centinela.agregarVacuna(vacunaActual);
	    }

		int i=1;
		vg.ImprimirMensaje("\n Lista de Vacunas:\n");
		    while(!vacunasUnicas.Vacia()) {
		    	vacunasUnicas.Remover(vacunaActual);
		        vg.ImprimirString3("Marca  Nro",i++,": "+vacunaActual.getMarca());
		    }
	}

void IAlmacen::ImprimirLotes(string marca,MCentinela & centinela)
{
	Pila<MAlmacenVacuna> auxvacuna;
	MAlmacenVacuna vacunaActual;
	VGeneral vg;
	int i=1;
		vg.ImprimirMensaje("\n Lista de Lotes:\n");
		    while(!centinela.PVacia()) {

		    	centinela.removerPrimeraVacuna(vacunaActual);
		    	if(vacunaActual.getMarca()==marca and vacunaActual.getLote() !="")
		    	{
		    	vg.ImprimirString3("Codigo: ",i++,": "+vacunaActual.getLote());
		    	}
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
		int acum=0,acum2=0;

		vg.ImprimirMensaje("\n ==========   L I S T A     D E    V A C U N A S ==========\n\n\n");

		    while(!centinela.PVacia()) {
		    	centinela.removerPrimeraVacuna(vacunaActual);



                vg.ImprimirLineasBlanco(1);

		    	vg.ImprimirString5("Lote: " + vacunaActual.getLote()," Marca: "+vacunaActual.getMarca()," Cantidad Disponible: ",vacunaActual.getcantDisponible()," Cantidad Reservada: ",vacunaActual.getcantReservada());
		        auxvacuna.Insertar(vacunaActual);
		        acum=acum+vacunaActual.getcantDisponible();
		        acum2=acum2+vacunaActual.getcantReservada();
		    }
		    while(!auxvacuna.Vacia()) {
		        auxvacuna.Remover(vacunaActual);
		        centinela.agregarVacuna(vacunaActual);
		    }
		    vg.ImprimirLineasBlanco(1);
             vg.ImprimirNro("Cantidad Total Disponible:  ",acum);
             vg.ImprimirLineasBlanco(1);
             vg.ImprimirNro("Cantidad Total Reservada:  ",acum2);


}


