#ifndef Lista_H
#define Lista_H
#include <iostream>
#include <string>
using namespace std;
template <class Tipo>
class Lista;

template <class Tipo>
class nodo
{
   Tipo info;
   nodo<Tipo>* prox;    
   friend class Lista<Tipo>; //La clase Lista puede acceder a sus atributos privados
};

template <class Tipo>
class Lista
{
typedef nodo<Tipo>* Apuntador;
private:
         nodo<Tipo>* Primero; 
public:
         Lista();
         Lista(const Lista &that);
         nodo<Tipo>* ObtPrimero();
         void AsigPrimero(nodo<Tipo>* p);
         bool Vacia();
         bool Llena();
         bool InsComienzo(Tipo &Valor);
         bool EliComienzo(Tipo &Valor);
         bool InsDespues(Apuntador p,Tipo Valor);
         bool EliDespues(Apuntador p,Tipo &Valor);
         ~Lista();
         Lista& operator=(const Lista &that);
         nodo<Tipo>* ObtProx(Apuntador p);
         void AsigProx(Apuntador p,Apuntador q);
         Tipo ObtInfo(Apuntador p);
         void AsigInfo(Apuntador p,Tipo Valor);
         int Contar();
         nodo<Tipo>*Buscar(Tipo Valor);
         void pasarListaAux(Lista<Tipo> &listaFuente, Lista<Tipo> &listaDestino);
};

#include "Sources/Lista.cpp"
#endif

