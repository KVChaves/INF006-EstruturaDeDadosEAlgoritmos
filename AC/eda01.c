#include <stdio.h>

//Escrever uma função que diga qual dos dois números é maior.

void maior(int a, int b){
  if (a>b){
    printf("O maior número é %d",a);
  }
  else
    printf("O maior número é %d",b);
}

int main() {
    int valor1, valor2;
    printf ("digite o valor1 ");
    scanf("%d", &valor1);
    printf("digite o valor2 ");
    scanf("%d", &valor2);
    
    maior(valor1, valor2);
    return 0;
  }
  