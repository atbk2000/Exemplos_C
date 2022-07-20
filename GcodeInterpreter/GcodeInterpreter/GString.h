#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Operations.h"
#ifndef Functions

typedef struct data {
	float mode1;
	float posX;
	float posY;
	float mode2;
}data;

void readString(data* Data, char* str);
void setCommand(data* Data, char command, float Command);
float getCommandValue(char* str, int index);
void writeData(data* Data);
char isCommand(Command);

#endif // !Functions



