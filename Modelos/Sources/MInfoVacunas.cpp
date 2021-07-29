/*
 * MInfoVacunas.cpp
 *
 *  Created on: 24/07/2021
 *      Author: Dazzlin
 */

#include "../MInfoVacunas.h"

MInfoVacunas::MInfoVacunas() {
	// TODO Auto-generated constructor stub

}

MInfoVacunas::MInfoVacunas(string _marca, int _NroDosis)
{

	marca = _marca;
	NroDosis= _NroDosis;
}



void MInfoVacunas::setMarca(string _marca)
{
	marca = _marca;
}



void MInfoVacunas::setNroDosis(int _NroDosis)
{
	NroDosis= _NroDosis;
}



string MInfoVacunas::getMarca()
{
	return marca;
}



int MInfoVacunas::getNroDosis()
{
	return NroDosis;
}







