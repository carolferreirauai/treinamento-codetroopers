/*
3051 - SOMA

TEMOS UMA SEQUÊNCIA DE N QUADRADOS DESENHADOS LADO A LADO. CADA QUADRADO POSSUI 
UM NÚMERO NATURAL ANOTADO DENTRO DELE. DADOS A SEQUÊNCIA DOS N QUADRADOS E UM
VALOR K, QUANTOS RETÂNGULOS DISTINTOS EXISTEM CUJA SOMA DOS NÚMEROS DENTRO DO
RETÂNGULO É EXATAMENTE IGUAL A K? POR EXEMPLO, A FIGURA MOSTRA UMA SEQUÊNCIA DE N
= 10 QUADRADOS PARA QUAL EXISTEM 5 RETÂNGULOS CUJA SOMA DOS NÚMEROS É IGUAL A K =
4.

ENTRADA: A PRIMEIRA LINHA DA ENTRADA CONTÉM DOIS INTEIROS N (1 <= N <= 5 * 10^5) E K (0 <= K <= 10^6)
REPRESENTANDO O NÚMEROS DE QUADRADOS NA SEQUÊNCIA E O VALOR DA SOMA DESEJADA. A
SEGUNDA LINHA DA ENTRADA CONTÉM N NÚMEROS NATURAIS X_I, PARA 1 <= I <= N, INDICANDO A
SEQUÊNCIA DE NÚMEROS ANOTADOS DENTRO DOS QUADRADOS.

SAÍDA: SEU PROGRAMA DEVE IMPRIMIR UMA LINHA CONTENDO UM NÚMERO INTEIRO REPRESENTANDO
QUANTOS RETÂNGULOS EXISTEM NA SEQUÊNCIA CUJA SOMA É IGUAL A K.
*/

//biblioteca
#include <iostream>
#include <map> //biblioteca necessária para usar map

using namespace std;

//função principal
int main()
{
    //declaração de váriaveis
    long long N, K;
    map<long long, long long> frequencia; //map ele guarda: map<valor_da_soma, quantas_vezes_apareceu>
    long long soma_atual = 0;
    long long contador = 0;

    frequencia[0] = 1;

    //entrada de dados
    cin >> N >> K;

    //desemvolvimento
    for (int i = 0; i < N; i++)
    {
        long long valor;
        cin >> valor;

        //atualiza a soma 
        soma_atual += valor;
        
        //calcular soma antiga
        long long soma_antiga = soma_atual - K;

        //o map responde quantas vezes a soma antiga ocorreu, se nunca, ele simplesmente retorna 0 e não alterna o contador
        contador += frequencia[soma_antiga];

        //avisar ao map qie acabamos de ver essa 'soma atual' mais uma vez
        frequencia[soma_atual]++;
    }

    //saída de dados
    cout << contador << endl;

    return 0;
}