#include <stdio.h>
#include <omp.h>

int main (void){
	
	int i;
	int a[100];
// ser verde no es nada facil	
	for (i=0;i<100;i++){
		a[i]=i*5;
	}
// ignorar esto xd	
	#pragma omp parallel private(i) shared(a)
	{
		#pragma omp for ordered
			for (i=0;i<100;i++){
				#pragma omp  ordered
					printf("%3d ", a[i]);
				if((i+1)%10==0)
					printf("\n");
			}
	}
	printf("\n");
}
// Modificando el archivo plancha