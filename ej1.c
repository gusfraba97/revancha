#include<stdio.h>
#include<omp.h>
#include<assert.h>




void main(){

 int nthreads;
 int i,j;
 int *ptr_i,*ptr_j;	

nthreads=4;
omp_set_num_threads(nthreads);
ptr_i=&i;
ptr_j=&j;
i=1;
j=2;

#pragma omp parallel private(i,j)
{

i=-2;
j=-4;
assert(*ptr_i	==1 &&	*ptr_j	==2);


	printf("El valor de i es %d y el valor de j es %d, hilo numero %d \n",i,j,omp_get_thread_num());

}

assert(i ==1 && j==2);
	printf("El valor de i es %d y el valor de j es %d\n",i,j);

}



