#include<stdio.h>
#include<stdlib.h>

struct calificaciones{
	char matricula[15];
	float parciales[7];
}calificacion[29];

void alumnos(float *calfinal, int *parcial_noaprobado) {
		int i, j;
	  for(i=0; i<29; i++){
	  	*calfinal=0;
	  	*parcial_noaprobado=0;
		for(j=0; j<7; j++){
			*calfinal=*calfinal+calificacion[i].parciales[j];
			if(calificacion[i].parciales[j]<7){
				*parcial_noaprobado= *parcial_noaprobado+1;
			}
		}
		*(parcial_noaprobado)++;
		*calfinal=*calfinal/7;
	    *(calfinal)++;
	}
}

void calificacion_parcial(int *promedioparcial, int *alumnos_noaprobados_porparcial){
	int i, j;
	for(j=0; j<7; j++){
		*promedioparcial=0;
		*alumnos_noaprobados_porparcial=0;
		for(i=0; i<29; i++){
		    *promedioparcial=*promedioparcial+calificacion[i].parciales[j];
		   	if(calificacion[i].parciales[j]<7){
		       *alumnos_noaprobados_porparcial=*alumnos_noaprobados_porparcial+1;
	     }
      }
   	*promedioparcial=*promedioparcial/29;	
    *(promedioparcial)++;
	*(alumnos_noaprobados_porparcial)++;
  } 
}

int grupo2(int reprobados, int *calfinal){
    	reprobados=0;
	    if(*calfinal<7){
        	reprobados=reprobados+1;
		}
		
		return reprobados;
}
	
void grupo( int calfinal[29], int *promediogrupo){
	int i;
	promediogrupo=0;
	for(i=0; i<29; i++){
        promediogrupo=promediogrupo+calfinal[i];
	}	
	*promediogrupo=*promediogrupo/29;
	

}	
	



int main(){
	int i, j;
	FILE *ap;
	FILE *nu;
	int promedioparcial[7];
	int alumnos_noaprobados_porparcial[7];
	float calfinal[29];
	int parcial_noaprobado[29];
	int promediogrupo[0];
    char encabezado[255];
	int reprobados=0;
	char matricula[50], parcial1[50], parcial2[50], parcial3[50], parcial4[50], parcial5[50], parcial6[50], parcial7[50];
	ap=fopen("calificaciones_pia_pe.csv", "r");
	if(ap == NULL){
		printf("Error\n");
	}else{
	printf("El archivo se abrio correctamente\n");
   }
    fflush(stdin);
	//fscanf(ap, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", matricula, parcial1, parcial2, parcial3, parcial4, parcial5, parcial6, parcial7);
	fgets(encabezado,255,ap);
	for(i=0; i<29; i++){
      fscanf(ap,"%[^,],", calificacion[i].matricula);
      for(j=0; j<7; j++){
        fscanf(ap,"%f,", &calificacion[i].parciales[j]);
	  }
	  fscanf(ap, "\n");
    }
	fclose(ap);
	nu=fopen("C:/Users/alexi/Desktop/Salida.csv", "w+");
		if(nu == NULL){
		printf("Error\n");
	}else{
	printf("El archivo se creo correctamente\n");
   }
   fprintf(nu,"Matricula, Parcial1, Parcial2, Parcial3, Parcial4, Parcial5, Parcial6, Parcial7, Promedio de calificaciones parciales, No Aprobados\n");
   alumnos(calfinal, parcial_noaprobado);
	for(i=0; i<29; i++){
      int k=3;
      fprintf(nu,"%c",02);
      while(k<7){
        fprintf(nu,"%c", calificacion[i].matricula[k]);
        k++;
      }
      fprintf(nu,",");
      //fprintf(nu, "%s,",calificacion[i].matricula);
      for(j=0; j<7; j++){
        fprintf(nu,"%0.f,", calificacion[i].parciales[j]);
      }
	  fprintf(nu, "%.0f,", calfinal[i]);
	  fprintf(nu, "%d,", parcial_noaprobado[i]);
	  fprintf(nu, "\n");
    }
    /*
    calificacion_parcial(promedioparcial, alumnos_noaprobados_porparcial);
    grupo(calfinal, promediogrupo);
    grupo2(reprobados, calfinal);
    printf("%d\n", reprobados);
    printf("%d", promediogrupo);
    fprintf(nu, "Promedios, Promedio Parcial1, Promedio Parcial2, Promedio Parcial3, Promedio Parcial4, Promedio Parcial5, Promedio Parcial6, Promedio Parcial7, Promedio del grupo\n,");
    for(j=0; j<7; j++){
    fprintf(nu, "%d,", promedioparcial[j]);
     }
    fprintf(nu, "%d", promediogrupo[j]);
    fprintf(nu, "\n");
    fprintf(nu, "No aprobados, Cantidad de alumnos que no aprobaron el parcial1, Cantidad de alumnos que no aprobaron el parcial2, Cantidad de alumnos que no aprobaron el parcial3, Cantidad de alumnos que no aprobaron el parcial4, Cantidad de alumnos que no aprobaron el parcial5, Cantidad de alumnos que no aprobaron el parcial6, Cantidad de alumnos que no aprobaron el parcial7, Total de no aprobados\n,");
    for(j=0; j<7; j++){
    fprintf(nu, "%d,", alumnos_noaprobados_porparcial[j]);
     }
     fprintf(nu, "%d\n", reprobados);
	fclose(nu);*/
	return 0;
}


   






