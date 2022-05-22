#include <stdio.h>

//Escrever uma função que peça dois números e os imprima em ordem crescente.

void ordem(int a, int b){

  if (a>b){
    printf("Ordem crescente: %d - %d",b,a);
  }
  else
    printf("Ordem crescente: %d - %d",a,b);
}

int main(){

  int num1, num2;
  printf("Insira um valor: ");
  scanf("%d",&num1);
  printf("Insira outro valor: ");
  scanf("%d",&num2);

  ordem(num1,num2);
  return 0;
  
}