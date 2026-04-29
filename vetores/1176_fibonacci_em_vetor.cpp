/*Faça um programa que leia um valor e apresente o número de Fibonacci correspondente a este valor lido. 
Lembre que os 2 primeiros elementos da série de Fibonacci são 0 e 1 e cada próximo termo é a soma dos 2 anteriores a ele. 
Todos os valores de Fibonacci calculados neste problema devem caber em um inteiro de 64 bits sem sinal.

Entrada
A primeira linha da entrada contém um inteiro T, 
indicando o número de casos de teste. 
Cada caso de teste contém um único inteiro N (0 ≤ N ≤ 60), 
correspondente ao N-esimo termo da série de Fibonacci.

Saída
Para cada caso de teste da entrada, 
imprima a mensagem "Fib(N) = X", 
onde X é o N-ésimo termo da série de Fibonacci.*/

//CÓDIGO C++ PARA RESOLVER O PROBLEMA
#include <iostream>

using namespace std; //biblioteca de ent e saida.

int main() //função principal
{
    //declaração de variáveis
    int T; //números de casos de teste
    int FIB[61]; //vetor para armazenar os valores de N
    int N; //descobrir o fibonacci

    //entrada de dados
    cin >> T;
    cin >> N;

    //cálculo dos valores de Fibonacci
    FIB[0] = 0; //primeiro termo da série de Fibonacci
    FIB[1] = 1; //segundo termo da série de Fibonacci

    for (int i = 2; i <= 61 ; i++)
    {
        FIB[i] = FIB[i-1] + FIB[i-2];
    }

    //saida de dados
    for (int i = 0; i < T; i++)
    {
        cout << "Fib (" << N << ") = " << FIB[i] << endl;
    }
    
    return 0;
} 