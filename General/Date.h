#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
using namespace std;

class Date{

private:
        int dia;
        int mes;
        int annio;

public:
         Date(string fecha);
         void setdia(int d1);
	     void setmes(int m1);
	     void setannio(int a1);
	     int getdia();
	     int getmes();
         int getannio();

         int Bisiesto(int annio);
         int NumeroDiasAnnio(int mes,int annio);
         int DiferenciaDias(Date fecha2);
};

#endif // DATE_H_INCLUDED
