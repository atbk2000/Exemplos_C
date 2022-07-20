#include "Cabeçalho.h"
#include <conio.h>

int main() {

	Pessoas pes[91];

	iniciar_struct(pes);

	imprimir_dados(pes);

	for (int ano = 0; ano < 150; ano++) {
		avancar_ano(pes, 1);
		imprimir_dados(pes);
	}

	char fim = getchar();

	return 0;
}