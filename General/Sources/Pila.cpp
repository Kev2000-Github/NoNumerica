#include "../Pila.h"

template <class Tipo>
Pila<Tipo>::Pila()
{
  Tope = NULL;
};

template <class Tipo>
Pila<Tipo>::Pila(const Pila<Tipo>& that)
{
	Apuntapila p;
	Apuntapila thatP;
	while(!Vacia()){
		p = Tope->ap;
		delete Tope;
		Tope = p;
	}

	if(that.Tope != NULL){
		thatP = that.Tope;
		Insertar(thatP->info);
		thatP = thatP->ap;
		p = ObtTope();
		while(thatP != NULL)
		{
			Apuntapila nuevo;
			if (!Llena()){
	               nuevo=new Nodopila<Tipo>;
	               nuevo->info=thatP->info;
	               nuevo->ap=p->ap;
	               p->ap=nuevo;
	               p = p->ap;
			}
			thatP = thatP->ap;
		}
	}
}

template <class Tipo>
Pila<Tipo>::~Pila()
{
	Apuntapila p;
	while(Tope != NULL){
		p = Tope->ap;
		delete Tope;
		Tope = p;
	}
}

template <class Tipo>
Pila<Tipo>& Pila<Tipo>::operator=(const Pila<Tipo>& that)
{
	if(this != &that){
		Apuntapila p;
		Apuntapila thatP;
		while(!Vacia()){
			p = Tope->ap;
			delete Tope;
			Tope = p;
		}

		if(that.Tope != NULL){
			thatP = that.Tope;
			Insertar(thatP->info);
			thatP = thatP->ap;
			p = ObtTope();
			while(thatP != NULL)
			{
				Apuntapila nuevo;
				if (!Llena()){
		               nuevo=new Nodopila<Tipo>;
		               nuevo->info=thatP->info;
		               nuevo->ap=p->ap;
		               p->ap=nuevo;
		               p = p->ap;
				}
				thatP = thatP->ap;
			}
		}
	}
	return *this;
}

//===========================================================================
template <class Tipo>
bool Pila<Tipo>::Vacia()
{
  return Tope == NULL;
};

//===========================================================================
template <class Tipo>
bool Pila<Tipo>::Llena()
{
  Apuntapila p;
  p = new Nodopila<Tipo>;
  if (p == NULL)
    return true;
  else
  {
    delete p;
    return false;
  }
};

//===========================================================================
template <class Tipo>
bool Pila<Tipo>:: Insertar(Tipo &Valor)
{
  Apuntapila nuevo;
  if (!Llena())
  {
    nuevo = new Nodopila<Tipo>;
    nuevo->info = Valor;
    nuevo->ap = Tope;
    Tope = nuevo;
    return true;
  }
  else
    return false;
};

//===========================================================================
template <class Tipo>
bool Pila<Tipo>::Remover(Tipo &Valor)
{
  Apuntapila viejo;
  if (!Vacia())
  {
    viejo = Tope;
    Valor = viejo->info;
    Tope = Tope->ap;
    delete viejo;
    return true;
  }
  else
    return false;
};

//===========================================================================
template <class Tipo>
Nodopila<Tipo>* Pila<Tipo>::ObtTope() const
{
  return Tope;
};

//===========================================================================
template <class Tipo>
void Pila<Tipo>::AsigTope(Nodopila<Tipo> *p)
{
  Tope = *p;
};

//===========================================================================
template <class Tipo>
Tipo Pila<Tipo>::ObtInfo(Nodopila<Tipo> *p)
{
  return p->info;
};         

//===========================================================================
template <class Tipo>
void Pila<Tipo>::AsigInfo(Nodopila<Tipo> *p,Tipo x)
{
  p->info = x;
};         
	     
template <class Tipo>
int Pila<Tipo>::Contar()
{
	 Nodopila<Tipo> *reco = Tope;
	    int cont = 0;
	    while (reco != NULL)
	    {
	        cont++;
	        reco = reco->ap;
	    }
	    return cont;
};





