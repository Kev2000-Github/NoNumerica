#include <iostream>
#include <cstdlib>
#include "Modelos/MCubiculo.h"
#include "General/Date.h"
using namespace std;

int main(){
	MCubiculo cubiculo;
	bool encontrado = false;
	cubiculo.agregarPaciente("111");
	cubiculo.agregarPaciente("222");
	cubiculo.agregarPaciente("333");
	string cedula;

	cubiculo.removerPrimerPaciente(cedula);
	cout << cedula << endl;
	cubiculo.agregarPaciente(cedula);

	cedula = "222";
	encontrado = cubiculo.removerPaciente(cedula);
	cout << encontrado << " " << cedula << endl;
	cubiculo.agregarPaciente(cedula);

	cedula = "123";
	cout << cubiculo.removerPaciente(cedula) << endl;

	return 0;
}
