#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#include "../Date.h"

Date::Date() {
}
void Date::setdia1(int d1){
	dia1=d1;
}
void Date::setmes1(int m1){
	mes1=m1;
}
void Date::setannio1(int a1){
	annio1=a1;
}
int Date::getdia1(){
	return dia1;
}
int Date::getmes1(){
	return mes1;
}
int Date::getannio1(){
	return annio1;
}

void Date::setdia2(int d2){
	dia2=d2;
}
void Date::setmes2(int m2){
	mes2=m2;
}
void Date::setannio2(int a2){
	annio2=a2;
}
int Date::getdia2(){
	return dia2;
}
int Date::getmes2(){
	return mes2;
}
int Date::getannio2(){
	return annio2;
}


int Date::Bisiesto(int annio){
    if((annio%4==0 && annio%100!=0) || annio%400==0 )   //si es mes es bisiesto
    	return 1;
    else
    	return 0;
}
int Date::NumeroDiasAnnio(int mes, int annio){
    // enero, marzo, mayo, julio, agosto, octubre, diciembre contar 31 dias
    if( mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12 )
        return 31;

    // abril, junio, septiembre, nov cuenta 30 dias
    if( mes==4 || mes==6 || mes==9 || mes==11 )
        return 30;

    else //Febrero
    {
        int n=Bisiesto(annio);
        if(n==1)
        return 29;

        else
        return 28;
    }
}
int Date::DiferenciaDias(int dia1,int mes1, int annio1, int dia2, int mes2, int annio2)
{
    if(annio1==annio2) //anio igual
    {
        if(mes1==mes2)
        {
            if(dia1==dia2)
                return 0;
            else
                return abs(dia1-dia2);
        }
        else if(mes1<mes2)
        {
            int result=0;
            for(int i=mes1; i<mes2; i++)
            result=result+NumeroDiasAnnio(i,annio1);

            if(dia1==dia2)
                return result;
            else if(dia1<dia2)
            {
                result=result+(dia2-dia1);
                return result;
            }
            else
            {
                result=result-(dia1-dia2);
                return result;
            }
        }
        else
        {
            int result=0;
            for(int i=mes2; i<mes1; i++)
            result=result+NumeroDiasAnnio(i,annio1);

            if(dia1==dia2)
                return result;
            else if(dia2<dia1)
            {
                result=result+(dia1-dia2);
                return result;
            }
            else
            {
                result=result-(dia2-dia1);
                return result;
            }
        }
    }
    else if(annio1<annio2)
    {
        int temp=0;  //eu
        for(int i=annio1; i<annio2; i++)
        {
            if(Bisiesto(i))
                temp=temp+366;
            else
                temp=temp+365;
        }

        if(mes1==mes2)
        {
            if(dia1==dia2)
                return temp;
            else if(dia1<dia2)
                return temp+(dia2-dia1);
            else
                return temp-(dia1-dia2);
        }
        else if(mes1<mes2)
        {
            int result=0;
            for(int i=mes1; i<mes2; i++)
            result=result+NumeroDiasAnnio(i,annio2);

            if(dia1==dia2)
                return temp+result;
            else if(dia1<dia2)
            {
                result=result+(dia2-dia1);
                return temp+result;
            }
            else
            {
                result=result-(dia1-dia2);
                return temp+result;
            }
        }
        else
        {
            int result=0;
            for(int i=mes2; i<mes1; i++)
            result=result+NumeroDiasAnnio(i,annio2);

            if(dia1==dia2)
                return temp-result;
            else if(dia2<dia1)
            {
                result=result+(dia1-dia2);
                return temp-result;
            }
            else
            {
                result=result-(dia2-dia1);
                return temp-result;
            }
        }
    }
    else
    { // lo necesitamos?
        int temp=0;
        for(int i=annio2; i<annio1; i++)
        {
            if(Bisiesto(i))
                temp=temp+366;
            else
                temp=temp+365;
        }

        if(mes1==mes2)
        {
            if(dia1==dia2)
                return temp;
            else if(dia2<dia1)
                return temp+(dia1-dia2);
            else
                return temp-(dia2-dia1);
        }
        else if(mes2<mes1)
        {
            int result=0;
            for(int i=mes2; i<mes1; i++)
            result=result+NumeroDiasAnnio(i,annio1);

            if(dia1==dia2)
                return temp+result;
            else if(dia2<dia1)
            {
                result=result+(dia1-dia2);
                return temp+result;
            }
            else
            {
                result=result-(dia2-dia1);
                return temp+result;
            }
        }
        else
        {
            int result=0;
            for(int i=mes1; i<mes2; i++)
            result=result+NumeroDiasAnnio(i,annio1);

            if(dia1==dia2)
                return temp-result;
            else if(dia1<dia2)
            {
                result=result+(dia2-dia1);
                return temp-result;
            }
            else
            {
                result=result-(dia1-dia2);
                return temp-result;
            }
        }
    }
}
