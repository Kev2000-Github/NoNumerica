/*
 * MCubiculo.cpp
 *
 *  Created on: 25/06/2021
 *      Author: Usuario
 */

#include "../MCubiculo.h"

MCubiculo::MCubiculo(string _codigo) {
	codigo = _codigo;
}
MCubiculo::MCubiculo(){

}

string MCubiculo::getCodigo(){
	return codigo;
}
void MCubiculo::setCodigo(string _codigo){
	codigo = _codigo;
}

bool MCubiculo::agregarPaciente(string cedula){
	return cedulaPaciente.Insertar(cedula);
}

bool MCubiculo::removerPrimerPaciente(string &cedula){
	return cedulaPaciente.Remover(cedula);
}

bool MCubiculo::esVacia(){
	return cedulaPaciente.Vacia();
}

int MCubiculo::total(){
  string ced,punto="fin";
  int cont=0;
  bool final=false;
  if(esVacia()==true)
    return 0;
  else{
    agregarPaciente(punto);
    while(!(final)){
      removerPrimerPaciente(ced);
      cont++;
      if(ced==punto)
        final=true;
      else{
        agregarPaciente(ced);
      };
      return cont;
    };
  };
}
