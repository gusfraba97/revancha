#include<stdio.h>
#include<omp.h>
// Estoy comentando este archivo
int main () {
  int a, i;
  int new;
int f,g,h,p;  
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

/*estoy modificando este archivo equisde*/


