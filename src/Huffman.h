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
#endif
