#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
using namespace std;

class Date{

private:
        int dia1;
        int mes1;
        int annio1;
        int dia2;
        int mes2;
        int annio2;

public:
         Date();
         void setdia1(int d1);
	     void setmes1(int m1);
	     void setannio1(int a1);
	     int getdia1();
	     int getmes1();
         int getannio1();
         void setdia2(int d2);
	     void setmes2(int m2);
	     void setannio2(int a2);
         int getdia2();
	     int getmes2();
         int getannio2();

         int Bisiesto(int annio);
         int NumeroDiasAnnio(int mes,int annio);
         int DiferenciaDias(int dia1,int mes1, int annio1, int dia2, int mes2, int annio2);

};

#endif // DATE_H_INCLUDED
