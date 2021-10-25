/*
 * inputs.c
 *
 *  Created on: 14 oct. 2021
 *      Author: martinl
 */
#include "inputs.h"
static int getFloat(float* pResultado);
static int esFlotante(char* cadena);

//####################################### MENUS ##############################################
int menu()
{
    char opcion;

    system("cls");
    printf("        *** Menu de la Bicicleteria ***          \n");
    printf("-------------------------------------------------\n");
    printf("   A- Alta Avion\n");
    printf("   B- Modificar Avion\n");
    printf("   C- Baja Avion\n");
    printf("   D- Listar Aviones\n");
    printf("   E- Listar Tipos\n");
    printf("   E- Listar Destinos\n");
    printf("   E- Alta Vuelo\n");
    printf("   E- Listar Vuelos\n");
    printf("   Z- Salir\n");

    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = toupper(opcion);

    return opcion;
}

int menuDeModificaciones()
{
    int opcion;

    system("cls");
    printf("        *** Menu de Modificaciones ***          \n");
    printf("------------------------------------------------\n");
    printf("   1- Tipo\n");
    printf("   2- Material\n");
    printf("   3- Salir\n");

    printf("Ingrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}

//####################################### PEDIR DATOS ##############################################
/// @fn int myGets(char* input, int tam);
/// @brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un maximo
/// 		de longitud -1 caracteres
/// @param vector input Puntero donde se copiara la cadena obtenida
/// @param int tamano del vector de caracteres
/// @return 0 si obtiene una cadena, -1 si no
int utn_myGets(char *input, int tam)
{
    int retorno = -1;
    char bufferString[4096];

    if (input != NULL && tam > 0)
    {
        fflush(stdin);
        if (fgets(bufferString, sizeof(bufferString), stdin) != NULL) //valida que recibio algun dato
        {
            if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] == '\n') //cambia \n (string) lo cambia por \0
            {
                bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
            }
            if (strnlen(bufferString, sizeof(bufferString)) <= tam) //valida que no desbordo
            {
                strncpy(input, bufferString, tam); //copia el string al puntero input
                retorno = 0;
            }
        }
    }
    return retorno;
}

/// @fn int esString(char* input, int tam)
/// @brief verifica si la cadena es string
///
/// @param input puntero a donde se copia la cadena
/// @param tam tamanio de la cadena
/// @return

