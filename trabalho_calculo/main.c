#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// função que recebe os pontos e retorna salva o valor do coeficiente angular e o b
void calcularReta(double x1, double y1, double x2, double y2, double* a, double* b) {
    *a = (y2 - y1) / (x2 - x1);
    *b = (-*a * x1 + y1);
}

void calcularPontos(double x, double* ponto) {
    ponto[0] = x;
    ponto[1] = x*x;  // ou outra função f(x)
}

void retaSecante(double x1, double y1, double pontoInicial, char direcao) {
    double ponto[2];
    double pontoAproximando;

    double a;
    double b;

    if (direcao == 'D'||direcao == 'd') {
        pontoAproximando = 0.5;

        // Primeira aproximação grosseira
        for (int i = 0; i < 4; i++) {
            calcularPontos((pontoInicial + pontoAproximando), ponto);
            calcularReta(x1, y1, ponto[0], ponto[1], &a, &b);
            printf("%f | %f | f(x) = %lf x + %lf\n",(pontoInicial + pontoAproximando),ponto[1], a, b);
            pontoAproximando -= 0.1;
        }

        // Segunda aproximação refinada
        for (int i = 1; i <= 10; i++) {
            calcularPontos((pontoInicial + pontoAproximando), ponto);
            calcularReta(x1, y1, ponto[0], ponto[1], &a, &b);
            printf("%f | %f | f(x) = %lf x + %lf\n",(pontoInicial + pontoAproximando),ponto[1], a, b);
            pontoAproximando = pontoAproximando/10;
        }
    } else if (direcao == 'E'||direcao == 'e') {
        pontoAproximando = 0.5;

        // Primeira aproximação grosseira
        for (int i = 0; i < 4; i++) {
            calcularPontos((pontoInicial - pontoAproximando), ponto);
            calcularReta(x1, y1, ponto[0], ponto[1], &a, &b);
            printf("%f | %f | f(x) = %lf x + %lf\n",(pontoInicial - pontoAproximando),ponto[1], a, b);
            pontoAproximando += 0.1;
        }

        // Segunda aproximação refinada
        for (int i = 0; i < 10; i++) {
            calcularPontos((pontoInicial - pontoAproximando), ponto);
            calcularReta(x1, y1, ponto[0], ponto[1], &a, &b);
            printf("%f | %f | f(x) = %lf x + %lf\n",(pontoInicial - pontoAproximando),ponto[1], a, b);
            pontoAproximando = pontoAproximando/10;
        }
    }
}

int main() {
    char direcao = 'D';
    retaSecante(2, 4, 2, direcao);

    return 0;
}
