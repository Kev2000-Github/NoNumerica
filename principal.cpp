#include <iostream>
#include <cstdlib>
#include "General/Lista.h"
#include "General/Pila.h"
#include "General/Cola.h"
using namespace std;

int main(){
	Lista<int> list1;
	Pila<int> pila1;
	Cola<int> cola1;
	list1.InsComienzo(1);
	pila1.Insertar(2);
	cola1.Insertar(3);
	cout << "MAIN"<<endl;
	cout << list1.ObtInfo(list1.ObtPrimero()) << endl;
	cout << pila1.ObtInfo(pila1.ObtTope()) << endl;
	int value;
	cola1.Remover(value);
	cout << value << endl;
	cola1.Insertar(value);

	return 0;
}
