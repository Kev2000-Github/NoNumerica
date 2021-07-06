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
	MEstado estado;
		VGeneral vgeneral;
		MMunicipio municipio;
		MCentinela centinela;
		IMunicipio Imunicipio;
		ICentinela Icentinela;
		ICubiculo Icubiculo;

		vgeneral.Limpiar();
			Imunicipio.ImprimirListaMunicipio(estado);
			string municipioCodigo = vgeneral.LeerString("Ingrese el codigo del municipio: ");

			while(!estado.removerMunicipio(municipioCodigo, municipio)) {
				vgeneral.ImprimirMensaje("Error: El municipio solicitado no existe");
				vgeneral.Pausa();
				vgeneral.Limpiar();

				Imunicipio.ImprimirListaMunicipio(estado);
				municipioCodigo = vgeneral.LeerString("Ingrese el codigo del municipio: ");
			};

			vgeneral.Limpiar();

			Icentinela.ImprimirListaCentinela(municipio);
			string centinelaCodigo = vgeneral.LeerString("Ingrese el codigo del centinela: ");

			while(!municipio.removerCentinela(centinelaCodigo, centinela)) {
				vgeneral.ImprimirMensaje("Error: El centinela solicitado no existe");
				vgeneral.Pausa();
				vgeneral.Limpiar();

				Icentinela.ImprimirListaCentinela(municipio);
				centinelaCodigo = vgeneral.LeerString("Ingrese el codigo del centinela: ");
			};

			Icubiculo.ReportarCubiculo(centinela);

	/**
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

void Controlador::incluirPacienteACola() {
	MEstado estado;
	VGeneral vGeneral;
	MMunicipio municipio;
	MCentinela centinela;
	MCubiculo cubiculo;
	IMunicipio Imunicipio;
	ICentinela Icentinela;
	ICubiculo Icubiculo;


	vGeneral.Limpiar();
	Imunicipio.ImprimirListaMunicipio(estado);
	string municipioCodigo = vGeneral.LeerString("Ingrese el codigo del municipio: ");

	while(!estado.removerMunicipio(municipioCodigo, municipio)) {
		vGeneral.ImprimirMensaje("Error: El municipio solicitado no existe");
		vGeneral.Pausa();
		vGeneral.Limpiar();

		Imunicipio.ImprimirListaMunicipio(estado);
		municipioCodigo = vGeneral.LeerString("Ingrese el codigo del municipio: ");
	};

	vGeneral.Limpiar();

	Icentinela.ImprimirListaCentinela(municipio);
	string centinelaCodigo = vGeneral.LeerString("Ingrese el codigo del centinela: ");

	while(!municipio.removerCentinela(centinelaCodigo, centinela)) {
		vGeneral.ImprimirMensaje("Error: El centinela solicitado no existe");
		vGeneral.Pausa();
		vGeneral.Limpiar();

		Icentinela.ImprimirListaCentinela(municipio);
		centinelaCodigo = vGeneral.LeerString("Ingrese el codigo del centinela: ");
	};

	vGeneral.Limpiar();

	Icubiculo.ImprimirListaCubiculo(centinela);
	string cubiculoCodigo = vGeneral.LeerString("Ingrese el codigo del cubiculo: ");

	while(!centinela.removerCubiculo(cubiculoCodigo, cubiculo)) {
		vGeneral.ImprimirMensaje("Error: El cubiculo solicitado no existe");
		vGeneral.Pausa();
		vGeneral.Limpiar();

		Icubiculo.ImprimirListaCubiculo(centinela);
		cubiculoCodigo = vGeneral.LeerString("Ingrese el codigo del cubiculo: ");
	};

	string cedula = vGeneral.LeerString("Ingrese la cedula: ");

	bool encontrado = false;
	string marca = ".";
	string paciente = "";

	cubiculo.agregarPaciente(marca);
	cubiculo.removerPrimerPaciente(paciente);
	while(paciente != marca) {
		if(paciente == cedula) {
			encontrado = true;
		}
		cubiculo.agregarPaciente(paciente);
		cubiculo.removerPrimerPaciente(paciente);
	};

	vGeneral.Limpiar();
	if(encontrado) {
		vGeneral.ImprimirMensaje("Error: El paciente esta registrado en la cola");
	}
	else {
		if(cubiculo.agregarPaciente(cedula)) {
			vGeneral.ImprimirMensaje("Paciente agregado satisfactoriamente");
		}
		else {
			vGeneral.ImprimirMensaje("Error: El paciente no pudo ser agregado");
		}
	}

	centinela.agregarCubiculo(cubiculo);
	municipio.agregarCentinela(centinela);
	estado.agregarMunicipio(municipio);
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
