//Funções com recursividade.

#include <stdlib.h>
#include <stdio.h>

int main()
{

  int fatorial(int n);
  
  int a;
  
  a = fatorial(5);

  printf("%d", a);
}

//Função recursiva.

int fatorial(int n)
{
  if(n == 1)
  {
    return 1;
  }
  else
  {
    return n*fatorial(n-1);
  }
}

//Busca binária recursiva.

int BB(int A[], int ini, int fim, int v) 
{
  int meio;
  if (ini > fim)
  {
    return -1;
  }
  else 
  {
    meio = (imi+fim)/2;
  }
  if (A[meio] == v)
  {
    return meio;
  }
  else
  {  
    if (v < A[meio])
    {
      return BB(A,ini,meio-1, v);
    }
  }
  else
  {
  return BB(A,k+1,fim, v);
  }
}