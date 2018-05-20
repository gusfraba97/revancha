#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100
void rellenar(int A[],int length){

int i;	
srand(time(NULL));
for(i=0;i<length ;i++)
  	A[i]=rand()%100+1;
}

void imprimir(int A[],int length){
int i;
for(i=0;i<length ;i++)
  	printf("%d \n",A[i]);
}

void main(){

int min,i,max,A[SIZE];
rellenar(A,SIZE);
imprimir(A,SIZE);


#pragma omp parallel private(i) shared(max)
{
     #pragma omp master
	max=-5,min=500;
 #pragma omp for ordered 
  for (i = 0; i < SIZE; i++) 
      #pragma omp ordered
	{if(A[i]>max)
		max=A[i];
 	if(A[i]<min)
		min=A[i];

   }
 	#pragma omp barrier
#pragma omp single
printf("El maximo es %d y el menor es %d, hilo %d \n",max,min,omp_get_thread_num());
 }
  
}
