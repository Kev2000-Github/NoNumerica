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
