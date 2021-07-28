#ifndef MAlmacenVacuna_H
#define MAlmacenVacuna_H
#include <iostream>
#include <string>
using namespace std;

class MAlmacenVacuna {
private:
    string marca,lote;
    int cantDisponible,cantReservada;
public:
    MAlmacenVacuna();
    MAlmacenVacuna(string _marca, int _cantDisponible, int _cantReservada);

    void setMarca(string _marca);
    void setcantDisponible(int _cantDisponible);
    void setcantReservada(int _cantReservada);
    int getcantDisponible();
    int getcantReservada();
    string getMarca();
    void setLote(string _lote);
    string getLote();

    int calcularTotal();



};

#endif
