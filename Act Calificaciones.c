#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct datos{
	int mat;
	int p1, p2, pia;
	float final;
}datos[10];
int main (){
	FILE *fp;int i;
	fp=fopen("C:/Users/alexi/Desktop/Progra Estruct/Promedio.xlsx","w");
	for(i=0;i<10;i++){
	datos[i].mat=1729201-i;
	datos[i].p1=10-i;
	datos[i].p2=10-i;
	datos[i].pia=10-i;
	datos[i].final=10-i;
	fprintf(fp,"%d &d %d &d %.2f \n",datos[i].mat, datos[i].p1, datos[i].p2, datos[i].pia, datos[i].final);
	}
	fclose(fp);
	printf("Archivo guardado");
	
	fp=fopen("C:/Users/alexi/Desktop/Progra Estruct/Promedio.xlsx","r");
	for(i=0; i<10; i++)
	{
		fscanf(fp, "%d &d %d &d %.2f \n",datos[i].mat, datos[i].p1, datos[i].p2, datos[i].pia, datos[i].final);
		fprintf(fp, "%d &d %d &d %.2f \n",datos[i].mat, datos[i].p1, datos[i].p2, datos[i].pia, datos[i].final);
	}
	fclose(fp);
	return 0;
}
