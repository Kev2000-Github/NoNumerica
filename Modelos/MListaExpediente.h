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
#include "ExpedienteVacunacion.h"

namespace std {

class MListaExpediente {
private:
  Lista <ExpedienteVacunacion> Expediente;

public:
  MListaExpediente();
  MListaExpediente();

  bool agregarExpediente(ExpedienteVacunacion expediente);
  bool removerExpediente(string cedula, ExpedienteVacunacion &Expediente);
  bool removerPrimerExpediente (ExpedienteVacunacion &Expediente);

};
