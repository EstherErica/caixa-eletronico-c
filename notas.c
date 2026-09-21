#include <stdio.h>

struct caixa{
    int quantidade;
    int valor;
    
};
    // talvez colocar o for dentro de void- 
void reposicao(struct caixa notas[]){
    for (int i= 0; i<4; i++){
    // int=0 (inicia o loop na posicao 0) i<4 (se o valor da "rodada"for menor que 4,  adicionar 1)
        printf("Quanto quer repor cédula do valor %d?\n", notas[i].valor);
        printf("Digite 0 para próxima cédula\n");
        int repor;
        scanf("%d", &repor);
        notas[i].quantidade += repor;
        printf("Quantidade final: %d\n", notas[i].quantidade);
    }
    
}

//SAQUE//
 

int saque(){
    int valor_saque;
    printf("Qual o valor do saque: \n");
    scanf("%d", &valor_saque);

    return valor_saque;
}

void processar_saque(struct caixa notas[], int valor_saque) {
    struct caixa temp_notas[4];
    for (int i= 0; i<4; i++){
        temp_notas[i]= notas[i];
    }
    int valor_teste= valor_saque;

for(int i=0; i<4; i++){
    int quant_necessaria= valor_teste/ temp_notas[i].valor;
    if (quant_necessaria> temp_notas[i].quantidade){
    quant_necessaria= temp_notas[i].quantidade;
}


if (quant_necessaria> 0){
    valor_teste -= quant_necessaria * temp_notas[i].valor;
    temp_notas[i].quantidade -= quant_necessaria;
    printf("Entregar %d notas de R$ %d\n", quant_necessaria, temp_notas[i].valor);
}
}
if (valor_teste > 0) {
printf("Valor indisponivel\n");
    }
else {
        for (int i = 0; i < 4; i++) {
            notas[i].quantidade = temp_notas[i].quantidade;
        }
        printf("Saque realizado com sucesso\n");
    }

}


int menu(){
    int opcao; 
    printf("\nEscolha um opção:\n0- Cédulas disponíveis \n1- Abastecer ATM\n2- Sacar\n9- Sair\n");
    scanf("%d", &opcao);
    return opcao;
}

int main(){
    

    struct caixa notas[4]= {
        {0,100},
        {0,50},
        {0,20},
        {0,10}
    };

    int opcao_escolhida;
    do{
        opcao_escolhida= menu();

        if (opcao_escolhida== 0){
        for (int i=0; i<4; i++){
            printf("Notas de R$: %d com %d unidade\n", notas[i].valor, notas[i].quantidade);
         }
        }
        else if (opcao_escolhida==1){
            reposicao(notas);
        }
        else if (opcao_escolhida==2){
            int valor_desejado= saque();
            processar_saque(notas, valor_desejado);
        }
        else if(opcao_escolhida==9){
            printf("Fechando sistema. Até logo.");
        }
        else{
            printf("Opção inválida, tente novamente\n");
        }
    } while(opcao_escolhida !=9);
    return 0;
}
