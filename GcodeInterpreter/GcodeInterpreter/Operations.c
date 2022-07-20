#include "Operations.h"


//Retorna 1 se 'a' for um caracter num�rico
//Retorna 0 caso contr�rio
char isNumeric(char a) {
	if (a >= '0' && a <= '9') {
		return 1;
	}
	return 0;
}


//Percorre 'str' at� achar '.' ou ','
//Retorna o �ndice de '.' ou ','
//Se n�o achar, retorna 0
int findPoint(char* str) {

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ',' || str[i] == '.') {
			return i;
		}
	}
	return 0;
}


//Multiplica 'number1' por 'number2' 'times' vezes
//Retorna o produto da multiplica��o
float multiply(float number1, float number2, int times) {
	for (int i = 0; i < times; i++) {
		number1 *= number2;
	}
	return number1;
}


//Transforma string num�rica 'str' em um n�mero
//Retorna o n�mero, -1 se 'str' n�o for num�rica
//Aceita n�meros com ponto flutuante
float stringToFloat(char* str) {
	if (str[0] == '\0') {
		return -1;
	}

	int length = strlen(str);
	int expoent = 0;
	float number = 0;

	//Informa o �ndice de ',' ou '.' na string 'str'
	int pointIndex = findPoint(str);

	for (int i = length - 1; i >= 0; i--) {

		if (isNumeric(str[i])) {
			int algarism = str[i] - '0';
			number += algarism * multiply(1, 10, expoent);
			expoent += 1;
		}
	}

	if (pointIndex != 0) {
		number = multiply(number, 0.1, length - 1 - pointIndex);
	}

	return number;
}
