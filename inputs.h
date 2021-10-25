#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define VERDADERO 1
#define FALSO 0
#define MIN 1
#define MAX 5

#ifndef BIBLIOTECA_UTN_H_INCLUDED
#define BIBLIOTECA_UTN_H_INCLUDED
//####################################### MENUS #######################################
int menuDeModificaciones();
int menu();

//####################################### NUMEROS #######################################
int utn_myGets(char *input, int tam);
//funciones de Strings
int utn_esString(char *input, int tam);
int utn_getString(char *pResultado, int tam, char mensaje[], char mensajeError[], int reintentos); //esta es la del tp2

//funciones de numeros enteros
int getInt(int *pResultado);
int esNumerica(char *input, int tam);
int utn_getNumero(int *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);

//funciones de numeros float
int utn_getNumeroFlotanteConMinMax(float *pResultado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos);
int utn_getNumeroFlotanteSinMinMax(float *pResultado, char mensaje[], char mensajeError[]);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

//funciones de enteros con minimos y maximos
int getIntMinMax(char *mensaje, int min, int max);
int getValidIntMinMax(int* numero, char* mensaje, int min, int max);

//confirmacion "S" "N"
char getConfirmacion(char mensaje[]);

//funciones de char

int utn_pedirCaracter(char* caracter, char* mensaje, char* mensajeError, char caracter1, char caracter2);



//######################PARA REVISAR###########################################

int utn_getStringCaracteres(char *pResultado, int tam, char mensaje[], char mensajeError[], int reintentos);

int getStringCaracteres(char *pResultado, int tam);

int my_getIntdetp(char *mensaje);

int getValidInt(int* numero, char *mensaje);

char getChar(char mensaje[]);

int my_getValidChar(char* letra);

void getString_tp(char mensaje[], char cadena[]);

int getStringLetras(char cadena[]);

void my_pedirCadenaSoloLetras (char mensaje[], char cadena[]);

void my_firstToUpper(char cadena[]);

int getValidFloat(float* numero, char* mensaje);


#endif // INPUTS_H_INCLUDED
