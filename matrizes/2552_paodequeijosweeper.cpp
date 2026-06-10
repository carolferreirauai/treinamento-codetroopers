/*
2552 - PÃO DE QUEIJO SWEEPER

ESTÁ CHEGANDO A GRANDE FINAL DO COMPEONATO NLOGONENSE DE SURF AQUÁTICO, QUE ESTE
ANO OCORRERÁ NA CIDADE DE BONITA HORELENINHA (BH)! NESTA CIDADE, O JOGO
PÃODEQUEIJOSWEPPER É BASTANTE POPULAR!

O TABULEIRO DO JOGO CONSISTE EM UMA MATRIZ DE N LINHAS E M COLUNAS. CADA CÉLULA DA
MATRIZ CONTÉM UM PÃO DE QUEIJO OU O NÚMERO DE PÃES DE QUEIJO QUE EXISTEM NAS
CELULAS ADJACENTES A ELA. UMA CÉLULA É ADJACENTE A OUTRA SE ESTIVER IMEDIATAMENTE Á
ESQUERDA, Á DIREITA, ACIMA OU ABAIXO DA CÉLULA. NOTE QUE, SE NÃO CONTIVER UM PÃO DE
QUEIJO, UMA CÉLULA DEVE OBRIGATÓRIAMENTE CONTER UM NÚMERO ENTRE 0 A 4, INCLUSIVE.

DADAS AS POSIÇÕES DOS PÃES DE QUEIJO, DETERMINE O TABULEIRO DO JOGO!

ENTRADA: A ENTRADA CONTÉM VÁRIOS CASOS DE TESTE. A PRIMEIRA LINHA DE CADA CASO CONTÉM OS
INTEIROS N E M (1 <= N, M <= 100). AS PRÓXIMAS N LINHAS CONTÉM M INTEIROS CADA,
SEPARADOS POR ESPAÇOS, DESCREVENDO OS PÃES DE QUEIJO NO TABULEIRO. O J-ÉNSIMO INTEIRO
DA I-ÉSIMA LINHA É 1 SE EXISTE UM PÃO DEQUEIJO NA LINHA I E COLUNA J DO TABULEIRO, OU 0 CASO CONTRÁRIO.

A ENTRADA TERMINA COM FIM-DO-ARQUIVO (EOF)

SAÍDA: PARA CADA CASO DE TESTE, IMPRIMA N LINHAS COM M INTEIROS CADA, NÃO SEPARADOS POR
ESPAÇOS, DESCREVENDOA CONFIGURAÇÃO DO TABULEIRO. SE UMA POSIÇÃO CONTÉM UM PÃO DE
QUEIJO, IMPRIMA 9 PARA ELA; CASO CONTRÁRIO, IMPRIMA O NÚMERO CUJA POSIÇÃO DEVE
CONTER.
*/

//biblioteca
#include <iostream>

using namespace std;

int main()
{
    //declaração de váriaveis
    int N; //linhas
    int M; //colunas
    int matriz[100][100]; //matriz

    //entrada de dados
    while (cin >> N >> M)
    {
        //lendo o tabuleiro
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> matriz[i][j];
            }
        }

        //desenvolvimento
        //varrer cada posição do tabuleiro
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                //saida de dados
                if (matriz[i][j] == 1) //primeira checagem
                {
                    cout << 9; //tem pão, imprimir 9
                }
                else //segunda checagem: se não tem (é 0), precisamos contar os vizinhos
                {
                    int contador = 0; //váriavel para acumular os pães

                    //cima: a linha deve ser > 0
                    if (i > 0 && matriz[i - 1][j] == 1)
                    {
                        contador++;
                    }
                    //baixo: a linha deve ser < que o limite final (N-1)
                    if (i < N - 1 && matriz[i + 1][j] == 1)
                    {
                        contador++;
                    }
                    //esquerda: a coluna deve ser > 0
                    if (j > 0 && matriz[i][j - 1] == 1)
                    {
                        contador++;
                    }
                    //direita: a coluna deve ser menor que o limite final (M - 1)
                    if (j < M - 1 && matriz[i][j + 1] == 1)
                    {
                        contador++;
                    }
                    //imprime a quantidade entrada em volta
                    cout << contador;
                }
            }
            //pula para próxima linha
            cout << endl;
        }
    }
    
    return 0;
}