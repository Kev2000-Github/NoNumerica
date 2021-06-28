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
    void setmarca(string m);
    string getmarca();

    void setcantidad(int c);
    int getcantidad();

};

#endif
