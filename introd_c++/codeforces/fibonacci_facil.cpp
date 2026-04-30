/*
A. TEOREMA HEXADECIMAL

RECENTEMENTE, UM VIRUS CAÓTICO HEXADECIMAL AVANÇOU UM NOVO TEOREMA QUE ABALARÁ O 
UNIVERSO. ELA ACHA QUE CADA NÚMERO DE FIBONACCI PODE SER REPRESENTADO COMO SOMA DE 3
NÚMEROS DE FIBONACCI DIFERENTES NÃO NECESSÁRIOS.

VAMOS LEMBRAR COMO OS NÚMEROS DE FIBONACCI PODE SER CALCULADOS F_0 = 0, F_1 = 1,
E TODOS OS PRÓXIMOS NÚMEROS SÃO F_I = F_I-2 + F_I-1.

SE NÃO FUGIU DO PC COM MEDO, TEM QUE AJUDAR O VIRUS. SUA TAREFA É DIVIDIR DADO O NÚMERO DE
FIBONACCI N POR 3 NÃO NECESSÁRIOS NÚMEROS DIFERENTES DE FIBONACCI OU DIZER QUE É
IMPOSSIVEL.

ENTRADA: A ENTRADA CONTÉM DE UM ÚNICO NÚMERO INTEIRO N (0 <= N < 10^9) O NÚMERO  QUE DEVE
SER REPRESENTADO PELAS REGRAS DESCRITAS ACIMA. É GARANTIDO QUE N É UM NÚMETO DE FIBONACCI.

SAIDA: SAIDA 3 NÚMEROS NECESSÁRIOS: A, B E C. O SE NÃO OUVER RESPOSTA PARA A PROVA
VOCÊ TEM QUE IMPRIMIR "SOU IDIOTA PARA RESOLVER ESSE PROBLEMA" SEM AS CITAÇÕES.
SE HOUVER MÚLTIPLAS RESPOSTAS, IMPRIMA QUALQUR UMA DELAS.
*/

//biblioteca
#include <iostream>
#include <bits/stdc++.h> //todas bibliotecas

using namespace std; //espaços

int main() //função principal
{
    //declaração de variaveis
    int n; //número inteiro
    int indice = -1; //indice de n na sequência
    int fibonacci[50]; //vetor fixo (50 posições)
    int auxiliar = 2; //auxiliar começa em 2, pois fibonacci 0 e 1 já estão preenchida

    //entrada de dados
    //le o número inteiro, se é um número de fibonacci
    cin >> n;

    //desenvolvimento
    //base da sequência
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    //gera fibonacci enquanto o último valor for menor que 10^9
    for (int i = 2; fibonacci[i-1] < 1e9; i++)
    {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2]; //calculo de fibonacci
        auxiliar++; //conta mais um
    }

    //percorre o vetor procurado n
    for (int i = 0; i < auxiliar; i++)
    {
        if (fibonacci[i] == n) 
        {
            indice = i; //guarda onde n foi encontrado
            break; //para assim que achar
        }
    }

    //imprime a tripla conforme o índice
    if(indice == 0) //n = 0
    {
        cout << "0 0 0" << endl;
    }
    else if (indice == 1) //n = 1
    {
        cout << "0 0 1" << endl;
    }
    else if (indice == 2) //n = 1
    {
        cout << "0 0 1" << endl;
    }
    else if (indice == 3) //n = 2
    {
        cout << "0 1 1" << endl;
    }
    else if (indice == 4) //n = 3
    {
        cout << "1 1 1" << endl;
    }
    else if (indice >= 5) //n >= 5
    {
        cout << 0 << " " << fibonacci[indice-2] << " " << fibonacci[indice-1] << endl;
    }
    else
    {
        cout << "I'm too stupid to solve this problem" << endl;

    }

    return 0;
}