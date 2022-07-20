#include "GString.h"

//Comandos: G, X, Y, R

int main() {

	char str[35] = { "ABG1.1478ULOX12.819Y1.739ZZR1.899" };

	data Data = { 0, 0, 0, 0 };

	readString(&Data, str);

	writeData(&Data);

	return 0;
}

