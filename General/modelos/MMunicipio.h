#ifndef MMunicipio_H
#define MMunicipio_H
#include <iostream>
#include <string>
using namespace std;

class MMunicipio {
private:
    string nombre;
    string codigo;
    // centinelas;
public:
    MMunicipio();
    int totalCentinelas();
    void agregarCentinela();
    void removerCentinela();
    int buscarCentinela();
};

#endif
