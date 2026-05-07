/*
1176 - FIBONACCI EM VETOR

FAÇA UM PROGRAMA QUE LEIA UM VALOR E APRESENTE O NÚMERO DE FIBONACCI
CORRESPONDENTE ESTE VALOR LIDO. LEMBRE QUE OS 2 PRIMEIROS ELEMENTOS DA SÉRIE DE 
FIBONACCI SÃO 0 E 1 E CADA PRÓXIMO TERMO É A SOMA DOS 2 ANTERIORES A ELE. TODOS OS 
VALORES DE FIBONACCI CALCULADOS NESTE PROBLEMA DEVEM CABER EM UM INTEIRO DE 64 BITS
SEM SINAL.

ENTRADA: A PRIMEIRA LINHA DA ENTRADA CONTÉM UM INTEIRO T, INDICANDO O NÚMERO DE CASOS DE 
TESTE. CADA CASO DE TESTE CONTÉM UM ÚNICO INTEIRO N (0 <= N <= 60), CORRESPONDENTE AO
N-ESIMO TERMO DA SÉRIE DE FIBONACCI.

SAÍDA: PARA CADA CASO DE TESTE DA ENRADA, IMPRIMA A MENSAGEM "Fib(N) = X", ONDE X É O N-
ÉSIMO TERMO DA SÉRIE DE FIBONACCIÇ
*/

//biblioteca
#include <iostream> //entrada e saida
#include <bits/stdc++.h> //todas bibliotecas

using namespace std; //espaços

int main() //função principal
{
    //declaração de váriaveis
    int T; //números de casos de testes.
    int N; //N-esimo
    unsigned long long fibonacci[61]; //vetor para armazenar fibonacci

    //definir a base
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    //desenvolvimentos
    for (int i = 2; i <= 60; i++) //int i, incia em 2, porque 0 e 1, já estão pré estibulado
    {
        fibonacci[i] = fibonacci[i-1] + fibonacci [i-2]; //calculo de fibonacci
    }

    //entrada de dados
    cin >> T;

    //saida de dados
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cout << "Fib(" << N << ") = " << fibonacci[N] << endl; 
    }

    return 0;
}