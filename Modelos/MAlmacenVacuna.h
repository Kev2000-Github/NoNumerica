#ifndef MAlmacenVacuna_H
#define MAlmacenVacuna_H
#include <iostream>
#include <string>
using namespace std;

class MAlmacenVacuna {
private:
    string marca;
    int cantidad;
public:
    MAlmacenVacuna();
    MAlmacenVacuna(string _marca, int _cantidad);
    void setMarca(string _marca);
    void setCantidad(int _cantidad);
    string getMarca();
    int getCantidad();
};

#endif
