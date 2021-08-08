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

bool MEstado::agregarInfoVacunas(MInfoVacunas & infoVacuna)
{
	return infoVacunas.InsComienzo(infoVacuna);
}

bool MEstado::removerInfoVacunas(string marca, MInfoVacunas &infoVacunabuscada)
{
		Lista<MInfoVacunas> auxInfoVacunas;
		MInfoVacunas info;
		bool encontrado = false;
		while (!infoVacunas.Vacia())
		{
			infoVacunas.EliComienzo(info);
			if (info.getMarca() == marca)
			{
				infoVacunabuscada = info;
				encontrado = true;
				break;
			}
			auxInfoVacunas.InsComienzo(info);
		}
		while (!auxInfoVacunas.Vacia())
		{
			auxInfoVacunas.EliComienzo(info);
			infoVacunas.InsComienzo(info);
		}
		return encontrado;
}

bool MEstado::infVacio()
{
	return infoVacunas.Contar() == 0;
}

bool MEstado::removerPrimerInfo(MInfoVacunas & infoVacuna)
{
	return infoVacunas.EliComienzo(infoVacuna);
}

bool MEstado::buscarPaciente(string cedula) {
	Lista<MMunicipio> auxMunicipio;
	MMunicipio municipioActual;

	bool encontrado = false;
	while(!municipios.Vacia()) {
		municipios.EliComienzo(municipioActual);
		if(municipioActual.buscarPaciente(cedula))
			encontrado = true;
		auxMunicipio.InsComienzo(municipioActual);
	}

	while(!auxMunicipio.Vacia()) {
		auxMunicipio.EliComienzo(municipioActual);
		municipios.InsComienzo(municipioActual);
	}
	return encontrado;
}


