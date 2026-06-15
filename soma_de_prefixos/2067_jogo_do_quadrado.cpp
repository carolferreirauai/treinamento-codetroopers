/*
2067 - JOGO DO QUADRADO

O "JOGO DO QUADRADO" É UM JOGO MUITO POPULAR HOJE EM DIA! O JOGO É MUITO SIMPLES: É
DADA UM RETÂNGULO DE N LINHAS E M COLUNAS CONTENDO NÚMEROS INTEIROS NÃO NEGATIVOS.
A IMAGEM A SEGUIR MOSTRA UM RETÂNGULO COM 3 LINHAS E 4 COLUNAS.

3  4 0  3
0 *2 3* 1
4 *2 1* 0

TAMBÉM É DADO UM INTEIRO S. VOCÊ DEVE ESCOLHER ALGUM QUADRADO COM S LINHAS E S
COLUNAS CONTIDO INTEIRAMENTE DENTRO DO RETÂNGULO. SUA PONTUAÇÃO É DADA PELO 
PRODUTO DE TODOS OS INTEIROS DENTRO DO QUADRADO QUE VOCÊ ESCOLHEU. POR EXEMPLO, SE
S = 2 E VOCÊ ESCOLHEU O QUADRADO MOSTRADO EM AZUL NA IMAGEM ACIMA, SUA PONTUAÇÃO
SERÁ IGUAL A 2 * 3 * 2 * 1 = 12.

VOCÊ PERCEBEU QUE, DEPENDENDO DO QUADRADO QUE VOCÊ ESCOLHER, A SUA PONTUAÇÃO
PODE SER IGUAL A ZERO. SÃO DADOS UM RETÂNGULO E UMA LISTA DE CONSULTAS. PARA CADA
CONSULTA, É DADO UM INTEIRO S E VOCÊ DEVE DETERMINAR SE É POSSÍVEL ESCOLHER ALGUM
QUADRADO S x S, DE TAL FORMA QUA SUA PONTUAÇÃO NÃO SERÁ IGUAL A ZERO.

ENTRADA: A PRIMEIRA LINHA CONTÉM DOIS INTEIROS N E M (1 <= N, M <= 200) INDICANDO O NÚMERO DE
LINHAS E DE COLUNAS DO RETÂNGULO. AS PRÓXIMAS N LINHAS CONTÉM M INTEIROS CADA, 
DESCREVENDO O RETÂNGULO. CADA INTEIRO NO RETÂNGULO NÃO É MAIOR QUE 10^9.

A PRÓXIMA LINHA CONTÉM UM INTEIRO Q (1 <= Q <= 200) INDICANDO O NÚMERO DE CONSULTAS.
CADA UMA DAS PRÓXIMA Q LINHAS DESCREVE UMA CONSULTA. CADA LINHA CONTÉM UM
INTEIRO S (1 <= S <= MIN(N, M)) INDICANDO O COMPRIMENTO DO LADO DO QUADRADO QUE VOCÊ
DEVE ESCOLHER.

SAÍDA: PARA CADA CONSULTA, IMPRIMA UMA LINHA CONTENDO YES SE É POSSIVEL ESCOLHER UM
QUADRADO TAL QUE SUA PONTUAÇÃO NÃO SERÁ IGUAL A ZERO, OU NO CASO CONTRÁRIO.
*/

//biblioteca
#include <iostream>

using namespace std;

//declaração globais
int matriz_zeros[205][205];

//função principal
int main()
{
    //declaração de váriaveis
    int N; //linas
    int M; //colunas
    int Q; //números de consultas

    //entrada de dados
    cin >> N >> M;

    //desenvolvimento
    //construção da matriz
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            int valor;
            cin >> valor;

            //se for zero, consider 1. se não, é 0.
            int zero = 0;
            if (valor == 0)
            {
                zero = 1;
            }

            //construção da soma 2d
            matriz_zeros[i][j] = zero + matriz_zeros[i - 1][j] + matriz_zeros[i][j - 1] - matriz_zeros[i - 1][j - 1];
        }
    }

    //entrada de dados
    cin >> Q;

    //verificar cada consulta
    for (int q = 1; q <= Q; q++)
    {
        int S; //tamanho da consulta atual
        cin >> S;

        bool achou = false;

        //verificar cantos inferiores direitos possíveis
        for (int i = S; i <= N; i++)
        {
            for (int j = S; j <= M; j++)
            {
                //descobrir a quantidade de zeros atual
                int total_zeros = matriz_zeros[i][j] - matriz_zeros[i - S][j] - matriz_zeros[i][j - S] + matriz_zeros[i - S][j - S];

                //se o total de zero for zero, a multiplicação não zera!
                if (total_zeros == 0)
                {
                    achou = true;
                    break; //interrompe o for do j
                }
            }

            //se já achou dentro do for, não precisa continuae
            if (achou == true)
            {
                break; //interrompe o for i
            }
        }

        //saida de dados
        if (achou == true)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
    return 0;
}