/*
 * ListaExpediente.cpp
 *
 *  Created on: 27/06/2021
 *      Author: Gina
 */

#include "../MListaExpediente.h"

MListaExpediente::MListaExpediente(){};

bool MListaExpediente::agregarExpediente(MExpedienteVacunacion &expediente)
{
	return expedientes.InsComienzo(expediente);
}

bool MListaExpediente::removerExpediente(string cedula, MExpedienteVacunacion &expedienteBuscado)
{
	Lista<MExpedienteVacunacion> listaAux;
	MExpedienteVacunacion expedienteActual;
	bool encontrado = false;
	while (!expedientes.Vacia())
	{
		expedientes.EliComienzo(expedienteActual);
		if (expedienteActual.getCedula() == cedula)
		{
			expedienteBuscado = expedienteActual;
			encontrado = true;
			break;
		}
		listaAux.InsComienzo(expedienteActual);
	}
	while (!listaAux.Vacia())
	{
		listaAux.EliComienzo(expedienteActual);
		expedientes.InsComienzo(expedienteActual);
	}
	return encontrado;
}

bool MListaExpediente::removerPrimerExpediente(MExpedienteVacunacion &expediente)
{
	return expedientes.EliComienzo(expediente);
}

bool MListaExpediente::estaVacia()
{
	return expedientes.Vacia();
}

