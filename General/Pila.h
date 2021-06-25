#ifndef Pila_H
#define Pila_H
#include <string>

template <class Tipo>
class Pila;

#ifndef NODOPILA_H
#define NODOPILA_H
template <class Tipo>
class Nodopila
{
public:
  Tipo info;
  Nodopila<Tipo>* ap;
  friend class Pila<Tipo>;
};
#endif

template <class Tipo>
class Pila
{  

typedef Nodopila<Tipo>* Apuntapila;

public:
  Apuntapila Tope;
  Pila();
  bool Vacia();
  bool Llena();
  bool Insertar(Tipo Valor);
  bool Remover(Tipo &Valor);
  Apuntapila ObtTope();
  void AsigTope(Apuntapila p);
  Tipo ObtInfo(Nodopila<Tipo> *p);
  void AsigInfo(Nodopila<Tipo> *p,Tipo x);
};

#include "Source/Pila.cpp"
#endif
