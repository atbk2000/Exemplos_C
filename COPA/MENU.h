#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <conio.h>
#define UEFA 14
#define AFC 5
#define CAF 5
#define CONCACAF 3
#define CONMEBOL 5

void menu();
void instrucoes(FILE * fp1);
void cadastrar();
void retirar(char *s);


#endif // MENU_H_INCLUDED
