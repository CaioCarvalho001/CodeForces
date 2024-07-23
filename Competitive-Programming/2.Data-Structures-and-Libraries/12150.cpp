#include <iostream>
#include <vector>

int main(void){
    int N;

    while(scanf("%d", &N), N){
        std::vector<int> posicaoInicial (N, 0);
        bool impossivel = false;

        for(int i = 0; i< N; i++){
            
            int numero, ultra;
            scanf("%d %d", &numero, &ultra);

            if(impossivel)
                continue;
            
            if((ultra + i) >= 0 && (ultra + i) < N && (!posicaoInicial[i + ultra])){
                posicaoInicial[i + ultra] = numero;
            } else {
                impossivel = true;
            }
            
        }

        if(impossivel)
            printf("-1\n");
        else {
            for(std::vector<int>::iterator it = posicaoInicial.begin(); it != posicaoInicial.end(); it++ ){
                printf("%d%s", *it, (posicaoInicial.end()-1) != it ? " ":"");

            }
            printf("\n");        
        }

    }


    return 0;
}