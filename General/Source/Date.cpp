#include <iostream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
using namespace std;
#include "../Date.h"

Date::Date(string fecha) {
	string aux = "";
	stringstream ss;
	int slashCounter = 0;
	for(unsigned int i = 0; i < fecha.length(); i ++){
		if(fecha[i] == '/'){
			ss << aux;
			switch(slashCounter){
				case 0:
					ss >> dia;
					break;
				case 1:
					ss >> mes;
					break;
				default:
					ss >> annio;
					break;
			}
			slashCounter++;
		}
		else{
			aux += fecha[i];
		}
	}
}

void Date::setdia(int d1){
	dia=d1;
}
void Date::setmes(int m1){
	mes=m1;
}
void Date::setannio(int a1){
	annio=a1;
}
int Date::getdia(){
	return dia;
}
int Date::getmes(){
	return mes;
}
int Date::getannio(){
	return annio;
}

int Date::Bisiesto(int annio){
    if((annio%4==0 && annio%100!=0) || annio%400==0 )   //si es mes es bisiesto
    	return 1;
    else
    	return 0;
}

int Date::NumeroDiasAnnio(int mes,int annio){
    // enero, marzo, mayo, julio, agosto, octubre, diciembre contar 31 dias
    if( mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12 )
        return 31;

    // abril, junio, septiembre, nov cuenta 30 dias
    if( mes==4 || mes==6 || mes==9 || mes==11 )
        return 30;

    else //Febrero
    {
        int n= Bisiesto(annio);
        if(n==1)
        return 29;

        else
        return 28;
    }
}
int Date::DiferenciaDias(Date fecha2)
{
    if(annio==fecha2.getannio()) //anio igual
    {
        if(mes==fecha2.getmes())
        {
            if(dia==fecha2.getdia())
                return 0;
            else
                return abs(dia-fecha2.getdia());
        }
        else if(mes<fecha2.getmes())
        {
            int result=0;
            for(int i=mes; i<fecha2.getmes(); i++)
            result=result + NumeroDiasAnnio(i,annio);

            if(dia==fecha2.getdia())
                return result;
            else if(dia<fecha2.getdia())
            {
                result=result+(fecha2.getdia() - dia);
                return result;
            }
            else
            {
                result=result-(dia - fecha2.getdia());
                return result;
            }
        }
        else
        {
            int result=0;
            for(int i=fecha2.getmes(); i<mes; i++)
            result=result + NumeroDiasAnnio(i,annio);

            if(dia==fecha2.getdia())
                return result;
            else if(fecha2.getdia()<dia)
            {
                result=result+(dia-fecha2.getdia());
                return result;
            }
            else
            {
                result=result-(fecha2.getdia()-dia);
                return result;
            }
        }
    }
    else if(annio<fecha2.getannio())
    {
        int temp=0;  //eu
        for(int i=annio; i<fecha2.getannio(); i++)
        {
            if(Bisiesto(i))
                temp=temp+366;
            else
                temp=temp+365;
        }

        if(mes==fecha2.getmes())
        {
            if(dia==fecha2.getdia())
                return temp;
            else if(dia<fecha2.getdia())
                return temp+(fecha2.getdia()-dia);
            else
                return temp-(dia-fecha2.getdia());
        }
        else if(mes<fecha2.getmes())
        {
            int result=0;
            for(int i=mes; i<fecha2.getmes(); i++)
            result=result+NumeroDiasAnnio(i,fecha2.getannio());

            if(dia==fecha2.getdia())
                return temp+result;
            else if(dia<fecha2.getdia())
            {
                result=result+(fecha2.getdia()-dia);
                return temp+result;
            }
            else
            {
                result=result-(dia-fecha2.getdia());
                return temp+result;
            }
        }
        else
        {
            int result=0;
            for(int i=fecha2.getmes(); i<mes; i++)
            result=result+NumeroDiasAnnio(i,fecha2.getannio());

            if(dia==fecha2.getdia())
                return temp-result;
            else if(fecha2.getdia()<dia)
            {
                result=result+(dia-fecha2.getdia());
                return temp-result;
            }
            else
            {
                result=result-(fecha2.getdia()-dia);
                return temp-result;
            }
        }
    }
    else
    { // lo necesitamos?
        int temp=0;
        for(int i=fecha2.getannio(); i<annio; i++)
        {
            if(Bisiesto(i))
                temp=temp+366;
            else
                temp=temp+365;
        }

        if(mes==fecha2.getmes())
        {
            if(dia==fecha2.getdia())
                return temp;
            else if(fecha2.getdia()<dia)
                return temp+(dia-fecha2.getdia());
            else
                return temp-(fecha2.getdia()-dia);
        }
        else if(fecha2.getmes()<mes)
        {
            int result=0;
            for(int i=fecha2.getmes(); i<mes; i++)
            result=result+NumeroDiasAnnio(i,annio);

            if(dia==fecha2.getdia())
                return temp+result;
            else if(fecha2.getdia()<dia)
            {
                result=result+(dia-fecha2.getdia());
                return temp+result;
            }
            else
            {
                result=result-(fecha2.getdia()-dia);
                return temp+result;
            }
        }
        else
        {
            int result=0;
            for(int i=mes; i<fecha2.getmes(); i++)
            result=result+NumeroDiasAnnio(i,annio);

            if(dia==fecha2.getdia())
                return temp-result;
            else if(dia<fecha2.getdia())
            {
                result=result+(fecha2.getdia()-dia);
                return temp-result;
            }
            else
            {
                result=result-(dia-fecha2.getdia());
                return temp-result;
            }
        }
    }
}
