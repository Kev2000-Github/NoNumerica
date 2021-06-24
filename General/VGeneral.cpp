/*
 *  VGeneral.cpp
 *  Creado: 16/02/2011
 *  Autores: Prof. Margarita Pereira, Prof. Rosa Díaz,
 *                 Prof. Giovanni Torrealba, Prof. Luis Pereira
 *  Ajustado: 07/05/2012 Prof. Margarita Pereia
 */

#include "VGeneral.h"
VGeneral::VGeneral(){}
//--------------------------------------------------------------------------
// ****************METODOS GENERALES EFECTOS DE PANTALLA********************
//--------------------------------------------------------------------------
// Permite hacer una pausa
void VGeneral::Pausa()
{
   system("pause");
}
// Blanquea la pantalla
void VGeneral::Limpiar()
{
   system("cls");
}
// Imprime dos lineas de Encabezado consecutivas
void VGeneral::ImprimirEncabezado(string msj1, string msj2)
{
   cout << msj1 << endl;
   cout<< msj2 << endl << endl;
}
// Imprime un mensaje en la pantalla
void VGeneral::ImprimirMensaje (string msj)
{
   cout << msj;
}
// Imprime una secuencia de lineas en blanco de acuerdo a la cantidad
// especificada en el parametro ct
void VGeneral::ImprimirLineasBlanco(int ct)
{
   for (int i = 0; i < ct; ++i)
	   cout << endl;
}
//-------------------------------------------------------------------------
// ****************METODOS PARA LEER DATOS POR TECLADO ********************
//-------------------------------------------------------------------------
// Escribe un mensaje y leer una variable char
char VGeneral :: LeerChar(string msj)
{
    char n;
    cout<<msj;
    cin>>n;
    return n;
}
// Escribe un mensaje y lee una variable sring
string VGeneral::LeerString(string msj)
{
   string dato;
   do
     { cout<<msj;
       cin.sync();
       getline(cin,dato);
       if (dato.size() == 0)  // No escribio nada
           ImprimirMensaje("\n Dato no v\xa0lido \n");
     } while (dato.size() == 0);
    return dato;
}
// Escribe un mensaje y lee un valor numerico sin decimales (variable int, long)
long VGeneral::LeerNro(string msj)
{
   /*long c;
   cout<<msj;
   cin>>c;
   return c;*/
   long dato;
   int valido;
   string s;
	do
	   {  valido = 0;
	      s = LeerString(msj);
	      for(unsigned int i=0; i<s.size(); i++)
	       { if(!(s[i]>='0' and s[i]<= '9'))
	           {  ImprimirMensaje("\n Dato no v\xa0lido \n");
	              valido = -1;
	              break;
	           }
	        }  // for
	      } while(valido == -1);
	      dato = atof(s.c_str());
	   return dato;
}
// Lee y valida un valor numerico sin decimales (int, long) en un rango de valores
long VGeneral::LeerValidarNro(string msj, long valorinicial, long valorfinal)
{    
 long dato;
 do 
  { dato=LeerNro(msj);
    if (dato<valorinicial or dato>valorfinal)
        ImprimirMensaje("\n Dato no v\xa0lido \n");
  } while (dato<valorinicial or dato>valorfinal);
 return dato;
}
// Lee y valida un valor numerico sin decimales (int, long) con un valor inicial
long VGeneral::LeerValidarNroValorInicial(string msj, long valorinicial)
{
 long dato;
 do
  { dato=LeerNro(msj);
    if (dato<valorinicial)
    	ImprimirMensaje("\n Dato no v\xa0lido \n");
  } while (dato<valorinicial);
 return dato;
}
// Lee y valida valor numerico sin decimales (int, long) con un valor final
long VGeneral::LeerValidarNroValorFinal(string msj, long valorfinal)
{
 long dato;
 do
  { dato=LeerNro(msj);
    if (dato>valorfinal)
    	ImprimirMensaje("\n Dato no v\xa0lido \n");
  } while (dato>valorfinal);
 return dato;
}
// Escribe un mensaje y leer una variable numerica con decimales (float, double)
double VGeneral::LeerNroDecimal(string msj)
{
   double dato;
   int valido,cont;
   string s;

   do
   {  valido = 0;
      cont = 0;
      s = LeerString(msj);
      for(unsigned int i=0; i<s.size(); i++)
       { if(s[i] == '.')
            cont += 1;
         if(!(s[i]>='0' and s[i]<= '9') and (s[i]!='-') && (s[i] != '.'))
           {  ImprimirMensaje("\n Dato no v\xa0lido \n");
              valido = -1;
              break;
           }
          if(cont > 1)
            {  ImprimirMensaje("\n Dato no v\xa0lido \n");
               valido = -1;
               break;
            }
        }  // for
      } while(valido == -1);
      dato = atof(s.c_str());
   return dato;
}
// Lee y valida un valor numerico con decimales (float, double) en un rango de valores
double VGeneral :: LeerValidarNroDecimal(string msj,double valorinicial,double valorfinal)
{ double dato;
	do
	  { dato=LeerNroDecimal(msj);
	    if (dato<valorinicial or dato>valorfinal)
	    	ImprimirMensaje("\n Dato no v\xa0lido \n");
	   } while (dato < valorinicial or dato>valorfinal);
	 return dato;
}
// Lee y valida un valor numerico con decimales (float, double) con un valor inicial
double VGeneral :: LeerValidarNroDecimalValorInicial(string msj,double valorinicial)
{ double dato;
	do
	  { dato=LeerNroDecimal(msj);
	    if (dato<valorinicial)
	    	ImprimirMensaje("\n Dato no v\xa0lido \n");
	   } while (dato < valorinicial);
	 return dato;
}
// Lee y valida un valor numerico con decimales (float, double) con un valor final
double VGeneral :: LeerValidarNroDecimalValorFinal(string msj,double valorfinal)
{ double dato;
	do
	  { dato=LeerNroDecimal(msj);
	    if (dato>valorfinal)
	    	ImprimirMensaje("\n Dato no v\xa0lido \n");
	   } while (dato>valorfinal);
	 return dato;
}
//------------------------------------------------------------------------------
// ****************METODOS PARA IMPRIMIR A NIVEL DE PANTALLA********************
//------------------------------------------------------------------------------
// Escribe un mensaje e imprime un dato de tipo char
void VGeneral :: ImprimirChar(string msj, char c)
{
     cout << msj << c;
}
// Escribe un mensaje e imprime un dato de tipo string
void VGeneral :: ImprimirString(string msj, string s)
{
     cout << msj << s;
}
// Escribe un mensaje e imprime un dato numerico (int,long)
void VGeneral :: ImprimirNro(string msj, long n)
{
    cout << msj << n;
}
// Escribe un mensaje e imprime un dato de tipo float
// usando un formato fijo con una precision de dos decimales
void VGeneral :: ImprimirNroDecimal(string msj, double f)
{
     cout << msj <<setiosflags(ios::fixed) << setprecision(2)<< f;
}

