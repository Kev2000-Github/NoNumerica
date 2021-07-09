#include <iostream>
#include <string>
#include <cstdlib>
#include "Controlador.h"
using namespace std;


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

	MPersona persona;
	MExpedienteVacunacion vacunaPersona;
	ifstream archCensoPersonas;
	while(!vGeneral.AbrirArchivoEntrada(archCensoPersonas, "Datos/CensoPersonas.txt")){
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo CensoPersonas.txt\n");
	}
	vGeneral.ImprimirMensaje("\n CARGANDO DATOS CensoPersonas.txt...");
	while(!vGeneral.FinArchivo(archCensoPersonas)){
		string linea = vGeneral.LeerLineaArchivo(archCensoPersonas);
		vector<string> personaExpediente = vGeneral.Split(linea, ',');
		persona.setcedula(personaExpediente[0]);
		persona.setnombre(personaExpediente[1]);
		persona.setapellido(personaExpediente[2]);
		vacunaPersona.setCedula(personaExpediente[0]);
		vacunaPersona.setVacunaTomada(personaExpediente[3]);
		// TODO: agregar cargar pila DosisTomadas
		listaPersonas.agregarPersona(persona);
		listaExpedientes.agregarExpediente(vacunaPersona);
	}
	vGeneral.CerrarArchivoEntrada(archCensoPersonas);
	vGeneral.ImprimirMensaje("\n DATOS CensoPersonas.txt CARGADOS EXITOSAMENTE");

	MEstado estado;
	estado.setNombre("Lara");
	MMunicipio municipio;
	ifstream archMunicipios;
	ifstream archCentinelas;
	ifstream archVacunas;
	ifstream archCubiculos;
	ifstream archColaPacientes;

	while(!vGeneral.AbrirArchivoEntrada(archMunicipios, "Datos/Municipios.txt")){
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo Municipios.txt\n");
	}
	vGeneral.ImprimirMensaje("\n CARGANDO DATOS Municipios.txt...");

	while(!vGeneral.AbrirArchivoEntrada(archCentinelas, "Datos/Centinelas.txt")){
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo Centinelas.txt\n");
	}
	vGeneral.ImprimirMensaje("\n CARGANDO DATOS Centinelas.txt...");

	while(!vGeneral.AbrirArchivoEntrada(archVacunas, "Datos/VacunasEnExistencia.txt")){
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo VacunasEnExistencia.txt\n");
	}
	vGeneral.ImprimirMensaje("\n CARGANDO DATOS VacunasEnExistencia.txt...");

	while(!vGeneral.AbrirArchivoEntrada(archCubiculos, "Datos/Cubiculos.txt")){
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo Cubiculos.txt\n");
	}
	vGeneral.ImprimirMensaje("\n CARGANDO DATOS Cubiculos.txt...");

	while(!vGeneral.AbrirArchivoEntrada(archColaPacientes, "Datos/ColasPacientes.txt")){
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo ColasPacientes.txt\n");
	}
	vGeneral.ImprimirMensaje("\n CARGANDO DATOS ColasPacientes.txt...");

	while(!vGeneral.FinArchivo(archMunicipios)){
		string lineaMunicipio = vGeneral.LeerLineaArchivo(archMunicipios);
		vector<string> vmunicipio = vGeneral.Split(lineaMunicipio, ',');
		municipio.setCodigo(vmunicipio[0]);
		// TODO: agregar setNombre a MMunicipio

		MCentinela centinela;
		while(!vGeneral.FinArchivo(archCentinelas)){
			string lineaCentinela = vGeneral.LeerLineaArchivo(archCentinelas);
			vector<string> vcentinela = vGeneral.Split(lineaCentinela, ',');
			centinela.setCodigo(vcentinela[0]);

			MAlmacenVacuna vacuna;
			while(!vGeneral.FinArchivo(archVacunas)){
				string lineaVacuna = vGeneral.LeerLineaArchivo(archVacunas);
				vector<string> vvacuna = vGeneral.Split(lineaVacuna, ',');
				vacuna.setMarca(vvacuna[0]);
				int cantidad;
				stringstream _ss;
				_ss << vvacuna[1];
				_ss >> cantidad;
				vacuna.setCantidad(cantidad);
				if(vvacuna[2] == vcentinela[0]){
					centinela.agregarVacuna(vacuna);
				}
			}

			MCubiculo cubiculo;
			while(!vGeneral.FinArchivo(archCubiculos)){
				string lineaCubiculo = vGeneral.LeerLineaArchivo(archCubiculos);
				vector<string> vcubiculo = vGeneral.Split(lineaCubiculo, ',');
				cubiculo.setCodigo(vcubiculo[0]);

				string cedula;
				while(!vGeneral.FinArchivo(archColaPacientes)){
					string lineaPaciente = vGeneral.LeerLineaArchivo(archColaPacientes);
					vector<string> vpaciente = vGeneral.Split(lineaPaciente, ',');
					if(vpaciente[1] == vcubiculo[0]){
						cubiculo.agregarPaciente(vpaciente[0]);
					}
				}
				if(vcubiculo[1] == vcentinela[0]){
					centinela.agregarCubiculo(cubiculo);
				}
			}
			if(vcentinela[1] == vmunicipio[0]){
				municipio.agregarCentinela(centinela);
			}
		}
		estado.agregarMunicipio(municipio);
	}
	vGeneral.CerrarArchivoEntrada(archColaPacientes);
	vGeneral.CerrarArchivoEntrada(archCubiculos);
	vGeneral.CerrarArchivoEntrada(archVacunas);
	vGeneral.CerrarArchivoEntrada(archCentinelas);
	vGeneral.CerrarArchivoEntrada(archMunicipios);

	vGeneral.ImprimirMensaje("\n DATOS ColasPacientes.txt CARGADOS EXITOSAMENTE");
	vGeneral.ImprimirMensaje("\n DATOS Cubiculos.txt CARGADOS EXITOSAMENTE");
	vGeneral.ImprimirMensaje("\n DATOS VacunasEnExistencia.txt CARGADOS EXITOSAMENTE");
	vGeneral.ImprimirMensaje("\n DATOS Centinelas.txt CARGADOS EXITOSAMENTE");
	vGeneral.ImprimirMensaje("\n DATOS Municipios.txt CARGADOS EXITOSAMENTE");
}

