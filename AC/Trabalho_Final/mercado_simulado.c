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

float cotacoes[3] = {0, 0, 0};
int anular = 0, resto = 0, tr = 0;

acoes *petr4v = NULL;
acoes *petr4c = NULL;
acoes *vale5v = NULL;
acoes *vale5c = NULL;
acoes *lame3v = NULL;
acoes *lame3c = NULL;

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

acoes *compra(float Val, int Qtd , acoes *ptr, int num){
	acoes* busca; 
	acoes* anterior;
	anterior = NULL;
	busca = ptr;
	while (busca != NULL) {
		if (busca->val <= Val) {
      cotacoes[num] = (busca->val - Val)/2 + Val;
      printf("\n-\n-\n-\n-\n-\n-------------------------------\n| TRANSAÇÃO REALIZADA: $%.2f |\n-------------------------------\n> %.2f & %.2f\n", cotacoes[num], Val, busca->val);
      if(busca->qtd > Qtd){
        busca->qtd = busca->qtd - Qtd;
        anular = 1;
        printf("> %d\n",Qtd);
        return ptr;
      }
      else{
        if (anterior != NULL){ //primeiro elemento da lista
          tr = 1;
          resto = Qtd - busca->qtd;
				  anterior->prox = busca -> prox;
          anular = 0;
          printf("> %d", busca->qtd);
				  return ptr;
			  }
        else{
          tr = 1;
          resto = Qtd - busca->qtd;
				  ptr = busca-> prox;
          anular = 0;
          printf("> %d", busca->qtd);
				  return ptr;
			  };
      }
		};
    tr = 0;
    anular = 0;
		anterior = busca;
		busca = busca->prox;
	}
  return ptr;
}

//####################################################################

acoes *venda(float Val, int Qtd , acoes *ptr, int num){
	acoes* busca; 
	acoes* anterior;
	anterior = NULL;
	busca = ptr;
	while (busca != NULL) {
		if (busca->val >= Val) {
      cotacoes[num] = (busca->val - Val)/2 + Val;
      printf("\n-\n-\n-\n-\n-\n-------------------------------\n| TRANSAÇÃO REALIZADA: $%.2f |\n-------------------------------\n> %.2f & %.2f\n", cotacoes[num], busca->val, Val);
      if(busca->qtd > Qtd){
        busca->qtd = busca->qtd - Qtd;
        anular = 1;
        printf("> %d",Qtd);
        return ptr;
      }
      else{
        if (anterior != NULL){
          tr = 1;
          resto = Qtd - busca->qtd;
				  anterior->prox = busca -> prox;
          anular = 0;
          printf("> %d", busca->qtd);
				  return ptr;
			  }
        else{
          tr = 1;
          resto = Qtd - busca->qtd;
				  ptr = busca-> prox;
          anular = 0;
          printf("> %d", busca->qtd);
				  return ptr;
			  };
      }
		};
    tr = 0;
    resto = Qtd;
    anular = 0;
		anterior = busca;
		busca = busca->prox;
	}
  return ptr;
}

//####################################################################

void consulta_ofertas(acoes* p1, acoes* p2, char* nome){
	acoes *referencia;
  printf("\n###############################\n");
  printf("Cotação para %s: %.2f\n-------------------------\n", nome, cotacoes[0]);
  printf("-- VENDA --\n\n");
	for(referencia= p1;referencia!= NULL; referencia=referencia->prox){
    if(referencia->qtd != 0){
		  printf("[%s | %d | %.2f]\n--------------------\n",nome, referencia->qtd, referencia->val);
    };
	}
  printf("\n-- COMPRA --\n\n");
  for(referencia= p2;referencia!= NULL; referencia=referencia->prox){
		if(referencia->qtd != 0){
      printf("[%s | %d | %.2f]\n--------------------\n", nome, referencia->qtd, referencia->val);
    };
	}
  printf("###############################\n");
}

//####################################################################

int menu(){
  int opcao;
  printf("\n\n___ MERCADO DE AÇÕES ___\n\n1 - Carregar ofertas via arquivo.\n2 - Criar uma oferta de compra.\n3 - Criar uma oferta de venda.\n4 - Consultar ofertas.\n5 - Sair.\n\n> ");
	scanf("%d",&opcao);

  return opcao;
}

//####################################################################

