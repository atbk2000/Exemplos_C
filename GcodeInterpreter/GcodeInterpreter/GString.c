#include "GString.h"
#include "Operations.h"

const char commands[5] = { 'G', 'X', 'Y', 'R', '\0' };

//Percorre 'str' em busca de caracteres que indicam comandos
//Preenche os valores dos comandos na struct 'Data'
void readString(data* Data, char* str) {
	
	for (int i = 0; str[i] != '\0'; i++) {
		if (isCommand(str[i])) {
			float value = getCommandValue(str, i + 1);
			setCommand(Data, str[i], value);
		}
	}
}


/*Preenche o valor 'value' do comando 'Command' na variável correta
da struct 'Data'*/
void setCommand(data* Data, char Command, float value) {
	if(Command == commands[0]){
		Data->mode1 = value;
	}
	else if (Command == commands[1]) {
		Data->posX = value;
	}
	else if (Command == commands[2]) {
		Data->posY = value;
	}
	else if (Command == commands[3]) {
		Data->mode2 = value;
	}
	return;
}


//Retorna o valor do comando contido no índice 'index' -1
float getCommandValue(char* str, int index) {

	int cIndex = 0;
	char commandValue[7];

	for (int i = index; (str[i] != '\0' && isNumeric(str[i]))
		|| str[i] == '.' || str[i] == ','; i++){
		commandValue[cIndex] = str[i];
		cIndex += 1;
	}

	commandValue[cIndex] = '\0';

	return stringToFloat(commandValue);
}


//Imprime os valores contidos na struct 'Data'
void writeData(data* Data) {
	printf("Mode 1: %f\n", Data->mode1);
	printf("X position: %f\n", Data->posX);
	printf("Y position: %f\n", Data->posY);
	printf("Mode 2: %f", Data->mode2);
}


//Determina se 'Command' é um comando válido
//1 se for, 0 caso contrário
char isCommand(Command) {

	for (int i = 0; commands[i] != '\0'; i++) {
		if (Command == commands[i]) {
			return 1;
		}
	}

	return 0;
}


