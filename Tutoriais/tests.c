// Arquivo para a realização de testes em C

#include <stdint.h>
#include <stdio.h>

void ledsCounter(uint8_t counter){
    
    uint8_t mask[4];
    
    int i;
    for(i = 0; i < 4; i++){
        
        if(counter % 2 == 0){
            mask[3 - i] = 0;
        }
        else{
            mask[3 - i] = 1;
        }
        
        counter = ((uint8_t)counter / 2);
    }

    printf("%d%d%d%d", mask[0], mask[1], mask[2], mask[3]);
}

int main(){

    uint8_t counter = 9;

    ledsCounter(counter);

    return 0;
}