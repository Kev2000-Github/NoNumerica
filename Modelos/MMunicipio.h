#ifndef MMunicipio_H
#define MMunicipio_H
#include <iostream>
#include <string>
#include "MCentinela.h"
#include "../General/Lista.h"
using namespace std;

class MMunicipio {
private:
    string nombre;
    string codigom;
    Lista<MCentinela> centinelas;
public:
    MMunicipio();
    MMunicipio(string codi);
    string getCodigo();
	void setCodigo(string codi);
    int totalCentinelas();
    bool agregarCentinela(MCentinela centinela);
    bool removerCentinela(string codigo, MCentinela &centinela);
    bool removerPrimerCentinela(MCentinela &centinela);
};

#endif
