#include<stdio.h>
#include<string.h>
int main (int contVector,char **vector){
  if (!strcmp(vector[1],"C")){}
  else if (!strcmp(vector[1],"D")){}
  else if (!strcmp(vector[1],"H")){
    printf("Compresor y Descompresor Huffman\n");
    printf("Creado por Jose Bryan Estrada Bernal\nBienvenido a la Ayuda\n");
    printf("Forma de uso: OPCION ARCHIVO\nEjemplo: Huffman D comprimido.cpm\n\n");
    printf("\tOPCION:\nC         -Comprimir-\nD         -Descomprimir-\n");
  }
  else {
    printf("Error: ");
    for (int i=1;i<contVector;i++)printf("%s ",vector[i]);
    printf("\nOrden no encontrada\nH   -Para pedir ayuda-\n" );
  }
}