void Controlador::procesar(){
	/**
	 * Antes de esto, se cargan los datos justo al iniciar el programa
	 *
	 * MOSTRAR MENU INICIAL 1
	 *  M E N U
	 *  1) CrearMunicipio (no estamos seguros de esto profesor, AYUDA) //DEBUG
	 *  2) CrearCentinela (no estamos seguros de esto profesor, HELP US) //DEBUG
	 *  3) Recibir Vacunas
	 *  4) Iniciar Proceso de Vacunacion
	 *  5) Salir
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


void Controlador::agregarMunicipio(){
	/**
	 * Codigo del Municipio: //Ingresar// (validar que el codigo sea unico)
	 * Nombre del municipio: //Ingresar//
	 * Ingresar nro de centinelas: //Ingresar//
	 * Por cada centinela hacer:
	 * 		Codigo del Centinela: //Ingresar//
	 * 		Ingresar nro de cubiculos del centinela actual: //Ingresar//
	 * 			Por cada cubiculo hacer:
	 * 			Codigo del cubiculo: //Ingresar//
	 * 	Al terminar el proceso imprimir mensaje de creacion exitosa
	 */
}

void Controlador::agregarCentinela(){
	/**
	 * Codigo del Municipio: //Ingresar// (buscar que sea codigo de un municipio existente)
	 * Ingresar nro de centinelas: //Ingresar//
	 * Por cada centinela hacer:
	 * 		Codigo del Centinela: //Ingresar//
	 * 		Ingresar nro de cubiculos del centinela actual: //Ingresar//
	 * 			Por cada cubiculo hacer:
	 * 			Codigo del cubiculo: //Ingresar//
	 * 	Al terminar el proceso imprimir mensaje de creacion exitosa
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
	 * SI -> A
	 * NO -> B
	 *
	 */

	/**
	 * A)
	 * 	 * Paciente es de este centinela?
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
	 * SI -> FINAL
	 * NO -> Pa Fuera Ramon
	 */

	/**
	 * B)
	 * Nombre: //Ingresar//
	 * Apellido: //Ingresar//
	 * Cedula: //Ingresar//
	 *
	 * ----------------
	 * Marca de la Vacuna a Suministrar: PFizer (se agarra cualquiera de las vacunas disponibles en el almacen)
	 * Fecha de Hoy: //Ingresar//
	 *
	 * ->FINAL
	 */

	/**
	 * FINAL)
	 * Actualizar Dosis Tomada
	 * Actualizar Almacen de Vacunas
	 *
	 *
	 * IMPRIMIR:
	 * ------------------
	 * Nro de la Dosis: 2
	 * Marca de la Vacuna: PFizer
	 * Kevin Cheng 27.317.962
	 * Fecha para la siguiente Dosis: 18/12/2030
	 * ------------------
	 *
	 */
}
