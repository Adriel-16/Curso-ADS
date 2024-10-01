#include <stdio.h>

double soma(double A, double B){
    
    return A + B;
    
}

double subtracao(double A, double B){
    
    return A - B;
    
}

double multiplicacao(double A, double B){
    
    return A * B;
    
}

double divisao(double A, double B){
    
    return A / B;
    
}

double potencia(float a, floatb){
    
    
    
}

double fat(float A){
    
    if(A == 0){
        
        return 1;
        
    }else{
        
        return A * fat (A-1);
        
    }
    
}

int main() {
    int numero = 5;
    printf("Fatorial de %d é %.6lf\n", numero, fat(numero));
    return 0;
}