#include "../MMunicipio.h"

// class MMunicipio
// {
// private:
//     string nombre;
//     string codigo;
//     // centinelas;

MMunicipio::MMunicipio()
{
}
MMunicipio::MMunicipio(string codi){
	codigom = codi;
}

string MMunicipio::getCodigo(){
	return codigom;
}
void MMunicipio::setCodigo(string codi){
	codigom = codi;
}

bool MMunicipio::agregarCentinela(MCentinela centinela){
    return centinelas.InsComienzo(centinela);

}

bool MMunicipio::removerCentinela(string codigo, MCentinela &centinela)
{

	nodo<MCentinela>* ap;
		ap = centinelas.ObtPrimero();
		string codigoActual = centinelas.ObtInfo(ap).getCodigo();
		//SI ES EL PRIMER ELEMENTO
		if(codigoActual == codigo){
			return centinelas.EliComienzo(centinela);
		}
		//SI ESTA DESPUES DEL PRIMER ELEMENTO
		while(centinelas.ObtProx(ap) != NULL){
			codigoActual = centinelas.ObtInfo(centinelas.ObtProx(ap)).getCodigo();
			if(codigoActual == codigo){
				return centinelas.EliDespues(ap, centinela);
			}
			else{
				ap = centinelas.ObtProx(ap);
			}
		};
		return false;
}
int MMunicipio::totalCentinelas()
{
	return centinelas.Contar();
}

bool MMunicipio::removerPrimerCentinela(MCentinela &centinela)
{
	return centinelas.EliComienzo(centinela);
}
