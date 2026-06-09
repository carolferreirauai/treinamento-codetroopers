/*
1187 - ÁREA SUPERIOR

LEIA UM CARACTERE MAIÚSCULO, QUE INDICA UMA OPERAÇÃO QUE DEVE SER REALIZADA E UMA
MATRIZ M[12][12]. EM SEGUIDA, CALCULE E MOSTRE A SOMA OU A MÉDIA CONSIDERANDO
SOMENTE AQUELES ELEMENTOS QUE ESTÃO NA ÁREA SUPERIOR DA MATRIZ, CONFORME ILUSTRADO
ABAIXO (ÁREA VERDE).
1-10
2-9
3-8
4-7
5-6

ENTRADA: A PRIMEIRA LINHA DE ENTRADA CONTEM UM ÚNICO CARACTERE MAIÚSCULO O ('S' OU 'M'),
INDICANDO A OPERAÇÃO (SOMA OU MÉDIA) QUE DEVERÁ SER REALIZADA COM OS ELEMENTOS DA
MATRIZ. SEGUEM 144 VALORES COM UM PONTO FLUTUANTE DE DUPLA PRECISÃO QUE COMPÕEM A
MATRIZ.

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
    char O; //operação - letras
    double M[12][12]; //matriz 12x12
    double soma = 0;
    double media;
    int area = 0; //contar a área superior


    //entrada de dados
    cin >> O; //ler o operador

    //ler a matriz
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            cin >> M[i][j];
        }
    }

    //desenvolvimento
    //calcular a área superior
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            //para estar dentro da área, coluna (j) deve ser > que a linha (i) e, ao mesmo tempo, < que o limite final daquela linha (11 - i).
            if (j > i && j < 11 - i)
            {
                soma += M[i][j];
                area++;
            }
        }
    }

    //saída de dados
    if (O == 'S')
    {
        cout << fixed << setprecision(1) << soma << endl;
    }
    else if (O == 'M')
    {
        media = soma / area;
        cout << fixed << setprecision(1) << media << endl;
    }

    return 0;
}