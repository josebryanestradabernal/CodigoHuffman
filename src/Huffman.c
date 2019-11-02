#include <stdio.h>
#include <stdlib.h>

//estructuras que se usaran

typedef struct nodo
{
   char letra;             /* Letra a la que hace referencia el nodo */
   unsigned long int bits; /* Valor de la codificación de la letra */
   char nbits;             /* Número de bits de la codificación */
   nodo *cero;            /* Puntero a la rama cero de un árbol */
   nodo *uno;             /* Puntero a la rama uno de un árbol */
} tNodo;
typedef struct _nodo
{
   char letra;      /* Letra a la que hace referencia el nodo */
   int frecuencia;  /* veces que aparece la letra en el texto o las letras */
                    /* de los nodos de las ramas cero y uno */
   _nodo *sig;      /* Puntero a siguiente nodo de una lista enlazada */
   _nodo *cero;     /* Puntero a la rama cero de un árbol */
   _nodo *uno;      /* Puntero a la rama uno de un árbol */
} tipoNodo;
typedef struct _tabla
{
   char letra;      /* Letra a la que hace referencia el nodo */
   unsigned long int bits; /* Valor de la codificación de la letra */
   char nbits;      /* Número de bits de la codificación */
   _tabla *sig;     /* Siguiente elemento de la tabla */
} tipoTabla;
tipoTabla *Tabla;
