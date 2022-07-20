#include <stdio.h>
#include <stdlib.h>

// Operações com lista duplamente encadeada

typedef struct queue_i{
    struct queue_i *next, *prev;
    int id;
}queue_i;

queue_i *queue = NULL;

int queue_size() {
	if (queue == NULL){
		return 0;
	}

    int size = 0;

	do {
		size += 1;
		queue = queue->next;
	} while (queue != NULL);

	return size;
}

void queue_print()
{
	if (queue == NULL) {
		printf("\nA fila esta vazia\n");
		return;
	}

	printf("\nFila: ");

    queue_i *iterador = queue;

    while(iterador != NULL){
        printf("%d ", iterador->id);

		iterador = iterador->next;

    }
}

void queue_append(int valor)
{
	if (queue == NULL){
		queue_i* aux = malloc(sizeof(queue_i));

		aux->next = NULL;
		aux->prev = NULL;
		aux->id = valor;

        queue_i **first = &queue;

		*first = aux;

        return;
	}

    queue_i *iterador = queue;

    while(iterador->next != NULL){
        iterador = iterador->next;
    }

	queue_i* aux = malloc(sizeof(queue_i));

	aux->next = NULL;
	aux->prev = iterador;
	aux->id = valor;

	iterador->next = aux;
}

// Retira o primeiro elemento da fila
int queue_remove()
{
	if (queue == NULL) {
		return 0;
	}

    int id;

    queue_i **first = &queue;

	if (queue->next == NULL) {
		queue_i* out = queue;

        id = out->id;

		free(out);

		*first = NULL;

		return id;
	}

	queue_i* out = queue;

	out->next->prev = NULL;

	*first = (*first)->next;

	free(out);

	return 0;
}

// Retira todos os elementos da fila
void queue_free(){
    while(queue != NULL){
        queue_remove();
    }
}

// Joga o elemento com id = valor para a primeira posição
// Primeiro elemento vai para a segunda posição
void queue_swap(int valor){
    if(queue == NULL){
        return;
    }

    queue_i *iterador = queue;

    if(iterador->id == valor){
        return;
    }

    while(iterador->id != valor){
        iterador = iterador->next;

        if(iterador == NULL){
            printf("O elemento %d nao esta na fila\n", valor);

            return;
        }
    }

    iterador->prev->next = iterador->next;
    if(iterador->next != NULL){
        iterador->next->prev = iterador->prev;
    }

    iterador->prev = NULL;
    iterador->next = queue;
    queue->prev = iterador;

    queue_i **first = &queue;

    *first = iterador;
}


int main(){

    queue_append(1);
    queue_append(3);
    queue_append(5);
    queue_append(4);

    queue_print();

    queue_swap(5);

    queue_print();

    queue_swap(4);

    queue_print();

    return 0;
}