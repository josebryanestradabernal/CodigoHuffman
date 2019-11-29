#include "Huffman.h"
#include <stdio.h>
#include <stdlib.h>

struct nodoArbol* nuevoNodo(char dato, unsigned freq)
{
	struct nodoArbol* temp	= (struct nodoArbol*)malloc (sizeof(struct nodoArbol));
	temp->izq = temp->der = NULL;
	temp->dato = dato;
	temp->freq = freq;
	return temp;
}

struct listaNodo* crearLista(unsigned capacidad)
{
	struct listaNodo* Lista	= (struct listaNodo*)malloc(sizeof(struct listaNodo));
	Lista->tam = 0;
	Lista->capacidad = capacidad;
	Lista->array = (struct nodoArbol**)malloc(Lista->capacidad * sizeof(struct nodoArbol*));
	return Lista;
}

void intercambiaNodo(struct nodoArbol** a,struct nodoArbol** b)

{
	struct nodoArbol* t = *a;
	*a = *b;
	*b = t;
}

void ordenar(struct listaNodo* Lista, int idx)
{
	int menor = idx;
	int izq = 2 * idx + 1;
	int der = 2 * idx + 2;
	if (izq < Lista->tam && Lista->array[izq]->
freq < Lista->array[menor]->freq)
		menor = izq;
	if (der < Lista->tam && Lista->array[der]->
freq < Lista->array[menor]->freq)
		menor = der;
	if (menor != idx) {
		intercambiaNodo(&Lista->array[menor],
						&Lista->array[idx]);
		ordenar(Lista, menor);
	}
}

int TamUno(struct listaNodo* Lista)
{

	return (Lista->tam == 1);
}

struct nodoArbol* Min(struct listaNodo* Lista)

{

	struct nodoArbol* temp = Lista->array[0];
	Lista->array[0]
		= Lista->array[Lista->tam - 1];
	--Lista->tam;
	ordenar(Lista, 0);
	return temp;
}

void InsertaLista(struct listaNodo* Lista,	struct nodoArbol* nodoArbol)

{

	++Lista->tam;
	int i = Lista->tam - 1;

	while (i && nodoArbol->freq < Lista->array[(i - 1) / 2]->freq) {

		Lista->array[i] = Lista->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}

	Lista->array[i] = nodoArbol;
}

void crearNodolista(struct listaNodo* Lista)

{

	int n = Lista->tam - 1;
	int i;

	for (i = (n - 1) / 2; i >= 0; --i)
		ordenar(Lista, i);
}

void imprimirArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		printf("%d", arr[i]);

}

int Hoja(struct nodoArbol* root)

{

	return !(root->izq) && !(root->der);
}

struct listaNodo* creandoListaNodo(char dato[], int freq[], int tam)

{

	struct listaNodo* Lista = crearLista(tam);

	for (int i = 0; i < tam; ++i)
		Lista->array[i] = nuevoNodo(dato[i], freq[i]);

	Lista->tam = tam;
	crearNodolista(Lista);

	return Lista;
}

struct nodoArbol* crearArbol(char dato[], int freq[], int tam)

{
	struct nodoArbol *izq, *der, *top;

	struct listaNodo* Lista = creandoListaNodo(dato, freq, tam);

	while (!TamUno(Lista)) {

		izq = Min(Lista);
		der = Min(Lista);
		top = nuevoNodo('$', izq->freq + der->freq);

		top->izq = izq;
		top->der = der;

		InsertaLista(Lista, top);
	}
	return Min(Lista);
}

void imprimirCodigos(struct nodoArbol* root, int arr[], int top)

{

	if (root->izq) {

		arr[top] = 0;
		imprimirCodigos(root->izq, arr, top + 1);
	}

	if (root->der) {

		arr[top] = 1;
		imprimirCodigos(root->der, arr, top + 1);
	}

	if (Hoja(root)) {

		printf("%c: ", root->dato);
		imprimirArray(arr, top);
    printf("\n");
	}
}

struct nodoArbol* codigoHuffman(char dato[], int freq[], int tam)

{
	struct nodoArbol* root = crearArbol(dato, freq, tam);

	int arr[TAMLIMITE], top = 0;

	imprimirCodigos(root, arr, top);
  return root;
}

int inicializarLista(LISTA *Lista){
    *Lista=(struct lista*)malloc(sizeof(struct lista));
    (*Lista)->ArrayElementos=(int*)malloc(sizeof(int));
    (*Lista)->cantElementos=0;
    if ((*Lista)->ArrayElementos==NULL)return -1;
    return 0;
  }
  int agregar (LISTA list,int elemento){
    list->ArrayElementos=realloc(list->ArrayElementos,(list->cantElementos+1)*sizeof(int));
    if (list->ArrayElementos==NULL)return -1;
    *(list->ArrayElementos+list->cantElementos)=elemento;
    list->cantElementos++;
    return 0;
  }
  void Contar (char *arr,int *fre,int elemento,int *tam)
  {
    int flagEnc=0;
    for (int i=0;i<*tam;i++){
      if (arr[i]==elemento){
        fre[i]++;
        flagEnc=1;
        return;
      }
    }
    if (flagEnc==0){
    arr[*tam]=elemento;
    fre[(*tam)++]=1;
    }
  }

  void imprimirUnCodigo(struct nodoArbol* root, int arr[], int top,char dato)

  {

  	if (root->izq) {

  		arr[top] = 0;
  		imprimirUnCodigo(root->izq, arr, top + 1,dato);
  	}

  	if (root->der) {

  		arr[top] = 1;
  		imprimirUnCodigo(root->der, arr, top + 1,dato);
  	}

  	if (Hoja(root)) {
  		if (root->dato==dato)imprimirArray(arr, top);
  	}
  }
