#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<time.h>




void rellenar(int A[],int length){
int i; 


for(i=0 ; i<length ; i++)
	A[i]=i+1;
}


void main(){

int i;
                //Variables contadoras del ciclo.
int lista[100]; //Declaracion e inicializacion de un arreglo de 100 elementos.
int temp=0;             //Variable temporal.

rellenar(lista,100);



#pragma omp parallel shared(lista) private(i) 
{
    #pragma omp for ordered 	
 	for(i=0 ; i<100 ; i++)      
		#pragma omp  ordered 
			{printf("%d ",lista[i]);	
		        if((i+1)%5==0)
				printf("\n");		
			}
 
}





}