//------------------------------------------------------------------------------
// ****************METODOS PARA IMPRIMIR A NIVEL DE PANTALLA DE MANERA JUSTIFICADA********************
//------------------------------------------------------------------------------

// Imprime un dato de tipo char justificado
void VGeneral :: ImprimirCharJustificado(char c, int espacio)
{
     cout << setw(espacio) << c;
}
// Imprime un dato de tipo string justificado
void VGeneral :: ImprimirStringJustificado(string s, int espacio)
{
     cout << setw(espacio) << s;
}

// Imprime un dato de tipo numerico justificado
void VGeneral :: ImprimirNroJustificado(long n, int espacio)
{
    cout << setw(espacio) << n;
}
// Imprime un dato de tipo float justificado
// usando un formato fijo con una precision de dos decimales
void VGeneral :: ImprimirNroDecimalJustificado(double f, int espacio)
{
     cout << setw(espacio) <<setiosflags(ios::fixed) << setprecision(2)<< f;
}

//-------------------------------------------------------------------------------------------------
// ****************METODOS PARA TRABAJAR CON ARCHIVOS TEXTO DE ENTRADA DE DATOS********************
//-------------------------------------------------------------------------------------------------
// Permite Leer el nombre físico del archivo
// Aporte de Tapias Jean Carlos
// http://www.cplusplus.com/reference/clibrary/cstdio/fgets/
/* Lee el nombre físico del archivo a nivel de teclado y si es necesario se puede
   incluir la ruta donde se localiza el archivo */
