#include <stdio.h>
#include <stdlib.h>

int main(){

  printf("Insira um digito: ");
  char c;
  scanf("%c",&c);

  char c2[1];
  c2[0] = c;

  printf("%c",c2[0]);
}