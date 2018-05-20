#include<omp.h>
#include<stdio.h>




void main(){

	int i;
	omp_set_num_threads(4);

#pragma omp parallel private(i)
{
	#pragma omp for ordered 
		for(i=1 ; i<=20 ; i++){
			#pragma omp ordered
			printf("i=%d, hilo numero %d \n",i,omp_get_thread_num());
		}



}

}
