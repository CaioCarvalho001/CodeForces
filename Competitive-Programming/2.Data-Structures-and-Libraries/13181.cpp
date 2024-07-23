#include <iostream>

int distancia(int maior, int nCamas, int nOcupadas, bool ant){
    int valor;

    if(ant){
       if(nCamas)
            valor = nCamas-1;
        else
            valor = 0;

    } else {
        if(nOcupadas > 1)
            if(nCamas % 2)
                valor = nCamas / 2;
            else
                valor = (nCamas/2) -1;
        else
            if(nCamas)
                valor = nCamas-1;
            else
                valor = 0;

    }

    if(maior < valor)
         maior = valor;

    
    return maior;
}

int main(void){
    char c;
    int camasVazias = 0, maior = -10;
    int camasOcupadas = 0;
    bool anterior;

    while(scanf("%c", &c) != EOF){
        
        if(c == '\n'){
            
            maior = distancia(maior, camasVazias, camasOcupadas, anterior);

            printf("%d\n", maior);

            camasVazias = camasOcupadas = 0;
            maior = -10;
        } else if(c == 'X') {
            anterior = false;
            camasOcupadas++;

            maior = distancia(maior, camasVazias, camasOcupadas, anterior);

            camasVazias =  0;
        } else {
            anterior = true;
            camasVazias++;
        }
        
        

    }

    return 0;
}