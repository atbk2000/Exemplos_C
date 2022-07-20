#include "Cabeçalho.h"

void iniciar_struct(Pessoas pes[91]) {
	int qtd = 33350;

	for (int i = 0; i < 70; i++) {
		pes[i].idade = i;
		pes[i].quantidade = qtd;
		qtd = (int)(qtd * 0.993 + 0.5);
	}
	for (int i = 70; i <= 90; i++) {
		pes[i].idade = i;
		pes[i].quantidade = qtd;
		qtd = (int)(qtd * 0.8 + 0.5);
	}
}

void imprimir_dados(Pessoas pes[91]) {
	int qtdTotal = qtd_pessoas(pes, 0, 90);

	printf("%i\n", qtdTotal);
}

//Retorna a quantidade de pessoas em determinada faixa de idades
int qtd_pessoas(Pessoas pes[91], int idadeInicial, int idadeFinal) {
	int qtd = 0;

	for (int i = idadeInicial; i <= idadeFinal; i++) {
		qtd += pes[i].quantidade;
	}

	return qtd;
}

void avancar_ano(Pessoas pes[91], float natalidade) {
	for (int i = 90; i > 70; i--) {
		pes[i].quantidade = (int)(pes[i - 1].quantidade * 0.8 + 0.5);
	}
	for (int i = 70; i >= 0; i--) {
		pes[i].quantidade = (int)(pes[i - 1].quantidade * 0.993 + 0.5);
	}

	int novosIndividuos = (int)(natalidade * qtd_pessoas(pes, 18, 45)
		/ (28 * 2));

	pes[0].quantidade = novosIndividuos;
}