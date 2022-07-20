#ifndef LOGSORTEIO_H_INCLUDED
#define LOGSORTEIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include"STRUCTS.h"

void probabilidade(int n, char **s,pote *p);
int verificaPais(grupo *g,char s[],int n);
void temporeal(FILE *fp4,pote *p);
void printa(int grupo,int posicao,char *s,pote *p);
void gotoxy(int x,int y);
void sleep(int s);
void ordenaarquivo(FILE *fp4);

#endif // LOGSORTEIO_H_INCLUDED
