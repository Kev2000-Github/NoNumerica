#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#include "../MPersona.h"

MPersona::MPersona(string _nombre = "John", string _apellido = "Cena", string _cedula = "V14553201") {
	nombre = _nombre;
	apellido = _apellido;
	cedula = _cedula;
}
MPersona::MPersona(){
	
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
