/*
1182 - COLUNA NA MATRIZ

NESTE PROBLEMA VOCÊ DEVE LER UM NÚMERO QUE INDICA UMA COLUNA DE UMA MATRIZ NA
QUAL UM OPERAÇÃO DEVE SER REALIZADA, UM CARACTERE MAIÚSCULO, INDICANDO A OPERÇÃO
QUE SERÁ REALIZADA, E TODOS OS ELEMENTOS DE UMA MATRIZ M[12][12]. EM SEGUIDA,
CALCULE E MOSTRE A SOMA OU A MÉDIA DOS ELEMENTOS QUE ESTÃO NA ÁREAS VERDE DA MATRIZ,
CONFORME FOR O CASO. A IMAGEM ABAIXO ILUSTRA O CASO DE ENTRADA DO VALOR 5 PARA A
COLUNA DA MATRIZ, DEMOSTRANDO OS ELEMENTOS QUE DEVERÃO SE CONSIDERADOS NA
OPERAÇÃO.

ENTRADA: A PRIMEIRA LINHA DE ENTRADA CONTEM UM NÚMERO C (0 <= C <= 1) INDICANDO A COLUNA QUE
SERÁ CONSIDERADA PARA OPERAÇÃO. A SEGUNDA LINHA DE ENTRADA CONTÉM UM ÚNICO
CARACTER MAIÚSCULO T ('S' OU 'M'), INDICANDO A OPERAÇÃO (SOMA OU MÉDIA) QUE DEVERÁ
SER REALIZADA COM OS ELEMENTOS DA MATRIS. SEGUEM OS 144 VALORES DE PONTO FLUTUANTE
QUE COMPÕEM A MATRIZ.

SAÍDA: IMPRIMA O RESULTADO SOLICITADO (A SOMA OU MÉDIA), COM 1 CASA APÓS O PONTO DECIMAL.
*/

//biblioteca
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    //declaração de variáveis
    double M[12][12]; //matriz 12x12
    int C; //indicando a coluna que será considerada para operação
    char T; //qual operação usar soma ou média
    double soma = 0; //calcular a soma
    double media; //calcular a média

    //entrada de dados
    cin >> C >> T;

    //desenvolvimento
    //matriz
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            cin >> M[i][j];
        }
    }

    //calcular a soma das linhas
    for (int k = 0; k < 12; k++)
    {
        soma += M[k][C]; //k vai variar mais C trava.
    }

    //saída de dados - decidir qual vai imprimir
    if (T == 'S') //soma
    {
        cout << fixed << setprecision(1) << soma << endl;
    }
    else if (T == 'M') //média
    {
        media =  soma / 12.0; //media é soma / pela 12 linhas
        cout << fixed << setprecision(1) << media << endl;
    }

    return 0;
}