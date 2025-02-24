#include <stdio.h>

double soma(){

    float A;
    float B;

    printf("Digite o primeiro numero:\n");
    scanf("%f", &A);
    printf("\nDigite o segundo numero:\n");
    scanf("%f", &B);

    float resultado = A + B;

    printf("O resultado da soma e:
} %.5f\n", resultado);
    return resultado;

double subtracao(){

    float A;
    float B;

    printf("Digite o primeiro numero:\n");
    scanf("%f", &A);
    printf("\nDigite o segundo numero:\n");
    scanf("%f", &B);

    float resultado = A - B;

    printf("O resultado da subtracao e: %.5f\n", resultado);
    return resultado;

}

double multiplicacao(){

    float A;
    float B;

    printf("Digite o primeiro numero:\n");
    scanf("%f", &A);
    printf("\nDigite o segundo numero:\n");
    scanf("%f", &B);

    float resultado = A * B;

    printf("O resultado da multiplicacao e: %.5f\n", resultado);
    return resultado;


}

double divisao(){

    float A;
    float B;

    printf("Digite o primeiro numero:\n");
    scanf("%f", &A);
    printf("\nDigite o segundo numero:\n");
    scanf("%f", &B);

    float resultado = A / B;

    printf("O resultado da divisao e: %.5f\n", resultado);
    return resultado;


}

double fat(){

    float A;
    double result = 1.0;

    printf("\ndigite o numero que voce queira saber o fatorial:(nao pode ser negativo)\n");
    scanf("%f", &A);

    if(A < 1){

        printf("Fatorial nao funciona para numeros negativos");
        return -1;
    }else{

        for(int i = 1; i <=A; i++){

            result *= i;

        }

    }

    printf("o fatorial de %f é: %f", A, reuslt);
    return result;

}


int main() {

    char sair;
    int escolha;

    do{

        printf("Faca a sua escolha: (Digite um numero para escolher)\n\n");
        printf("1. soma\n");
        printf("2. subtracao\n");
        printf("3. multiplicacao\n");
        printf("4. divisao\n");
        printf("7. fatorial\n");
        scanf("%d", &escolha);

        if(escolha == 1){

            soma();

        }else if(escolha == 2){

            subtracao();

        }else if( escolha == 3){

            multiplicacao();

        }else if(escolha == 4){

            divisao();

        }else if(escolha == 7){

            fat();

        }

    printf("\nvoce deseja sair?(digite N ou n para continuar)\n");
    scanf(" %c", &sair);
    }while(sair == 'N' || sair == 'n');
}
