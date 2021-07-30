#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
using namespace std;

class Date{

private:
        int dia;
        int mes;
        int annio;

public:
         Date();
         Date(int _dia, int _mes, int _annio);
         Date(string fecha);
         void setdia(int d1);
	     void setmes(int m1);
	     void setannio(int a1);
	     void setFecha(string fecha);
	     bool esMayor(Date fecha);
	     int getdia();
	     int getmes();
         int getannio();
         string getFecha();
         string parseFecha(int _dia, int _mes, int _annio);

         int Bisiesto(int annio);
         int NumeroDiasAnnio(int mes,int annio);
         int DiferenciaDias(Date fecha2);

         string avanzarFecha(int dia);

};

#endif // DATE_H_INCLUDED
