#ifndef HARDCODEO_H_INCLUDED
#define HARDCODEO_H_INCLUDED

typedef struct
{
    int id;
    char nombre[50];
    char tipo;
    float efectividad;
}eVacuna;


int hardcodeo(eVacuna lista[], int tam, int cant);
int ordenarMarcaPrecio(eVacuna list[], int len);
void mostrarVector(eVacuna lista);
int mostrarVectores(eVacuna lista[], int tam);


#endif // HARDCODEO_H_INCLUDED
