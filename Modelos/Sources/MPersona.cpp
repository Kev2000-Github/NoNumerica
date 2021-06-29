#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#include "../MPersona.h"

MPersona::MPersona() {
}
void MPersona::setnombre(string n){
	nombre=n;
}
void MPersona::setapellido(string a){
	apellido=a;
}
void MPersona::setcedula(string c){
	cedula=c;
}
string MPersona::getnombre(){
	return nombre;
}
string MPersona::getapellido(){
	return apellido;
}
string MPersona::getcedula(){
	return cedula;
}
