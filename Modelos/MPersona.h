#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
using namespace std;
#include <string>

class MPersona
{

private:
        string nombre;
        string apellido;
        string cedula;

public:
        MPersona();
        MPersona(string _nombre, string _apellido, string _cedula);
        void setnombre(string n);
        void setapellido(string a);
        void setcedula(string c);
        string getnombre();
        string getapellido();
        string getcedula();
};

#endif // PERSONA_H_INCLUDED
