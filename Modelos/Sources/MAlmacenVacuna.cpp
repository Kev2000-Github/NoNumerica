#include "../MAlmacenVacuna.h"

MAlmacenVacuna::MAlmacenVacuna()
{
	marca="";
	cantidad=0;
}
void MAlmacenVacuna::setmarca(string m){
	marca=m;
}

string MAlmacenVacuna::getmarca(){
	return marca;
}

void MAlmacenVacuna::setcantidad(int c){
	cantidad=c;
}

int MAlmacenVacuna::getcantidad(){
	return cantidad;
}

MAlmacenVacuna::MAlmacenVacuna(string _marca, int _cantidad){
	marca = _marca;
	cantidad = _cantidad;
}

void MAlmacenVacuna::setCantidad(int _cantidad){
	cantidad = _cantidad;
}

void MAlmacenVacuna::setMarca(string _marca){
	marca = _marca;
}

int MAlmacenVacuna::getCantidad(){
	return cantidad;
}

string MAlmacenVacuna::getMarca(){
	return marca;
}
