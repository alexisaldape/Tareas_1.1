#include<stdio.h>
#include<stdlib.h>

int factorial(int number){
  if(number <= 1){
    return 1;
  }else{
    return number * factorial(number - 1);
  }
}

int main(int argc, char **argv){
  int numero = atoi(argv[1]);
  int resp;
  resp = factorial(numero);
  printf("EL factorial del numero %d es: %d\n",numero,resp);
  return 0;
}
