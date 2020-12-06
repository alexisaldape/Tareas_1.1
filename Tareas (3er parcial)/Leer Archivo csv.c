#include <stdio.h>
#include<stdlib.h>


struct alumnos{
	int matricula;
	int parcial1;
	int parcial2;
	int pia;
	float calfinal;
}alumno[3];

int main(){
   FILE *ar;
   char matricula[50], primerparcial[50], segundoparcial[50], pia[50], final[50];
   ar=fopen("archivo1.csv", "r");
   	int j;
    int i;
   if(ar==NULL){
   	printf("ERROR\n");
   }else
   printf("El archivo se abrio correctamente\n");
   fflush(stdin);
   fscanf(ar, "%[^,], %[^,], %[^,], %[^,], %[^,\n]\n", matricula, primerparcial, segundoparcial, pia, final);
   printf("%s,%s,%s,%s,%s\n", matricula, primerparcial, segundoparcial, pia, final);
   	for(i=1; i<=3; i++){
           fscanf(ar, "%d, %d, %d, %d, %f\n", &alumno[i].matricula, &alumno[i].parcial1, &alumno[i].parcial2, &alumno[i].pia, &alumno[i].calfinal);
      }
   for(i=1; i<=3; i++){
   	printf("%d,%d,%d,%d,%.2f\n", alumno[i].matricula, alumno[i].parcial1, alumno[i].parcial2, alumno[i].pia, alumno[i].calfinal);  
   }
   fclose(ar);
   
   return 0;
}
