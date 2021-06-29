#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#include "Controlador.h"

Controlador::Controlador(){

}

void Controlador::cargarDatos(){
	/**
	 * Cargar los datos iniciales almacenados en los .txt
	 * los TXT son:
	 * CensoPersonas.txt
	 * VacunasEnExistencia.txt
	 * Municipios.txt
	 * Centinelas.txt
	 * Cubiculos.txt
	 * ColasPacientes.txt
	 */
}

void Controlador::procesar(){
	/**
	 * MOSTRAR MENU INICIAL 1
	 *  M E N U
	 *  -1) CrearMunicipio (no estamos seguros de esto profesor, AYUDA) //DEBUG
	 *  0) CrearCentinela (no estamos seguros de esto profesor, HELP US) //DEBUG
	 *  1) Cargar datos //(todos los txt)
	 *  2) Recibir Vacunas
	 *  3) Iniciar Proceso de Vacunacion
	 *  4) Salir
	 */
}

void Controlador::procesar2(){
	/**
	 * MOSTRAR MENU INICIAL 1
	 *  M E N U  V A C U N A C I O N
	 *  1) Consultar Persona
	 *  2) Consultar Municipios
	 *  3) Consultar Centinelas
	 *  4) Consultar Cubiculos
	 *  5) Consultar Vacunas en Almacen
	 *  6) Incluir Paciente a una Cola
	 *  7) Sacar Paciente de la Cola (HELP ME)??
	 *  8) Procesar Paciente
	 *  9) Salir
	 */
}

void Controlador::consultarPersona(){
	/**
	 * Reportar informacion acerca de una persona del censo de personas
	 * ------
	 * Cedula: //ingresar//
	 * ----------
	 * REPORTE
	 * Kevin Cheng
	 * 27.317.962
	 * Vacuna Tomada: Chino
	 * Dosis Tomadas: 3
	 */
}

void Controlador::consultarMunicipios(){
	/**
	 *
	 * Reportar Informacion de los Municipios
	 * ----------------------------------
	 * Municipio [123]
	 * Municipio<123>: (10) //Sumatoria de todas las cedulas de todas las colas
	 * Municipio<456>: (30) //Sumatoria de todas las cedulas de todas las colas
	 * Municipio<789>: (50) //Sumatoria de todas las cedulas de todas las colas
	 * ----------------------------------
	 * ...
	 */
}

void Controlador::consultarCentinelas(){
	/**
	 * Municipio: //Ingresar//
	 *
	 * Reportar Informacion de los Centinelas
	 * ----------------------------------
	 * Municipio [123]
	 * Centinela<abc>: (10) //Sumatoria de todas las cedulas de todas las colas
	 * Centinela<cdz>: (30) //Sumatoria de todas las cedulas de todas las colas
	 * Centinela<cdz>: (50) //Sumatoria de todas las cedulas de todas las colas
	 * ----------------------------------
	 * ...
	 */
}

void Controlador::consultarCubiculos(){
	/**
	 * Municipio: //Ingresar//
	 * Centinela: //Ingresar//
	 *
	 * Reportar Informacion de los Cubiculos
	 * ----------------------------------
	 * Centinela [abc]
	 * Cubiculo<111>: (10) //Sumatoria de todas las cedulas de todas las colas
	 * Cubiculo<222>: (30) //Sumatoria de todas las cedulas de todas las colas
	 * Cubiculo<333>: (50) //Sumatoria de todas las cedulas de todas las colas
	 * ----------------------------------
	 * ...
	 */
}

void Controlador::consultarColas(){
	/**
	 * Municipio: //ingresar//
	 * Centinela: //ingresar//
	 * Cubiculo: //ingresar//
	 *
	 * Reportar Informacion de la cola
	 * ----------------------------------
	 * Cubiculo [111]
	 * Kevin Cheng 27.317.962
	 * Don Juancho 25.317.962
	 * ...
	 */
}

void Controlador::consultarVacunas(){
	/**
	 * Municipio: //ingresar//
	 * Centinelas: //ingresar//
	 *
	 * Reportar las Vacunas Existentes
	 * ----------------------------------
	 * Cubiculo [111]
	 * Kevin Cheng 27.317.962
	 * Don Juancho 25.317.962
	 * ...
	 */
}

void Controlador::incluirPacienteACola(){
	/**
	 * Municipio: //ingresar//
	 * Centinelas: //ingresar//
	 * Cubiculo: //ingresar//
	 *
	 * el paciente ya existe en la cola?
	 * NO -> agregar
	 * SI -> Pa Fuera Rancho
	 */
}

void Controlador::SacarPacienteDeCola(){
	/**
	 * Municipio: //ingresar//
	 * Centinelas: //ingresar//
	 * Cubiculo: //ingresar//
	 *
	 * Buscar cedula en la cola y sacarlo de ahi
	 */
}

void Controlador::procesarPaciente(){
	/**
	 * Municipio: //ingresar//
	 * Centinelas: //ingresar//
	 * Cubiculo: //ingresar//
	 *
	 * Agarra el primer paciente de la cola
	 * Paciente tiene expediente?
	 * SI -> SEGUIR
	 * NO -> //DEJAME PENSA...
	 *
	 * Paciente es de este centinela?
	 * SI -> SEGUIR
	 * NO -> Pa fuera juan
	 *
	 * Existen Vacunas que el Paciente haya tomado?
	 * SI -> SEGUIR
	 * NO -> PA OTRO DIA CHAVAL
	 *
	 * Fecha de Hoy: //Ingresar//
	 *
	 * Pasaron 3 meses desde su ultima dosis?
	 * SI -> Actualizar Dosis Tomada, Actualizar Almacen de Vacunas
	 * NO -> Pa Fuera Ramon
	 *
	 * IMPRIMIR:
	 * ------------------
	 * Nro de la Dosis: 2
	 * Marca de la Vacuna: PFizer
	 * Kevin Cheng 27.317.962
	 * Fecha para la siguiente Dosis: 18/12/2030
	 * ------------------
	 */
}
