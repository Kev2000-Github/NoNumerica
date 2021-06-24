#ifndef Cola_H
#define Cola_H

template <class Tipo>
class Cola;

template <class Tipo>
class nodo
{
Tipo info;
nodo *prox;
friend class Cola<Tipo>;
};

template <class Tipo>
class Cola
{
nodo<Tipo> *Frente,*Final;
public:
Cola();
bool Vacia();
bool Llena();
bool Insertar(Tipo Valor);
bool Remover(Tipo &Valor);
};

#include "Cola.cpp"
#endif
