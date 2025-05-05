#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//função que recebe os pontos e retorna salva o valor do coeficiente angular e o b
void calcularReta(float x1,float y1,float x2,float y2,float* a,float* b){
    *a = (y2-y1)/(x2-x1);
    *b = (-*a*x1+y1);
}

void calcularPontos(float x, float* ponto[2]){
    *ponto[0]=x;
    *ponto[1]= pow(x,2);//grau da equação
}

void retaTangenteX2(float aproximacao){
    float ponto[2];
    while(1){
       calcularPontos(0, &ponto);
    }
}

int main()
{
    float a;
    float b;

    calcularReta(1,4,3,6, &a , &b);
    printf("f(x)= %f x + %f",a,b);
    return 0;
}
