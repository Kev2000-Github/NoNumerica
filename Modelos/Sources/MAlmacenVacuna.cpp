#include "../MAlmacenVacuna.h"

MAlmacenVacuna::MAlmacenVacuna()
{
	marca = "";
	cantDisponible=0;
	cantReservada=0;
}

MAlmacenVacuna::MAlmacenVacuna(string _marca, int _cantDisponible, int _cantReservada)
{
	marca = _marca;
	cantDisponible = _cantDisponible;
	cantReservada=_cantReservada;
}



void MAlmacenVacuna::setMarca(string _marca)
{
	marca = _marca;
}

string MAlmacenVacuna::getMarca()
{
	return marca;
}

void MAlmacenVacuna::setLote(string _lote)
{
	lote=_lote;
}



string MAlmacenVacuna::getLote()
{
	return lote;
}

void MAlmacenVacuna::setcantDisponible(int _cantDisponible)
{
	cantDisponible=_cantDisponible;
}



void MAlmacenVacuna::setcantReservada(int _cantReservada)
{
	cantReservada=_cantReservada;
}



int MAlmacenVacuna::getcantDisponible()
{
	return cantDisponible;
}



int MAlmacenVacuna::getcantReservada()
{
	return cantReservada;
}

int MAlmacenVacuna::calcularTotal()
{
	return cantDisponible+cantReservada;

}