//#############Funciones de Strings#######################################
int esString(char *input, int tam)
{
    int i;
    int retorno = 0;

    if (input != NULL && tam > 0)
    {
        for (i = 0; input[i] != '\0' && i < tam; i++)
        {
            if (input[i] != ' ' && input[i] != '.' && (input[i] < 'A' || input[i] > 'Z') && (input[i] < 'a' || input[i] > 'z') && (input[i] < '0' || input[i] > '9'))
            {
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

/// @fn int getString(char* pResultado, int tam);
/// @brief obtiene un string y lo valida con la funcion esString(). a su vez esta funcion es llamada por utn_getString
///
/// @param pResultado puntero se deja el resultado de la funcion
/// @param tam tamanio max de la cadena
/// @return 0 si obtiene un entero, -1 si no
int getString(char *pResultado, int tam)
{
    int retorno = -1;
    char buffer[4096];

    if (pResultado != NULL && tam > 0)
    {
        if (utn_myGets(buffer, sizeof(buffer)) == 0 && strnlen(buffer, sizeof(buffer)) < tam && esString(buffer, sizeof(buffer)) == 0 )
        {
            strncpy(pResultado, buffer, tam);
            retorno = 0;
        }
    }
    return retorno;
}


/// @fn int utn_getString(char* pResultado, int tam, char mensaje[], char mensajeError[], int reintentos);
/// @brief pide una cadena al usuario, verifica llamando a la funcion getString(), y devuelve el resultado en *pResultado
///
/// @param pResultado puntero donde se dejara el resultado si salio ok
/// @param tam longitud del vector
/// @param mensaje mensaje a ser mostrado
/// @param mensajeError mensaje en caso de error
/// @param reintentos numero de veces que el usuario puede reintentar
/// @return 0 si obtiene un entero, -1 si no
int utn_getString(char *pResultado, int tam, char mensaje[], char mensajeError[], int reintentos)
{
    char bufferString[50];
    int retorno = -1;
    while (reintentos >= 0)
    {
        reintentos--;
        printf("%s", mensaje);
        if (getString(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < tam)
        {
            strncpy(pResultado, bufferString, tam);
            retorno = 0;
            break;
        }
        printf("%s", mensajeError);
    }
    return retorno;
}

//########################String con caracteres########################################

/// @fn int getStringCaracteres(char* pResultado, int tam);
/// @brief obtiene un string y lo valida con la funcion esString(). a su vez esta funcion es llamada por utn_getString
///
/// @param pResultado puntero se deja el resultado de la funcion
/// @param tam tamanio max de la cadena
/// @return 0 si obtiene un entero, -1 si no
int getStringCaracteres(char *pResultado, int tam)
{
    int retorno = -1;
    char buffer[4096];

    if (pResultado != NULL && tam > 0)
    {
        if (utn_myGets(buffer, sizeof(buffer)) == 0 && strnlen(buffer, sizeof(buffer)) < tam  )
        {
            strncpy(pResultado, buffer, tam);
            retorno = 0;
        }
    }
    return retorno;
}


/// @fn
/// @brief pide una cadena al usuario y permite caracteres, verifica llamando a la funcion getString(), y devuelve el resultado en *pResultado
///
/// @param pResultado puntero donde se dejara el resultado si salio ok
/// @param tam longitud del vector
/// @param mensaje mensaje a ser mostrado
/// @param mensajeError mensaje en caso de error
/// @param reintentos numero de veces que el usuario puede reintentar
/// @return 0 si obtiene un entero, -1 si no
int utn_getStringCaracteres(char *pResultado, int tam, char mensaje[], char mensajeError[], int reintentos)
{
    char bufferString[50];
    int retorno = -1;
    while (reintentos >= 0)
    {
        reintentos--;
        printf("%s", mensaje);
        if (getStringCaracteres(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < tam)
        {
            strncpy(pResultado, bufferString, tam);
            retorno = 0;
            break;
        }
        printf("%s", mensajeError);
    }
    return retorno;
}


//##############Funciones de Numeros enteros#########################

/// @fn int getInt valida que sea numerico y si es numero lo guarda en *pResultado
/// @brief Obtener un numero entero desde la terminal
///
/// @param pResultado Puntero donde se guardara el resultado de la funcion
/// @return Retorna 0 (exito) si se obtiene un entero y -1 (error)
///
int getInt(int *pResultado)
{
    int retorno = -1;
    char bufferString[50];
    if (pResultado != NULL &&
            utn_myGets(bufferString, sizeof(bufferString)) == 0 &&
            esNumerica(bufferString, sizeof(bufferString))) //valida numero que sea numero
    {
        retorno = 0;
        *pResultado = atoi(bufferString); //convierte a int
    }
    return retorno;
}

/// @fn int esNumerica(char* input, int tam);
/// @brief Verifica si la cadena ingresada es numerica, es llamada por la funcion getInt
///
/// @param input Puntero donde se dejara el resultado de la funcion
/// @param tam limite de la cadena
/// @return Retorna 1 si salio OK si la cadena es numero y -1 si no lo es.
///
int esNumerica(char *input, int tam)
{
    int retorno = 1; //verdadero

    if (input[0] == '\0' || input[0] == ' ') //valido que no presione enter, ni espacio al principio
    {
        retorno = 0;
    }

    for (int i = 0; i < tam && input[i] != '\0'; i++)
    {
        if (i == 0 && (input[i] == '+' || input[i] == '-'))
        {
            continue;
        }
        if ( input[i] > '9' || input[i] < '0' )
        {
            retorno = 0;
            break;
        }

    }
    return retorno;
}

/// @fn int utn_getNumero(int* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);
/// @brief Solicita el ingreso de un entero por mensaje y lo retorna por puntero pResultado
///
/// @param pResultado  Numero a retoronar
/// @param mensaje		Mensaje
/// @param mensajeError Mensaje Error
/// @param minimo		Rango minimo de numeros que puede ingresar
/// @param maximo		Rango maximo de numeros que puede ingresar
/// @param reintentos   Cantidad de reintentos
/// @return   return (1) If ok,   (0) Error, se quedo sin reintentos
int utn_getNumero(int *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int bufferInt;
    do
    {
        printf("%s", mensaje);
        if (getInt(&bufferInt) == 0 &&
                bufferInt >= minimo &&
                bufferInt <= maximo)
        {
            retorno = 0;
            *pResultado = bufferInt;
            break;
        }
        printf("%s", mensajeError);
        reintentos--;
    }
    while (reintentos >= 0);

    return retorno;
}

//###############funciones de numeros float###############

/// @fn int utn_getNumeroFlotanteConMinMax(float* pResultado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos);
/// @brief Solicita el ingreso de un numero y lo pasa a float por mensaje y lo retorna por puntero pResultado
///
/// @param pResultado  Numero a retoronar
/// @param mensaje		Mensaje
/// @param mensajeError Mensaje Error
/// @param minimo		Rango minimo de numeros que puede ingresar
/// @param maximo		Rango maximo de numeros que puede ingresar
/// @param reintentos   Cantidad de reintentos
/// @return   Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
int utn_getNumeroFlotanteConMinMax(float *pResultado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos)
{
    int retorno = -1;
    int bufferFloat;
    do
    {
        printf("%s", mensaje);
        if (getInt(&bufferFloat) == 0 && //si es numerico get int devuelve cero y lo guarda en bufferfloat
                bufferFloat >= minimo &&
                bufferFloat <= maximo)
        {
            retorno = 0;
            *pResultado = bufferFloat;
            break;
        }
        printf("%s", mensajeError);
        reintentos--;
    }
    while (reintentos >= 0);

    return retorno;
}

/// @fn pide numero float sin min y max, sin cantidad de reintentos
/// @brief Solicita el ingreso de un numero con la funcion getInt(), lo pasa a float y lo retorna por puntero pResultado
/// @param pResultado  Numero a retoronar
/// @param mensaje		Mensaje
/// @param mensajeError Mensaje Error
/// @return   Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
int utn_getNumeroFlotanteSinMinMax(float *pResultado, char mensaje[], char mensajeError[])
{
    int retorno = -1;
    int bufferFloat;
    int esNumero;
    do
    {
        printf("%s", mensaje);
        esNumero = getInt(&bufferFloat); //si es numerico get int devuelve cero y lo guarda en bufferfloat
        if (esNumero == 0 )
        {
            retorno = 0;
            *pResultado = bufferFloat;
            break;
        }
        printf("%s", mensajeError);
    }
    while (esNumero == -1);

    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
static int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}


/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
//#################Numeros con max y min########################

/**
 * @fn int getIntMinMax(char*, int, int) y llama a la funcion getValidIntMinMax() para validar
 * @brief obtiene un numero entre un rango minimo y maximo
 *
 * @param mensaje para mostrar, ingresarlo SIN ":" NI espacio, se agrega automaticamente con los min y max
 * @param min numero minimo a permitir
 * @param max numero maximo a permitir
 * @return devuelve el numero dentro de los valores
 */
int getIntMinMax(char *mensaje, int min, int max)
{
    int numero;
    while ((getValidIntMinMax(&numero, mensaje, min, max)) == -1)
    {
        printf("Error. Ingrese solo numeros entre el rango: [%d] y [%d] \n",
               min, max);
    }
    return numero;
}

/**
 * @fn int getValidIntMinMax(int*, char*, int, int)
 * @brief valida que el numero este en el rango y lo devuelve por puntero
 *
 * @param numero dir de mem del numero a analizar
 * @param mensaje a mostrar recibido por param
 * @param min numero minimo a analizar
 * @param max numero maximo a analizar
 * @return Devuelve -1 si no es un entero o es un entero mas otro valor no entero, o esta fuera de rango o 0 si es todo entero
 */
int getValidIntMinMax(int *numero, char *mensaje, int min, int max)
{
    int sePudo = 1;
    int esEspacio = 1;
    char cadenaCargada[20];
    int i;
    printf("%s entre [%d] y [%d]: ", mensaje, min, max);
    fflush(stdin);
    scanf("%[^\n]", cadenaCargada); //leer todo hasta que se encuentre \n
    for (i = 0; i < strlen(cadenaCargada); i++)
    {
        if (cadenaCargada[i] != '\0')
        {
            if (cadenaCargada[i] < '0' || cadenaCargada[i] > '9')
            {
                sePudo = -1;
            }
            if (cadenaCargada[i] != ' ')
            {
                esEspacio = -1;
            }
        }
    }
    if (esEspacio == 1)
    {
        sePudo = -1;
    }
    if (sePudo == 1)
    {
        *numero = atoi(cadenaCargada);
    }
    while (!(*numero >= min && *numero <= max)) //valido que este dentro del rango min y max.
    {
        sePudo = -1;
        break;
    }
    return sePudo;
}

//#######################CARACTERES##########################
/** \brief Pide un caracter lo pasa a minuscula y lo devuelve
 *
 * \param mensaje[] char Mensaje a mostrar
 * \return char Caracter ingresado
 *
 */
char getChar(char mensaje[])
{
    char letter;
    char auxchar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &auxchar);
    letter = tolower(auxchar);
    return letter;
}

int utn_pedirCaracter(char* caracter, char* mensaje, char* mensajeError, char caracter1, char caracter2)
{
	int todoOk = -1;
	char caracterIngresado;

	if(caracter != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c", &caracterIngresado);
		caracterIngresado = tolower(caracterIngresado);

		while(caracterIngresado != caracter1 && caracterIngresado != caracter2)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%c", &caracterIngresado);
			caracterIngresado = tolower(caracterIngresado);
		}
		*caracter=caracterIngresado;
		todoOk=0;
	}
	return todoOk;
}

//###############confirmacion#######################

/** \brief Esta funcion pide el ingreso de 's' o de 'n'  y lo pasa a minuscula
 *
 * \param mensaje[] char Mensaje de ingreso
 * \return char Devuelve el caracter validado "s" o "n"
 *
 */
char getConfirmacion(char mensaje[])
{
    char letter;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &letter);
    letter = tolower(letter);
    while (letter != 's' && letter != 'n')
    {
        printf("Error. Ingrese \"s\" para SI o \"n\" para NO: \n");
        fflush(stdin);
        scanf("%c", &letter);
        letter = tolower(letter);
    }
    return letter;
}




//######################PARA REVISAR###########################################




/** \brief Pide un entero  sin rango, ni max  ni min, y lo devuelve
 *
 * \param mensaje char* mensaje de ingreso
 * \return int Entero  validado
 *
 */
int my_getIntdetp(char *mensaje)
{
    int numero;
    while ((getValidInt(&numero, mensaje)) == -1)
    {
        printf("Error. Ingrese solo numeros!\n");
    }
    return numero;
}

/** \brief Valida si el valor ingresado es un entero o no es llamada por getInt
 *
 * \param numero int* valor ingresado
 * \param mensaje char* mensaje recibido por param
 * \return int Devuelve "-1" si no es un int o es un entero con espacio, o "0" si es solo int.
 *
 */
int getValidInt(int *numero, char *mensaje)
{
    int sePudo = 1;
    int esEspacio = 1;
    char cadenaCargada[20];
    int i;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadenaCargada); //leer todo hasta que se encuentre \n
    for (i = 0; i < strlen(cadenaCargada); i++)
    {
        if (cadenaCargada[i] != '\0')
        {
            if (cadenaCargada[i] < '0' || cadenaCargada[i] > '9')
            {
                sePudo = -1;
            }
            if (cadenaCargada[i] != ' ')
            {
                esEspacio = -1;
            }
        }
    }
    if (esEspacio == 1)
    {
        sePudo = -1;
    }
    if (sePudo == 1)
    {
        *numero = atoi(cadenaCargada);
    }
    return sePudo;
}

/** \brief Valida que sea un caracter y lo guarda en el puntero char letra
 *
 * \param letra char* Valor ingresado
 * \return int Devuelve "1" si no es una letra, o "0" si es letra
 *
 */
int my_getValidChar(char *letra)
{
    int retorno = 0;
    if (*letra < 'a' || *letra > 'z')
    {
        printf("Error. ingrese UNA sola letra.\n");
        retorno = 1;
    }
    return retorno;
}



/** \brief Verifica que el string ingresado sea solo de letras.
 *
 * \param cadena[] char vector a validar
 * \return int Devuelve "-1" (si hay otros caracteres que no sean letras, o "0" si son solo letras):
 *
 */
int getStringLetras(char cadena[])
{
    int flag = 0;
    int esEspacio = 0;
    int tam = strlen(cadena);
    for (int i = 0; i < tam; i++)
    {
        if (cadena[i] != '\0')
        {
            if ((cadena[i] < 'a' || cadena[i] > 'z')
                    && (cadena[i] < 'A' || cadena[i] > 'Z')
                    && cadena[i] != ' ') //si es lo contrario a esto -1, (ose si no es: espacio, no es letra de "A" a "Z")
            {
                flag = -1;
            }

            if (cadena[i] != ' ')   // si NO ingresa SOLO espacio o enter, OK
            {
                esEspacio = 1;
            }

        }
    }

    if (esEspacio == 0)   //si es solo espacio error.
    {
        flag = -1;
    }
    return flag;
}

/** \brief Pide una cadena de string y lo valida llamando la funcion "getStringLetras" y no permite otra.
 * cosa que no sea letras y pasa cada primer letra a mayuscula con la funcion "my_firstToUpper"
 * \param mensaje[] char Mensaje a mostrar
 * \param cadena[] char vector destino para el string validado
 * \return void
 *
 */
void my_pedirCadenaSoloLetras(char mensaje[], char cadena[])
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena); //leer todo hasta que se encuentre \n
    while (getStringLetras(cadena) == -1)
    {
        printf("Error. Ingrese solo letras!\n");
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", cadena);
    }
    my_firstToUpper(cadena);
}

