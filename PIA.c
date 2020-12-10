#include<stdio.h>
#include<stdlib.h>

struct calificaciones{
	char matricula[7];
	int parciales[7];
}calificacion[29];

void alumnos(int *calfinal, int *parcial_noaprobado) {
		int indice, indice_2;
	  for(indice=0; indice<29; indice++){
	  	*calfinal=0;
	  	*parcial_noaprobado=0;
		for(indice_2=0; indice_2<7; indice_2++){
			*calfinal=*calfinal+calificacion[indice].parciales[indice_2];
			if(calificacion[indice].parciales[indice_2]<7){
				*parcial_noaprobado= *parcial_noaprobado+1;
			}
		}
		*(parcial_noaprobado)++;
		*calfinal=*calfinal/7;
	    *(calfinal)++;
	}
}

void calificacion_parcial(int *promedio_parcial, int *alumnos_noaprobados_porparcial){
	int indice, indice_2;
	for(indice_2=0; indice_2<7; indice_2++){
		*promedio_parcial=0;
		*alumnos_noaprobados_porparcial=0;
		for(indice=0; indice<29; indice++){
		    *promedio_parcial=*promedio_parcial+calificacion[indice].parciales[indice_2];
		   	if(calificacion[indice].parciales[indice_2]<7){
		       *alumnos_noaprobados_porparcial=*alumnos_noaprobados_porparcial+1;
	     }
      }
   	*promedio_parcial=*promedio_parcial/29;	
    *(promedio_parcial)++;
	*(alumnos_noaprobados_porparcial)++;
  } 
}

int grupo2(int reprobados, int *cal_final){
    	reprobados=0;
	    if(*cal_final<7){
        	reprobados=reprobados+1;
		}
		
		return reprobados;
}
	
void grupo( int cal_final[29], int *promedio_grupo){
	int indice;
	promedio_grupo=0;
	for(indice=0; indice<29; indice++){
        promedio_grupo=promedio_grupo+cal_final[indice];
	}	
	*promedio_grupo=*promedio_grupo/29;
	

}	
	



int main(){
	int indice, indice_2;
	FILE *ap;
	FILE *nu;
	int promedio_parcial[7];
	int alumnos_noaprobados_porparcial[7];
	int calfinal[29];
	int parcial_noaprobado[29];
	int promediogrupo[0];
	int reprobados=0;
	char matricula[50], parcial1[50], parcial2[50], parcial3[50], parcial4[50], parcial5[50], parcial6[50], parcial7[50];
	ap=fopen("calificaciones_pia_pe (2).csv", "r");
	if(ap == NULL){
		printf("Error\n");
	}else{
	printf("El archivo se abrio correctamente\n");
   }
    fflush(stdin);
	fscanf(ap, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,\n]\n", matricula, parcial1, parcial2, parcial3, parcial4, parcial5, parcial6, parcial7);
	for(indice=0; indice<29; indice++){
		fscanf(ap,"%[^,],", calificacion[indice].matricula);
		  for(indice_2=0; indice_2<7; indice_2++){
		  fscanf(ap,"%d,", &calificacion[indice].parciales[indice_2]);
	  }
	  fprintf(ap, "\n");
    }
	fclose(ap);
	nu=fopen("Archivo Nuevo.csv", "w+");
		if(nu == NULL){
		printf("Error\n");
	}else{
	printf("El archivo se creo correctamente\n");
   }
   fprintf(nu,"Matricula, Parcial1, Parcial2, Parcial3, Parcial4, Parcial5, Parcial6, Parcial7, Promedio de calificaciones parciales, No Aprobados\n");
   alumnos(calfinal, parcial_noaprobado);
	for(indice=0; indice<29; indice++){
		int k=3;
		while(k<7){
		    fprintf(nu,"%c", calificacion[indice].matricula[k]);
		    k++;
		  }
		  fprintf(nu, ",");
		   for(indice_2=0; indice_2<7; indice_2++){
	       fprintf(nu,"%d,", calificacion[indice].parciales[indice_2]);
	  }
	  fprintf(nu, "%d,", calfinal[indice]);
	  fprintf(nu, "%d,", parcial_noaprobado[indice]);
	  fprintf(nu, "\n");
    }
    calificacion_parcial(promedio_parcial, alumnos_noaprobados_porparcial);
    grupo(calfinal, promediogrupo);
    grupo2(reprobados, calfinal);
    printf("%d\n", reprobados);
    printf("%d", promediogrupo);
    fprintf(nu, "Promedios, Promedio Parcial1, Promedio Parcial2, Promedio Parcial3, Promedio Parcial4, Promedio Parcial5, Promedio Parcial6, Promedio Parcial7, Promedio del grupo\n,");
    for(indice_2=0; indice_2<7; indice_2++){
    fprintf(nu, "%d,", promedio_parcial[indice_2]);
     }
    fprintf(nu, "%d", promediogrupo[indice_2]);
    fprintf(nu, "\n");
    fprintf(nu, "No aprobados, Cantidad de alumnos que no aprobaron el parcial1, Cantidad de alumnos que no aprobaron el parcial2, Cantidad de alumnos que no aprobaron el parcial3, Cantidad de alumnos que no aprobaron el parcial4, Cantidad de alumnos que no aprobaron el parcial5, Cantidad de alumnos que no aprobaron el parcial6, Cantidad de alumnos que no aprobaron el parcial7, Total de no aprobados\n,");
    for(indice_2=0; indice_2<7; indice_2++){
    fprintf(nu, "%d,", alumnos_noaprobados_porparcial[indice_2]);
     }
     fprintf(nu, "%d\n", reprobados);
	fclose(nu);
	return 0;
}


   






