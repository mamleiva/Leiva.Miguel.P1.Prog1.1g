#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#define TAM_CADENA 50
#define TAM 10
#include "hardcodeo.h"

//hardcodeo
int id[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


char nombre[10][50] =
{
    "nombre1",
    "nombre2",
    "nombre3",
    "nombre4",
    "nombre5",
    "nombre6",
    "nombre7",
    "nombre8",
    "nombre9",
    "nombre10"
};

char tipo[10] =
{
    'a',
    't',
    'r',
    'g',
    'r',
    'g',
    'f',
    'd',
    'c',
    'b'
};

float efectividad[10] = {90, 80, 70, 60, 90, 50, 40, 50, 80, 90};



int hardcodeo(eVacuna lista[], int tam, int cant)
{

    int contador = -1;
    if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam )
    {
        contador = 0;
        for(int i=0; i < cant; i++)
        {
            //strcpy(lista[i]., procesador[i]);
            strcpy(lista[i].nombre, nombre[i]);
            lista[i].id = id[i];
            lista[i].efectividad = efectividad[i];
            lista[i].tipo = tipo[i];
            contador++;
        }
    }
    return contador;
}//finhardcodeo

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

int mostrarVectores(eVacuna lista[], int tam)
{
    int todoOk = 0;
    int flag = 1;
    if(lista != NULL && tam > 0)
    {
        printf("   ***Listado de Vacunas***\n\n");
        printf("   id         Nombre       Tipo        Efectividad\n");
        printf("----------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            mostrarVector(lista[i]);
                flag = 0;
        }
        if(flag)
        {
            printf("   No hay vacunas para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

/** \brief imprime todos los datos de las personas y llama a la funcion que trae el string de la decripcion
 * y lo guarda en el vector "descLocalidad"
 * \param vector de persona con su numero de indice
 * \param vector tipo struct  de localidades
 * \param tam del vector de localidades
 * \return no devuelve nada
 *
 */
void mostrarVector(eVacuna lista)
{
    printf("   %d  %10s     %15c       %.2f\n",
           lista.id,
           lista.nombre,
           lista.tipo,
           lista.efectividad
          );
}
