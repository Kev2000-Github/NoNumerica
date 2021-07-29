#include <iostream>
#include <string>
#include <cstdlib>
#include "Controlador.h"
using namespace std;

Controlador::Controlador()
{
}

void Controlador::cargarDatos()
{
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
	ifstream archCensoPersonas;
	string instructions = "Por favor, verifique que existe la carpeta /Datos \nen el directorio del ejecutable y dentro el txt correspondiente\n";
	while (!vGeneral.AbrirArchivoEntrada(archCensoPersonas, "Datos/CensoPersonas.txt"))
	{
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo CensoPersonas.txt\n" + instructions);
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}
	vGeneral.ImprimirMensaje("\n CARGANDO DATOS CensoPersonas.txt...");
	vector<string> lineaActual;
	while (!vGeneral.FinArchivo(archCensoPersonas))
	{
		MExpedienteVacunacion vacunaPersona;
		string linea = vGeneral.LeerLineaArchivo(archCensoPersonas);
		lineaActual = vGeneral.Split(linea, ',');
		persona.setcedula(lineaActual[0]);
		persona.setnombre(lineaActual[1]);
		persona.setapellido(lineaActual[2]);
		vacunaPersona.setCedula(lineaActual[0]);
		vacunaPersona.setVacunaTomada(lineaActual[3]);
		vacunaPersona.setCodCentinela(lineaActual[4]);
		for (int i = 5; i < lineaActual.size(); i++)
		{
			Date fecha(lineaActual[i]);
			vacunaPersona.AgregarNuevaDosis(fecha);
		}
		lineaActual.clear();
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

	while (!vGeneral.AbrirArchivoEntrada(archMunicipios, "Datos/Municipios.txt"))
	{
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo Municipios.txt\n" + instructions);
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}
	vGeneral.ImprimirMensaje("\n CARGANDO DATOS Municipios.txt...");

	while (!vGeneral.AbrirArchivoEntrada(archCentinelas, "Datos/Centinelas.txt"))
	{
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo Centinelas.txt\n" + instructions);
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}
	vGeneral.ImprimirMensaje("\n CARGANDO DATOS Centinelas.txt...");

	while (!vGeneral.AbrirArchivoEntrada(archVacunas, "Datos/VacunasEnExistencia.txt"))
	{
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo VacunasEnExistencia.txt\n" + instructions);
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}
	vGeneral.ImprimirMensaje("\n CARGANDO DATOS VacunasEnExistencia.txt...");

	while (!vGeneral.AbrirArchivoEntrada(archCubiculos, "Datos/Cubiculos.txt"))
	{
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo Cubiculos.txt\n" + instructions);
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}
	vGeneral.ImprimirMensaje("\n CARGANDO DATOS Cubiculos.txt...");

	while (!vGeneral.AbrirArchivoEntrada(archColaPacientes, "Datos/ColasPacientes.txt"))
	{
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo ColasPacientes.txt\n" + instructions);
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}
	vGeneral.ImprimirMensaje("\n CARGANDO DATOS ColasPacientes.txt...");

	while (!vGeneral.FinArchivo(archMunicipios))
	{
		string lineaMunicipio = vGeneral.LeerLineaArchivo(archMunicipios);
		lineaActual = vGeneral.Split(lineaMunicipio, ',');
		string municipioCod = lineaActual[0];
		string municipioNombre = lineaActual[1];
		lineaActual.clear();
		MMunicipio municipio;
		municipio.setCodigo(municipioCod);
		municipio.setNombre(municipioNombre);

		while (!vGeneral.FinArchivo(archCentinelas))
		{
			string lineaCentinela = vGeneral.LeerLineaArchivo(archCentinelas);
			lineaActual = vGeneral.Split(lineaCentinela, ',');
			string centinelaCod = lineaActual[0];
			string centinelaMunCod = lineaActual[1];
			lineaActual.clear();
			if (centinelaMunCod == municipioCod)
			{
				MCentinela centinela(centinelaCod);
				while (!vGeneral.FinArchivo(archVacunas))
				{
					string lineaVacuna = vGeneral.LeerLineaArchivo(archVacunas);
					lineaActual = vGeneral.Split(lineaVacuna, ',');
					string marca = lineaActual[0];
					string cant = lineaActual[1];
					string vacunaCent = lineaActual[2];
					lineaActual.clear();
					if (vacunaCent == centinelaCod)
					{
						MAlmacenVacuna vacuna;
						vacuna.setMarca(marca);
						int cantidad = vGeneral.parseInt(cant);
						vacuna.setCantidad(cantidad);
						centinela.agregarVacuna(vacuna);
					}
				}
				vGeneral.RegresarPrimeraLinea(archVacunas);
				while (!vGeneral.FinArchivo(archCubiculos))
				{
					string lineaCubiculo = vGeneral.LeerLineaArchivo(
						archCubiculos);
					lineaActual = vGeneral.Split(lineaCubiculo, ',');
					string cubCod = lineaActual[0];
					string cubCentinelaCod = lineaActual[1];
					lineaActual.clear();
					if (cubCentinelaCod == centinelaCod)
					{
						MCubiculo cubiculo;
						cubiculo.setCodigo(cubCod);
						string cedula;
						while (!vGeneral.FinArchivo(archColaPacientes))
						{
							string lineaPaciente = vGeneral.LeerLineaArchivo(
								archColaPacientes);
							lineaActual = vGeneral.Split(lineaPaciente, ',');
							string pacienteCubCod = lineaActual[1];
							string cedula = lineaActual[0];
							lineaActual.clear();
							if (pacienteCubCod == cubCod)
							{
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

void Controlador::guardarDatos()
{
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
	MMunicipio municipio;
	MCentinela centinela;
	MCubiculo cubiculo, cubiculoAux;
	MPersona persona;
	MExpedienteVacunacion vacunaPersona;
	Pila<Date> fechasAux;
	Lista<MPersona> personasAux;
	Date fecha;
	string cedula;
	ofstream archCensoPersonas;
	string instructions = "Por favor, verifique que existe la carpeta /Datos \nen el directorio del ejecutable y dentro el txt correspondiente\n";
	while (!vGeneral.AbrirArchivoSalida(archCensoPersonas, "Datos/CensoPersonas.txt"))
	{
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo CensoPersonas.txt\n" + instructions);
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}
	vGeneral.ImprimirMensaje("\n GUARDANDO DATOS CensoPersonas.txt...");
	vector<string> lineaActual;
	string linea;
	while(!listaPersonas.esVacia()){
		listaPersonas.removerPrimerPersona(persona);
		personasAux.InsComienzo(persona);
	}
	while (!personasAux.Vacia())
	{
		linea="";
		personasAux.EliComienzo(persona);
		listaExpedientes.removerExpediente(persona.getcedula(), vacunaPersona);
		linea += persona.getcedula() + ",";
		linea += persona.getnombre() + ",";
		linea += persona.getapellido() + ",";
		linea += vacunaPersona.getVacunaTomada() + ",";
		linea += vacunaPersona.getCodCentinela() + ",";
		while(vacunaPersona.removerTopeDosis(fecha)){
			fechasAux.Insertar(fecha);
		}
		while(fechasAux.Remover(fecha)){
			linea += fecha.getFecha();
			if(!fechasAux.Vacia()){
				linea += ",";
			}
		}
		if(!personasAux.Vacia()) linea += "\n";
		archCensoPersonas << linea;
	}
	vGeneral.CerrarArchivoSalida(archCensoPersonas);
	vGeneral.ImprimirMensaje("\n DATOS CensoPersonas.txt GUARDADOS EXITOSAMENTE");
	vGeneral.Limpiar();

	ofstream archMunicipios;
	ofstream archCentinelas;
	ofstream archVacunas;
	ofstream archCubiculos;
	ofstream archColaPacientes;

	while (!vGeneral.AbrirArchivoSalida(archMunicipios, "Datos/Municipios.txt"))
	{
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo Municipios.txt\n" + instructions);
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}
	vGeneral.ImprimirMensaje("\n GUARDANDO DATOS Municipios.txt...");

	while (!vGeneral.AbrirArchivoSalida(archCentinelas, "Datos/Centinelas.txt"))
	{
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo Centinelas.txt\n" + instructions);
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}
	vGeneral.ImprimirMensaje("\n GUARDANDO DATOS Centinelas.txt...");

	while (!vGeneral.AbrirArchivoSalida(archCubiculos, "Datos/Cubiculos.txt"))
	{
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo Cubiculos.txt\n" + instructions);
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}
	vGeneral.ImprimirMensaje("\n GUARDANDO DATOS Cubiculos.txt...");

	while (!vGeneral.AbrirArchivoSalida(archColaPacientes, "Datos/ColasPacientes.txt"))
	{
		vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo ColasPacientes.txt\n" + instructions);
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}
	vGeneral.ImprimirMensaje("\n GUARDANDO DATOS ColasPacientes.txt...");

	while (!estado.esVacio())
	{
		linea = "";
		estado.removerPrimerMunicipio(municipio);
		linea += municipio.getCodigo() + ",";
		linea += municipio.getNombre();
		if(!estado.esVacio()) linea += "\n";
		archMunicipios << linea;

		while (!municipio.esVacio())
		{
			linea = "";
			municipio.removerPrimerCentinela(centinela);
			linea += centinela.getCodigo() + ",";
			linea += municipio.getCodigo();
			if(!(estado.esVacio() && municipio.esVacio())) linea += "\n";
			archCentinelas << linea;

			while(!centinela.esVacia())
			{
				linea = "";
				centinela.removerPrimerCubiculo(cubiculo);
				linea += cubiculo.getCodigo() + ",";
				linea += centinela.getCodigo();
				if(!(estado.esVacio() && municipio.esVacio() && centinela.esVacia())) linea += "\n";
				archCubiculos << linea;

				while(!cubiculo.esVacia())
				{
					cubiculo.removerPrimerPaciente(cedula);
					cubiculoAux.setCodigo(cubiculo.getCodigo());
					cubiculoAux.agregarPaciente(cedula);
				}
				while(!cubiculoAux.esVacia())
				{
					linea = "";
					cubiculoAux.removerPrimerPaciente(cedula);
					linea += cedula + ",";
					linea += cubiculoAux.getCodigo();
					if(!(estado.esVacio() && municipio.esVacio() && centinela.esVacia() && cubiculoAux.esVacia())) linea += "\n";
					archColaPacientes << linea;
				}
			}
		}
	}

	vGeneral.CerrarArchivoSalida(archColaPacientes);
	vGeneral.CerrarArchivoSalida(archCubiculos);
	vGeneral.CerrarArchivoSalida(archCentinelas);
	vGeneral.CerrarArchivoSalida(archMunicipios);

	vGeneral.ImprimirMensaje("\n DATOS ColasPacientes.txt CARGADOS EXITOSAMENTE");
	vGeneral.ImprimirMensaje("\n DATOS Cubiculos.txt CARGADOS EXITOSAMENTE");
	vGeneral.ImprimirMensaje("\n DATOS VacunasEnExistencia.txt CARGADOS EXITOSAMENTE");
	vGeneral.ImprimirMensaje("\n DATOS Centinelas.txt CARGADOS EXITOSAMENTE");
	vGeneral.ImprimirMensaje("\n DATOS Municipios.txt CARGADOS EXITOSAMENTE");
	vGeneral.Limpiar();
}

void Controlador::recibirVacunas()
{

	IMunicipio imunicipio;
	IAlmacen ialmacen;
	ICentinela icentinela;
	MAlmacenVacuna almacen;
	MCentinela centinelas;
	MMunicipio municipio;

	string codmuni, codcenti, marca;
	int cant;

	vGeneral.ImprimirMensaje("==========   R E C I B I R __ V A C U N A S   ==========");
	imunicipio.ImprimirListaMunicipio(estado);
	codmuni = vGeneral.LeerString("\n Codigo de Municipio: ");
	municipio.setCodigo(codmuni);

	while (!estado.removerMunicipio(codmuni, municipio))
	{
		vGeneral.ImprimirMensaje("Error: El municipio solicitado no existe \n\n");
		vGeneral.Pausa();
		vGeneral.Limpiar();

		imunicipio.ImprimirListaMunicipio(estado);
		codmuni = vGeneral.LeerString("\n Ingrese el codigo del municipio: ");
	}

	vGeneral.Limpiar();

	icentinela.ImprimirListaCentinela(municipio);
	codcenti = vGeneral.LeerString("\n Ingrese el codigo del centinela: ");

	while (!municipio.removerCentinela(codcenti, centinelas))
	{
		vGeneral.ImprimirMensaje("Error: El centinela solicitado no existe \n\n");
		vGeneral.Pausa();
		vGeneral.Limpiar();

		icentinela.ImprimirListaCentinela(municipio);
		codcenti = vGeneral.LeerString("\n Ingrese el codigo del centinela: ");
	}

	vGeneral.Limpiar();

	ialmacen.ImprimirVacunas(centinelas);

	vGeneral.ImprimirMensaje("Nota: Puede agregar marcas que no esten en la lista \n");
	marca = vGeneral.LeerString("\nEscribir marca: ");

	while (!centinelas.removerVacuna(marca, almacen))
	{
		vGeneral.ImprimirMensaje("La marca solicitada no existe \n");

		int rpta = vGeneral.LeerValidarNro("\nDesea Agregarla? [1]. SI, [2].No:  ", 1, 2);

		if (rpta == 1)
		{
			almacen.setMarca(marca);
			almacen.setCantidad(0);
			centinelas.agregarVacuna(almacen);
		}
		else
		{
			vGeneral.Limpiar();
			ialmacen.ImprimirVacunas(centinelas);
			marca = vGeneral.LeerString("\n Ingrese la marca de la vacuna: ");
			almacen.setMarca(marca);
		}
	}
	centinelas.agregarVacuna(almacen);
	cant = vGeneral.LeerValidarNro("\n Cantidad: ", 0, INT_MAX);

	while (cant % 3 != 0)
	{
		vGeneral.ImprimirMensaje("\n La cantidad Ingresada debe ser Multiplo de 3!\n");
		cant = vGeneral.LeerValidarNro("\n Cantidad: ", 0, INT_MAX);
	}
	centinelas.aumentarVacunas(marca, cant);
	vGeneral.ImprimirMensaje("\n Cantidad Ingresada Exitosamente!\n");
	municipio.agregarCentinela(centinelas);
	estado.agregarMunicipio(municipio);
	vGeneral.Pausa();
	vGeneral.Limpiar();
}

void Controlador::procesar()
{
	/**
	 * Antes de esto, se cargan los datos justo al iniciar el programa
	 *
	 * MOSTRAR MENU INICIAL 1
	 *  M E N U
	 *  1) Administrar
	 *  2) Recibir Vacunas
	 *  3) Iniciar Proceso de Vacunacion
	 *  4) Salir
	 */
	int rpta;
	while (rpta != 4)
	{
		vGeneral.ImprimirEncabezado("M E N U", "_______");
		vGeneral.ImprimirMensaje("1) Administrar");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("2) Recibir Vacunas");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("3) Iniciar Proceso de Vacunacion");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("4) Salir");
		vGeneral.ImprimirLineasBlanco(1);

		rpta = vGeneral.LeerNro("Respuesta: ");
		vGeneral.Limpiar();
		switch (rpta)
		{
		case 1:
			procesarAdmin();
			break;
		case 2:
			recibirVacunas();
			break;
		case 3:
			procesar2();
			break;
		case 4:
			return;
		default:
			vGeneral.ImprimirMensaje("Por favor ingrese una opcion valida\n");
			vGeneral.Pausa();
			vGeneral.Limpiar();
			break;
		}
	}
}

void Controlador::procesar2()
{
	int rpta;
	while (rpta != 10)
	{
		vGeneral.ImprimirEncabezado("M E N U  V A C U N A C I O N",
									"_______  ___________________");
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
		vGeneral.ImprimirMensaje("6) Consultar Colas");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("7) Incluir Paciente a una Cola");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("8) Sacar Paciente de una Cola");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("9) Procesar Paciente");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("10) Salir");
		vGeneral.ImprimirLineasBlanco(1);

		rpta = vGeneral.LeerNro("Respuesta: ");
		vGeneral.Limpiar();
		switch (rpta)
		{
		case 1:

			break;
		case 2:
			consultarMunicipios();
			break;
		case 3:
			consultarCentinelas();
			break;
		case 4:
			consultarCubiculos();
			break;
		case 5:
			consultarVacunas();
			break;
		case 6:
			consultarColas();
			break;
		case 7:
			incluirPacienteACola();
			break;
		case 8:
			SacarPacienteDeCola();
			break;
		case 9:
			procesarPaciente();
			break;
		case 10:
			return;
		default:
			vGeneral.ImprimirMensaje("Por favor ingrese una opcion valida\n");
			vGeneral.Pausa();
			vGeneral.Limpiar();
			break;
		}
	}
}

void Controlador::procesarAdmin(){
	int rpta;
	while (rpta != 4)
	{
		vGeneral.ImprimirEncabezado("M E N U  A D M I N I S T R A C I O N",
									"_______  ___________________________");
		vGeneral.ImprimirMensaje("1) Modificar");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("2) Eliminar");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("3) Agregar");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("4) Salir");
		vGeneral.ImprimirLineasBlanco(1);

		rpta = vGeneral.LeerNro("Respuesta: ");
		vGeneral.Limpiar();
		switch (rpta)
		{
		case 1:
			menuModificar();
			break;
		case 2:
			menuEliminar();
			break;
		case 3:
			menuAgregar();
			break;
		case 4:
			return;
		default:
			vGeneral.ImprimirMensaje("Por favor ingrese una opcion valida\n");
			vGeneral.Pausa();
			vGeneral.Limpiar();
			break;
		}
	}
}
void Controlador::menuEliminar(){
	int rpta;
	while (rpta != 5)
	{
		vGeneral.ImprimirEncabezado("M E N U  E L I M I N A R",
									"_______  _______________");
		vGeneral.ImprimirMensaje("1) Eliminar Municipio");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("2) Eliminar Centinela");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("3) Eliminar Cubiculo");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("4) Eliminar Vacuna");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("5) Salir");
		vGeneral.ImprimirLineasBlanco(1);

		rpta = vGeneral.LeerNro("Respuesta: ");
		vGeneral.Limpiar();
		switch (rpta)
		{
		case 1: eliminarMunicipio();
			break;
		case 2:
			EliminarCentinela();
			break;
		case 3:
			eliminarCubiculo();
			break;
		case 4:
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
void Controlador::eliminarMunicipio()
{
	MMunicipio municipio;
	IMunicipio Imunicipio;

    vGeneral.Limpiar();
    Imunicipio.ImprimirListaMunicipio(estado);
    string municipioCodigo = vGeneral.LeerString("Ingrese el codigo del municipio: ");
    municipio.setCodigo(municipioCodigo);

    while (!estado.removerMunicipio(municipioCodigo, municipio)){
    	vGeneral.ImprimirMensaje("Error: El municipio solicitado no existe");
    	vGeneral.Pausa();
    	vGeneral.Limpiar();

    	Imunicipio.ImprimirListaMunicipio(estado);
    	municipioCodigo = vGeneral.LeerString("Ingrese el codigo del Municipio: ");
    };

    vGeneral.ImprimirLineasBlanco(1);

    if(municipio.PersonasMunicipio(municipio)!=0){
    	vGeneral.ImprimirMensaje("Error: El municipio tiene pacientes en cola");
    	estado.agregarMunicipio(municipio);
    	vGeneral.Pausa();
    	vGeneral.Limpiar();
    }
    else{
    	vGeneral.ImprimirMensaje("El Municipio y todos sus contenidos fueron eliminados exitosamente");
    	vGeneral.Pausa();
    	vGeneral.Limpiar();
    }

    vGeneral.ImprimirLineasBlanco(1);

}//final metodo

void Controlador::menuModificar(){
	int rpta;
	while (rpta != 5)
	{
		vGeneral.ImprimirEncabezado("M E N U  M O D I F I C A R",
									"_______  _________________");
		vGeneral.ImprimirMensaje("1) Modificar Municipio");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("2) Modificar Persona");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("3) Modificar Expediente");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("4) Modificar Vacuna");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("5) Salir");
		vGeneral.ImprimirLineasBlanco(1);

		rpta = vGeneral.LeerNro("Respuesta: ");
		vGeneral.Limpiar();
		switch (rpta)
		{
		case 1: modificarMunicipio();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
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

void Controlador::modificarMunicipio(){

	MMunicipio municipio;
	IMunicipio Imunicipio;

	vGeneral.Limpiar();
	Imunicipio.ImprimirListaMunicipio(estado);
	string municipioCodigo = vGeneral.LeerString("Ingrese el codigo del municipio: ");
	municipio.setCodigo(municipioCodigo);

		while (!estado.removerMunicipio(municipioCodigo, municipio))
		{
			vGeneral.ImprimirMensaje("Error: El municipio solicitado no existe");
			vGeneral.Pausa();
			vGeneral.Limpiar();

			Imunicipio.ImprimirListaMunicipio(estado);
			municipioCodigo = vGeneral.LeerString("Ingrese el codigo del Municipio: ");
		};

	vGeneral.Limpiar();
	vGeneral.ImprimirLineasBlanco(1);
	vGeneral.ImprimirString2("El Nombre del Municipio seleccionado es: ", municipio.getNombre());
	vGeneral.ImprimirLineasBlanco(1);

	string nombreMunicipio = vGeneral.LeerString("Ingrese el nuevo nombre del Municipio: ");
	municipio.setNombre(nombreMunicipio);
	vGeneral.Pausa();
	vGeneral.Limpiar();
	vGeneral.ImprimirLineasBlanco(1);

	vGeneral.ImprimirMensaje("Nombre modificado exitosamente \n\n");
	estado.agregarMunicipio(municipio);

}

void Controlador::menuAgregar(){
	int rpta;
	while (rpta != 5)
	{
		vGeneral.ImprimirEncabezado("M E N U  A G R E G A R",
									"_______  _____________");
		vGeneral.ImprimirMensaje("1) Agregar Municipio");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("2) Agregar Centinela");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("3) Agregar Cubiculo");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("4) Salir");
		vGeneral.ImprimirLineasBlanco(1);

		rpta = vGeneral.LeerNro("Respuesta: ");
		vGeneral.Limpiar();
		switch (rpta)
		{
		case 1:
			agregarMunicipio();
			break;
		case 2:
			agregarCentinela();
			break;
		case 3:
			agregarCubiculo();
			break;
		case 4:
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
}

void Controlador::agregarCubiculo(){
	MMunicipio municipio;
	MCentinela centinela;
	MCubiculo cubiculo;
	IMunicipio Imunicipio;
	ICentinela Icentinela;
	ICubiculo Icubiculo;

	vGeneral.Limpiar();
	do{
		Imunicipio.ImprimirListaMunicipio(estado);
		string codigoMunicipio = vGeneral.LeerString("Ingrese el codigo del municipio: ");
		if(estado.removerMunicipio(codigoMunicipio, municipio)){
			vGeneral.Limpiar();
			break;
		}
		vGeneral.ImprimirMensaje("Error: El municipio solicitado no existe\n");
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}while(true);

	do{
		Icentinela.ImprimirListaCentinela(municipio);
		string codigoCentinela = vGeneral.LeerString("Ingrese el codigo del centinela: ");
		centinela.setCodigo(codigoCentinela);
		if(municipio.removerCentinela(codigoCentinela, centinela)){
			vGeneral.Limpiar();
			break;
		}
		vGeneral.ImprimirMensaje("Error: El centinela solicitado no existe\n");
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}while(true);

	do{
		Icubiculo.ImprimirListaCubiculo(centinela);
		string codigoCubiculo = vGeneral.LeerString("Ingrese el codigo del cubiculo: ");
		cubiculo.setCodigo(codigoCubiculo);
		if(centinela.removerCubiculo(codigoCubiculo, cubiculo)){
			vGeneral.ImprimirMensaje("Error: El cubiculo ya existe\n");
			vGeneral.Pausa();
			vGeneral.Limpiar();
			centinela.agregarCubiculo(cubiculo);
		}
		else{
			centinela.agregarCubiculo(cubiculo);
			municipio.agregarCentinela(centinela);
			estado.agregarMunicipio(municipio);
			vGeneral.ImprimirMensaje("Cubiculo agregado exitosamente\n\n");
			vGeneral.Pausa();
			vGeneral.Limpiar();
			break;
		}
	}while(true);
}

void Controlador::agregarCentinela()
{
	MMunicipio municipio;
	IMunicipio Imunicipio;
	ICentinela Icentinela;
	ICubiculo Icubiculo;

	vGeneral.Limpiar();
	Imunicipio.ImprimirListaMunicipio(estado);
	string municipioCodigo = vGeneral.LeerString("Ingrese el codigo del municipio: ");
	municipio.setCodigo(municipioCodigo);

	while (!estado.removerMunicipio(municipioCodigo, municipio))
	{
		vGeneral.ImprimirMensaje("Error: El municipio solicitado no existe");
		vGeneral.Pausa();
		vGeneral.Limpiar();

		Imunicipio.ImprimirListaMunicipio(estado);
		municipioCodigo = vGeneral.LeerString("Ingrese el codigo del Municipio: ");
	};

	vGeneral.Limpiar();
	int numCenti = vGeneral.LeerNro("Ingrese el numero de Centinelas que desea agregar: ");
	MCentinela centinela;
	for (int i = 0; i < numCenti; ++i)
	{

		Icentinela.ImprimirListaCentinela(municipio);
		string centiCodigo = vGeneral.LeerString("Ingrese el codigo del Centinela: ");
		centinela.setCodigo(centiCodigo);

		while (municipio.removerCentinela(centiCodigo, centinela))
		{
			vGeneral.ImprimirMensaje("Error: La centinela ya existe \n\n");
			vGeneral.Pausa();
			vGeneral.Limpiar();
			municipio.agregarCentinela(centinela);
			Icentinela.ImprimirListaCentinela(municipio);
			centiCodigo = vGeneral.LeerString("Ingrese el codigo de la centinela: ");
			centinela.setCodigo(centiCodigo);
		}

			int numCubiculo = vGeneral.LeerNro("Ingrese el numero de Cubiculos que desea agregar en el Centinela: ");
			MCubiculo cubiculo;


			while(numCubiculo<3){

				vGeneral.ImprimirMensaje("Error: Se deben ingresar 3 cubiculos minimo \n\n");
				vGeneral.Pausa();
				vGeneral.Limpiar();
				numCubiculo = vGeneral.LeerNro("Ingrese el numero de Cubiculos que desea agregar en el Centinela: ");
			}

			for (int j = 0; j < numCubiculo; ++j)
			{
			centinela.removerPrimerCubiculo(cubiculo);
			}

			for (int j = 0; j < numCubiculo; ++j)
			{

				string cubiCodigo = vGeneral.LeerString("Ingrese el codigo del Cubiculo: ");
				cubiculo.setCodigo(cubiCodigo);


				while(centinela.removerCubiculo(cubiCodigo,cubiculo)){
					vGeneral.ImprimirMensaje("Error: El cubiculo ya existe \n\n");
					vGeneral.Pausa();
					vGeneral.Limpiar();
					centinela.agregarCubiculo(cubiculo);
					cubiCodigo = vGeneral.LeerString("Ingrese el codigo del Cubiculo: ");
					cubiculo.setCodigo(cubiCodigo);

				}

				if (centinela.agregarCubiculo(cubiculo))
				{
					vGeneral.ImprimirMensaje("Cubiculo agregado exitosamente \n\n");

				} //final del else if de cubiculo

				}//final for cubiculo
			if (municipio.agregarCentinela(centinela))
						{
							vGeneral.ImprimirMensaje("Centinela agregado exitosamente \n\n");
							vGeneral.ImprimirLineasBlanco(1);
							vGeneral.Pausa();
							vGeneral.Limpiar();
						}//final else cubiculo
			}//final for centinela


	estado.agregarMunicipio(municipio);
	vGeneral.ImprimirLineasBlanco(1);
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

void Controlador::consultarPersona()
{
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

void Controlador::consultarMunicipios()
{
    VGeneral vgeneral;
	MMunicipio municipio;
	MCentinela centinela;
	IMunicipio Imunicipio;
	ICentinela Icentinela;

	vgeneral.Limpiar();
        Imunicipio.ConsultaMunicipio(estado);
        vgeneral.Pausa();
	vgeneral.Limpiar();
}

void Controlador::consultarCentinelas()
{
	VGeneral vgeneral;
	MMunicipio municipio;
	MCentinela centinela;
	IMunicipio Imunicipio;
	ICentinela Icentinela;

	vgeneral.Limpiar();
	Imunicipio.ImprimirListaMunicipio(estado);
	string municipioCodigo = vgeneral.LeerString("\n Ingrese el codigo del municipio: ");

	while (!estado.removerMunicipio(municipioCodigo, municipio))
	{
		vgeneral.ImprimirMensaje("Error: El municipio solicitado no existe \n\n");
		vgeneral.Pausa();
		vgeneral.Limpiar();

		Imunicipio.ImprimirListaMunicipio(estado);
		municipioCodigo = vgeneral.LeerString("\n Ingrese el codigo del municipio: ");
	};

	vgeneral.Limpiar();

	Icentinela.ImprimirListaCentinelaConsultar(municipio);
	vgeneral.Pausa();
	vgeneral.Limpiar();

	//municipio.agregarCentinela(centinela);
	estado.agregarMunicipio(municipio);
}

void Controlador::consultarCubiculos()
{
	VGeneral vgeneral;
	MMunicipio municipio;
	MCentinela centinela;
	IMunicipio Imunicipio;
	ICentinela Icentinela;
	ICubiculo Icubiculo;

	vgeneral.Limpiar();
	Imunicipio.ImprimirListaMunicipio(estado);
	string municipioCodigo = vgeneral.LeerString("\n Ingrese el codigo del municipio: ");

	while (!estado.removerMunicipio(municipioCodigo, municipio))
	{
		vgeneral.ImprimirMensaje("Error: El municipio solicitado no existe \n\n");
		vgeneral.Pausa();
		vgeneral.Limpiar();

		Imunicipio.ImprimirListaMunicipio(estado);
		municipioCodigo = vgeneral.LeerString("\n Ingrese el codigo del municipio: ");
	};

	vgeneral.Limpiar();

	Icentinela.ImprimirListaCentinela(municipio);
	string centinelaCodigo = vgeneral.LeerString("\n Ingrese el codigo del centinela: ");

	while (!municipio.removerCentinela(centinelaCodigo, centinela))
	{
		vgeneral.ImprimirMensaje("Error: El centinela solicitado no existe \n\n");
		vgeneral.Pausa();
		vgeneral.Limpiar();

		Icentinela.ImprimirListaCentinela(municipio);
		centinelaCodigo = vgeneral.LeerString("\n Ingrese el codigo del centinela: ");
	};

	Icubiculo.ReportarCubiculo(centinela);

	municipio.agregarCentinela(centinela);
	estado.agregarMunicipio(municipio);
}

void Controlador::consultarColas()
{
	VGeneral vgeneral;
	MMunicipio municipio;
	MCentinela centinela;
	MCubiculo cubiculo;
	IMunicipio Imunicipio;
	ICentinela Icentinela;
	ICubiculo Icubiculo;

	vgeneral.Limpiar();
	vGeneral.ImprimirMensaje("==========   CONSULTAR  COLA   =========");
	vGeneral.ImprimirLineasBlanco(2);
	Imunicipio.ImprimirListaMunicipio(estado);
	string municipioCodigo = vgeneral.LeerString("\n Ingrese el codigo del municipio: ");

	while (!estado.removerMunicipio(municipioCodigo, municipio))
	{
		vgeneral.ImprimirMensaje("Error: El municipio solicitado no existe \n\n");
		vgeneral.Pausa();
		vgeneral.Limpiar();

		Imunicipio.ImprimirListaMunicipio(estado);
		municipioCodigo = vgeneral.LeerString("\n Ingrese el codigo del municipio: ");
	};

	vgeneral.Limpiar();
	vGeneral.ImprimirLineasBlanco(1);
	vGeneral.ImprimirString("------MUNICIPIO: ", municipio.getNombre());
	vGeneral.ImprimirLineasBlanco(1);
	Icentinela.ImprimirListaCentinela(municipio);
	string centinelaCodigo = vgeneral.LeerString("\n Ingrese el codigo del centinela: ");

	while (!municipio.removerCentinela(centinelaCodigo, centinela))
	{
		vgeneral.ImprimirMensaje("Error: El centinela solicitado no existe \n\n");
		vgeneral.Pausa();
		vgeneral.Limpiar();

		Icentinela.ImprimirListaCentinela(municipio);
		centinelaCodigo = vgeneral.LeerString("\n Ingrese el codigo del centinela: ");
	};

	vgeneral.Limpiar();
	vGeneral.ImprimirLineasBlanco(1);
	vGeneral.ImprimirString("-------CENTINELA: ", centinela.getCodigo());
	vGeneral.ImprimirLineasBlanco(1);
	Icubiculo.ImprimirListaCubiculo(centinela);
	string cubiculoCodigo = vgeneral.LeerString("\n Ingrese el codigo del cubiculo: ");

	while (!centinela.removerCubiculo(cubiculoCodigo, cubiculo))
	{
		vgeneral.ImprimirMensaje("Error: El cubiculo solicitado no existe \n\n");
		vgeneral.Pausa();
		vgeneral.Limpiar();

		Icubiculo.ImprimirListaCubiculo(centinela);
		string cubiculoCodigo = vgeneral.LeerString("\n Ingrese el codigo del cubiculo: ");
	};

	vGeneral.ImprimirLineasBlanco(1);
	vgeneral.Limpiar();

	vGeneral.ImprimirLineasBlanco(1);
		int respuesta;
			while (respuesta != 4)
			{
				vGeneral.ImprimirLineasBlanco(1);
				vGeneral.ImprimirString("-------CUBICULO: ", cubiculo.getCodigo());
				vGeneral.ImprimirLineasBlanco(2);
				vGeneral.ImprimirEncabezado("Menu de Consulta en la cola",
											"___________________________");
				vGeneral.ImprimirMensaje("1) Pacientes con 1 dosis");
				vGeneral.ImprimirLineasBlanco(1);
				vGeneral.ImprimirMensaje("2) Pacientes con 2 dosis");
				vGeneral.ImprimirLineasBlanco(1);
				vGeneral.ImprimirMensaje("3) Totalidad de Pacientes");
				vGeneral.ImprimirLineasBlanco(1);
				vGeneral.ImprimirMensaje("4)  Salir");
				vGeneral.ImprimirLineasBlanco(1);

				respuesta = vGeneral.LeerNro("Respuesta: ");
				vGeneral.Limpiar();
				switch (respuesta)
				{
				case 1:
					vGeneral.ImprimirLineasBlanco(1);
					vGeneral.ImprimirString("-------CUBICULO: ", cubiculo.getCodigo());
					vGeneral.ImprimirLineasBlanco(1);
					Icubiculo.reportarPersonas1Dosis(listaExpedientes,listaPersonas,cubiculo);
					vGeneral.ImprimirLineasBlanco(1);
					vGeneral.Pausa();
					vGeneral.Limpiar();
					break;
				case 2:
					vGeneral.ImprimirLineasBlanco(1);
					vGeneral.ImprimirString("-------CUBICULO: ", cubiculo.getCodigo());
					vGeneral.ImprimirLineasBlanco(1);
					Icubiculo.reportarPersonas2Dosis(listaExpedientes,listaPersonas,cubiculo);
					vGeneral.ImprimirLineasBlanco(1);
					vGeneral.Pausa();
					vGeneral.Limpiar();
					break;
				case 3:
					vGeneral.ImprimirLineasBlanco(1);
					vGeneral.ImprimirString("-------CUBICULO: ", cubiculo.getCodigo());
					vGeneral.ImprimirLineasBlanco(1);
					Icubiculo.reportarPersonasDelaCola(listaPersonas,cubiculo);
					vGeneral.ImprimirLineasBlanco(1);
					vGeneral.Pausa();
					vGeneral.Limpiar();

					break;
				case 4:
					centinela.agregarCubiculo(cubiculo);
					municipio.agregarCentinela(centinela);
					estado.agregarMunicipio(municipio);
					return;

				default:
					vGeneral.ImprimirLineasBlanco(1);
					vGeneral.ImprimirMensaje("Por favor ingrese una opcion valida\n");
					vGeneral.Pausa();
					vGeneral.Limpiar();
					break;
				}
			}

	vGeneral.ImprimirLineasBlanco(1);
	vGeneral.Pausa();
	vGeneral.Limpiar();
}

void Controlador::consultarVacunas()
{
	IAlmacen ialmacen;
	IMunicipio imunicipio;
	ICentinela icentinela;
	MAlmacenVacuna almacen;
	MCentinela centinelas;
	MMunicipio municipio;

	string codmuni, marca, codcenti, codcubi;

	vGeneral.ImprimirMensaje("==========   C O N S U L T A R  V A C U N A S   ==========");

	imunicipio.ImprimirListaMunicipio(estado);
	codmuni = vGeneral.LeerString("\n Codigo de Municipio: ");
	municipio.setCodigo(codmuni);

	while (!estado.removerMunicipio(codmuni, municipio))
	{
		vGeneral.ImprimirMensaje("Error: El municipio solicitado no existe \n\n");
		vGeneral.Pausa();
		vGeneral.Limpiar();

		imunicipio.ImprimirListaMunicipio(estado);
		codmuni = vGeneral.LeerString("\n Ingrese el codigo del municipio: ");
	}

	vGeneral.Limpiar();

	icentinela.ImprimirListaCentinela(municipio);
	codcenti = vGeneral.LeerString("\n Ingrese el codigo del centinela: ");

	while (!municipio.removerCentinela(codcenti, centinelas))
	{
		vGeneral.ImprimirMensaje("Error: El centinela solicitado no existe \n\n");
		vGeneral.Pausa();
		vGeneral.Limpiar();

		icentinela.ImprimirListaCentinela(municipio);
		codcenti = vGeneral.LeerString("\n Ingrese el codigo del centinela: ");
	}

	ialmacen.ImprimirCantidadVacunas(centinelas);
	vGeneral.ImprimirLineasBlanco(2);
	vGeneral.Pausa();
	vGeneral.Limpiar();
	municipio.agregarCentinela(centinelas);
	estado.agregarMunicipio(municipio);
}

void Controlador::incluirPacienteACola()
{
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

	while (!estado.removerMunicipio(municipioCodigo, municipio))
	{
		vGeneral.ImprimirMensaje("Error: El municipio solicitado no existe \n\n");
		vGeneral.Pausa();
		vGeneral.Limpiar();

		Imunicipio.ImprimirListaMunicipio(estado);
		municipioCodigo = vGeneral.LeerString("\n Ingrese el codigo del municipio: ");
	};

	vGeneral.Limpiar();

	Icentinela.ImprimirListaCentinela(municipio);
	string centinelaCodigo = vGeneral.LeerString("\n Ingrese el codigo del centinela: ");

	while (!municipio.removerCentinela(centinelaCodigo, centinela))
	{
		vGeneral.ImprimirMensaje("Error: El centinela solicitado no existe \n\n");
		vGeneral.Pausa();
		vGeneral.Limpiar();

		Icentinela.ImprimirListaCentinela(municipio);
		centinelaCodigo = vGeneral.LeerString("\n Ingrese el codigo del centinela: ");
	};

	vGeneral.Limpiar();

	Icubiculo.ImprimirListaCubiculo(centinela);
	string cubiculoCodigo = vGeneral.LeerString("\n Ingrese el codigo del cubiculo: ");

	while (!centinela.removerCubiculo(cubiculoCodigo, cubiculo))
	{
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
	while (paciente != marca)
	{
		if (paciente == cedula)
		{
			encontrado = true;
		}
		cubiculo.agregarPaciente(paciente);
		cubiculo.removerPrimerPaciente(paciente);
	};

	vGeneral.Limpiar();
	if (encontrado)
	{
		vGeneral.ImprimirMensaje("Error: El paciente esta registrado en la cola \n");
	}
	else
	{
		if (cubiculo.agregarPaciente(cedula))
		{
			vGeneral.ImprimirMensaje("Paciente agregado satisfactoriamente \n");
		}
		else
		{
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

void Controlador::SacarPacienteDeCola()
{
	VGeneral vgeneral;
	MMunicipio municipio;
	MCentinela centinela;
	MCubiculo cubiculo;
	IMunicipio Imunicipio;
	ICentinela Icentinela;
	ICubiculo Icubiculo;

	vgeneral.Limpiar();
	vGeneral.ImprimirMensaje("==========   SACAR PACIENTE DE LA  COLA   =========");
	vGeneral.ImprimirLineasBlanco(2);
	Imunicipio.ImprimirListaMunicipio(estado);
	string municipioCodigo = vgeneral.LeerString("\n Ingrese el codigo del municipio: ");

	while (!estado.removerMunicipio(municipioCodigo, municipio))
	{
		vgeneral.ImprimirMensaje("Error: El municipio solicitado no existe \n\n");
		vgeneral.Pausa();
		vgeneral.Limpiar();

		Imunicipio.ImprimirListaMunicipio(estado);
		municipioCodigo = vgeneral.LeerString("\n Ingrese el codigo del municipio: ");
	};

	vgeneral.Limpiar();
	vGeneral.ImprimirLineasBlanco(1);
	vGeneral.ImprimirString("------MUNICIPIO: ", municipio.getNombre());
	vGeneral.ImprimirLineasBlanco(1);
	Icentinela.ImprimirListaCentinela(municipio);
	string centinelaCodigo = vgeneral.LeerString("\n Ingrese el codigo del centinela: ");

	while (!municipio.removerCentinela(centinelaCodigo, centinela))
	{
		vgeneral.ImprimirMensaje("Error: El centinela solicitado no existe \n\n");
		vgeneral.Pausa();
		vgeneral.Limpiar();

		Icentinela.ImprimirListaCentinela(municipio);
		centinelaCodigo = vgeneral.LeerString("\n Ingrese el codigo del centinela: ");
	};

	vgeneral.Limpiar();
	vGeneral.ImprimirLineasBlanco(1);
	vGeneral.ImprimirString("-------CENTINELA: ", centinela.getCodigo());
	vGeneral.ImprimirLineasBlanco(1);
	Icubiculo.ImprimirListaCubiculo(centinela);
	string cubiculoCodigo = vgeneral.LeerString("\n Ingrese el codigo del cubiculo: ");

	while (!centinela.removerCubiculo(cubiculoCodigo, cubiculo))
	{
		vgeneral.ImprimirMensaje("Error: El cubiculo solicitado no existe \n\n");
		vgeneral.Pausa();
		vgeneral.Limpiar();

		Icubiculo.ImprimirListaCubiculo(centinela);
		string cubiculoCodigo = vgeneral.LeerString("\n Ingrese el codigo del cubiculo: ");
	};

	vgeneral.Limpiar();
	vGeneral.ImprimirString("-------CUBICULO: ", cubiculo.getCodigo());
	Icubiculo.reportarPersonasDelaCola(listaPersonas,cubiculo);
	string cedulaPaciente = vgeneral.LeerString("\n Ingrese la cedula a eliminar: ");

	if (cubiculo.removerPaciente(cedulaPaciente))
	{
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("Paciente sacado exitosamente \n");
	}
	else
	{
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("El Paciente no pudo ser sacado \n");
	}

	centinela.agregarCubiculo(cubiculo);
	municipio.agregarCentinela(centinela);
	estado.agregarMunicipio(municipio);

	vGeneral.ImprimirLineasBlanco(1);
	vGeneral.Pausa();
	vGeneral.Limpiar();
}

void Controlador::procesarPaciente()
{
	MExpedienteVacunacion mExpediente;
	MMunicipio municipio;
	MCentinela centinela;
	MCubiculo cubiculo;
	IMunicipio Imunicipio;
	ICentinela Icentinela;
	ICubiculo Icubiculo;
	MAlmacenVacuna vacuna;
	Date date;
	string cedula = "", fecha;
	bool final = false;

	vGeneral.Limpiar();
	do{
		Imunicipio.ImprimirListaMunicipio(estado);
		string codigoMunicipio = vGeneral.LeerString("Ingrese el codigo del municipio: ");
		if(estado.removerMunicipio(codigoMunicipio, municipio)){
			vGeneral.Limpiar();
			break;
		}
		vGeneral.ImprimirMensaje("Error: El municipio solicitado no existe\n");
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}while(true);

	do{
		Icentinela.ImprimirListaCentinela(municipio);
		string codigoCentinela = vGeneral.LeerString("Ingrese el codigo del centinela: ");
		centinela.setCodigo(codigoCentinela);
		if(municipio.removerCentinela(codigoCentinela, centinela)){
			vGeneral.Limpiar();
			break;
		}
		vGeneral.ImprimirMensaje("Error: El centinela solicitado no existe\n");
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}while(true);

	do{
		Icubiculo.ImprimirListaCubiculo(centinela);
		string codigoCubiculo = vGeneral.LeerString("Ingrese el codigo del cubiculo: ");
		if(centinela.removerCubiculo(codigoCubiculo, cubiculo)){
			vGeneral.Limpiar();
			break;
		}
		vGeneral.ImprimirMensaje("Error: El cubiculo solicitado no existe\n");
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}while(true);

	cubiculo.removerPrimerPaciente(cedula);
	if(cedula != ""){
		if(listaExpedientes.removerExpediente(cedula, mExpediente)){
			//A
			if(mExpediente.getCodCentinela() == centinela.getCodigo()){
				if(centinela.removerVacunaLote(mExpediente.getVacunaTomada(), mExpediente.getLote(),vacuna))
				{
					fecha = vGeneral.LeerString("Ingrese la fecha (dd/mm/aaaa): ");
					date.setFecha(fecha);
					Date ultimaDosisDate;
					mExpediente.removerTopeDosis(ultimaDosisDate);
					mExpediente.AgregarNuevaDosis(ultimaDosisDate);
					int diferenciaDias = ultimaDosisDate.DiferenciaDias(date);
					if(diferenciaDias >= 90)
					{
						final = true;
					}
					else
					{
						Date sigFechaEstipulada = mExpediente.getSigFechaEstipulada();
						vGeneral.ImprimirMensaje("Lo sentimos, pero no han pasado los dias para recibir su siguiente dosis\n por favor regrese el dia " + sigFechaEstipulada.getFecha());
						vGeneral.Pausa();
						vGeneral.Limpiar();
					}
				}
				else
				{
					vGeneral.ImprimirMensaje("Lo sentimos, pero no quedan reservas de su vacuna disponibles\n");
					vGeneral.Pausa();
					vGeneral.Limpiar();
				}
			}
			else{
				vGeneral.ImprimirMensaje("Su centinela correspondiente es el " + mExpediente.getCodCentinela() + "\nPor favor, atienda a su centinela asignada\n");
				vGeneral.Pausa();
				vGeneral.Limpiar();
			}
			listaExpedientes.agregarExpediente(mExpediente);
		}
		else{
			//B
			string nombre, apellido, cedula, marcaVacuna;
			vGeneral.Limpiar();
			vGeneral.ImprimirEncabezado("Registro de Persona",
										"======== == =======");
			nombre = vGeneral.LeerString("Nombre: ");
			apellido = vGeneral.LeerString("Apellido: ");
			cedula = vGeneral.LeerString("Cedula: ");
			MPersona personaActual(nombre, apellido, cedula);
			MExpedienteVacunacion expedienteVacunaActual;
		}
	}
	else{
		vGeneral.ImprimirMensaje("No existen personas en cola para este cubiculo\n");
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}

	if(final)
	{
		mExpediente.AgregarNuevaDosis(date);
		vacuna.setcantReservada(vacuna.getcantReservada() - 1);
	}
	centinela.agregarVacuna(vacuna);
	centinela.agregarCubiculo(cubiculo);
	municipio.agregarCentinela(centinela);
	estado.agregarMunicipio(municipio);
	listaExpedientes.agregarExpediente(mExpediente);
	return;

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

void Controlador::eliminarCubiculo(){
	VGeneral vgeneral;
	MMunicipio municipio;
	MCentinela centinela;
	MCubiculo cubiculo;
	IMunicipio Imunicipio;
	ICentinela Icentinela;
	ICubiculo Icubiculo;

	vgeneral.Limpiar();
	vGeneral.ImprimirMensaje("==========   ELIMINAR CUBICULO   =========");
	vGeneral.ImprimirLineasBlanco(2);
	Imunicipio.ImprimirListaMunicipio(estado);
	string municipioCodigo = vgeneral.LeerString("\n Ingrese el codigo del municipio: ");

	while (!estado.removerMunicipio(municipioCodigo, municipio))
	{
		vgeneral.ImprimirMensaje("Error: El municipio solicitado no existe \n\n");
		vgeneral.Pausa();
		vgeneral.Limpiar();

		Imunicipio.ImprimirListaMunicipio(estado);
		municipioCodigo = vgeneral.LeerString("\n Ingrese el codigo del municipio: ");
	};

	vgeneral.Limpiar();
	vGeneral.ImprimirLineasBlanco(1);
	vGeneral.ImprimirString("------MUNICIPIO: ", municipio.getNombre());
	vGeneral.ImprimirLineasBlanco(1);
	Icentinela.ImprimirListaCentinela(municipio);
	string centinelaCodigo = vgeneral.LeerString("\n Ingrese el codigo del centinela: ");

	while (!municipio.removerCentinela(centinelaCodigo, centinela))
	{
		vgeneral.ImprimirMensaje("Error: El centinela solicitado no existe \n\n");
		vgeneral.Pausa();
		vgeneral.Limpiar();

		Icentinela.ImprimirListaCentinela(municipio);
		centinelaCodigo = vgeneral.LeerString("\n Ingrese el codigo del centinela: ");
	};

	vgeneral.Limpiar();
	vGeneral.ImprimirLineasBlanco(1);
	vGeneral.ImprimirString("-------CENTINELA: ", centinela.getCodigo());
	vGeneral.ImprimirLineasBlanco(1);
	Icubiculo.ImprimirListaCubiculo(centinela);

	if (centinela.totalCubiculos()<=3)
	{
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirMensaje("Error: Este centinela tiene la cantidad minima de cubiculos \nen el, no puedes eliminar ningun cubiculo \n");
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}
	else
 {
	string cubiculoCodigo = vgeneral.LeerString("\n Ingrese el codigo del cubiculo a Eliminar: ");

	while (!centinela.removerCubiculo(cubiculoCodigo, cubiculo))
	{
		vgeneral.ImprimirMensaje("Error: El cubiculo solicitado no existe \n\n");
		vgeneral.Pausa();
		vgeneral.Limpiar();

		Icubiculo.ImprimirListaCubiculo(centinela);
		string cubiculoCodigo = vgeneral.LeerString("\n Ingrese el codigo del cubiculo a Eliminar: ");
	}

	if (!cubiculo.esVacia())
		{
			vGeneral.ImprimirMensaje("Error: El cubiculo no puede ser eliminado por tener pacientes en la cola \n");
			centinela.agregarCubiculo(cubiculo);
		}
		else
		{
			vGeneral.ImprimirMensaje("Cubiculo eliminado satisfactoriamente \n");
         }

 }



	municipio.agregarCentinela(centinela);
	estado.agregarMunicipio(municipio);

	vGeneral.ImprimirLineasBlanco(1);
	vGeneral.Pausa();
	vGeneral.Limpiar();
}

void Controlador::EliminarCentinela(){
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

    if(centinela.PersonasCentinela(centinela)==0){
      vgeneral.ImprimirMensaje("Se elimino de forma exitosa el centienla " + centinelaCodigo + "\n");
      vgeneral.Pausa();
      vgeneral.Limpiar();
    }
    else{
      municipio.agregarCentinela(centinela);
      vgeneral.ImprimirMensaje("No se pudo eliminar el Centinela debido a que aun \nhay personas en cola dentro"+centinelaCodigo+"\n");
      vgeneral.Pausa();
      vgeneral.Limpiar();
    }

    estado.agregarMunicipio(municipio);
}
