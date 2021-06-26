#ifndef MMunicipio_H
#define MMunicipio_H
#include <iostream>
#include <string>
#include "MCentinela.h"
using namespace std;

class MMunicipio {
private:
    string nombre;
    string codigo;
    MCentinela centinelas;
public:
    MMunicipio();
    int totalCentinelas();
    void agregarCentinela(MCentinela centinela);
    void removerCentinela(string codigo);
};

#endif
