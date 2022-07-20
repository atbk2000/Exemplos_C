#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

	int idade;
	int quantidade;

}Pessoas;

void iniciar_struct(Pessoas pes[91]);
void imprimir_dados(Pessoas pes[91]);
int qtd_pessoas(Pessoas pes[91], int idadeInicial, int idadeFinal);
void avancar_ano(Pessoas pes[91], float natalidade);
