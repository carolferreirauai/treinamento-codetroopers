/*
1912 - AJUDE SEU MADRUGA

SEU MADRUGA FINALMENTE ARRUMOU UM EMPREGO, É SUA GRANDE CHANCE DE PAGAR OS 14
MESES DE ALUGUEL QUE ESTÃO ATRASADOS. SEU CARGO É O DE CORTADOR DE PAPEL E O SALÁRIO É
EXCELENTE.

MADRUGA IRÁ RECEBER N TIRAS RETANGULARES DE PAPEL COM 1 CM DE LARGURA E C CM DE
COMPRIMENTO. AS TIRAS DEVEM SER COLOCADAS UMA AO LADO DA OUTRA DE FORMA QUE SUAS BASES
ESTEJAM ALINHADAS. A TAREFA DE SEU MADRUGA SERÁ, COM APENAS UM CORTE EM LINHA RETA,
PARALELO À BASE, FAZER COM QUE A SOMA DAS ÁREAS DAS TIRAS CORTADAS SEJA IGUAL A A CM^2.

VEJA A ILUSTRAÇÃO ABAIXO COM N = 5 E AS TIRAS COM 5, 3, 6, 2 E 3 CM DE COMPRIMENTO,
RESPECTIVAMENTE, PARA UM A = 3 CM^2.

COM UM CORTE FEITO A UMA ALTURA DE 4 CM EM RELAÇÃO A BASE, A ÁREA RESULTANTE, PINTADA DE
VERMELHO, É EXATAMENTE IGUAL A A CM^2. SUA TAREFA É DESCOBRIR ESSA ALTURA H E AJUDAR SEU
MADRUGA A SE MANTER NO EMPREGO.

ENTRADA: HAVERÁ DIVERSOS CASOS DE TESTES. A PRIMEIRA LINHA DE CADA CASO INICIA COM DOIS INTEIROS N (1
≤ N ≤ 10^5) E A (1 ≤ A ≤ 10^9) REPRESENTANDO, RESPECTIVAMENTE, A QUANTIDADE DE TIRAS E A ÁREA
RESULTANTE ESPERADA. A PRÓXIMA LINHA CONTERÁ N INTEIROS, REPRESENTANDO O COMPRIMENTO C_I
(1 <= C_I <= 10^4) DE CADA TIRA. 
A ENTRADA TERMINA COM N = A = 0, A QUAL NÃO DEVE SER PROCESSADA.

SAÍDA: PARA CADA CASO, EXIBA UMA ÚNICA LINHA, A ALTURA H DO CORTE QUE SEU MADRUGA DEVE FAZER
PARA QUE A SOMA DA ÁREA DAS TIRAS CORTADAS SEJA IGUAL A A CM^2. USE 4 CASAS DECIMAIS APÓS O
PONTO.
EXIBA ":D", CASO NENHUM CORTE SEJA NECESSÁRIO, OU "-.-" CASO SEJA IMPOSSÍVEL.
*/

//biblioteca
#include <iostream>
#include <iomanip> //necessária para setprecision
#include <algorithm> //necessária para função max 

using namespace std;

//declração globais
int Ci[1000005]; //comprimentos

int main()
{
    //declaração de variaveis
    long long N; //quantidade de tiras
    long long A; //área resultante
     
    //entrada de dados
    //o loop quebra quando N = 0 E A = 0
    while ((cin >> N >> A) && (N != 0 || A != 0))
    {
        //declaração de variaveis
        //a cada rodada, será zerada.
        long long soma_total = 0;
        int maior_Ci = 0;

        //entrada de dados
        for (int i = 0; i < N; i++) //lê as tiras
        {
            cin >> Ci[i];
            soma_total += Ci[i]; //acumular a soma do total dos papeis
            //max (valor1, valor2)
            maior_Ci = max(maior_Ci, Ci[i]); //procurar o máximo
        }

        //desenvolvimento
         if (soma_total == A) //precisamos de exatamente todo o papel disponível
        {
            cout << ":D" << endl;
        }
        else if (soma_total < A) //queremos mais papel do que realmente existe "impossivel"
        {
            cout << "-.-" << endl;
        }
        else //temos papel suficiente, precisamos achar a altura do corte.
        {
            //---------- BUSCA BINÁRIA ----------
            double baixo = 0.0; //o corte pode ser no chão (H = 0)
            double alto = maior_Ci; //o corte máximo, mas não pode passar da tira mais alta

            for (int i = 0; i < 100; i++)
            {
                //calcula a altura do corte
                double meio = (baixo + alto) / 2.0;
                double area_cortada = 0.0;

                //calcula o papel cortado
                for (int j = 0; j < N; j++)
                {
                    if (Ci[j] > meio) //corta, se for mais alta do que a altura
                    {
                        area_cortada += (Ci[j] - meio); //a área cortada é a parte da tira que ficou acima
                    }
                }

                //se cortamos área suficiente
                if (area_cortada >= A)
                {
                    baixo = meio;
                }
                //se cortamos pouco papel
                else
                {
                    alto = meio;
                }
            }
            //saida de dados
            cout << fixed << setprecision(4) << baixo << endl;
        }

    }
    return 0;
}