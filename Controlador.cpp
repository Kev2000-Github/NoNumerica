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
			vacunaPersona.setLote(lineaActual[5]);
			for (int i = 6; i < lineaActual.size(); i++)
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
		ifstream archInfoVacunas;

		while (!vGeneral.AbrirArchivoEntrada(archInfoVacunas, "Datos/infoVacunas.txt"))
					{
						vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo InfoVacunas.txt\n" + instructions);
						vGeneral.Pausa();
						vGeneral.Limpiar();
					}
					vGeneral.ImprimirMensaje("\n CARGANDO DATOS InfoVacunas.txt...");

					while (!vGeneral.FinArchivo(archInfoVacunas))
						{

							string lineaInfVacuna = vGeneral.LeerLineaArchivo(archInfoVacunas);
							lineaActual = vGeneral.Split(lineaInfVacuna, ',');
							string marca = lineaActual[0];
							string dosis = lineaActual[1];
							lineaActual.clear();
		                    MInfoVacunas info;
							info.setMarca(marca);
							int cantidadDosis = vGeneral.parseInt(dosis);
							info.setNroDosis(cantidadDosis);
			                estado.agregarInfoVacunas(info);


						}
						vGeneral.CerrarArchivoEntrada(archInfoVacunas);
						vGeneral.ImprimirMensaje("\n DATOS InfoVacunas.txt CARGADOS EXITOSAMENTE");
						vGeneral.Limpiar();



		while (!vGeneral.AbrirArchivoEntrada(archMunicipios, "Datos/Municipios.txt"))
		{
			vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo Municipios.txt\n" + instructions);
			vGeneral.Pausa();
			vGeneral.Limpiar();
		}
		vGeneral.ImprimirMensaje("\n CARGANDO DATOS Municipios.txt...");


		while (!vGeneral.AbrirArchivoEntrada(archInfoVacunas, "Datos/infoVacunas.txt"))
			{
				vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo InfoVacunas.txt\n" + instructions);
				vGeneral.Pausa();
				vGeneral.Limpiar();
			}
			vGeneral.ImprimirMensaje("\n CARGANDO DATOS InfoVacunas.txt...");


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
									if(lineaVacuna != "")
									{
										lineaActual = vGeneral.Split(lineaVacuna, ',');
										string marca = lineaActual[0];
										string cant = lineaActual[1];
										string cantR =lineaActual[2];
										string vacunaCent = lineaActual[3];
										string lote = lineaActual[4];
										lineaActual.clear();
										if (vacunaCent == centinelaCod)
										{
											MAlmacenVacuna vacuna;
											vacuna.setMarca(marca);
											int cantidad = vGeneral.parseInt(cant);
											int cantReser = vGeneral.parseInt(cantR);
											vacuna.setcantDisponible(cantidad);
											vacuna.setcantReservada(cantReser);
											vacuna.setLote(lote);
											centinela.agregarVacuna(vacuna);
										}
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
		MAlmacenVacuna vacunas;
		Date fecha;
		string cedula;
		MInfoVacunas infoVacunas;

		ofstream archCensoPersonas;
		ofstream archInfoVacunas;

		string instructions = "Por favor, verifique que existe la carpeta /Datos \nen el directorio del ejecutable y dentro el txt correspondiente\n";
		while (!vGeneral.AbrirArchivoSalida(archCensoPersonas, "Datos/CensoPersonas.txt"))
		{
			vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo CensoPersonas.txt\n" + instructions);
			vGeneral.Pausa();
			vGeneral.Limpiar();
		}
		vGeneral.ImprimirMensaje("\n GUARDANDO DATOS CensoPersonas.txt...");

		while (!vGeneral.AbrirArchivoSalida(archInfoVacunas, "Datos/infoVacunas.txt"))
		{
			vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo infoVacunas.txt\n" + instructions);
			vGeneral.Pausa();
			vGeneral.Limpiar();
		}
		vGeneral.ImprimirMensaje("\n GUARDANDO DATOS infoVacunas.txt...");

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
			linea += vacunaPersona.getLote() +",";
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

		while(!estado.infVacio()){
			linea = "";
			estado.removerPrimerInfo(infoVacunas);
			int nroDosis = infoVacunas.getNroDosis();
			linea += infoVacunas.getMarca() + ",";
			linea += vGeneral.toString(nroDosis);
			if(!estado.infVacio()) linea += "\n";
			archInfoVacunas << linea;
		}

		vGeneral.CerrarArchivoSalida(archCensoPersonas);
		vGeneral.ImprimirMensaje("\n DATOS CensoPersonas.txt GUARDADOS EXITOSAMENTE");
		vGeneral.CerrarArchivoSalida(archInfoVacunas);
		vGeneral.ImprimirMensaje("\n DATOS infoVacunas.txt GUARDADOS EXITOSAMENTE");

		vGeneral.Limpiar();

		ofstream archMunicipios;
		ofstream archCentinelas;
		ofstream archVacunas;
		ofstream archCubiculos;
		ofstream archColaPacientes;
		ofstream archVacunasEnExistencia;

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

		while (!vGeneral.AbrirArchivoSalida(archVacunasEnExistencia, "Datos/VacunasEnExistencia.txt"))
		{
			vGeneral.ImprimirMensaje("\n ERROR! No existe el archivo VacunasEnExistencia.txt\n" + instructions);
			vGeneral.Pausa();
			vGeneral.Limpiar();
		}
		vGeneral.ImprimirMensaje("\n GUARDANDO DATOS VacunasEnExistencia.txt...");

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

					while(!centinela.PVacia()){
						centinela.removerPrimeraVacuna(vacunas);
						linea = "";
						linea += vacunas.getMarca() + ",";
						linea += vGeneral.toString(vacunas.getcantDisponible()) + ",";
						linea += vGeneral.toString(vacunas.getcantReservada()) + ",";
						linea += centinela.getCodigo() + ",";
						linea += vacunas.getLote();
						if(!(estado.esVacio() && municipio.esVacio() && centinela.esVacia() && centinela.PVacia())) linea += "\n";
						archVacunasEnExistencia << linea;
					}
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
		IInfoVacunas iinfo;
		MInfoVacunas info;


		string codmuni, codcenti, marca,lote;
		int cant,nrodosis;

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
		almacen.setMarca(marca);

		while (!centinelas.removerVacuna(marca, almacen))
		{
			vGeneral.ImprimirLineasBlanco(1);
			vGeneral.ImprimirMensaje("La marca solicitada no existe \n");

			int rpta = vGeneral.LeerValidarNro("\nDesea Agregarla? [1]. SI, [2].No:  ", 1, 2);

			if (rpta == 1)
			{
				almacen.setMarca(marca);
				almacen.setcantDisponible(0);
				almacen.setcantReservada(0);
				almacen.setLote("");
				if(!estado.removerInfoVacunas(marca,info)){
					nrodosis = vGeneral.LeerNro("\n Ingrese La dosis requeridad por la Vacuna: ");
					info.setMarca(marca);
					info.setNroDosis(nrodosis);
					estado.agregarInfoVacunas(info);
				}
				else{
					estado.agregarInfoVacunas(info);
				}

				break;
			}
			else
			{
				vGeneral.Limpiar();
				ialmacen.ImprimirVacunas(centinelas);
				marca = vGeneral.LeerString("\n Ingrese la marca de la vacuna: ");

			}

		}
		centinelas.agregarVacuna(almacen);

        ialmacen.ImprimirLotes(marca,centinelas);
        vGeneral.ImprimirMensaje("Puede Ingresar un nuevo Lote! \n");
        lote=vGeneral.LeerString("\n Ingrese el Lote: ");


		 while(!centinelas.removerVacunaLote(marca , lote , almacen))

		 {

			 vGeneral.ImprimirMensaje("El lote ingresado no se ha registrado \n");

			 int rpta = vGeneral.LeerValidarNro("\nDesea registrarlo? [1]. SI, [2].No:  ", 1, 2);

			 			if (rpta == 1)
			 			{
			 				if(almacen.getLote()==""){
			 				centinelas.agregarLoteaVacuna(marca,lote,almacen);
			 				}
			 				else{
			 					almacen.setMarca(marca);
			 					almacen.setLote(lote);
			 					almacen.setcantDisponible(0);
			 					almacen.setcantReservada(0);
			 				}
		 				break;
			 			}
			 			else
			 			{
			 				vGeneral.Limpiar();
			 				ialmacen.ImprimirLotes(marca,centinelas);
			 				lote=vGeneral.LeerString("\n Ingrese el Lote: ");
			 			}

		 }
		centinelas.agregarVacuna(almacen);
		cant = vGeneral.LeerValidarNro("\n Cantidad: ", 0, INT_MAX);
		estado.removerInfoVacunas(marca,info);
		nrodosis=info.getNroDosis();
		estado.agregarInfoVacunas(info);

		while (cant % (nrodosis) != 0)
		{
			vGeneral.ImprimirNro("\n La cantidad Ingresada debe ser Multiplo de ",nrodosis);
			vGeneral.ImprimirLineasBlanco(1);
			cant = vGeneral.LeerValidarNro("\n Cantidad: ", 0, INT_MAX);
		}

		centinelas.aumentarVacunas(marca,lote, cant);
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
			consultarPersona();
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
			case 1:
				eliminarMunicipio();
				break;
			case 2:
				EliminarCentinela();
				break;
			case 3:
				eliminarCubiculo();
				break;
			case 4:
				eliminarVacunas();
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

void Controlador::eliminarMunicipio(){
	MMunicipio municipio;
	IMunicipio Imunicipio;
	MCentinela centinela;
	MCubiculo cubiculo;

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

    if(municipio.PersonasMunicipio(municipio)==0){
    	vGeneral.ImprimirMensaje("\n Se han encontrado Centinelas dentro del Municipio\n");
    	int Condicion = vGeneral.LeerNro("Desea eliminar todos los Centinelas dentro del Municipio? \n 1.SI  2.NO:");

    	if(Condicion==1){
    		while(!municipio.esVacio()){
    			municipio.removerPrimerCentinela(centinela);

    			if(centinela.PersonasCentinela(centinela)==0){
    				vGeneral.ImprimirMensaje("\n Se han encontrado Cubiculos dentro del Centinela\n");
    				int Condicion2 = vGeneral.LeerNro("Desea eliminar todos los Cubiculos dentro del Centinela? \n 1.SI  2.NO:");

    				if(Condicion2==1){
    					while(!centinela.esVacia()){
    						centinela.removerPrimerCubiculo(cubiculo);
    						vGeneral.ImprimirMensaje("Se elimino de forma exitosa el Cubiculo " + cubiculo.getCodigo() + "\n");
    					}
    					vGeneral.ImprimirMensaje("\nSe elimino de forma exitosa el Centienla " + centinela.getCodigo() +"\n");
    					vGeneral.Pausa();
    					vGeneral.Limpiar();
    				}
    				else{
    					vGeneral.ImprimirMensaje("No se pudo realizar esta operacion, por lo tanto se ha regresado al menu principal\n");
    					vGeneral.Pausa();
    					vGeneral.Limpiar();
    				}
    			}
    			else{
    				municipio.agregarCentinela(centinela);
    				vGeneral.ImprimirMensaje("No se pudo eliminar el Centinela debido a que aun \nhay personas en cola dentro "+centinela.getCodigo()+"\n");
    				vGeneral.Pausa();
    				vGeneral.Limpiar();
    			}
    		}
			vGeneral.ImprimirMensaje("\nSe elimino de forma exitosa el Municipio " + municipioCodigo +"\n");
			vGeneral.Pausa();
			vGeneral.Limpiar();
    	}
    	else{
    	    vGeneral.ImprimirMensaje("No Se pudo realizar esta operacion, por lo tanto se ha regresado al menu principal\n");
    	    vGeneral.Pausa();
    	    vGeneral.Limpiar();
    	}
    }
    else{
		estado.agregarMunicipio(municipio);
		vGeneral.ImprimirMensaje("No se pudo eliminar el Municipio debido a que aun \nhay personas en cola en "+municipio.getNombre()+"\n");
		vGeneral.Pausa();
		vGeneral.Limpiar();
    }
    /*
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
	*/

    vGeneral.ImprimirLineasBlanco(1);

}//final metodo

void Controlador::menuModificar(){

	int rpta;
		while (rpta != 4)
		{
			vGeneral.ImprimirEncabezado("M E N U  M O D I F I C A R",
										"_______  _________________");
			vGeneral.ImprimirMensaje("1) Modificar Municipio");
			vGeneral.ImprimirLineasBlanco(1);
			vGeneral.ImprimirMensaje("2) Modificar Persona");
			vGeneral.ImprimirLineasBlanco(1);
			vGeneral.ImprimirMensaje("3) Modificar Vacuna");
			vGeneral.ImprimirLineasBlanco(1);
			vGeneral.ImprimirMensaje("4) Salir");
			vGeneral.ImprimirLineasBlanco(1);

			rpta = vGeneral.LeerNro("Respuesta: ");
			vGeneral.Limpiar();
			switch (rpta)
			{
			case 1:
				modificarMunicipio();
				break;
			case 2:
				ModificarPersona();
				break;
			case 3:
				ModificarVacunas();
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

void Controlador::modificarMunicipio(){

	MMunicipio municipio;
	IMunicipio Imunicipio;

	vGeneral.Limpiar();
	Imunicipio.ImprimirListaMunicipio(estado);
	string municipioCodigo = vGeneral.LeerString("Ingrese el codigo del municipio: ");
	municipio.setCodigo(municipioCodigo);

		while (!estado.removerMunicipio(municipioCodigo, municipio))
		{
			vGeneral.ImprimirMensaje("Error: El municipio solicitado no existe\n");
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

void Controlador::ModificarPersona()
{
	  MPersona persona;
	  MExpedienteVacunacion expediente;
	  int rpta;
	  string cedula = vGeneral.LeerString("\n Ingrese la cedula: ");
	  while ( !listaPersonas.removerPersona(cedula,persona)){

	    vGeneral.ImprimirMensaje("la persona no existe\n");
	    vGeneral.Pausa();
	    vGeneral.Limpiar();
	    cedula = vGeneral.LeerString("\n Ingrese la cedula: ");
	  };
	  listaExpedientes.removerExpediente(cedula, expediente);
	  vGeneral.Limpiar();
		while (rpta != 5)
		{
			vGeneral.ImprimirString("------Nombre: ", persona.getnombre());
			vGeneral.ImprimirLineasBlanco(1);
			vGeneral.ImprimirString("------Apellido: ", persona.getapellido());
			vGeneral.ImprimirLineasBlanco(1);
			vGeneral.ImprimirString("------Vacuna tomada: ", expediente.getVacunaTomada());
			vGeneral.ImprimirLineasBlanco(1);
			vGeneral.ImprimirNro("------Dosis tomadas: ", expediente.contarTotalDosis());
			vGeneral.ImprimirLineasBlanco(1);
			vGeneral.ImprimirMensaje("====================================");
			vGeneral.ImprimirLineasBlanco(1);
			vGeneral.ImprimirEncabezado("M E N U  P E R S O N A",
										"_______  _____________");
			vGeneral.ImprimirMensaje("1) Modificar informacion personal");
			vGeneral.ImprimirLineasBlanco(1);
			vGeneral.ImprimirMensaje("2) Modificar Marca de la Vacuna Tomada");
			vGeneral.ImprimirLineasBlanco(1);
			vGeneral.ImprimirMensaje("3) Agregar Dosis");
			vGeneral.ImprimirLineasBlanco(1);
			vGeneral.ImprimirMensaje("4) Remover ultima dosis");
			vGeneral.ImprimirLineasBlanco(1);
			vGeneral.ImprimirMensaje("5) Salir");
			vGeneral.ImprimirLineasBlanco(1);

			rpta = vGeneral.LeerNro("Respuesta: ");
			vGeneral.Limpiar();
			switch (rpta)
			{
			case 1:
				   vGeneral.ImprimirMensaje(" datos de la persona \n");
				   vGeneral.ImprimirLineasBlanco(1);
				   vGeneral.ImprimirString("------NOMBRE: ", persona.getnombre());
				   vGeneral.ImprimirLineasBlanco(1);
				   vGeneral.ImprimirString("------APELLIDO: ", persona.getapellido());
				   vGeneral.ImprimirLineasBlanco(1);

				   persona.setnombre(vGeneral.LeerString("Ingrese el nombre: "));
				   persona.setapellido(vGeneral.LeerString("Ingrese el apellido: "));

					vGeneral.Limpiar();
					vGeneral.ImprimirMensaje("===========R E S U L T A D O============\n\n");
					vGeneral.ImprimirMensaje("Se modifico la informacion personal con exito!\n\n");
					vGeneral.ImprimirMensaje("========================================\n\n");
					vGeneral.ImprimirLineasBlanco(1);
					vGeneral.Pausa();
					vGeneral.Limpiar();
				break;
			case 2:
				{
					   MInfoVacunas infoV;
					   IInfoVacunas IinfoV;
					   vGeneral.ImprimirMensaje(" datos de la persona \n");
					   vGeneral.ImprimirLineasBlanco(1);
					   vGeneral.ImprimirString("------MARCA VACUNA TOMADA: ", expediente.getVacunaTomada());
					   vGeneral.ImprimirLineasBlanco(2);

					   IinfoV.ImprimirListaDosis(estado);
					   string marca = vGeneral.LeerString("Ingrese una nueva marca tomada: ");
					   if(estado.removerInfoVacunas(marca,infoV)){
						   estado.agregarInfoVacunas(infoV);
						   expediente.setVacunaTomada(marca);
							vGeneral.Limpiar();
							vGeneral.ImprimirMensaje("===========R E S U L T A D O============\n\n");
							vGeneral.ImprimirMensaje("Se Modifico la marca de la vacuna tomada exitosamente!\n\n");
							vGeneral.ImprimirMensaje("========================================\n\n");
							vGeneral.ImprimirLineasBlanco(1);
							vGeneral.Pausa();
							vGeneral.Limpiar();
					   }
					   else{
						   vGeneral.Limpiar();
						   vGeneral.ImprimirMensaje("La marca ingresada no existe\n");
						   vGeneral.Pausa();
						   vGeneral.Limpiar();
					   }
				}
				break;
			case 3:
				{
					string fecha = vGeneral.LeerString("Ingrese la fecha (dd/mm/aaaa): ");
					Date nuevaDosis(fecha);
					expediente.AgregarNuevaDosis(nuevaDosis);

					vGeneral.Limpiar();
					vGeneral.ImprimirMensaje("===========R E S U L T A D O============\n\n");
					vGeneral.ImprimirMensaje("Se agrego la nueva dosis exitosamente!\n\n");
					vGeneral.ImprimirMensaje("========================================\n\n");
					vGeneral.ImprimirLineasBlanco(1);
					vGeneral.Pausa();
					vGeneral.Limpiar();
				}
				break;
			case 4:
				{
					Date oldDosis;
					if(expediente.removerTopeDosis(oldDosis)){
						vGeneral.Limpiar();
						vGeneral.ImprimirMensaje("===========R E S U L T A D O============\n\n");
						vGeneral.ImprimirMensaje("Se elimino la ultima dosis exitosamente!\n\n");
						vGeneral.ImprimirMensaje("========================================\n\n");
						vGeneral.ImprimirLineasBlanco(1);
						vGeneral.Pausa();
						vGeneral.Limpiar();
					}
					else
					{
						vGeneral.Limpiar();
						vGeneral.ImprimirMensaje("===========R E S U L T A D O============\n\n");
						vGeneral.ImprimirMensaje("Ya la persona no tiene niguna dosis inyectada\n\n");
						vGeneral.ImprimirMensaje("========================================\n\n");
						vGeneral.ImprimirLineasBlanco(1);
						vGeneral.Pausa();
						vGeneral.Limpiar();
					}
				}
				break;
			case 5:
				listaPersonas.agregarPersona(persona);
				listaExpedientes.agregarExpediente(expediente);
			    return;
			default:
				vGeneral.ImprimirMensaje("Por favor ingrese una opcion valida\n");
				vGeneral.Pausa();
				vGeneral.Limpiar();
				break;
			}
		}
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
			vGeneral.ImprimirMensaje("4) Agregar Informacion De Vacunas");
			vGeneral.ImprimirLineasBlanco(1);
			vGeneral.ImprimirMensaje("5) Salir");
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
				AgregarInfoVacunas();
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
void Controlador::agregarMunicipio()
{
	MMunicipio municipioAux;
	MCentinela centinelaAux;
	MCubiculo cubiculoAux;
	IMunicipio Imunicipio;
	ICentinela Icentinela;
	ICubiculo Icubiculo;

	vGeneral.Limpiar();
	int numMun = vGeneral.LeerNro("Ingrese el numero de Municipios que desea agregar: ");
	for(int j = 0; j < numMun; j++)
	{
		MMunicipio newMunicipio;
		Imunicipio.ImprimirListaMunicipio(estado);
		string municipioCod = vGeneral.LeerString("Ingrese el codigo del nuevo Municipio: ");
		while(estado.removerMunicipio(municipioCod, municipioAux)){
			vGeneral.ImprimirMensaje("Error: El municipio ya existe \n\n");
			vGeneral.Pausa();
			vGeneral.Limpiar();
			estado.agregarMunicipio(municipioAux);
			Imunicipio.ImprimirListaMunicipio(estado);
			municipioCod = vGeneral.LeerString("Ingrese el codigo del nuevo Municipio: ");
		}
		newMunicipio.setCodigo(municipioCod);
		string municipioNom = vGeneral.LeerString("Ingrese el nombre del nuevo municipio: ");
		newMunicipio.setNombre(municipioNom);

		vGeneral.Limpiar();
		int numCenti = vGeneral.LeerNro("Ingrese el numero de Centinelas que desea agregar: ");
		for (int i = 0; i < numCenti; ++i)
		{
			MCentinela newCentinela;
			Icentinela.ImprimirListaCentinela(newMunicipio);
			string centiCodigo = vGeneral.LeerString("Ingrese el codigo de la nueva Centinela: ");
			newCentinela.setCodigo(centiCodigo);

			while (newMunicipio.removerCentinela(centiCodigo, centinelaAux))
			{
				vGeneral.ImprimirMensaje("Error: La centinela ya existe \n\n");
				vGeneral.Pausa();
				vGeneral.Limpiar();
				newMunicipio.agregarCentinela(centinelaAux);
				Icentinela.ImprimirListaCentinela(newMunicipio);
				centiCodigo = vGeneral.LeerString("Ingrese el codigo de la nueva centinela: ");
				newCentinela.setCodigo(centiCodigo);
			}

				int numCubiculo = vGeneral.LeerNro("Ingrese el numero de Cubiculos que desea agregar en el Centinela: ");

				while(numCubiculo<3){

					vGeneral.ImprimirMensaje("Error: Se deben ingresar 3 cubiculos minimo \n\n");
					vGeneral.Pausa();
					vGeneral.Limpiar();
					numCubiculo = vGeneral.LeerNro("Ingrese el numero de Cubiculos que desea agregar en el Centinela: ");
				}

				for (int j = 0; j < numCubiculo; ++j)
				{
					MCubiculo newCubiculo;
					Icubiculo.ImprimirListaCubiculo(newCentinela);
					string cubiCodigo = vGeneral.LeerString("Ingrese el codigo del nuevo Cubiculo: ");
					newCubiculo.setCodigo(cubiCodigo);

					while(newCentinela.removerCubiculo(cubiCodigo,cubiculoAux)){
						vGeneral.ImprimirMensaje("Error: El cubiculo ya existe \n\n");
						vGeneral.Pausa();
						vGeneral.Limpiar();
						newCentinela.agregarCubiculo(cubiculoAux);
						Icubiculo.ImprimirListaCubiculo(newCentinela);
						cubiCodigo = vGeneral.LeerString("Ingrese el codigo del nuevo Cubiculo: ");
						newCubiculo.setCodigo(cubiCodigo);
					}

					if (newCentinela.agregarCubiculo(newCubiculo))
					{
						vGeneral.ImprimirMensaje("Cubiculo agregado exitosamente \n\n");
						vGeneral.Limpiar();
					} //final del else if de cubiculo

					}//final for cubiculo
				if (newMunicipio.agregarCentinela(newCentinela))
							{
								vGeneral.ImprimirMensaje("Centinela agregado exitosamente \n\n");
								vGeneral.ImprimirLineasBlanco(1);
								vGeneral.Pausa();
								vGeneral.Limpiar();
							}//final else cubiculo
				}//final for centinela
		estado.agregarMunicipio(newMunicipio);
	}
	vGeneral.Limpiar();
	vGeneral.ImprimirMensaje("===========R E S U L T A D O============\n\n");
	vGeneral.ImprimirMensaje("la Operacion fue un exito!\n\n");
	vGeneral.ImprimirMensaje("========================================\n\n");
	vGeneral.ImprimirLineasBlanco(1);
	vGeneral.Pausa();
	vGeneral.Limpiar();
}

void Controlador::agregarCubiculo(){
	MMunicipio municipio;
	MCentinela centinela;
	MCubiculo cubiculoAux;
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
		MCubiculo newCubiculo;
		Icubiculo.ImprimirListaCubiculo(centinela);
		string codigoCubiculo = vGeneral.LeerString("Ingrese el codigo del cubiculo: ");
		newCubiculo.setCodigo(codigoCubiculo);
		if(centinela.removerCubiculo(codigoCubiculo, cubiculoAux)){
			vGeneral.ImprimirMensaje("Error: El cubiculo ya existe\n");
			vGeneral.Pausa();
			vGeneral.Limpiar();
			centinela.agregarCubiculo(cubiculoAux);
		}
		else{
			centinela.agregarCubiculo(newCubiculo);
			municipio.agregarCentinela(centinela);
			estado.agregarMunicipio(municipio);
			vGeneral.ImprimirMensaje("Cubiculo agregado exitosamente\n\n");
			vGeneral.Pausa();
			vGeneral.Limpiar();
			break;
		}
	}while(true);
	vGeneral.Limpiar();
	vGeneral.ImprimirMensaje("===========R E S U L T A D O============\n\n");
	vGeneral.ImprimirMensaje("la Operacion fue un exito!\n\n");
	vGeneral.ImprimirMensaje("========================================\n\n");
	vGeneral.ImprimirLineasBlanco(1);
	vGeneral.Pausa();
	vGeneral.Limpiar();
}

void Controlador::agregarCentinela()
{
	MMunicipio municipio;
	MCentinela centinelaAux;
	MCubiculo cubiculoAux;
	IMunicipio Imunicipio;
	ICentinela Icentinela;
	ICubiculo Icubiculo;

	vGeneral.Limpiar();
	Imunicipio.ImprimirListaMunicipio(estado);
	string municipioCodigo = vGeneral.LeerString("Ingrese el codigo del municipio: ");

	while (!estado.removerMunicipio(municipioCodigo, municipio))
	{
		vGeneral.ImprimirMensaje("Error: El municipio solicitado no existe\n");
		vGeneral.Pausa();
		vGeneral.Limpiar();

		Imunicipio.ImprimirListaMunicipio(estado);
		municipioCodigo = vGeneral.LeerString("Ingrese el codigo del Municipio: ");
	};

	vGeneral.Limpiar();

	vGeneral.Limpiar();
	int numCenti = vGeneral.LeerNro("Ingrese el numero de Centinelas que desea agregar: ");
	for (int i = 0; i < numCenti; ++i)
	{
		MCentinela newCentinela;
		string centiCodigo = vGeneral.LeerString("Ingrese el codigo de la nueva Centinela: ");
		newCentinela.setCodigo(centiCodigo);

		while (municipio.removerCentinela(centiCodigo, centinelaAux))
		{
			vGeneral.ImprimirMensaje("Error: La centinela ya existe \n\n");
			vGeneral.Pausa();
			vGeneral.Limpiar();
			municipio.agregarCentinela(centinelaAux);
			Icentinela.ImprimirListaCentinela(municipio);
			centiCodigo = vGeneral.LeerString("Ingrese el codigo de la nueva centinela: ");
			newCentinela.setCodigo(centiCodigo);
		}

			int numCubiculo = vGeneral.LeerNro("Ingrese el numero de Cubiculos que desea agregar en el Centinela: ");

			while(numCubiculo<3){

				vGeneral.ImprimirMensaje("Error: Se deben ingresar 3 cubiculos minimo \n\n");
				vGeneral.Pausa();
				vGeneral.Limpiar();
				numCubiculo = vGeneral.LeerNro("Ingrese el numero de Cubiculos que desea agregar en el Centinela: ");
			}

			for (int j = 0; j < numCubiculo; ++j)
			{
				MCubiculo newCubiculo;
				Icubiculo.ImprimirListaCubiculo(newCentinela);
				string cubiCodigo = vGeneral.LeerString("Ingrese el codigo del nuevo Cubiculo: ");
				newCubiculo.setCodigo(cubiCodigo);

				while(newCentinela.removerCubiculo(cubiCodigo,cubiculoAux)){
					vGeneral.ImprimirMensaje("Error: El cubiculo ya existe \n\n");
					vGeneral.Pausa();
					vGeneral.Limpiar();
					newCentinela.agregarCubiculo(cubiculoAux);
					Icubiculo.ImprimirListaCubiculo(newCentinela);
					cubiCodigo = vGeneral.LeerString("Ingrese el codigo del nuevo Cubiculo: ");
					newCubiculo.setCodigo(cubiCodigo);

				}

				if (newCentinela.agregarCubiculo(newCubiculo))
				{
					vGeneral.ImprimirMensaje("Cubiculo agregado exitosamente \n\n");
					vGeneral.Limpiar();

				} //final del else if de cubiculo

			}//final for cubiculo
			if (municipio.agregarCentinela(newCentinela))
						{
							vGeneral.ImprimirMensaje("Centinela agregado exitosamente \n\n");
							vGeneral.ImprimirLineasBlanco(1);
							vGeneral.Pausa();
							vGeneral.Limpiar();
						}//final else cubiculo
			}//final for centinela

	estado.agregarMunicipio(municipio);
	vGeneral.ImprimirLineasBlanco(1);

	vGeneral.Limpiar();
	vGeneral.ImprimirMensaje("===========R E S U L T A D O============\n\n");
	vGeneral.ImprimirMensaje("la Operacion fue un exito!\n\n");
	vGeneral.ImprimirMensaje("========================================\n\n");
	vGeneral.ImprimirLineasBlanco(1);
	vGeneral.Pausa();
	vGeneral.Limpiar();
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

	MPersona mp;
	MExpedienteVacunacion me;
	string cedula;

	cedula = vGeneral.LeerString("Ingrese el numero de cedula de la persona: ");
	if (!listaPersonas.removerPersona(cedula, mp)) {
		vGeneral.ImprimirMensaje("Error: La persona no se encuentra registrada\n");
		vGeneral.Pausa();
		vGeneral.Limpiar();
	} else {
		listaExpedientes.removerExpediente(mp.getcedula(), me);
		listaExpedientes.agregarExpediente(me);
		vGeneral.ImprimirMensaje("==============R E P O R T E===============\n\n");
		vGeneral.ImprimirString("NOMBRE: ", mp.getnombre());
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirString("APELLIDO: ", mp.getapellido());
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirString("CEDULA: ", mp.getcedula());
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirNro("CANTIDAD DE DOSIS TOMADAS: ", me.contarTotalDosis());
		vGeneral.ImprimirLineasBlanco(1);
		vGeneral.ImprimirString("LA VACUNA COLOCADA ES: ", me.getVacunaTomada());
		vGeneral.ImprimirLineasBlanco(2);
		vGeneral.ImprimirMensaje("==========================================\n\n");
		vGeneral.Pausa();
		vGeneral.Limpiar();
		listaPersonas.agregarPersona(mp);
	}
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
  vGeneral.ImprimirMensaje("==========   CONSULTAR  CENTINELA   =========");
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
  vGeneral.ImprimirString("------MUNICIPIO: ", municipio.getNombre());
  vGeneral.ImprimirLineasBlanco(1);

  Icentinela.ConsultarCentinela(municipio);
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
		cubiculoCodigo = vgeneral.LeerString("\n Ingrese el codigo del cubiculo: ");
	};

	vGeneral.ImprimirLineasBlanco(1);
	vgeneral.Limpiar();

	vGeneral.ImprimirLineasBlanco(1);
		int respuesta;
			while (respuesta != 5)
			{
				vGeneral.ImprimirLineasBlanco(1);
				vGeneral.ImprimirString("-------CUBICULO: ", cubiculo.getCodigo());
				vGeneral.ImprimirLineasBlanco(2);
				vGeneral.ImprimirEncabezado("Menu de Consulta en la cola",
											"___________________________");
				vGeneral.ImprimirMensaje("1) Pacientes con 0 dosis");
				vGeneral.ImprimirLineasBlanco(1);
				vGeneral.ImprimirMensaje("2) Pacientes con 1 dosis");
				vGeneral.ImprimirLineasBlanco(1);
				vGeneral.ImprimirMensaje("3) Pacientes con 2 dosis");
				vGeneral.ImprimirLineasBlanco(1);
				vGeneral.ImprimirMensaje("4) Totalidad de Pacientes");
				vGeneral.ImprimirLineasBlanco(1);
				vGeneral.ImprimirMensaje("5)  Salir");
				vGeneral.ImprimirLineasBlanco(1);

				respuesta = vGeneral.LeerNro("Respuesta: ");
				vGeneral.Limpiar();
				switch (respuesta)
				{
				case 1:
					vGeneral.ImprimirLineasBlanco(1);
					vGeneral.ImprimirString("-------CUBICULO: ", cubiculo.getCodigo());
					vGeneral.ImprimirLineasBlanco(1);
					Icubiculo.reportarPersonas0Dosis(listaExpedientes,listaPersonas,cubiculo);
					vGeneral.ImprimirLineasBlanco(1);
					vGeneral.Pausa();
					vGeneral.Limpiar();
					break;
				case 2:
					vGeneral.ImprimirLineasBlanco(1);
					vGeneral.ImprimirString("-------CUBICULO: ", cubiculo.getCodigo());
					vGeneral.ImprimirLineasBlanco(1);
					Icubiculo.reportarPersonas1Dosis(listaExpedientes,listaPersonas,cubiculo);
					vGeneral.ImprimirLineasBlanco(1);
					vGeneral.Pausa();
					vGeneral.Limpiar();
					break;
				case 3:
					vGeneral.ImprimirLineasBlanco(1);
					vGeneral.ImprimirString("-------CUBICULO: ", cubiculo.getCodigo());
					vGeneral.ImprimirLineasBlanco(1);
					Icubiculo.reportarPersonas2Dosis(listaExpedientes,listaPersonas,cubiculo);
					vGeneral.ImprimirLineasBlanco(1);
					vGeneral.Pausa();
					vGeneral.Limpiar();
					break;
				case 4:
					vGeneral.ImprimirLineasBlanco(1);
					vGeneral.ImprimirString("-------CUBICULO: ", cubiculo.getCodigo());
					vGeneral.ImprimirLineasBlanco(1);
					Icubiculo.reportarPersonasDelaCola(listaPersonas,cubiculo);
					vGeneral.ImprimirLineasBlanco(1);
					vGeneral.Pausa();
					vGeneral.Limpiar();

					break;
				case 5:
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

	string codmuni, marca, codcenti, codcubi,lote;

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
	IMunicipio iMunicipio;
	ICentinela iCentinela;
	ICubiculo iCubiculo;

	MMunicipio municipio;
	MCentinela centinela;
	MCubiculo cubiculo;
	MPersona persona;

	string cedula;

	vGeneral.Limpiar();
	vGeneral.ImprimirMensaje("\n========= INGRESAR PACIENTE A LA COLA =========");

	iMunicipio.obtenerMunicipio(estado, municipio);
	iCentinela.obtenerCentinela(municipio, centinela);
	iCubiculo.obtenerCubiculo(centinela, cubiculo);

	vGeneral.Limpiar();
	iCubiculo.reportarPersonasDelaCola(listaPersonas, cubiculo);
	cedula = vGeneral.LeerString("\n Cedula: ");
	while(cubiculo.buscarPaciente(cedula)) {
		vGeneral.ImprimirMensaje("\n ERROR: El paciente ya esta en la cola\n");
		vGeneral.Pausa();
		vGeneral.Limpiar();
		iCubiculo.reportarPersonasDelaCola(listaPersonas,cubiculo);
		cedula = vGeneral.LeerString("\n Cedula: ");
	}

	if(!listaPersonas.removerPersona(cedula, persona)) {
		vGeneral.ImprimirMensaje("\n ERROR: El paciente no esta censado\n");
		vGeneral.Pausa();
		vGeneral.Limpiar();

		vGeneral.ImprimirMensaje("\n========= DATOS DEL PACIENTE NUEVO =========");
		vGeneral.ImprimirString("\n Cedula: ", cedula);
		string nombre = vGeneral.LeerString("\n Nombre: ");
		string apellido = vGeneral.LeerString("\n Apellido: ");
		MPersona pacienteNuevo(nombre, apellido, cedula);

		vGeneral.ImprimirMensaje("\n CREANDO EXPEDIDENTE...");
		MExpedienteVacunacion expedienteNuevo(cedula, "Ninguno");
		expedienteNuevo.setVacunaTomada("Ninguna");
		expedienteNuevo.setLote("Ninguna");

		if(listaExpedientes.agregarExpediente(expedienteNuevo))
			vGeneral.ImprimirMensaje("\n Expediente creado exitosamente\n");
		else
			vGeneral.ImprimirMensaje("\n ERROR: El expediente no pudo ser creado\n");

		persona = pacienteNuevo;
	}

	listaPersonas.agregarPersona(persona);

	if(!estado.buscarPaciente(cedula) && !municipio.buscarPaciente(cedula) && !centinela.buscarPaciente(cedula)) {
		if(cubiculo.agregarPaciente(cedula))
			vGeneral.ImprimirMensaje("\n Paciente ingresado exitosamente\n");
		else
			vGeneral.ImprimirMensaje("\n ERROR: El paciente no pudo ser ingresado\n");
	}
	else
		vGeneral.ImprimirMensaje("\n ERROR: El paciente esta en otra cola\n");

	centinela.agregarCubiculo(cubiculo);
	municipio.agregarCentinela(centinela);
	estado.agregarMunicipio(municipio);

	vGeneral.Pausa();
	vGeneral.Limpiar();
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
		cubiculoCodigo = vgeneral.LeerString("\n Ingrese el codigo del cubiculo: ");
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
	MInfoVacunas infoVacuna;
	MPersona persona;
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
		listaPersonas.removerPersona(cedula, persona);
		listaPersonas.agregarPersona(persona);
		listaExpedientes.removerExpediente(cedula, mExpediente);
		listaExpedientes.agregarExpediente(mExpediente);
		vGeneral.ImprimirMensaje("======P R O C E S A R=======\n");
		vGeneral.ImprimirMensaje(cedula + " " + persona.getnombre() + " " + persona.getapellido());
		vGeneral.ImprimirLineasBlanco(2);
			//B
			string nombre, apellido, cedula, marcaVacuna;
			if(centinela.removerPrimeraVacuna(vacuna)){
				mExpediente.setCodCentinela(centinela.getCodigo());
				mExpediente.setLote(vacuna.getLote());
				mExpediente.setVacunaTomada(vacuna.getMarca());
				estado.removerInfoVacunas(vacuna.getMarca(), infoVacuna);
				estado.agregarInfoVacunas(infoVacuna);

				vacuna.setcantDisponible(vacuna.getcantDisponible() - infoVacuna.getNroDosis());
				vacuna.setcantReservada(vacuna.getcantReservada() + infoVacuna.getNroDosis());
				centinela.agregarVacuna(vacuna);
			}
			else{
				vGeneral.ImprimirMensaje("Lo sentimos, pero no queda ninguna vacuna disponible por el momento\n");
				vGeneral.Pausa();
				vGeneral.Limpiar();
				centinela.agregarCubiculo(cubiculo);
				municipio.agregarCentinela(centinela);
				estado.agregarMunicipio(municipio);
				return;
			}
		//A
		if(mExpediente.getCodCentinela() == centinela.getCodigo()){
			if(centinela.removerVacunaLote(mExpediente.getVacunaTomada(), mExpediente.getLote(),vacuna))
			{
				estado.removerInfoVacunas(mExpediente.getVacunaTomada(), infoVacuna);
				estado.agregarInfoVacunas(infoVacuna);

				if(mExpediente.contarTotalDosis() < infoVacuna.getNroDosis())
				{
					Date ultimaDosis;
					string fechaUltimaDosis = "N/A";
					if(mExpediente.removerTopeDosis(ultimaDosis)){
						fechaUltimaDosis = ultimaDosis.getFecha();
						mExpediente.AgregarNuevaDosis(ultimaDosis);
					}
					vGeneral.ImprimirMensaje("===================================\n\n");
					vGeneral.ImprimirMensaje("Vacuna a Suministrar: " + mExpediente.getVacunaTomada());
					vGeneral.ImprimirLineasBlanco(1);
					vGeneral.ImprimirMensaje("Fecha de la ultima dosis suministrada: " + fechaUltimaDosis);
					vGeneral.ImprimirLineasBlanco(2);
					vGeneral.ImprimirMensaje("===================================\n\n");
					fecha = vGeneral.LeerString("Ingrese la fecha (dd/mm/aaaa): ");
					date.setFecha(fecha);
					Date ultimaDosisDate;
					if(mExpediente.removerTopeDosis(ultimaDosisDate)){
						mExpediente.AgregarNuevaDosis(ultimaDosisDate);
						int diferenciaDias = ultimaDosisDate.DiferenciaDias(date);
						if(diferenciaDias >= 90 && date.esMayor(ultimaDosisDate))
						{
							final = true;
						}
						else
						{
							Date sigFechaEstipulada = mExpediente.getSigFechaEstipulada();
							vGeneral.ImprimirMensaje("Lo sentimos, pero no han pasado los dias para recibir su siguiente dosis\n por favor regrese el dia " + sigFechaEstipulada.getFecha());
							vGeneral.ImprimirLineasBlanco(1);
							vGeneral.Pausa();
							vGeneral.Limpiar();
						}
					}
					else{
						final = true;
					}
				}
				else
				{
					vGeneral.ImprimirMensaje("Ya usted se ha vacunado con todas las dosis necesarias\n");
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
	}
	else{
		vGeneral.ImprimirMensaje("No existen personas en cola para este cubiculo\n");
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}

	if(final)
	{
		estado.removerInfoVacunas(mExpediente.getVacunaTomada(), infoVacuna);
		estado.agregarInfoVacunas(infoVacuna);

		mExpediente.AgregarNuevaDosis(date);
		vacuna.setcantReservada(vacuna.getcantReservada() - 1);
		vGeneral.Limpiar();
		vGeneral.ImprimirMensaje("=============R E S U L T A D O=============\n\n");
		vGeneral.ImprimirMensaje(cedula + " " + persona.getnombre() + " " + persona.getapellido());
		vGeneral.ImprimirLineasBlanco(2);
		vGeneral.ImprimirNro("Nro de la dosis suministrada: ", mExpediente.contarTotalDosis());
		vGeneral.ImprimirLineasBlanco(2);
		vGeneral.ImprimirString("Marca de la vacuna: ", mExpediente.getVacunaTomada());
		vGeneral.ImprimirLineasBlanco(2);
		if(mExpediente.contarTotalDosis() >= infoVacuna.getNroDosis()){
			vGeneral.ImprimirMensaje("Ya se ha vacunado todas las dosis necesarias");
			vGeneral.ImprimirLineasBlanco(2);
		}
		else{
			Date sigD = mExpediente.getSigFechaEstipulada();
			vGeneral.ImprimirMensaje("Fecha para la siguiente dosis: " + sigD.getFecha());
			vGeneral.ImprimirLineasBlanco(2);
		}
		vGeneral.ImprimirMensaje("===========================================\n\n");
		vGeneral.Pausa();
		vGeneral.Limpiar();
	}
	centinela.agregarVacuna(vacuna);
	centinela.agregarCubiculo(cubiculo);
	municipio.agregarCentinela(centinela);
	estado.agregarMunicipio(municipio);
	listaExpedientes.agregarExpediente(mExpediente);

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
		cubiculoCodigo = vgeneral.LeerString("\n Ingrese el codigo del cubiculo a Eliminar: ");
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

void Controlador::eliminarVacunas()
{
		  IAlmacen ialmacen;
		  IMunicipio imunicipio;
		  ICentinela icentinela;
		  MAlmacenVacuna almacen;
		  MCentinela centinelas;
		  MMunicipio municipio;
		  int resps;
		  string codmuni, marca, lote, codcenti, codcubi;

		  vGeneral.ImprimirMensaje("==========   E L I M I N A R  V A C U N A S   ==========");

		  vGeneral.ImprimirLineasBlanco(1);
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
		  vGeneral.ImprimirLineasBlanco(1);
		  vGeneral.ImprimirString("------MUNICIPIO: ", municipio.getNombre());
		  vGeneral.ImprimirLineasBlanco(1);

		  icentinela.ImprimirListaCentinela(municipio);
		  codcenti = vGeneral.LeerString("\n Ingrese el codigo del centinela: ");

		  while (!municipio.removerCentinela(codcenti, centinelas))
		  {

			  vGeneral.ImprimirMensaje("Error: El centinela solicitado no existe \n\n");
		      vGeneral.Pausa();
		      vGeneral.Limpiar();

		      vGeneral.ImprimirString("------MUNICIPIO: ", municipio.getNombre());
		      icentinela.ImprimirListaCentinela(municipio);
		      codcenti = vGeneral.LeerString("\n Ingrese el codigo del centinela: ");
		  }
        while(centinelas.PVacia())

         {
        	 vGeneral.ImprimirMensaje("El Centinela ya no posee vacunas! \n");
        	 vGeneral.Pausa();
        	 vGeneral.Limpiar();


        	 municipio.agregarCentinela(centinelas);
        	 estado.agregarMunicipio(municipio);
        	 return;
         }



		  vGeneral.Limpiar();
		  vGeneral.ImprimirLineasBlanco(1);
		  vGeneral.ImprimirString("------CENTINELA: ", centinelas.getCodigo());
		  vGeneral.ImprimirLineasBlanco(1);

		  ialmacen.ImprimirVacunas(centinelas);
		  marca = vGeneral.LeerString("\nEscribir marca de la vacuna a eliminar: ");

		  while (!centinelas.removerVacuna(marca, almacen))
		  {
			  vGeneral.ImprimirMensaje("La marca solicitada no existe \n");
			  vGeneral.Pausa();
			  vGeneral.Limpiar();

			  ialmacen.ImprimirVacunas(centinelas);
			  marca = vGeneral.LeerString("\nEscribir marca de la vacuna a eliminar: ");
		  }
		  centinelas.agregarVacuna(almacen);
		  vGeneral.Limpiar();
		  vGeneral.ImprimirLineasBlanco(1);
		  vGeneral.ImprimirString("------MARCA VACUNA: ", almacen.getMarca());
		  vGeneral.ImprimirLineasBlanco(1);

		  ialmacen.ImprimirLotes(marca,centinelas);
		  lote = vGeneral.LeerString("\nEscribir lote de la vacuna a eliminar: ");

		  while (!centinelas.removerVacunaLote(marca,lote,almacen))
		  {
			  vGeneral.ImprimirMensaje("El lote solicitado no existe \n");
			  vGeneral.Pausa();
			  vGeneral.Limpiar();

			  ialmacen.ImprimirLotes(marca,centinelas);
			  lote = vGeneral.LeerString("\nEscribir lote de la vacuna a eliminar: ");
		  }



		  	  if(almacen.getcantDisponible()>0 or almacen.getcantReservada()>0)
		  	  {
		  		 vGeneral.ImprimirMensaje("\nWARNING! Existen vacunas en el almacen \n");
		  	     int resp= vGeneral.LeerNro("Estas seguro de eliminar? 1-Si 2-No: ");
		  	  if(resp==1)
		  	  {
		  		vGeneral.ImprimirMensaje("\nVacuna Eliminada satisfactoriamente ");
		  		vGeneral.ImprimirLineasBlanco(1);
		  		municipio.agregarCentinela(centinelas);
		  		estado.agregarMunicipio(municipio);
		  		vGeneral.Pausa();
		  		vGeneral.Limpiar();
		  		return;


		  	  }
		  	  else
		  	  {

		  		  	  	vGeneral.ImprimirLineasBlanco(1);
		  			  	centinelas.agregarVacuna(almacen);
		  			  	municipio.agregarCentinela(centinelas);
		  			  	estado.agregarMunicipio(municipio);
		  			  	vGeneral.Pausa();
		  			  	vGeneral.Limpiar();
		  			  	return;
		  	  }
		  	  }

		  	  else
		  	  {
		  		  	  	 vGeneral.ImprimirMensaje("Vacuna Eliminada satisfactoriamente \n");
		  		 	 	 vGeneral.ImprimirLineasBlanco(1);
		  				  municipio.agregarCentinela(centinelas);
		  				  estado.agregarMunicipio(municipio);
		  				  vGeneral.Pausa();
		  				  vGeneral.Limpiar();
		  				  return;
		  	  }
		  	vGeneral.ImprimirLineasBlanco(1);
		  	centinelas.agregarVacuna(almacen);
		  	municipio.agregarCentinela(centinelas);
		  	estado.agregarMunicipio(municipio);
		  	vGeneral.Pausa();
		  	vGeneral.Limpiar();
}

void Controlador::ModificarVacunas()
{

		IMunicipio imunicipio;
		IAlmacen ialmacen;
		ICentinela icentinela;
		MAlmacenVacuna almacen;
		MCentinela centinelas;
		MMunicipio municipio;
		IInfoVacunas iinfo;
		MInfoVacunas info;


		string codmuni, codcenti, marca,lote;
		int cant,cantr,nrodosis;

		vGeneral.ImprimirMensaje("==========   M O D I F I C A R __ V A C U N A S   ==========");

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
		marca = vGeneral.LeerString("\nEscribir marca: ");
		almacen.setMarca(marca);

		while (!centinelas.removerVacuna(marca, almacen))
		{
			vGeneral.ImprimirLineasBlanco(1);
			vGeneral.ImprimirMensaje("La marca solicitada no existe \n");


			vGeneral.Limpiar();
			ialmacen.ImprimirVacunas(centinelas);
			marca = vGeneral.LeerString("\n Ingrese la marca de la vacuna: ");



		}
		centinelas.agregarVacuna(almacen);

        ialmacen.ImprimirLotes(marca,centinelas);
        lote=vGeneral.LeerString("\n Ingrese el Lote: ");


		 while(!centinelas.removerVacunaLote(marca , lote , almacen))

		 {

			 	 vGeneral.ImprimirLineasBlanco(1);
			 	 vGeneral.ImprimirMensaje("El Lote solicitado no existe \n");

			 	vGeneral.Pausa();
			 	 vGeneral.Limpiar();
			 	 ialmacen.ImprimirLotes(marca,centinelas);
			 	lote = vGeneral.LeerString("\n Ingrese el Lote de la vacuna: ");
		 }


		 vGeneral.Limpiar();
		 centinelas.agregarVacuna(almacen);
		 municipio.agregarCentinela(centinelas);
		 estado.agregarMunicipio(municipio);
		 estado.removerInfoVacunas(marca,info);
		 estado.agregarInfoVacunas(info);
		 int rpta;

		while (rpta != 6)
		{
			vGeneral.ImprimirEncabezado("\nM E N U  M O D I F I C A R  V A C U N A S",
					                    "_______  _________________ _______________\n");
			vGeneral.ImprimirString("Centinela: ", centinelas.getCodigo());
			vGeneral.ImprimirString("\nMarca: ", almacen.getMarca());
			vGeneral.ImprimirString("\nLote: ", almacen.getLote());
			vGeneral.ImprimirNro("\nCantidad Disponible: ", almacen.getcantDisponible());
			vGeneral.ImprimirNro("\nCantidad Reservada: ", almacen.getcantReservada());
			vGeneral.ImprimirNro("\nNumero de dosis Necesaria: ", info.getNroDosis());
			vGeneral.ImprimirLineasBlanco(1);
			if(almacen.getcantDisponible() % nrodosis  != 0){
				vGeneral.ImprimirMensaje("\nWARNING: La cantidad de vacunas disponibles\n");
				vGeneral.ImprimirMensaje("No es multiplo del numero de dosis necesarias");
			}
			vGeneral.ImprimirLineasBlanco(2);
			vGeneral.ImprimirMensaje("1) Modificar Marca");
			vGeneral.ImprimirLineasBlanco(1);
			vGeneral.ImprimirMensaje("2) Modificar Lote");
			vGeneral.ImprimirLineasBlanco(1);
			vGeneral.ImprimirMensaje("3) Modificar Cantidad Disponible");
			vGeneral.ImprimirLineasBlanco(1);
			vGeneral.ImprimirMensaje("4) Modificar Cantidad Reservada");
			vGeneral.ImprimirLineasBlanco(1);
			vGeneral.ImprimirMensaje("5) Modificar Numero de dosis necesarias");
			vGeneral.ImprimirLineasBlanco(1);
			vGeneral.ImprimirMensaje("6) Salir");
			vGeneral.ImprimirLineasBlanco(1);


			rpta = vGeneral.LeerNro("Respuesta: ");
			vGeneral.Limpiar();
			switch (rpta)
			{

			case 1:
					estado.removerMunicipio(codmuni, municipio);
					municipio.removerCentinela(codcenti, centinelas);
				    vGeneral.Limpiar();
					vGeneral.ImprimirMensaje("\n------ MODIFICAR  MARCA ------");
                    centinelas.removerVacunaLote(marca,lote,almacen);
					marca = vGeneral.LeerString("\nEscribir Nueva Marca: ");
					almacen.setMarca(marca);
					if(centinelas.agregarVacuna(almacen))
					{
						vGeneral.ImprimirMensaje("Modificacion exitosa");
						if(estado.removerInfoVacunas(marca,info))
						{
							estado.agregarInfoVacunas(info);
						}
						else
						{
							info.setMarca(marca);
							estado.agregarInfoVacunas(info);
						}
						vGeneral.ImprimirLineasBlanco(1);
						vGeneral.Pausa();
						vGeneral.Limpiar();

					}
					else
					{
						vGeneral.ImprimirMensaje("No se pudo Modificar la Marca");
						return;
					}
					municipio.agregarCentinela(centinelas);
					estado.agregarMunicipio(municipio);
				break;
			case 2:
					estado.removerMunicipio(codmuni, municipio);
					municipio.removerCentinela(codcenti, centinelas);
					vGeneral.Limpiar();
				    vGeneral.ImprimirMensaje("\n------ MODIFICAR LOTE ------");
				    centinelas.removerVacunaLote(marca,lote,almacen);
				    lote = vGeneral.LeerString("\nEscribir Nuevo Lote: ");
				    almacen.setLote(lote);
				    if(centinelas.agregarVacuna(almacen))
				    {
				    	vGeneral.ImprimirMensaje("Modificacion exitosa");
				     	vGeneral.ImprimirLineasBlanco(1);
				    	vGeneral.Pausa();
				    	vGeneral.Limpiar();

				    }
				    	else
				    	{
				    		vGeneral.ImprimirMensaje("No se pudo Modificar el Lote");
				    		return;
				    	}



				break;

			case 3:
					estado.removerMunicipio(codmuni, municipio);
					municipio.removerCentinela(codcenti, centinelas);
					centinelas.removerVacunaLote(marca,lote,almacen);
					vGeneral.Limpiar();
					vGeneral.ImprimirMensaje("\n------ MODIFICAR  CANTIDAD DISPONIBLE ------");
					vGeneral.ImprimirNro("\nCantidad Disponible Actual: ", almacen.getcantDisponible());
					cant = vGeneral.LeerNro("\nEscribir Nueva Cantidad: ");

					while (cant % (info.getNroDosis()) != 0)
					{
						vGeneral.ImprimirNro("\n La cantidad Ingresada debe ser Multiplo de ",info.getNroDosis());
						vGeneral.ImprimirLineasBlanco(1);
						cant = vGeneral.LeerValidarNro("\n Cantidad: ", 0, INT_MAX);
					}

						almacen.setcantDisponible(cant);
						vGeneral.ImprimirMensaje("\n Cantidad Ingresada Exitosamente!\n");

						centinelas.agregarVacuna(almacen);
						municipio.agregarCentinela(centinelas);
						estado.agregarMunicipio(municipio);
						vGeneral.Pausa();
						vGeneral.Limpiar();


				break;
			case 4:
					estado.removerMunicipio(codmuni, municipio);
					municipio.removerCentinela(codcenti, centinelas);
					centinelas.removerVacunaLote(marca,lote,almacen);
					vGeneral.Limpiar();
					vGeneral.ImprimirMensaje("\n------ MODIFICAR CANTIDAD RESERVADA ------");
					vGeneral.ImprimirNro("\nCantidad Reservada Actual: ", almacen.getcantReservada());
					cantr = vGeneral.LeerNro("\nEscribir Nueva Cantidad: ");

					while (cantr % (info.getNroDosis()-1) != 0)
						{
							vGeneral.ImprimirNro("\n La cantidad Ingresada debe ser Multiplo de ",info.getNroDosis()-1);
							vGeneral.ImprimirLineasBlanco(1);
							cantr = vGeneral.LeerValidarNro("\n Cantidad: ", 0, INT_MAX);
						}

							almacen.setcantReservada(cantr);
							vGeneral.ImprimirMensaje("\n Cantidad Ingresada Exitosamente!\n");

							centinelas.agregarVacuna(almacen);
							municipio.agregarCentinela(centinelas);
							estado.agregarMunicipio(municipio);
							vGeneral.Pausa();
							vGeneral.Limpiar();


			break;
			case 5:
				estado.removerMunicipio(codmuni, municipio);
				municipio.removerCentinela(codcenti, centinelas);
				centinelas.removerVacunaLote(marca,lote,almacen);
				estado.removerInfoVacunas(marca,info);
				vGeneral.Limpiar();
				vGeneral.ImprimirMensaje("\n------ MODIFICAR NUMERO DE DOSIS NECESARIAS ------");
				vGeneral.ImprimirNro("\nNumero de dosis Necesarias Actual: ", info.getNroDosis());
				nrodosis = vGeneral.LeerNro("\nEscribir Nueva Dosis: ");
				if(almacen.getcantDisponible() % nrodosis  != 0){
					vGeneral.ImprimirMensaje("\nWARNING: La cantidad de vacuna disponible\n");
					vGeneral.ImprimirMensaje("no es multiplo del numero de dosis necesarias\n\n");
				}
				info.setNroDosis(nrodosis);
				estado.agregarInfoVacunas(info);
				centinelas.agregarVacuna(almacen);
				municipio.agregarCentinela(centinelas);
				estado.agregarMunicipio(municipio);
				vGeneral.Pausa();
				vGeneral.Limpiar();
				break;

			case 6:
				return;
			default:
				vGeneral.ImprimirMensaje("Por favor ingrese una opcion valida\n");
				vGeneral.Pausa();
				vGeneral.Limpiar();
				break;
			}



		}

}

void Controlador::AgregarInfoVacunas()
{

	IInfoVacunas iinfo;
	MInfoVacunas info;


	string marca;
	int nrodosis;
				vGeneral.ImprimirMensaje("==========   A G R E G A R__I N F O R M A C I O N__D E__V A C U N A S   ==========");

				iinfo.ImprimirListaDosis(estado);
				marca = vGeneral.LeerString("\n Marca: ");
                info.setMarca(marca);

				if (!estado.removerInfoVacunas( marca,info))
				{
					nrodosis = vGeneral.LeerNro("\n Numero De Dosis: ");
                    info.setNroDosis(nrodosis);
					estado.agregarInfoVacunas(info);
					vGeneral.ImprimirMensaje(" Informacion Agregada Correctamente!\n\n");


				}
				else
				{
				vGeneral.ImprimirLineasBlanco(1);
				vGeneral.ImprimirMensaje(" La Marca ya se encuentra Registrada!\n\n");
				estado.agregarInfoVacunas(info);
				}
				vGeneral.Pausa();
				vGeneral.Limpiar();
}

void Controlador::EliminarCentinela(){
  VGeneral vgeneral;
  MMunicipio municipio;
  MCentinela centinela;
  MCubiculo cubiculo;
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
    string centinelaCodigo = vgeneral.LeerString("\n Ingrese el codigo del centinela que desea eliminar: ");

    while(!municipio.removerCentinela(centinelaCodigo, centinela)) {
      vgeneral.ImprimirMensaje("Error: El centinela solicitado no existe \n\n");
      vgeneral.Pausa();
      vgeneral.Limpiar();

      Icentinela.ImprimirListaCentinela(municipio);
      centinelaCodigo = vgeneral.LeerString("\n Ingrese el codigo del centinela que desea eliminar: ");
    };

    if(centinela.PersonasCentinela(centinela)==0){
       vGeneral.ImprimirMensaje("\n Se han encontrado cubiculos dentro del centinela\n");
       int Condicion = vgeneral.LeerNro("Desea eliminar todos los Cubiculos dentro del Centinela? \n 1.SI  2.NO:");
            if(Condicion==1){
              while(!centinela.esVacia()){ //Eliminacion de cubiculos
                centinela.removerPrimerCubiculo(cubiculo);
                vgeneral.ImprimirMensaje("Se elimino de forma exitosa el Cubiculo " + cubiculo.getCodigo() + "\n");
              }
               vgeneral.ImprimirMensaje("\nSe elimino de forma exitosa el Centienla " + centinelaCodigo +"\n");
               vgeneral.Pausa();
               vgeneral.Limpiar();
            }
            else{
      vgeneral.ImprimirMensaje("No Se pudo realizar esta operacion, por lo tanto se ha regresado al menu principal\n");
       vgeneral.Pausa();
       vgeneral.Limpiar();
            }
    }
    else{
      municipio.agregarCentinela(centinela);
      vgeneral.ImprimirMensaje("No se pudo eliminar el Centinela debido a que aun \nhay personas en cola dentro "+centinelaCodigo+"\n");
      vgeneral.Pausa();
      vgeneral.Limpiar();
    }

    estado.agregarMunicipio(municipio);
}
