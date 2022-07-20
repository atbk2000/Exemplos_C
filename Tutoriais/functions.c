#include <stdio.h>

// Passando funções como argumentos

int somar(int num1, int num2){
    return num1 + num2;
}

void imprime(int (*func)(int, int), int num1, int num2){

    int soma = func(num1, num2);

    printf("A soma de %d com %d é: %d\n", num1, num2, soma);
}

int main(){

    for(int i = 0; i < 10; i++){
        imprime(somar, i, i + 1);
    }

    return 0;
}