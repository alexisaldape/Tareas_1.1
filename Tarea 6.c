// Ejemplo de estructuras con el cuadrado 
#include <stdio.h>

 

  struct cuadrilatero{
    int base; 
	float altura;
  };

 

int main(){
  struct cuadrilatero cuadrilatero1;
  struct cuadrilatero cuadrilatero2;
  cuadrilatero1.base = 25;
  cuadrilatero1.altura = 10;
  
  printf("Base del cuadrilatero1: %d \n", cuadrilatero1.base);
  printf("Altura del cuadrilatero1: %.4f \n", cuadrilatero1.altura); 
  
  	char caracter = '$';
	int posicion_actual, alto_actual, largo = 25, alto = 10;
	printf ("\n");
	
	for (alto_actual=0; alto_actual < alto; alto_actual = alto_actual + 1){
		
		for (posicion_actual = 0; posicion_actual < largo; posicion_actual = posicion_actual + 1){
			printf ("%c", caracter);
		}
		printf ("\n");
	}
  return 0;
}
