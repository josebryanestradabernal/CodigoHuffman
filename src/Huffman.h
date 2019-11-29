#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

/*
Programa de para generar el codigo de Huffman creado por Estrada Bernal José Bryan
en OpenSuse (GNU/LINUX) codificado en Atom y Vim
*/
#define TAMLIMITE 100
//Estructura del nodo de un arbol binario con el dato y la frecuencia con el que aparece el dato
struct nodoArbol {
	char dato;
	unsigned freq;
	struct nodoArbol *izq, *der;
};
/*Estructura del nodo de la Lista donde se gurdan los nodos del arbol que poco a
poco se van insertando
*/
struct listaNodo {
	unsigned tam;
	unsigned capacidad;
	struct nodoArbol** array;
};
typedef struct lista{
int *ArrayElementos;
int cantElementos;
}*LISTA;
/*Permite inicializar la lista (reservarle memoria inicializar en 0
 * el numero de elementos que contiene
 * */
int inicializarLista(LISTA *list);
/*
 *incrementa la memoria reseervada para introducir un nuevo elemento
 *consideraciones:
 *puede haber error en la asignacion de la memoria de ser asi retorna -1
 *si todo esta correcto solo retorna 0
 * */
int agregar(LISTA list,int Elemento);
//usa insertion sort para ordenar
void ordenarLitas(LISTA arr,LISTA freq);
void Contar (char *arr,int *fre,int elemento,int *tam);
/*Crea un nodo con el dato y su frecuencía*/
struct nodoArbol* nuevoNodo(char dato, unsigned freq);
/*Crea un nodo de cierta capacidad*/
struct listaNodo* crearLista(unsigned capacidad);
/*
Intercabia nodos de acuerdo a sus valores en memoria
*/
void intercambiaNodo(struct nodoArbol** a,struct nodoArbol** b);
/*Acomoda en su lugar un nodo ya creado*/
void ordenar(struct listaNodo* Lista, int idx);
/*retorna uno si el tamaño es uno*/
int TamUno(struct listaNodo* Lista);
/*Rertona el menor de los nodos de una lista*/
struct nodoArbol* Min(struct listaNodo* Lista);
/*Inrerta un nodo de un arbol en la lista*/
void InsertaLista(struct listaNodo* Lista,struct nodoArbol* nodoArbol);
void crearNodolista(struct listaNodo* Lista);
//imprime el array de valares
void imprimirArray(int arr[], int n);
//retorna 1 si el nodo es una hoja
int Hoja(struct nodoArbol* root);
//creacion de la lista solo teninedo los datos principales sin procesar
struct listaNodo* creandoListaNodo(char dato[], int freq[], int tam);
//usa los datos de la entrada para crear el arbol usando todas las funcions anteriores
struct nodoArbol* crearArbol(char dato[], int freq[], int tam);
//imprimir codigos de Huffman
void imprimirCodigos(struct nodoArbol* root, int arr[], int top);
//es el enlace entre la entrada de datos y todo el proceso

struct nodoArbol* codigoHuffman(char dato[], int freq[], int tam);
void imprimirUnCodigo(struct nodoArbol* root, int arr[], int top,char dato);



#endif
