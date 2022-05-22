//Alterar o código para que a inserção na lista seja permitida ao usuario com os valores e quantidade de elementos que ele quiser.

#include <stdio.h>
#include <stdlib.h>

struct tipo
{
	int info;
	struct tipo *prox;

};

typedef struct tipo Paciente;

Paciente* inserir_lista(Paciente* l, int i)
{
	Paciente* novo= malloc(sizeof(Paciente));
	novo->info= i;
	novo->prox = l;
	return novo;
}

void consultar_lista(Paciente* inicio)
{

	Paciente *referencia;

	for(referencia= inicio;referencia!= NULL; referencia=referencia->prox)
		printf("%d\n", referencia->info);
	
}

int main() {

	Paciente *lista;
	lista = NULL;
	lista = inserir_lista(lista, 89);
	lista = inserir_lista(lista, 76);
	lista = inserir_lista(lista, 43);
	consultar_lista(lista);
	
    return 0;
}