/*
 * MInfoVacunas.h
 *
 *  Created on: 24/07/2021
 *      Author: Dazzlin
 */

#ifndef MINFOVACUNAS_H_
#define MINFOVACUNAS_H_
#include <iostream>
#include <string>
using namespace std;


class MInfoVacunas {

private:
string marca;
int NroDosis;
public:
	MInfoVacunas();

	MInfoVacunas(string _marca, int _NroDosis);

	    void setMarca(string _marca);
	    void setNroDosis(int _NroDosis);
	    string getMarca();
	    int getNroDosis();




};

#endif /* MINFOVACUNAS_H_ */
