/*
1042 - SORT SIMPLES

LEIA 3 VALORES INTEIROS E ORDENE-OS EM ORDEM CRESCENTE. NO FINAL, MOSTRE OS VALORES EM ORDEM CRESCENTE,
UMA LINHA EM BRANCO E EM SEGUIDA, OS VALORES NA SEQUÊNCIA COMNO FORAM LIDOS.

ENTRADA: A ENTRADA CONTEM 3 NÚMEROS INTEIROS.

SAIDA: IMPRIMA A SAÍDA CONFORME FOI ESPECIFICADO.
*/

//biblioteca
#include <iostream>
#include <bits/stdc++.h> //todas bibliotecas

using namespace std; //espaços

int main() //função principal
{
    //declaração de variaveis
    int num1, num2, num3;
    int min, med, max;

    //entrada de dados
    //ler os 3 valores
    cin >> num1 >> num2 >> num3;
    
    //desenvolvimentos
    //ordenação menor, medio, maior
    //bloco 1 - num1 é menor?
    if (num1 < num2 && num1 < num3) //se for menor que num2 e menor que num3
    {
        min = num1; 
        if (num2 < num3) //os dois que sobraram que é o menor?
        {
            med = num2;
            max = num3;
        }
        else
        {
            med = num3;
            max = num2;
        }
    }

    //bloco 2 - num2 é menor?
    else if (num2 < num3) //se for menor que num3

    {
        min = num2;
        if (num1 < num3) //dos dois que sobraram, quem é o menor?
        {
            med = num1;
            max = num3;
        }
        else
        {
            med = num3;
            max = num1;
        }
    }

    //bloco 3 - num3 é menor
    else //senão é num1 e num2, num3 é o menor
    {
        min = num3;
        if(num1 < num2)
        {
            med = num1;
            max = num2;
        }
        else
        {
            med = num2;
            max = num1;
        }
    }

    //saida de dados
    //saida dos menor, medio, maior
    cout << min << endl;
    cout << med << endl;
    cout << max << endl;

    //linha branca
    cout << endl;

    //valores na ordem original
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    return 0;
}