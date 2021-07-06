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
	codigo = codi;
}

string MMunicipio::getCodigo(){
	return codigo;
}
string MMunicipio::getnombre(){
	return nombre;
}
void MMunicipio::setnombre(string nomb){
	nombre = nomb;
}
void MMunicipio::setCodigo(string codi){
	codigo = codi;
}

bool MMunicipio::agregarCentinela(MCentinela centinela){
    return centinelas.InsComienzo(centinela);

}

bool MMunicipio::removerCentinela(string codigo, MCentinela &centinelaBuscado)
{
	Lista<MCentinela> listaAux;
	MCentinela centinelaActual;
	bool encontrado = false;
	while(!centinelas.Vacia()){
		centinelas.EliComienzo(centinelaActual);
		if(centinelaActual.getCodigo() == codigo){
			centinelaBuscado = centinelaActual;
			encontrado = true;
			break;
		}
		listaAux.InsComienzo(centinelaActual);
	}
	while(!listaAux.Vacia()){
		listaAux.EliComienzo(centinelaActual);
		centinelas.InsComienzo(centinelaActual);
	}
	return encontrado;
}

int MMunicipio::totalCentinelas()
{
	return centinelas.Contar();
}

bool MMunicipio::removerPrimerCentinela(MCentinela &centinela)
{
	return centinelas.EliComienzo(centinela);
}
