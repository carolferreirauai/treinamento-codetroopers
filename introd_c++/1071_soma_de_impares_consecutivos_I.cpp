/*
1071 - SOMA DE IMPARES CONSECUTIVOS I

LEIA 2 VALORES INTEIRO X E Y. A SEGUIR, CALCULE E MOSTRE A SOMA DOS NÚMEROS IMPARES
ENTRE ELES.

ENTRADA: O ARQUIVO DE ENTRADA CONTÉM DOIS VALORES INTEIROS.

SAIDA: O PROGRAMA DEVE IMPRIMIR UM VALOR INTEIRO. ESTE VALOR É A SOMA DOS VALORES IMPARES
QUE ESTÃO ENTRE OS VALORES FORNECIDOS NA ENTRADA QUE DEVERÁ CABER EM UM INTEIRO.
*/

//biblioteca
#include <iostream>
#include <bits/stdc++.h> //todas bibliotecas

using namespace std;

int main() //função principal
{
    //declaração de variaveis
    int x, y; //valores inteiros
    int min, max; //armazenar o valor de x e y
    int soma = 0; //soma, inicia em 0

    //entrada de dados
    //ler os valores
    cin >> x >> y;

    //desenvolvimentos
    //determinar menor e maior
    if (x < y)
    {
        min = x;
        max = y;
    }
    else
    {
        min = y;
        max = x;
    }
   
    //começa depois do menor valor, vai até antes do maior valor, incrementa 1
    for (int i = min + 1; i < max; i++)
    {
        //verificar se o número e impar
        if(i % 2 != 0) 
        {
            soma += i;
        }
    }

    //saida de dados
    cout << soma << endl;

    return 0;
}