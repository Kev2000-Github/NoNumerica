/*
 * MCentinela.cpp
 *
 *  Created on: 25 jun. 2021
 *      Author: Kloux
 */

#include "../MCentinela.h"

MCentinela::MCentinela(string _codigo) {
	codigo = _codigo;
}
MCentinela::MCentinela(){

}

string MCentinela::getCodigo(){
	return codigo;
}
void MCentinela::setCodigo(string _codigo){
	codigo = _codigo;
}

bool MCentinela::agregarCubiculo(MCubiculo cubiculo){
	return cubiculos.InsComienzo(cubiculo);
}
bool MCentinela::removerCubiculo(string codigo, MCubiculo &cubiculo){
	nodo<MCubiculo>* ap;
		ap = cubiculos.ObtPrimero();
		string codigoActual = cubiculos.ObtInfo(ap).getCodigo();
		//SI ES EL PRIMER ELEMENTO
		if(codigoActual == codigo){
			return cubiculos.EliComienzo(cubiculo);
		}
		//SI ESTA DESPUES DEL PRIMER ELEMENTO
		while(cubiculos.ObtProx(ap) != NULL){
			codigoActual = cubiculos.ObtInfo(cubiculos.ObtProx(ap)).getCodigo();
			if(codigoActual == codigo){
				return cubiculos.EliDespues(ap, cubiculo);
			}
			else{
				ap = cubiculos.ObtProx(ap);
			}
		};
		return false;
}

bool MCentinela::removerPrimerCubiculo(MCubiculo &cubiculo){
	return cubiculos.EliComienzo(cubiculo);
}

bool MCentinela::esVacia(){
	return cubiculos.Contar() == 0;
}
int MCentinela::consultarVacunas(string marca)
{
	Pila<MAlmacenVacuna> PilaAux;
    MAlmacenVacuna vacunas;
  int cont=0;

	while(!vacuna.Vacia())
	{
		if(marca==vacunas.getMarca())
		{
		return cont++;
		}
		else
		return cont;

	}
	return cont;


}

bool MCentinela::agregarVacuna(MAlmacenVacuna vacunas){
	return vacuna.Insertar(vacunas);
}

bool MCentinela::removerVacuna(string marca, MAlmacenVacuna &vacunas){

}

bool MCentinela::usarVacunas(string marca, MAlmacenVacuna &vacunas)
{
	Pila<MAlmacenVacuna> PilaAux;
	       int cant = vacunas.getCantidad();

	        while(!vacuna.Vacia())
	        {
		         vacuna.Remover(vacunas);

		             if(vacunas.getMarca()!= marca)
		             {
			            PilaAux.Insertar(vacunas);
		              }

	        }

	               while(!PilaAux.Vacia())
	                  {
		            PilaAux.Remover(vacunas);
		            vacuna.Insertar(vacunas);
	                   }
	     if(vacunas.getCantidad()<cant)
	    	 return true;
	     else
	        return false;

}

int MCentinela::totalCubiculos(){
	return cubiculos.Contar();
}
