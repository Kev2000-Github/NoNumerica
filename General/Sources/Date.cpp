#include <iostream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
using namespace std;
#include "../Date.h"
#include "../VGeneral.h"

Date::Date(){

}

Date::Date(int _dia, int _mes, int _annio){
	dia=_dia;
	mes=_mes;
	annio=_annio;

}

Date::Date(string fecha) {
	string aux = "";
	stringstream ss;
	int slashCounter = 0;
	for(unsigned int i = 0; i < fecha.length(); i ++){
		if(fecha[i] == '/'){
			ss << aux;
			if(slashCounter == 0) ss >> dia;
			else ss >> mes;
			slashCounter++;
			ss.clear();
			aux="";
		}
		else{
			aux += fecha[i];
		}
	}
	ss.clear();
	ss << aux;
	ss >> annio;
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
string Date::getFecha(){
	return parseFecha(dia, mes, annio);
}

string Date::parseFecha(int _dia, int _mes, int _annio){
	VGeneral vg;
	string fecha;
	if(_dia < 10) fecha += "0";
	fecha += vg.toString(_dia) + "/";
	if(_mes < 10) fecha += "0";
	fecha += vg.toString(_mes) + "/" + vg.toString(_annio);
	return fecha;
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

string Date::avanzarFecha(int dias) {
	VGeneral vg;
	int annioA = annio;
	int mesA = mes;
	int diaA = dia;
	int diasMes = NumeroDiasAnnio(mes, annio);

	int diasR = min(diasMes - diaA, dias);
	diaA += diasR;
	dias -= diasR;
	while (dias > 0) {
		diasMes = NumeroDiasAnnio(mesA, annioA);
		diasR = min(dias, diasMes);
		diaA = diasR;
		dias -= diasR;
		if (mesA == 12) {
			mesA = 1;
			annioA++;
		} else{
			mesA++;}
	}
	string fecha = parseFecha(diaA,mesA,annioA);
	return fecha;

}

void Date::setFecha(string fecha){
	string aux = "";
	stringstream ss;
	int slashCounter = 0;
	for(unsigned int i = 0; i < fecha.length(); i ++){
		if(fecha[i] == '/'){
			ss << aux;
			if(slashCounter == 0) ss >> dia;
			else ss >> mes;
			slashCounter++;
			ss.clear();
			aux="";
		}
		else{
			aux += fecha[i];
		}
	}
	ss.clear();
	ss << aux;
	ss >> annio;
}

bool Date::esMayor(Date fecha2){
	if(annio > fecha2.getannio()) return true;
	else if(annio < fecha2.getannio()) return false;

	if(mes > fecha2.getmes()) return true;
	else if(mes < fecha2.getmes()) return false;

	if(dia > fecha2.getdia()) return true;
	else if(dia < fecha2.getdia()) return false;

	return false;
}
