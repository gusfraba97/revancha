#include<stdio.h>
#include<omp.h>

int main () {
  int a, i;
  
#pragma omp parallel shared(a)
{
#pragma omp master      
	a = 0;
#pragma omp for ordered reduction (+:a)  private(i) 
  for (i = 0; i < 10; i++) {
      #pragma omp ordered
{		

        a += i;
	
 }
   }
#pragma omp single
printf("La suma es %d \n",a);
 }
}


