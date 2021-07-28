/*
 * ListaExpediente.h
 *
 *  Created on: 27/06/2021
 *      Author: Gina
 */

#ifndef MLISTAEXPEDIENTE_H_
#define MLISTAEXPEDIENTE_H_
#include "../General/cola.h"
#include "../General/Lista.h"
#include "MPersona.h"
#include "MExpedienteVacunacion.h"

class MListaExpediente
{
private:
  Lista<MExpedienteVacunacion> expedientes;

public:
  MListaExpediente();

  bool agregarExpediente(MExpedienteVacunacion &expediente);
  bool removerExpediente(string cedula, MExpedienteVacunacion &Expediente);
  bool removerPrimerExpediente(MExpedienteVacunacion &Expediente);
  bool estaVacia();
};

#endif

