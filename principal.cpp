#include <iostream>
#include <cstdlib>
#include "General/Lista.h"
#include "General/Pila.h"
#include "General/Cola.h"
#include "General/Date.h"
using namespace std;

int main(){
	Date date1("26/06/2021");
	Date date2("20/06/2021");
	cout << "DIFERENCIAS EN DIAS: " << date1.DiferenciaDias(date2) << endl;

	return 0;
}
