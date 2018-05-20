#include<stdio.h>
#include<omp.h>

int main () {
  int a, i;
  
#pragma omp parallel 
{
     a = 0;

#pragma omp for ordered reduction (+:a) 
  for (i = 0; i < 10; i++) {
      #pragma omp ordered
{		

        a += i;
	
 }
   }
#pragma omp single
printf("La suma es %d, hilo %d \n",a,omp_get_thread_num());
 }
}


