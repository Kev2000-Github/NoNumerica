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
	string instructions = "Por favor, verifique que existe la carpeta /Datos \nen el directorio del ejecutable y dentro el txt correspondiente\n";
	while(!vGeneral.AbrirArchivoEntrada(archCensoPersonas, "Datos/CensoPersonas.txt")){
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo CensoPersonas.txt\n" + instructions);
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}
	vGeneral.ImprimirMensaje("\n CARGANDO DATOS CensoPersonas.txt...");
	vector<string> lineaActual;
	while(!vGeneral.FinArchivo(archCensoPersonas)){
		string linea = vGeneral.LeerLineaArchivo(archCensoPersonas);
		lineaActual = vGeneral.Split(linea, ',');
		persona.setcedula(lineaActual[0]);
		persona.setnombre(lineaActual[1]);
		persona.setapellido(lineaActual[2]);
		vacunaPersona.setCedula(lineaActual[0]);
		vacunaPersona.setVacunaTomada(lineaActual[3]);
		vacunaPersona.setCodCentinela(lineaActual[4]);
		lineaActual.clear();
		// TODO: agregar cargar pila DosisTomadas
		listaPersonas.agregarPersona(persona);
		listaExpedientes.agregarExpediente(vacunaPersona);
	}
	vGeneral.CerrarArchivoEntrada(archCensoPersonas);
	vGeneral.ImprimirMensaje("\n DATOS CensoPersonas.txt CARGADOS EXITOSAMENTE");

	estado.setNombre("Lara");

	ifstream archMunicipios;
	ifstream archCentinelas;
	ifstream archVacunas;
	ifstream archCubiculos;
	ifstream archColaPacientes;

	while(!vGeneral.AbrirArchivoEntrada(archMunicipios, "Datos/Municipios.txt")){
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo Municipios.txt\n" + instructions);
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}
	vGeneral.ImprimirMensaje("\n CARGANDO DATOS Municipios.txt...");

	while(!vGeneral.AbrirArchivoEntrada(archCentinelas, "Datos/Centinelas.txt")){
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo Centinelas.txt\n" + instructions);
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}
	vGeneral.ImprimirMensaje("\n CARGANDO DATOS Centinelas.txt...");

	while(!vGeneral.AbrirArchivoEntrada(archVacunas, "Datos/VacunasEnExistencia.txt")){
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo VacunasEnExistencia.txt\n" + instructions);
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}
	vGeneral.ImprimirMensaje("\n CARGANDO DATOS VacunasEnExistencia.txt...");

	while(!vGeneral.AbrirArchivoEntrada(archCubiculos, "Datos/Cubiculos.txt")){
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo Cubiculos.txt\n" + instructions);
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}
	vGeneral.ImprimirMensaje("\n CARGANDO DATOS Cubiculos.txt...");

	while(!vGeneral.AbrirArchivoEntrada(archColaPacientes, "Datos/ColasPacientes.txt")){
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo ColasPacientes.txt\n" + instructions);
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}
	vGeneral.ImprimirMensaje("\n CARGANDO DATOS ColasPacientes.txt...");

	while(!vGeneral.FinArchivo(archMunicipios)){
		string lineaMunicipio = vGeneral.LeerLineaArchivo(archMunicipios);
		lineaActual = vGeneral.Split(lineaMunicipio, ',');
		string municipioCod = lineaActual[0];
		string municipioNombre = lineaActual[1];
		lineaActual.clear();
		MMunicipio municipio;
		municipio.setCodigo(municipioCod);
		municipio.setNombre(municipioNombre);
		// TODO: agregar setNombre a MMunicipio

		while(!vGeneral.FinArchivo(archCentinelas)){
			string lineaCentinela = vGeneral.LeerLineaArchivo(archCentinelas);
			lineaActual = vGeneral.Split(lineaCentinela, ',');
			string centinelaCod = lineaActual[0];
			string centinelaMunCod = lineaActual[1];
			lineaActual.clear();
			if(centinelaMunCod == municipioCod){
				MCentinela centinela(centinelaCod);
				while(!vGeneral.FinArchivo(archVacunas)){
					string lineaVacuna = vGeneral.LeerLineaArchivo(archVacunas);
					lineaActual = vGeneral.Split(lineaVacuna, ',');
					string marca = lineaActual[0];
					string cant = lineaActual[1];
					string vacunaCent = lineaActual[2];
					lineaActual.clear();
					if(vacunaCent == centinelaCod){
						MAlmacenVacuna vacuna;
						vacuna.setMarca(marca);
						int cantidad = vGeneral.parseInt(cant);
						vacuna.setCantidad(cantidad);
						centinela.agregarVacuna(vacuna);
					}
				}
				vGeneral.RegresarPrimeraLinea(archVacunas);
				while(!vGeneral.FinArchivo(archCubiculos)){
					string lineaCubiculo = vGeneral.LeerLineaArchivo(archCubiculos);
					lineaActual = vGeneral.Split(lineaCubiculo, ',');
					string cubCod = lineaActual[0];
					string cubCentinelaCod = lineaActual[1];
					lineaActual.clear();
					if(cubCentinelaCod == centinelaCod){
						MCubiculo cubiculo;
						cubiculo.setCodigo(cubCod);
						string cedula;
						while(!vGeneral.FinArchivo(archColaPacientes)){
							string lineaPaciente = vGeneral.LeerLineaArchivo(archColaPacientes);
							lineaActual = vGeneral.Split(lineaPaciente, ',');
							string pacienteCubCod = lineaActual[1];
							string cedula = lineaActual[0];
							lineaActual.clear();
							if(pacienteCubCod == cubCod){
								cubiculo.agregarPaciente(cedula);
							}
						}
						vGeneral.RegresarPrimeraLinea(archColaPacientes);
						centinela.agregarCubiculo(cubiculo);
					}
				}
				vGeneral.RegresarPrimeraLinea(archCubiculos);
				municipio.agregarCentinela(centinela);
			}
		}
		vGeneral.RegresarPrimeraLinea(archCentinelas);
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
	vGeneral.Limpiar();

}

