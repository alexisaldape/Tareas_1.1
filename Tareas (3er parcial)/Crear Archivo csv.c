#include<stdio.h>
#include<stdlib.h>

struct calificaciones{
	int matricula;
	int parcial_1;
	int parcial_2;
	int pia;
	float califinal;
}calificacion[3];

int main(){
	FILE *ar;
	int i;
	
	ar=fopen("archivo1.csv", "w+");
	fprintf(ar,"Matricula, Parcial 1, Parcial 2, Pia, Calificacion final\n");
	if(ar==NULL){
		printf("Error");
		exit(1);
	}else
	printf("El archivo se creo\n");
	for(i=1; i<=3; i++){
		printf("Ingrese la matricula del alumno [%d]: \n", i);
		scanf("%d", &calificacion[i].matricula);
		printf("Ingrese la calificacion del primer parcial: \n");
		scanf("%d", &calificacion[i].parcial_1);
		printf("Ingrese la calificacion del segundo parcial: \n");
		scanf("%d", &calificacion[i].parcial_2);
		printf("Ingrese la calificacion del pia: \n");
		scanf("%d", &calificacion[i].pia);
		calificacion[i].califinal=(calificacion[i].parcial_1+calificacion[i].parcial_2+calificacion[i].pia)/3;
		system("cls");
	}
	fflush(ar);
	for(i=1; i<=3; i++){
		fprintf( ar , "%d, %d, %d, %d, %.2f\n", calificacion[i].matricula, calificacion[i].parcial_1, calificacion[i].parcial_2, calificacion[i].pia, calificacion[i].califinal);
	} 
	
	
	fclose(ar);
	
	
	return 0;
}
