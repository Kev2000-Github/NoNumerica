#include "../MCensoPersonas.h";

MCensoPersonas::MCensoPersonas(){

}

bool MCensoPersonas::agregarPersona(MPersona persona){
	return personas.InsComienzo(persona);
}

bool MCensoPersonas::removerPersona(string cedula, MPersona &persona){

}

bool MCensoPersonas::removerPrimerPersona(MPersona &persona){
	return personas.EliComienzo(persona);
}
