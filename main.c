#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#define TAM_CADENA 50
#define TAM 10

float aplicarAumento(int precioSinAumento);
int reemplazarCaracteres(char cadenacaracteres[], char primerCaracter, char segundoCaracter);

/*
3. Dada la siguiente estructura generar una función que permita ordenar un array de dicha estructura por tipo.
Ante igualdad de tipo deberá ordenarse por efectividad creciente. Hardcodear datos y mostrarlos desde el main. *

*/
typedef struct
{
    int id;
    char nombre[50];
    char tipo;
    float efectividad;
} eVacuna;


int main()
{
    float precio;
    float precioConAumento;
    char cadenaCaracteres[TAM_CADENA];
    eVacuna vacunas[TAM];


    //lamada a la funcion
    utn_getNumeroFlotante(&precio, "Ingrese el precio del producto: ", "Error! reingrese precio: \n", 0, 500000, 10);
    if(precio > 0)
    {
        precioConAumento = aplicarAumento(precio);
        printf("El precio sin descuento es: %.2f. Con el descuento del 5%%, es: \"%.2f\"\n",precio, precioConAumento);
    }
    else
    {
        printf("El precio debe ser mayor a cero.\n");
    }

    //llamada a la funcion que cambia los caracteres
    utn_getStringCaracteres(cadenaCaracteres, TAM_CADENA, "Ingrese la cadena a la que se le remplazaran algunos caracteres: ", "Error! ingrese una cadena valida", 10);
    printf("--------------------------------------------------\n");
    printf("La cantidad de cambios es: \"%d\"\n ", reemplazarCaracteres(cadenaCaracteres, 'M', 'Z'));
    printf("la palabra con  los cambios quedo asi: %s \n", cadenaCaracteres);
    printf("--------------------------------------------------\n\n");
    system("pause");

/*
    //hardcodeo
    int id[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


    char nombre[2][50] =
    {
        "nombre1",
        "nombre2"
    };

    char tipo[2][50] =
    {
        "tipo1",
        "tipo2"
    };

    float efectividad[10] = {90.000, 80.500, 70.200, 60.800, 90.900, 50.000, 160.000, 150.000, 180.000, 150.000};

*/
    /*
    int hardcodeo(eVacuna lista[], int tam, int cant, int* pId)
    {
       int contador = -1;
       if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
       {
           contador = 0;
           for(int i=0; i < cant; i++)
           {
               lista[i].id = *pId; //con el * accedemos al valor del puntero.
               (*pId)++;
               strcpy(lista[i].procesador, procesador[i]);
               strcpy(lista[i].marca, marca[i]);
               lista[i].precio = precio[i];
               lista[i].isEmpty = 0;
               contador++;
           }
       }


       return contador;
    }
       */


    return 0;
}




/*
1. Crear una función llamada aplicarAumento que reciba como parámetro el precio de un producto
y devuelva el valor del producto con un aumento del 5%. Realizar la llamada desde el main. *

*/
float aplicarAumento(int precioSinAumento)
{
    float precioFinal = 0;
    float aumento;
    if(precioSinAumento >0) //si el precio es mayor a cero saco aumento
    {
        aumento = ( (float)(precioSinAumento * 5)) /100;
        precioFinal = precioSinAumento + aumento ;
    }

    return precioFinal;

}


/*
2. Crear una función que se llame reemplazarCaracteres que reciba una cadena de caracteres como primer parámetro,
un carácter como segundo y otro carácter como tercero, la misma deberá reemplazar cada ocurrencia del segundo parámetro por el tercero
y devolver la cantidad de veces que se reemplazo ese carácter en la cadena *

*/

int reemplazarCaracteres(char cadenacaracteres[], char primerCaracter, char segundoCaracter)
{
    int cantidadCaracteres;
    int retorno = 0;
    int contadorCaracter = 0;

    //paso a minusculas
    cadenacaracteres = strlwr(cadenacaracteres);
    primerCaracter = tolower(primerCaracter);
    segundoCaracter = tolower(segundoCaracter);

    cantidadCaracteres = strlen(cadenacaracteres);

    for(int i =0; i < cantidadCaracteres; i++)
    {
        if(primerCaracter == cadenacaracteres[i])
        {
            cadenacaracteres[i] = segundoCaracter;
            contadorCaracter++;
        }
        retorno = contadorCaracter;
    }
    return retorno;
}

int ordenarMarcaPrecio(eVacuna list[], int len)
{
    int retorno = -1;
    eVacuna auxVacunas;
    if (list != NULL && len > 0)
    {
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                //si estan desordenadas las marcas.... o si el precio es mayor y son las mismas marcas.
                if( list[i].efectividad > list[j].efectividad  )
                {
                    auxVacunas = list[i];
                    list[i] = list[j];
                    list[j] = auxVacunas;
                }


            }
        }
        retorno = 0;
    }
    return retorno;
}
