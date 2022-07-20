// Arquivo com operações matemáticas e aritméticas

#include <stdio.h>

/* 
 Retorna a soma dos números inteiros de i até j
*/
int somaNums(int i, int j){
    
    int aux;
    int soma = 0;

    for(aux = i; aux <= j; aux++){
        soma += aux;
    }

    return soma;
}

int main(){

    int soma = somaNums(1, 5);

    printf("%d", soma);

    return 0;
}