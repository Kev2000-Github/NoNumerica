#include "../MCensoPersonas.h"

MCensoPersonas::MCensoPersonas()
{
}

bool MCensoPersonas::agregarPersona(MPersona &persona)
{
	return personas.InsComienzo(persona);
}

bool MCensoPersonas::removerPersona(string cedula, MPersona &persona)
{
	Lista<MPersona> auxPersonas;
			MPersona personaActual;
			bool encontrado = false;
			while(!personas.Vacia()){
				personas.EliComienzo(personaActual);
					if(personaActual.getcedula() == cedula){
						persona = personaActual;
						encontrado = true;
						break;
					}
					auxPersonas.InsComienzo(personaActual);
				}
				while(!auxPersonas.Vacia()){
					auxPersonas.EliComienzo(personaActual);
					personas.InsComienzo(personaActual);
				}
				return encontrado;
}

bool MCensoPersonas::removerPrimerPersona(MPersona &persona)
{
	return personas.EliComienzo(persona);
}

bool MCensoPersonas::esVacia(){
	return personas.Vacia();
}

int MCensoPersonas::Contar(){
	return personas.Contar();
}