void Controlador::procesar(){
	/* PARA PROBAR LA ESTABILIDAD DE LAS ESTRUCTURAS DE DATOS
	MEstado estadoAux;
	MMunicipio municipio;
	MCentinela centinela;
	MCubiculo cubiculo;
	string cedula;
	while(!estado.esVacio()){
		estado.removerPrimerMunicipio(municipio);
		cout << "-----------MUNICIPIO: " << municipio.getNombre() << endl;
		while(!municipio.esVacio()){
			municipio.removerPrimerCentinela(centinela);
			cout << "-->CENTINELA: " << centinela.getCodigo() << endl;
			while(!centinela.esVacia()){
				centinela.removerPrimerCubiculo(cubiculo);
				cout << "CUBICULO: " << cubiculo.getCodigo() << endl;
				while(!cubiculo.esVacia()){
					cubiculo.removerPrimerPaciente(cedula);
					cout << "<cedula>: " << cedula << endl;
				}
			}
		}
		estadoAux.agregarMunicipio(municipio);
	}
	*/

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
	int rpta;
	while(rpta != 5){
		vGeneral.ImprimirEncabezado("M E N U", "_______");
		vGeneral.ImprimirMensaje("1) Crear Municipio");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("2) Crear Centinela");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("3) Recibir Vacunas");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("4) Iniciar Proceso de Vacunacion");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("5) Salir");
		vGeneral.ImprimirLineasBlanco(1);

		rpta = vGeneral.LeerNro("Respuesta: ");
		vGeneral.Limpiar();
		switch(rpta){
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			procesar2();
			break;
		case 5:
			return;
		default:
			vGeneral.ImprimirMensaje("Por favor ingrese una opcion valida\n");
			vGeneral.Pausa();
			vGeneral.Limpiar();
			break;
		}
	}
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

	int rpta;
	while(rpta != 9){
		vGeneral.ImprimirEncabezado("M E N U  V A C U N A C I O N", "_______  ___________________");
		vGeneral.ImprimirMensaje("1) Consultar Persona");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("2) Consultar Municipios");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("3) Consultar Centinelas");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("4) Consultar Cubiculos");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("5) Consultar Vacunas en Almacen");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("6) Incluir Paciente a una Cola");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("7) Sacar Paciente de una Cola");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("8) Procesar Paciente");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("9) Salir");
		vGeneral.ImprimirLineasBlanco(1);

		rpta = vGeneral.LeerNro("Respuesta: ");
		vGeneral.Limpiar();
		switch(rpta){
		case 1:

			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			consultarCubiculos();
			break;
		case 5:
			break;
		case 6:
			incluirPacienteACola();
			break;
		case 7:

			break;
		case 8:
			break;
		case 9:
			return;
		default:
			vGeneral.ImprimirMensaje("Por favor ingrese una opcion valida\n");
			vGeneral.Pausa();
			vGeneral.Limpiar();
			break;
		}
	}
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

			string numcenti = vGeneral.LeerString("Ingrese el numero de Centinelas que desea agregar: ");

			for(int i = 0; i < numcenti; ++i){
				string centiCodigo = vGeneral.LeerString("Ingrese el codigo de la centinela: ");

					bool encontrado = false;
					Lista<MCentinela> Listaux;
					//MCentinela centi=new string;

					while(municipio.obtenerPrimerCenti()!= NULL){

						municipio.removerPrimerCentinela(centinela);



					Lista1.EliComienzo(*valor); //retorna valor eliminado
					Listaux.InsComienzo(*valor); //agrega ese valor eliminado
					cout<<"Numero: "<<*valor<<"\n"; //imprime ese numero
					}






					//string marca = ".";
					string centinela = "";

					municipio.agregarCentinela(marca);
					cubiculo.removerPrimerPaciente(paciente);
					while(centinela != marca) {
						if(centinela == centiCodigo) {
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
			VGeneral vgeneral;
			MMunicipio municipio;
			MCentinela centinela;
			IMunicipio Imunicipio;
			ICentinela Icentinela;
			ICubiculo Icubiculo;

			vgeneral.Limpiar();
				Imunicipio.ImprimirListaMunicipio(estado);
				string municipioCodigo = vgeneral.LeerString("\n Ingrese el codigo del municipio: ");

				while(!estado.removerMunicipio(municipioCodigo, municipio)) {
					vgeneral.ImprimirMensaje("Error: El municipio solicitado no existe \n\n");
					vgeneral.Pausa();
					vgeneral.Limpiar();

					Imunicipio.ImprimirListaMunicipio(estado);
					municipioCodigo = vgeneral.LeerString("\n Ingrese el codigo del municipio: ");
				};

				vgeneral.Limpiar();

				Icentinela.ImprimirListaCentinela(municipio);
				string centinelaCodigo = vgeneral.LeerString("\n Ingrese el codigo del centinela: ");

				while(!municipio.removerCentinela(centinelaCodigo, centinela)) {
					vgeneral.ImprimirMensaje("Error: El centinela solicitado no existe \n\n");
					vgeneral.Pausa();
					vgeneral.Limpiar();

					Icentinela.ImprimirListaCentinela(municipio);
					centinelaCodigo = vgeneral.LeerString("\n Ingrese el codigo del centinela: ");
				};


				Icubiculo.ReportarCubiculo(centinela);


				municipio.agregarCentinela(centinela);
				estado.agregarMunicipio(municipio);

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

void Controlador::incluirPacienteACola(){
	VGeneral vGeneral;
		MMunicipio municipio;
		MCentinela centinela;
		MCubiculo cubiculo;
		IMunicipio Imunicipio;
		ICentinela Icentinela;
		ICubiculo Icubiculo;


		vGeneral.Limpiar();
		Imunicipio.ImprimirListaMunicipio(estado);
		string municipioCodigo = vGeneral.LeerString("\n Ingrese el codigo del municipio: ");

		while(!estado.removerMunicipio(municipioCodigo, municipio)) {
			vGeneral.ImprimirMensaje("Error: El municipio solicitado no existe \n\n");
			vGeneral.Pausa();
			vGeneral.Limpiar();

			Imunicipio.ImprimirListaMunicipio(estado);
			municipioCodigo = vGeneral.LeerString("\n Ingrese el codigo del municipio: ");
		};

		vGeneral.Limpiar();

		Icentinela.ImprimirListaCentinela(municipio);
		string centinelaCodigo = vGeneral.LeerString("\n Ingrese el codigo del centinela: ");

		while(!municipio.removerCentinela(centinelaCodigo, centinela)) {
			vGeneral.ImprimirMensaje("Error: El centinela solicitado no existe \n\n");
			vGeneral.Pausa();
			vGeneral.Limpiar();

			Icentinela.ImprimirListaCentinela(municipio);
			centinelaCodigo = vGeneral.LeerString("\n Ingrese el codigo del centinela: ");
		};

		vGeneral.Limpiar();

		Icubiculo.ImprimirListaCubiculo(centinela);
		string cubiculoCodigo = vGeneral.LeerString("\n Ingrese el codigo del cubiculo: ");

		while(!centinela.removerCubiculo(cubiculoCodigo, cubiculo)) {
			vGeneral.ImprimirMensaje("Error: El cubiculo solicitado no existe \n\n");
			vGeneral.Pausa();
			vGeneral.Limpiar();

			Icubiculo.ImprimirListaCubiculo(centinela);
			cubiculoCodigo = vGeneral.LeerString("\n Ingrese el codigo del cubiculo: ");
		};

		string cedula = vGeneral.LeerString("\n Ingrese la cedula: ");

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
			vGeneral.ImprimirMensaje("Error: El paciente esta registrado en la cola \n");
		}
		else {
			if(cubiculo.agregarPaciente(cedula)) {
				vGeneral.ImprimirMensaje("Paciente agregado satisfactoriamente \n");
			}
			else {
				vGeneral.ImprimirMensaje("Error: El paciente no pudo ser agregado \n");
			}
		}
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.Pausa();
		vGeneral.Limpiar();

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
