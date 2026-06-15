/*
1025 - ONDE ESTÁ O MÁRMORE?

RAJU E MEENA AFORAM JOGAR UM JOGO DIFERENTE COM PEQUENAS PEÇAS DE MÁMORES,
CHAMADOS MARBLES. ELES TÊM UM MONTE DESTAS PEÇAS COM NÚMEROS ESCRITOS NELES. NO
INÍCIO, RAJU COLOCARIA ESTES PEQUENOS MÁRMORES UM APÓS OUTRO EM ORDEM ASCENDENTES
DE NÚMEROS ESCRITOS NELES. ENTÃO MEENA GOSTARIA DE PEDIR A RAJU PARA ENCONTRAR O
PRIMEIRO MÁRMORE COM UM CERTO NÚMERO. ELE DEVERIA CONTAR 1...2...3. RAJU GANHA UM
PONTO POR CADA RESPOSTA CORRETA E MEENA GANHA UM PONTO SE RAJU FALHA. DEPOIS DE
UM NÚMERO FIXO DE TENTATIVAS, O JOGO TERMINA E O JOGADOR COM O MÁXIMO DE PONTOS
VENCE. HOJE É SUA CHANCE DE JOGAR COM RAJU. SENDO UM/A CARA ESPERTO/A, VOCÊ TEM EM
SEU FAVOR O COMPUTADOR. MAS NÃO SUBESTIME MEENA, ELA ESCREVEU UM PROGRAMA PARA
MONITORAR QUANTO TEMPO VOCÊ LEVARÁ PARA DAR TODAS AS RESPOSTAS. PORTANTO, AGORA
ESCREVA O PROGRAMA, QUE AJUDARÁ VOCÊ EM SEU DESAFIO COM RAJU.

ENTRADA: A ENTRADA CONTÉM VÁRIOS CASOS DE TESTE, MAS O TOTAL DE CASOS É MENOR DO QUE 65.
CADA CASO DE TESTE INICIA COM DOIS INTEIROS: N QUE É O NÚMERO DE MÁRMORES E Q QUE É
O NÚMERO DE CONSULTAS QUE MEENA DESEJA FAZER. AS PRÓXIMAS N LINHAS CONTERÃO OS
NÚMEROS ESCRITOS EM CADA UM DOS N MÁRMORES. OS NÚMEROS DESTES MÁRMORES NÃO
TEM QUALQUER ORDEM EM PARTICULAR. AS SEGUINTES Q LINHAS IRÃO CONTER Q CONSULTAS.
TENHA CERTEZA, NENHUM DOS NÚMEROS DA ENTRADA É MAIOR DO QUE 100000 E NENHUM 
DELES É NEGATIVOS.
A ENTRADA É TERMINADA POR UM CASO DE TESTE ONDE N = 0 E Q = 0.

SAÍDA: PARA CADA CASO DE TESTE DE SAÍDA DEVE HAVER UM NÚMERO SERIAL DO CASO DE TESTE. PARA
CADA CONSULTA, ESCREVA UMA LINHA DE SAÍDA. O FORMATO DESTA LINHA DEPENDERÁ SE O
NÚMERO CONSULTADO ESTIVER OU NÃO ESCRITO EM UM DOS MÁRMORES. OS DOIS DIFERENTES
FORMATOS SÃO DESCRITOS ABAIXO:
'X FOUND AT Y', SE O PRIMEIRO MARBLE X FOI ENCONTRADO NA POSIÇÃO Y. POSIÇÕES SÃO
NUMERADA DE 1, 2,... A N.
'X NOT FOUND', SE O MARBLE COM O NÚMERO X NÃO ESTIVER PRESENTE.
*/

//biblioteca
#include <iostream>
#include <algorithm> //biblioteca necessário para a função sort()

using namespace std;

//declaração global
int vetor[100001];

//função principal
int main()
{
    //declaração de váriaveis
    int N; //números de mármores
    int Q; //números de consultas
    int caso = 1; //controlar o número de caso de teste

    //entrada de dados
    while(cin >> N >> Q && (N != 0 || Q != 0))
    {
        //entrada de dados
        for (int i = 0; i < N; i++)
        {
            cin >> vetor[i];
        }

        //desenvolvimento
        //ordenação - a busca binária exige que o vetor esteja ordenado
        //pegue o vetor a partir do início até a posição N e de tudo do menor para o maior
        sort(vetor, vetor + N); //função sort ordena o vetor desde o início até a posição 'N'
        
        //saida de dados
        cout << "CASE# " << caso << ":" << endl;
        caso++;

        //processando as Q consultas de meena
        for (int i = 0; i < Q; i++)
        {
            int x; //número para encontrar
            cin >> x;

            //variáveis de busca binária
            int pos = -1; //começa no -1 (não encontrado)
            int baixo = 0; //começa na primeira posição
            int alto = N - 1; //começa na última posição

            //while - busca binária
            while (baixo <= alto)
            {
                //calculo o meio do intervalo atual
                int meio = (baixo + alto) / 2;

                if (x == vetor[meio])
                {
                    //encontramos x
                    pos = meio;
                    alto = meio - 1;
                }
                else if (x < vetor[meio])
                {
                    //se o x é menor que o meio, continua buscando esquerda
                    alto = meio - 1;
                }
                else
                {
                    //se o x é maior que o meio, continua buscando direita
                    baixo = meio + 1;
                }
                
            }

            //verificar se encontra algo
            if (pos != -1)
            {
                cout << x << " found at " << pos + 1 << endl;
            }
            else
            {
                cout << x << " not found" << endl;
            }
        }

    }

    return 0;
}