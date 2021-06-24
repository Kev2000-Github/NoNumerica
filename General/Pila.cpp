template <class Tipo>
Pila<Tipo>::Pila()
{
  Tope = NULL;
};

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
bool Pila<Tipo>:: Insertar(Tipo Valor)
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
Nodopila<Tipo>* Pila<Tipo>::ObtTope()
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
	     



