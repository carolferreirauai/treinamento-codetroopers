/*
1534 - MATRIZ 123

LEIA UM VALOR INTEIRO N QUE PE O TAMANHO DA MATRIZ QUE DEVE SER IMPRESSA CONFORME O
MODELO FORNECIDO.

- DIAGRAMA PRINCIPAL: 1
- DIAGRAMA SECUNDÁRIA: 2
- RESTANTE DA MATRIZ: 3

ENTRADA: A ENTRADA CONTÉM VÁRIOS CASOS DE TESTE E TERMINA COM EOF. CADA CASO DE TESTE É
COMPOSTO POR UM ÚNICO INTEIRO N (3 <= N <= 70), QUE DETERMINA O TAMANHO (LINHAS E 
COLUNAS) DE UMA MATRIZ QUE DEVE SER IMPRESSA.

SAÍDA: PARA CADA N LIDO, APRESENTE A SAÍDA CONFORME O EXEMPLO FORNECIDO.
*/

//biblioteca
#include <iostream>

using namespace std;

int main()
{
    //declaração de váriaveis
    int N; //tamanho da matriz.

    //entrada de dados
    while (cin >> N)
    {
        //desenvolvimento
        //matrizes
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                //saida de dados
                if (i + j == N - 1) //diagonal secundária
                {
                    cout << 2;
                }
                else if (i == j) //diagonal principal
                {
                    cout << 1;
                }
                else //restante da matrix
                {
                    cout << 3;
                }
            }
            //pula para próxima linha
            cout << endl;
        }
    }
    return 0;
}