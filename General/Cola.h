#ifndef Cola_H
#define Cola_H
#include <iostream>
using namespace std;

template <class Tipo>
class Cola;

template <class Tipo>
class nodoCola
{
Tipo info;
nodoCola *prox;
friend class Cola<Tipo>;
};

template <class Tipo>
class Cola
{
typedef nodoCola<Tipo>* Apuntador;
nodoCola<Tipo> *Frente,*Final;
public:
Cola();
~Cola();
Cola(const Cola& that);
Cola& operator=(const Cola& that);
bool Vacia();
bool Llena();
bool Insertar(Tipo &Valor);
bool Remover(Tipo &Valor);
};

#include "Sources/Cola.cpp"
#endif
