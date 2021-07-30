/*
 * CensoPersonas.h
 *
 *  Created on: 29/06/2021
 *      Author: Admin
 */

#ifndef CENSOPERSONAS_H_
#define CENSOPERSONAS_H_
#include "MPersona.h"
#include "../General/Lista.h"

class MCensoPersonas {
private:
  Lista<MPersona> personas;

public:
  MCensoPersonas();

  bool agregarPersona(MPersona &persona);
  bool removerPersona(string cedula, MPersona &persona);
  bool removerPrimerPersona (MPersona &persona);
  bool esVacia();
  int Contar();
};

#endif /* CENSOPERSONAS_H_ */
