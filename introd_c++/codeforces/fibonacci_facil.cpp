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
#include <vector>
#include <bits/stdc++.h> //todas bibliotecas

using namespace std; //espaços

int main() //função principal
{
    //declaração de variaveis
    int n; //número de entrada
    int sz; //tamanho temporário
    int indice = -1; //indice de n na sequência (-1, não encontrado)

    //entrada de dados
    cin >> n; //ler valor

    //desenvolvimento
    vector <long long> fib; //criar o vector de fibonacci dinamicamente
    fib.push_back(0); //f_0 = 0
    fib.push_back(1); //f_1 = 1

    //gera fib até ultrapassar 10^9
    //usa long long para não estourar nos cálculos intermediários
    while(fib.back() < 1e9)
    {
        sz = fib.size();
        fib.push_back(fib[sz-1] + fib[sz-2]); //f_i = f_{i-1} + f_{i-2}
    }

    //percorre o vector procurando n
    for (int i = 0; i < (int)fib.size(); i++)
    {
        if (fib[i] == n)
        {
            indice = i; //guarda o indice onde n foi encontrad
            break; //para assim que achar quebrar.
        }
    } 

    // se indice >= 4, a tripla 0 + f_{indice-2} + f_{indice-1} funciona
    // os 3 são sempre distintos e somam exatamente n
    if (indice >= 4)
    {
        cout << 0 << " " << fib [indice - 2] << " " << fib[indice - 1] << endl;
    }
    else //indice < 4: n é peqeuno demais, impossivel ter 3 distintos
    {
        cout << "I'm too stupid to solve this problem" << endl;
    }

    return 0;
}