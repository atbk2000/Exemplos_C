#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

typedef struct
{
    char nome[25];
    int ranking;
    char confederacao[10];
    int ordem;
} pais;

typedef struct
{
    pais a[8];
    char nome[7];
} pote;

typedef struct
{
	char nome;
	pais a[4];
} grupo;

typedef struct
{
    char nome[20];
    int posicao,grupo,ordem,pote;
} ordena;

#endif // STRUCTS_H_INCLUDED
