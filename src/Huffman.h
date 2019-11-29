#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__


#define TAMLIMITE 100

struct nodoArbol {
	char dato;
	unsigned freq;
	struct nodoArbol *izq, *der;
};

struct listaNodo {
	unsigned tam;
	unsigned capacidad;
	struct nodoArbol** array;
};
struct nodoArbol* nuevoNodo(char dato, unsigned freq);
struct listaNodo* crearLista(unsigned capacidad);
void intercambiaNodo(struct nodoArbol** a,struct nodoArbol** b);
void ordenar(struct listaNodo* Lista, int idx);
int TamUno(struct listaNodo* Lista);
struct nodoArbol* Min(struct listaNodo* Lista);
void InsertaLista(struct listaNodo* Lista,struct nodoArbol* nodoArbol);
void crearNodolista(struct listaNodo* Lista);
void imprimirArray(int arr[], int n);
int Hoja(struct nodoArbol* root);
struct listaNodo* creandoListaNodo(char dato[], int freq[], int tam);
struct nodoArbol* crearArbol(char dato[], int freq[], int tam);
void imprimirCodigos(struct nodoArbol* root, int arr[], int top);
void codigoHuffman(char dato[], int freq[], int tam);

#endif
