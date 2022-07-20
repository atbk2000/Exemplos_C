#ifndef SORTEIO_H_INCLUDED
#define SORTEIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include"STRUCTS.h"

pote *organizaPote(FILE *fp3);
int sortear1(pote* p, grupo*g);
int sortear(pote *p, grupo *g);
int verificaIguais(int v[],int n);
int *randNum(int n);
int verificagrupo(grupo *g,int j);
int trocatimedegrupo( grupo *g, int j, int posicao,int contador,pote *p,int q);
int contatime(grupo *g, int i);
int uefatem(grupo *g,int j);
int verifica(int *p,int *vetor,int i);
int *vetoraleatorio(int n);

#endif // SORTEIO_H_INCLUDED