/** \brief Convierte el string a minuscula y despues la primera letra del string a mayuscula.
 *
 * \param cadena[] char vector con la cadena ingresada
 * \return void
 *
 */
void my_firstToUpper(char cadena[])
{
    int tam = strlen(cadena);
    int i;
    strlwr(cadena);
    cadena[0] = toupper(cadena[0]); //primer letra a mayuscula
    for (i = 0; i < tam; i++)
    {
        if (cadena[i] != '\0')
        {
            if (isspace(cadena[i]))
            {
                cadena[i + 1] = toupper(cadena[i + 1]); //convierte lo siguiente a " " a mayuscula
            }
        }
    }
}

/** \brief Recibe un numero float y lo valida
 *
 * \param numero float* Numero a validar
 * \param mensaje char* Mensaje a mostrar
 * \return int Devuelve "-1" si no es float o "0" si es float
 *
 */
int getValidFloat(float *numero, char *mensaje)
{
    int sePudo = 1;
    int esEspacio = 1;
    char cadenaCargada[20];
    int i;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadenaCargada); //leer todo hasta que se encuentre \n
    for (i = 0; i < strlen(cadenaCargada); i++)
    {
        if (cadenaCargada[i] != '\0')
        {
            if ((cadenaCargada[i] < '0' || cadenaCargada[i] > '9')
                    && cadenaCargada[i] != '.')
            {
                sePudo = -1;
            }
            if (cadenaCargada[i] != ' ')
            {
                esEspacio = -1;
            }
        }
    }
    if (esEspacio == 1)
    {
        sePudo = -1;
    }
    if (sePudo == 1)
    {
        *numero = atof(cadenaCargada);
    }
    return sePudo;
}