int main() {
	int opcao;
  
  while(opcao!=5){
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
            petr4v = compra(vl, qt, petr4v, 0);
            if(anular == 0 && tr == 0){
              inserir_listaC(&petr4c, vl, qt);
            }
            else if(anular == 0 && tr == 1){
              inserir_listaC(&petr4c, vl, resto);
            };
            consulta_ofertas(petr4v, petr4c, "PETR4");
            getchar();
          }
          fclose(ofs);
          break;
            }
        case 2:{
          if((ofs = fopen("ovpetr4.txt","r")) != NULL) {
            fscanf(ofs,"%d%f",&qt, &vl);
            petr4c = venda(vl, qt, petr4c, 0);
            if(anular == 0 && tr == 0){
              inserir_listaV(&petr4v, vl, qt);
            }
            else if(anular == 0 && tr == 1){
              inserir_listaV(&petr4v, vl, resto);
            };
            consulta_ofertas(petr4v, petr4c, "PETR4");
            getchar();
          }
          fclose(ofs);
          break;
        }
      }
      break;
      }
    case 2:{
      int tit, q;
      float v;
      printf("\nDeseja comprar qual título? (Informe o número)\n");
      printf("1 - PETR4\n2 - VALE5\n3 - LAME3\n> ");
      scanf("%d",&tit);
      getchar();
      printf("Informe a quantidade de ações: ");
      scanf("%d",&q);
      getchar();
      printf("Informe o valor de cada ação: ");
      scanf("%f",&v);
      getchar();

      switch(tit){
        case 1:{
          petr4v = compra(v, q, petr4v, 0);
          if(anular == 0 && tr == 0){
            inserir_listaC(&petr4c, v, q);
          }
          else if(anular == 0 && tr == 1){
            inserir_listaC(&petr4c, v, resto);
          };
          consulta_ofertas(petr4v, petr4c, "PETR4");
          getchar();
        break;
        }
        case 2:{
          vale5v = compra(v, q, vale5v, 1);
          if(anular == 0 && tr == 0){
            inserir_listaC(&vale5c, v, q);
          }
          else if(anular == 0 && tr == 1){
            inserir_listaC(&vale5c, v, resto);
          };
          consulta_ofertas(vale5v, vale5c, "VALE5");
          getchar();
        break;
        }
        case 3:{
          lame3v = compra(v, q, lame3v, 2);
          if(anular == 0 && tr == 0){
            inserir_listaC(&lame3c, v, q);
          }
          else if(anular == 0 && tr == 1){
            inserir_listaC(&lame3c, v, resto);
          };
          consulta_ofertas(lame3v, lame3c, "LAME3");
          getchar();
        break;
        }
      }
      break;
    }
    case 3:{
      int tit, q;
      float v;
      printf("Deseja vender qual título? (Informe o número)\n");
      printf("1 - PETR4\n2 - VALE5\n3 - LAME3\n> ");
      scanf("%d",&tit);
      getchar();
      printf("Informe a quantidade de ações: ");
      scanf("%d",&q);
      getchar();
      printf("Informe o valor de cada ação: ");
      scanf("%f",&v);
      getchar();
      
      switch(tit){
        case 1:{
          petr4c = venda(v, q, petr4c, 0);
          if(anular == 0 && tr == 0){
            inserir_listaV(&petr4v, v, q);
          }
          else if(anular == 0 && tr == 1){
            inserir_listaV(&petr4v, v, resto);
          };
          consulta_ofertas(petr4v, petr4c, "PETR4");
          getchar();
        break;
        }
        case 2:{
          vale5c = venda(v, q, vale5c, 1);
          if(anular == 0 && tr == 0){
            inserir_listaV(&vale5v, v, q);
          }
          else if(anular == 0 && tr == 1){
            inserir_listaV(&vale5v, v, resto);
          };
          consulta_ofertas(vale5v, vale5c, "VALE5");
          getchar();
        break;
        }
        case 3:{
          lame3c = venda(v, q, lame3c, 2);
          if(anular == 0 && tr == 0){
            inserir_listaV(&lame3v, v, q);
          }
          else if(anular == 0 && tr == 1){
            inserir_listaV(&lame3v, v, resto);
          };
          consulta_ofertas(lame3v, lame3c, "LAME3");
          getchar();
        break;
        }
      }
      break;
    }
    case 4:{
      int tit;
      printf("Deseja consultar qual título? (Informe o número)\n");
      printf("1 - PETR4\n2 - VALE5\n3 - LAME3\n> ");
      scanf("%d",&tit);
      getchar();
      switch(tit){
        case 1:{
          printf("\n-\n-\n-\n-\n-\n");
          consulta_ofertas(petr4v, petr4c, "PETR4");
          getchar();
          break;
        }
        case 2:{
          printf("\n-\n-\n-\n-\n-\n");
          consulta_ofertas(vale5v, vale5c, "VALE5");
          getchar();
          break;
        }
        case 3:{
          printf("\n-\n-\n-\n-\n-\n");
          consulta_ofertas(lame3v, lame3c, "LAME3");
          getchar();
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