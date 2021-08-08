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
void MMunicipio::setCodigo(string codi){
	codigo = codi;
}
string MMunicipio::getNombre(){
	return nombre;
}
void MMunicipio::setNombre(string _nombre){
	nombre = _nombre;
}

bool MMunicipio::agregarCentinela(MCentinela &centinela){
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

bool MMunicipio::esVacio(){
	return centinelas.Contar() == 0;
}

int MMunicipio::PersonasMunicipio(MMunicipio &municipio){
  Lista<MCentinela>auxCentinela;
  MCentinela centinela;
  int TotalPersonasm=0;
  while(!municipio.esVacio()){
    municipio.removerPrimerCentinela(centinela);
    TotalPersonasm += centinela.PersonasCentinela(centinela);
    auxCentinela.InsComienzo(centinela);
  }
    while(!auxCentinela.Vacia()) {
      auxCentinela.EliComienzo(centinela);
        municipio.agregarCentinela(centinela);
    }
  return TotalPersonasm;
}

bool MMunicipio::buscarPaciente(string cedula) {
	Lista<MCentinela> auxCentinela;
	MCentinela centinelaActual;

	bool encontrado = false;
	while(!centinelas.Vacia()) {
		centinelas.EliComienzo(centinelaActual);
		if(centinelaActual.buscarPaciente(cedula))
			encontrado = true;
		auxCentinela.InsComienzo(centinelaActual);
	}

	while(!auxCentinela.Vacia()) {
		auxCentinela.EliComienzo(centinelaActual);
		centinelas.InsComienzo(centinelaActual);
	}
	return encontrado;
}
