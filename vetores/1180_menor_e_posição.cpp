/*
1180 - MENOR E POSIÇÃO

FAÇA UM PROGRAMA QUE LEIA UM VALOR N. ESTE N SERÁ O TAMANHO DE UM VETOR C[N]. A
SEGUIT, LEIA CADA UM DOS VALORES DE X, ENCONTRE O MENOR ELEMENTO DESTE VETOR E A SUA
POSIÇÃO DENTRO DO VETOR, MOSTRANDO ESTA INFORMAÇÃO.

ENTRADA: A PRIMEIRA LINHA DE ENTRADA CONTEM UM ÚNICO INTEIRO M (1 < N < 1000), INDICANDO O
NÚMERO DE ELEMENTOS QUE DEVERÃO SER LIDOS EM SEGUIDA PARA VETOR X[N] DE INTEIROS.
A SEGUNDA LINHA CONTÉM CADA UM DOS N VALORES, SEPARADOS POR UM ESPAÇO. VALE
LEMBRAR QUE NENHUMA ENTRADA HAVERÁ NÚMEROS REPETIDOS.

SAÍDA: A PRIMEIRA LINHA APRESENTA A MENSAGEM "MENOR VALOR:" SEGUIDA DE UM ESPAÇO E DO 
MENOR VALOR LIDO NA ENTRADA. A SEGUNDA LINHA APRESENTA A MENSAGEM "POSICAO:"
LEMBRANDO QUE O VETOR INICIA NA POSIÇÃO ZERO. 
*/
//biblioteca
#include <iostream> //entrada e saídas
#include <bits/stdc++.h> //todas bibliotecas

using namespace std;

int main() //função principal
{
    //declaração de variaveis
    int vetor_x[1000]; //vetor de n;
    int n; //quantidade de elemento para serem lidos
    int menor_valor; //guardar o menor valor
    int posicao = -1; //guardar a posição do menor valor (-1, vazio)

    //entrada de dados
    cin >> n; //quantidade de elementos

    //preenche as posições
    for(int i = 0; i < n; i++)
    {
        cin >> vetor_x[i];
    }

    menor_valor = vetor_x[0]; //assume que o primeiro é o menor
    posicao = 0;

    for (int i = 1; i < n; i++) //começa no indice 1, porque 0 já foi assumido
    {
        if (vetor_x[i] < menor_valor)
            {
                menor_valor = vetor_x[i]; //verificar o menor valor
                posicao = i; //verificar a posição
            }
    }

    //saida de dados
    cout << "Menor valor: " << menor_valor << endl; //saida do menor valor
    cout << "Posicao: " << posicao << endl; //saida da posição que está esse menor valor

    return 0;
}