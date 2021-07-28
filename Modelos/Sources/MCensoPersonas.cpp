#include "../MCensoPersonas.h";

MCensoPersonas::MCensoPersonas()
{
}

bool MCensoPersonas::agregarPersona(MPersona &persona)
{
	return personas.InsComienzo(persona);
}

bool MCensoPersonas::removerPersona(string cedula, MPersona &persona)
{
	return 0;
}

bool MCensoPersonas::removerPrimerPersona(MPersona &persona)
{
	return personas.EliComienzo(persona);
}

bool MCensoPersonas::esVacia(){
	return personas.Vacia();
}
