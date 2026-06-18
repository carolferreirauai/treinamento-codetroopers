/*
2973 - MARATONA BRASILEIRA DE COMEDORES DE PIPOCA

A MARATONA BRASILEIRA DE COMEDORES DE PIPOCAS É UMA COMPETIÇÃO QUE OCORRE
ANUALMENTE COM O INTUITO DE DESCOBRIR QUAL A EQUIPE MAIS ORGANIZADA, PREPARADA E
BEM-TREINADA NA ARTE DE COMER PIPOCA.

ELA É ORGANIZADA PELA SBCP (SOCIEDADE BRASILEIRA DE COMEDORES DE PIPOCAS), QUE
PERIODICAMENTE SE REÚNE PARA DISCUTIR AS REGRAS E O FORMATO DA COMPETIÇÃO.

A COMPETIÇÃO CONSISTE EM N SACOS DE PIPOCAS COLOCADOS LADO A LADO, ONDE CADA SACO
POSSUI UMA QUANTIDADE ARBITRÁRIA DE PIPOCA. PARA PROPORCIONAR UMA MAIOR DIVERSÃO, A
COMPETIÇÃO OCORRE EM EQUIPES, CADA UMA COMPOSTA POR C COMPETIDORES. COMO A
MARATONA BRASILEIRA DE COMEDORES DE PIPOCAS É UM EVENTO SÉRIO QUE PREZA, ALÉM DE
TUDO, PELA SAÚDE DOS COMPETIDORES, A COMISSÃO MÉDICA IMPÔS QUE CADA COMPETIDOR
PODERÁ COMER, NO MÁXIMO, T PIPOCAS POR SEGUNDO, A FIM DE EVITAR UM POSSÍVEL MAL-
ESTAR.

A SBCP, EM SUA ÚLTIMA REUNIÃO, DEFINIU DUAS NOVAS REGRAS PARA A EDIÇÃO DE 2019:

CADA COMPETIDOR DA EQUIPE DEVERÁ COMER UMA SEQUÊNCIA CONTÍGUA DE SACOS DE
PIPOCA. É PERFEITAMENTE VÁLIDO QUE UM COMPETIDOR NÃO COMA NENHUMA PIPOCA.
TODAS AS PIPOCAS DE UM MESMO SACO DEVEM SER COMIDAS POR UM ÚNICO COMPETIDOR.
O OBJETIVO DA COMPETIÇÃO É COMER TODAS AS PIPOCAS NO MENOR TEMPO POSSÍVEL, DADO
QUE OS C COMPETIDORES PODEM COMER EM PARALELO E ELES RESPEITARÃO TODAS AS REGRAS
IMPOSTAS PELA SBCP.

ENTRADA: A PRIMEIRA LINHA CONTÉM TRÊS INTEIROS N, C E T (1 ≤ N ≤ 10^5, 1 ≤ C ≤ 10^5 E 1 ≤ T ≤ 50),
REPRESENTANDO A QUANTIDADE DE SACOS DE PIPOCA, A QUANTIDADE DE COMPETIDORES DE
UMA MESMA EQUIPE E QUANTIDADE MÁXIMA DE PIPOCA POR SEGUNDO QUE UM COMPETIDOR
PODE COMER. A SEGUNDA LINHA CONTERÁ N INTEIROS P_I (1 ≤ P_I ≤ 10^4), SENDO ESTES A
QUANTIDADE DE PIPOCA EM CADA UM DOS N SACOS.

SAÍDA: SEU PROGRAMA DEVE PRODUZIR UMA ÚNICA LINHA COM UM INTEIRO REPRESENTANDO A
QUANTIDADE MÍNIMA DE SEGUNDOS NECESSÁRIA PARA A EQUIPE COMER TODAS AS PIPOCAS SE
ELA SE ORGANIZAR DA MELHOR MANEIRA POSSÍVEL.
*/
//biblioteca
#include <iostream>

using namespace std;

//declaração globais
int Pi[100005]; //quantidade de pipocas

//função testadora - o juiz
bool testa(long long tempo, long long N, long long C, long long T)
{
    long long competidores_usados = 1;
    long long pipocas_comidas_agora = 0;
    long long capacidade_max = tempo * T; //calcular a capacidade máxima
    
    //o loop vai de 0 até N
    for(int i = 0; i <= N; i++)
    {
        //se a pipocas mais que capacidade máxima, é impossível
        if (Pi[i] > capacidade_max)
        {
            return false;
        }
        //se o saco atual estourar o limite do competidor atual, passar para o próximo competidor
        else if (pipocas_comidas_agora + Pi[i] > capacidade_max)
        {
            competidores_usados++;
            pipocas_comidas_agora = Pi[i];
        }
        //se não estourar, o competidor atual come esse saco e acumula
        else
        {
            pipocas_comidas_agora += Pi[i];
        }

    }
    //se uma quantidade válida de competidores
    return competidores_usados <= C;
}

int main()
{
    //declaração de váriaveis
    long long N; //quantidade de sacos de pipocas
    long long C; //quantidade de competidor
    long long T; //quantidade máxima de pipoca

    //entrada de dados
    //ler múltiplos casos de teste
    while(cin >> N >> C >> T)
    {
        //declaração de dados
        long long soma_total = 0;

        //lendo os sacos de pipoca
        for (int i = 0; i < N; i++)
        {
            cin >> Pi[i];
            soma_total += Pi[i];
        }

        //desenvolvimento
        // ========== BUSCA BINÁRIA ==========
        //baixo = melhor tempo possível, alto = pior tempo possível
        long long baixo = 0, alto = soma_total, melhor_tempo = alto;

        //loop da busca binária
        while (baixo <= alto)
        {
            long long meio = (baixo + alto) / 2;

            if (testa(meio, N, C, T))
            {
                melhor_tempo = meio; //se conseguir comer tudo, salva
                alto = meio - 1; //forçamos a busca para esquerda
            }
            else
            {
                baixo = meio + 1; //se não der certo, forçamos a busca para direita
            }
        }
        //saida de dados
        cout << melhor_tempo << endl;
    }
    return 0;
}