
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Acoes
{
	int qtd;
  float val;
	struct Acoes *prox;
};
typedef struct Acoes acoes;

float cotacoes[1] = {0};
int anular = 0, resto = 0;

acoes *inicio = NULL;
acoes *petr4v = NULL;
acoes *petr4c = NULL;

//####################################################################

void inserir_listaC(acoes **p, float valor, int quantidade){
  acoes *aux, *novo = malloc(sizeof(acoes));

    if(novo){
        novo->val = valor;
        novo->qtd = quantidade;
        
        if(*p == NULL){ // a lista está vazia?
            novo->prox = NULL;
            *p = novo;
        }
        else if(novo->val > (*p)->val){ // é o menor?
            novo->prox = *p;
            *p = novo;
        }
        else{ // inserção no meio ou no final da lista
            aux = *p;
            while(aux->prox && novo->val < aux->prox->val)
                aux = aux->prox;
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

//####################################################################

void inserir_listaV(acoes **p, float valor, int quantidade){
  acoes *aux, *novo = malloc(sizeof(acoes));  

    if(novo){
        novo->val = valor;
        novo->qtd = quantidade;
        
        if(*p == NULL){ // a lista está vazia?
            novo->prox = NULL;
            *p = novo;
        }
        else if(novo->val < (*p)->val){ // é o menor?
            novo->prox = *p;
            *p = novo;
        }
        else{ // inserção no meio ou no final da lista
            aux = *p;
            while(aux->prox && novo->val > aux->prox->val)
                aux = aux->prox;
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

//####################################################################

acoes *compra(float Val, int Qtd , acoes *ptr, int num)
{
	acoes* busca; 
	acoes* anterior;
	anterior = NULL;
	busca = ptr;
	while (busca != NULL) {
		if (busca->val <= Val) {
      cotacoes[num] = (busca->val - Val)/2 + Val;
      printf("\n\n\n------------------------------------\n| TRANSAÇÃO REALIZADA: %d - %.2f |\n------------------------------------\n", Qtd, cotacoes[num]);
      if(busca->qtd > Qtd){
        busca->qtd = busca->qtd - Qtd;
        anular = 1;
        return ptr;
      }
      else{
        if (anterior != NULL){
          resto = Qtd - busca->qtd;
				  anterior->prox = busca -> prox;
          anular = 0;
				  return ptr;
			  }
        else{
          resto = Qtd - busca->qtd;
				  ptr = busca-> prox;
          anular = 0;
				  return ptr;
			  };
      }
		};
    anular = 0;
		anterior = busca;
		busca = busca->prox;
	}
  return ptr;
}

//####################################################################

acoes *venda(float Val, int Qtd , acoes *ptr, int num)
{
	acoes* busca; 
	acoes* anterior;
	anterior = NULL;
	busca = ptr;
	while (busca != NULL) {
		if (busca->val >= Val) {
      cotacoes[num] = (busca->val - Val)/2 + Val;
      printf("\n\n\n------------------------------------\n| TRANSAÇÃO REALIZADA: %d - %.2f |\n------------------------------------\n", Qtd, cotacoes[num]);
      if(busca->qtd > Qtd){
        busca->qtd = busca->qtd - Qtd;
        anular = 1;
        return ptr;
      }
      else{
        if (anterior != NULL){
          resto = Qtd - busca->qtd;
				  anterior->prox = busca -> prox;
          anular = 0;
				  return ptr;
			  }
        else{
          resto = Qtd - busca->qtd;
				  ptr = busca-> prox;
          anular = 0;
				  return ptr;
			  };
      }
		};
    anular = 0;
		anterior = busca;
		busca = busca->prox;
	}
  return ptr;
}

//####################################################################

void consulta_ofertas(acoes* p1, acoes* p2, char* nome){
	acoes *referencia;
  printf("###############################\n");
  printf("Cotação para PETR4: %.2f\n-------------------------\n",cotacoes[0]);
  printf("-- VENDA --\n\n");
	for(referencia= p1;referencia!= NULL; referencia=referencia->prox){
		printf("[%s | %d | %.2f]\n--------------------\n",nome, referencia->qtd, referencia->val);
	}
  printf("\n-- COMPRA --\n\n");
  for(referencia= p2;referencia!= NULL; referencia=referencia->prox){
		printf("[%s | %d | %.2f]\n--------------------\n", nome, referencia->qtd, referencia->val);
	}
  printf("###############################\n");
}

//####################################################################

int menu(){
  int opcao;
  printf("\n\n___ MERCADO DE AÇÕES ___\n\n1 - Carregar ofertas via arquivo.\n5 - Criar uma oferta de compra.\n6 - Criar uma oferta de venda.\n7 - Consultar ofertas.\n8 - Sair.\n> ");
	scanf("%d",&opcao);

  return opcao;
}

//####################################################################

int main() {
	int opcao, elemento;
  
  
	acoes *lista;
	lista = NULL;
	
  while(opcao!=9){
  opcao = menu();
  switch(opcao){
    case 1:{
      int qt;
      float vl;
      FILE *ofs;
      int tit, tipo;
      printf("\nDeseja carregar de qual título? (Informe o número)\n");
      printf("1 - PETR4\n> ");
      scanf("%d",&tit);
      getchar();
      printf("Compra (1) ou Venda (2)?\n> ");
      scanf("%d",&tipo);
      getchar();
      switch(tipo){
        case 1:{
          if((ofs = fopen("ocpetr4.txt","r")) != NULL) {
            fscanf(ofs,"%d%f",&qt, &vl);
            inserir_listaC(&petr4c, vl, qt);
            consulta_ofertas(petr4v, petr4c, "PETR4");
            getchar();
            }
          fclose(ofs);
          break;
            }
        case 2:{
          if((ofs = fopen("ovpetr4.txt","r")) != NULL) {
            fscanf(ofs,"%d%f",&qt, &vl);
            inserir_listaV(&petr4v, vl, qt);
            consulta_ofertas(petr4v, petr4c, "PETR4");
            getchar();
          }
          fclose(ofs);
          break;
        }
      }
      break;
      }
    case 5:{
      int tit, q;
      float v;
      printf("\nDeseja comprar qual título? (Informe o número)\n");
      printf("1 - PETR4\n> ");
      scanf("%d",&tit);
      getchar();
      printf("Informe a quantidade de ações: ");
      scanf("%d",&q);
      getchar();
      printf("Informe o valor de cada ação: ");
      scanf("%f",&v);
      getchar();
      petr4v = compra(v, q, petr4v, 0);

      switch(tit){
        case 1:{
          if(anular == 0){
            inserir_listaC(&petr4c, v, resto);
          };
          consulta_ofertas(petr4v, petr4c, "PETR4");
          getchar();
        break;
        }
      }
      break;
    }
    case 6:{
      int tit, q;
      float v;
      printf("Deseja vender qual título? (Informe o número)\n");
      printf("1 - PETR4\n> ");
      scanf("%d",&tit);
      getchar();
      printf("Informe a quantidade de ações: ");
      scanf("%d",&q);
      getchar();
      printf("Informe o valor de cada ação: ");
      scanf("%f",&v);
      getchar();
      petr4c = venda(v, q, petr4c, 0);
      
      switch(tit){
        case 1:{
          if(anular == 0){
            inserir_listaV(&petr4v, v, resto);
          };
          consulta_ofertas(petr4v, petr4c, "PETR4");
          getchar();
        break;
        }
      }
      break;
    }
    case 7:{
      int tit;
      printf("Deseja consultar qual título? (Informe o número)\n");
      printf("1 - PETR4\n> ");
      scanf("%d",&tit);
      getchar();
      switch(tit){
        case 1:{
          consulta_ofertas(petr4v, petr4c, "PETR4");
          break;
        }
        }
      break;
    }
    default:{
      printf("Saindo..\n");
      return 0;
  }
    }
    }
  }