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


int main(){
	Controlador con;
	con.cargarDatos();
	con.procesar();
	con.guardarDatos();
	return 0;
}




