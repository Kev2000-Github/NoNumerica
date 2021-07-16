#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <list>
#include "Modelos/MCubiculo.h"
#include "Modelos/MCentinela.h"
#include "General/Date.h"
#include "General/VGeneral.h"
#include "Controlador.h"

using namespace std;

void prueba1();
void prueba2();
void addToCentinela(MCentinela &centinela, string codigo, string cedula);
void addToMunicipio(MMunicipio &municipio);
void imprimirCedulas(MCubiculo &cubiculo);
int createNumber();
int main(){
	Controlador con;
	con.cargarDatos();
	con.procesar();
	con.consultarCubiculos();
	return 0;
}




