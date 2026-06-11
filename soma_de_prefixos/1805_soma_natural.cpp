/*
1805 - SOMA NATURAL

UM NÚMERO NATURAL É INTEIRO NÃO NEGATIVO (0, 1, 2, 3, 4, 5,...). A SUA TAREFA NESTE
PROBLEMA É CALCULAR A SOMA DOS NÚMEROS NATURAIS QUE ESTÃO PRESENTES EM UM
DETERMINADO INTERVALO [A, B] INCLUSIVE.

POR EXEMPLO, A SOMA DOS NÚMEROS NATURAIS NO INTERVALO [2, 5] É 14 = (2 + 3 + 4 + 5).

ENTRADA: CADA CASO DE TESTE CONTÉM DOIS INTEIROS A E B (1 <= A <= B <= 10^9), REPRESENTANDO O
LIMITE INFERIOR E SUPERIOR RESPECTIVAMENTE.

SAÍDA: PARA CADA CASO DE TESTE, A SAÍDA CONSISTE DE UMA LINHA CONTENDO A SOMA DOS NÚMEROS
NATURAIS DO INTERVALO.
*/

//biblioteca
#include <iostream>

using namespace std;

//função principal
int main()
{
    //declaração de váriaveis
    long long A, B, resultado;

    //entrada de dados
    cin >> A >> B; //limites

    //desenvolvimento
    resultado = (A + B) * (B - A + 1) / 2; //soma de progressão aritmética (pa)

    //saída de dados
    cout << resultado << endl;

    return 0;
}