void VGeneral::LeerNombreArchivo(string msj, char V[128])
{
    cout << msj;
    fflush(stdin);               // Limpia el buffer del teclado.(stdin)
    fgets (V, 128 , stdin);      // Metodo que funciona igual al getline..
    V[strlen(V)-1] = '\0';

}
// Permite abrir un archivo de entrada
bool VGeneral :: AbrirArchivoEntrada (std::ifstream &archivo, char nomb_arch [120])
{
   archivo.open (nomb_arch, ios::in);
   return archivo.is_open();
}
// Lee una linea completa del archivo
string VGeneral :: LeerLineaArchivo(std::ifstream &archivo)
{
   string linea;
   getline(archivo, linea);
   return linea;
}
// Lee un dato char  del archivo
char VGeneral :: LeerDatoCharArchivo(std::ifstream &archivo)
{
   char caracter;
   archivo >> caracter;
   string resto;
   getline(archivo, resto);
   return caracter;
}
// Lee del archivo un dato numérico sin decimales (long, int)
long VGeneral :: LeerDatoNroArchivo(std::ifstream &archivo)
{
   long nro;
   archivo >> nro;
   string resto;
   getline(archivo, resto);
   return nro;
}
// Lee del archivo un dato numérico con decimales (float, dobule)
double VGeneral :: LeerDatoNroDecimalArchivo(std::ifstream &archivo)
{
   double nro;
   archivo >> nro;
   string resto;
   getline(archivo, resto);
   return nro;
}
// Chequea si el archivo llego al fin
bool VGeneral :: FinArchivo (std::ifstream &archivo)
{
   return archivo.eof();
}
// Cierra el archivo
void VGeneral :: CerrarArchivoEntrada (std::ifstream &archivo)
{
   archivo.close();
}
//---------------------------------------------------------------------------------------
// ****************METODOS PARA TRABAJAR CON ARCHIVOS TEXTO DE SALIDA********************
//---------------------------------------------------------------------------------------
// Permite abrir un archivo de salida
bool VGeneral :: AbrirArchivoSalida (std::ofstream &archivo, char nomb_arch [128])
{
   archivo.open (nomb_arch, ios::out);
   return archivo.is_open();
}
// Graba en el archivo una linea de caracteres en el archivo
void VGeneral :: GrabarLineaArchivo(std::ofstream &archivo, string linea)
{
   archivo << linea << endl;
}
// Graba en el archivo una linea con un dato char
void VGeneral :: GrabarDatoCharArchivo(std::ofstream &archivo, char caracter)
{
   archivo << caracter << endl;
}
// Graba en el archivo una línea con un dato numérico sin decimales (int, long)
void VGeneral :: GrabarDatoNroArchivo(std::ofstream &archivo, long nro)
{
    archivo << nro << endl;
}
// Graba en el archivo una línea con un dato numérico con decimales (float, double)
void VGeneral :: GrabarDatoNroDecimalArchivo(std::ofstream &archivo, double nro)
{
    archivo << setiosflags(ios::fixed) << setprecision(2) << nro << endl;
}
// Cierra el archivo de salida
void VGeneral :: CerrarArchivoSalida (std::ofstream &archivo)
{
   archivo.close();
}
