#include <stdio.h>
#include <stdlib.h>

struct lista
{
	int info;
	struct lista* prox;
};

typedef struct lista Lista;

Lista* criar_lista ()
{
	return NULL;
}

Lista* inserir_lista (Lista* l, int i)
{
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
  return novo;
}

void consultar_lista(Lista *l)
{
	Lista *ref;
	for (ref = l; ref!=NULL; ref = ref->prox)
		printf ("%d\n", ref->info);
}

void buscar_lista(Lista *l, int i)
{
	Lista *ref;
	for (ref = l; ref!=NULL; ref = ref->prox)
	{
		if (ref->info == i)
			printf ("valor encontrado %d\n", i);
	}	
	
}

int main(int argc, char** argv)
{
	Lista* lista;
	lista = criar_lista();
	lista = inserir_lista(lista, 78);
	lista = inserir_lista(lista, 81);
	lista = inserir_lista(lista, 85);
	consultar_lista(lista);
	
	int valor = 80;
	buscar_lista(lista, valor);

	// criar uma função para remover um no ou um elemento da lista	
	return 0;
}