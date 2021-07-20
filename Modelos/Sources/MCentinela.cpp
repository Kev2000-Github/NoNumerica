/*
 * MCentinela.cpp
 *
 *  Created on: 25 jun. 2021
 *      Author: Kloux
 */

#include "../MCentinela.h"

MCentinela::MCentinela(string _codigo)
{
	codigo = _codigo;
}
MCentinela::MCentinela()
{
}

string MCentinela::getCodigo()
{
	return codigo;
}
void MCentinela::setCodigo(string _codigo)
{
	codigo = _codigo;
}

bool MCentinela::agregarCubiculo(MCubiculo &cubiculo)
{
	return cubiculos.InsComienzo(cubiculo);
}
bool MCentinela::removerCubiculo(string codigo, MCubiculo &cubiculoBuscado)
{
	Lista<MCubiculo> listaAux;
	MCubiculo cubiculoActual;
	bool encontrado = false;
	while (!cubiculos.Vacia())
	{
		cubiculos.EliComienzo(cubiculoActual);
		if (cubiculoActual.getCodigo() == codigo)
		{
			cubiculoBuscado = cubiculoActual;
			encontrado = true;
			break;
		}
		listaAux.InsComienzo(cubiculoActual);
	}
	while (!listaAux.Vacia())
	{
		listaAux.EliComienzo(cubiculoActual);
		cubiculos.InsComienzo(cubiculoActual);
	}
	return encontrado;
}

bool MCentinela::removerPrimerCubiculo(MCubiculo &cubiculo)
{
	return cubiculos.EliComienzo(cubiculo);
}

bool MCentinela::esVacia()
{
	return cubiculos.Contar() == 0;
}
int MCentinela::ConsultarCantidadPorMarca(string marca)
{
	//METODO QUE SE ENCARGA DE ACUMULAR LA CANTIDAD DE VACUNAS POR MARCA
	Pila<MAlmacenVacuna> auxvacuna;
	MAlmacenVacuna almacen;
	int cant = 0;
	while (!vacuna.Vacia())
	{
		vacuna.Remover(almacen);
		auxvacuna.Insertar(almacen);
		if (almacen.getMarca() == marca)
		{
			cant = almacen.getCantidad();
			break;
		}
	}
	while (!auxvacuna.Vacia())
	{
		auxvacuna.Remover(almacen);
		vacuna.Insertar(almacen);
	}
	return cant;
}

bool MCentinela::agregarVacuna(MAlmacenVacuna &vacunas)
{
	return vacuna.Insertar(vacunas);
}

bool MCentinela::removerVacuna(string marca, MAlmacenVacuna &vacunaBuscada)
{
	MAlmacenVacuna vacunaActual;
	Pila<MAlmacenVacuna> pilaAux;
	bool encontrado = false;
	while (!vacuna.Vacia())
	{
		vacuna.Remover(vacunaActual);
		if (vacunaActual.getMarca() == marca)
		{
			vacunaBuscada = vacunaActual;
			encontrado = true;
			break;
		}
		pilaAux.Insertar(vacunaActual);
	}
	while (!pilaAux.Vacia())
	{
		pilaAux.Remover(vacunaActual);
		vacuna.Insertar(vacunaActual);
	}
	return encontrado;
}

bool MCentinela::usarVacunas(string marca)
{
	Pila<MAlmacenVacuna> PilaAux;
	MAlmacenVacuna vacunas;
	int cant;
	bool actualizado = false;
	while (!vacuna.Vacia())
	{
		vacuna.Remover(vacunas);
		if (vacunas.getMarca() == marca)
		{
			cant = vacunas.getCantidad() - 1;
			if (cant > 0)
			{
				vacunas.setCantidad(cant);
				PilaAux.Insertar(vacunas);
			}
			actualizado = true;
			break;
		}
		else
		{
			PilaAux.Insertar(vacunas);
		}
	}
	while (!PilaAux.Vacia())
	{
		PilaAux.Remover(vacunas);
		vacuna.Insertar(vacunas);
	}
	return actualizado;
}

bool MCentinela::aumentarVacunas(string marca, int cantidad)
{
	Pila<MAlmacenVacuna> PilaAux;
	MAlmacenVacuna vacunas;
	int cant;
	bool actualizado = false;
	while (!vacuna.Vacia())
	{
		vacuna.Remover(vacunas);
		if (vacunas.getMarca() == marca)
		{
			cant = vacunas.getCantidad() + cantidad;
			vacunas.setCantidad(cant);
			actualizado = true;
			PilaAux.Insertar(vacunas);
			break;
		}
		PilaAux.Insertar(vacunas);
	}
	while (!PilaAux.Vacia())
	{
		PilaAux.Remover(vacunas);
		vacuna.Insertar(vacunas);
	}
	return actualizado;
}

int MCentinela::totalCubiculos()
{
	return cubiculos.Contar();
}

bool MCentinela::PVacia()
{
	return vacuna.Vacia();
}

bool MCentinela::removerPrimeraVacuna(MAlmacenVacuna &vacunas)
{
	return vacuna.Remover(vacunas);
}
