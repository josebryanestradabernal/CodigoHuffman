#include<stdio.h>
#include<string.h>
#include"Huffman.h"
void mostrarLista(LISTA list){
      LISTA aux=list;
      for (int i=0;i<list->cantElementos;i++){
        printf("%c ",*(aux->ArrayElementos+i));
      }
      printf("\n");
    }
int main()
{

  char arr[20000];
  int freq[20000],tam=0;

  //contar
  char palabra[200];
  fgets(palabra,200,stdin);
if(strlen(palabra)>2){
  for (int i=0;i<strlen(palabra)&& palabra[i]!='\n';i++){
    Contar(arr,freq,palabra[i],&tam);
  }
  for (int i =0 ;i<tam;i++){
    printf("letra %c , valor %i\n",arr[i],freq[i]);
  }
 struct nodoArbol *root=NULL;
 int aux[TAMLIMITE],top=0;
	root =codigoHuffman(arr,freq,tam);
  printf("Codigo de la palabra: %s",palabra);
  for (int i=0;i<strlen(palabra);i++){
    imprimirUnCodigo(root,aux,top,palabra[i]);
  }
  printf("\n");
}
  else {printf("0\n");}
	return 0;
}
