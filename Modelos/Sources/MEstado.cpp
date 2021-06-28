/*
 * MEstado.cpp
 *
 *  Created on: 25/06/2021
 *      Author: Usuario
 */

#include "../MEstado.h"

MEstado::MEstado() {}

MEstado::MEstado(string n) {
	nombre = n;
}

string MEstado::getNombre(){
	return nombre;
}
void MEstado::setNombre(string n){
	nombre = n;
}

int MEstado::totalMunicipio(){
    return municipios.Contar();
}

bool MEstado::agregarMunicipio(MMunicipio municipio){
    return municipios.InsComienzo(municipio);

}
bool MEstado::removerMunicipio(string codigo, MMunicipio &municipio){
    nodo<MMunicipio>* ap;
	ap = municipios.ObtPrimero();
	string codigoActual = municipios.ObtInfo(ap).getCodigo();
	//SI ES EL PRIMER ELEMENTO
	if(codigoActual == codigo){
		return municipios.EliComienzo(municipio);
	}
	//SI ESTA DESPUES DEL PRIMER ELEMENTO
	while(municipios.ObtProx(ap) != NULL){
		codigoActual = municipios.ObtInfo(municipios.ObtProx(ap)).getCodigo();
		if(codigoActual == codigo){
			return municipios.EliDespues(ap, municipio);
		}
		else{
			ap = municipios.ObtProx(ap);
		}
	};
	return false;

}
