/*
 * MEstado.cpp
 *
 *  Created on: 25/06/2021
 *      Author: Usuario
 */

#include "../MEstado.h"

MEstado::MEstado() {}

MEstado::MEstado(string n)
{
	nombre = n;
}

string MEstado::getNombre()
{
	return nombre;
}
void MEstado::setNombre(string n)
{
	nombre = n;
}

int MEstado::totalMunicipio()
{
	return municipios.Contar();
}

bool MEstado::agregarMunicipio(MMunicipio &municipio)
{
	return municipios.InsComienzo(municipio);
}
bool MEstado::removerMunicipio(string codigo, MMunicipio &municipioBuscado)
{
	Lista<MMunicipio> listaAux;
	MMunicipio municipioActual;
	bool encontrado = false;
	while (!municipios.Vacia())
	{
		municipios.EliComienzo(municipioActual);
		if (municipioActual.getCodigo() == codigo)
		{
			municipioBuscado = municipioActual;
			encontrado = true;
			break;
		}
		listaAux.InsComienzo(municipioActual);
	}
	while (!listaAux.Vacia())
	{
		listaAux.EliComienzo(municipioActual);
		municipios.InsComienzo(municipioActual);
	}
	return encontrado;
}

bool MEstado::esVacio()
{
	return municipios.Contar() == 0;
}

bool MEstado::removerPrimerMunicipio(MMunicipio &municipio)
{
	return municipios.EliComienzo(municipio);
}
