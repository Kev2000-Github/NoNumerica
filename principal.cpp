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
	/* PRUEBA 1
	Cola<Cola<Cola<Cola<int> > > > enormousNumbers;
		for(int x = 0; x < 10; x++){
			Cola<Cola<Cola<int> > > bigNumbers;
			for(int j = 0; j < 10; j++){
				Cola<Cola<int> > numbers2;
				for(int i = 0; i < 10; i ++){
					Cola<int> numbers;
					int number = 2;
					numbers.Insertar(number);
					numbers2.Insertar(numbers);
				}
				bigNumbers.Insertar(numbers2);
			}
			enormousNumbers.Insertar(bigNumbers);
		}
		*/
	MEstado estado;
	for(int i = 0; i < 10; i ++){
		MMunicipio municipio;
		for(int j = 0; j < 10; j++){
			MCentinela centinela;
			for(int n = 0; n < 10; n++){
				MCubiculo cubiculo;
				string cedula = "123";
				cubiculo.agregarPaciente(cedula);
				centinela.agregarCubiculo(cubiculo);
			}
			municipio.agregarCentinela(centinela);
		}
		estado.agregarMunicipio(municipio);
	}
	cout<<"end"<<endl;
	system("PAUSE");
	return 0;
}

int createNumber(){
	int a = 1;
	return a;
}

void addToMunicipio(MMunicipio &municipio){
	MCentinela centinela("111");
	municipio.agregarCentinela(centinela);
}

void prueba1(){
		MCubiculo cubiculo;
		cubiculo.agregarPaciente("111");
		cubiculo.agregarPaciente("222");
		cubiculo.agregarPaciente("333");
		string cedula;

		cubiculo.removerPrimerPaciente(cedula);
		cout << cedula << endl;
		cubiculo.agregarPaciente(cedula);

}

void prueba2(){
	VGeneral vgeneral;
	MCentinela centinela("ABCD");
	MCubiculo cubiculo;
	string codCubiculo = "";
	addToCentinela(centinela, "111", "1");
	addToCentinela(centinela, "222", "2");
	addToCentinela(centinela, "333", "3");

	//MENU CENTINELA//
	MCentinela centinelaAux;
	while(codCubiculo != "-1"){
			vgeneral.ImprimirString("CODIGO DE CENTINELA: ", centinela.getCodigo());
			vgeneral.ImprimirLineasBlanco(1);
			vgeneral.ImprimirEncabezado("CUBICULOS","=======");
			for(int i = 0; !centinela.esVacia(); i ++){
				centinela.removerPrimerCubiculo(cubiculo);
				centinelaAux.agregarCubiculo(cubiculo);
				vgeneral.ImprimirNro("", i + 1);
				vgeneral.ImprimirMensaje(") Codigo[" + cubiculo.getCodigo() + "]");
				vgeneral.ImprimirLineasBlanco(1);
			}
			while(!centinelaAux.esVacia()){
				centinelaAux.removerPrimerCubiculo(cubiculo);
				centinela.agregarCubiculo(cubiculo);
			}
			vgeneral.ImprimirMensaje("-1) Salir");
			vgeneral.ImprimirLineasBlanco(1);
			codCubiculo = vgeneral.LeerString("Codigo del Cubiculo: ");
			vgeneral.Limpiar();
			if(codCubiculo == "-1") return;

			//REPORTE CEDULAS//
			if(centinela.removerCubiculo(codCubiculo, cubiculo)){
				imprimirCedulas(cubiculo);
				centinela.agregarCubiculo(cubiculo);
			}
			else{
				vgeneral.ImprimirMensaje("El codigo ingresado no existe");
				vgeneral.ImprimirLineasBlanco(1);
				system("PAUSE");
			}
			vgeneral.Limpiar();
	}
}

void addToCentinela(MCentinela &centinela, string codigo, string cedula){
	MCubiculo cubiculo(codigo);
	cubiculo.agregarPaciente(cedula);
	cubiculo.agregarPaciente(cedula + "2");
	cubiculo.agregarPaciente(cedula + "3");
	centinela.agregarCubiculo(cubiculo);
}

void imprimirCedulas(MCubiculo &cubiculo){
	VGeneral vgeneral;
	string cedula;
					MCubiculo cubiculoAux;
					for(int i = 0; !cubiculo.esVacia(); i ++){
						cubiculo.removerPrimerPaciente(cedula);
						cubiculoAux.agregarPaciente(cedula);
						vgeneral.ImprimirNro("", i + 1);
						vgeneral.ImprimirString("Cedula:", cedula);
						vgeneral.ImprimirLineasBlanco(1);
					}
					while(!cubiculoAux.esVacia()){
						cubiculoAux.removerPrimerPaciente(cedula);
						cubiculo.agregarPaciente(cedula);
					}
					vgeneral.ImprimirMensaje("Pulsa cualquier tecla para regresar al menu anterior");
					system("PAUSE");
}
