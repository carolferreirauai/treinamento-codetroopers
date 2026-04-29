/*
1046 - TEMPO DE JOGO

LEIA A HORA INICIAL E A HORA FINAL DE UM JOGO. A SEGUIR CALCULE A DURAÇÃO DO JOGO, SABENDO QUE O MESMO PODE
COMEÇAR EM UM DIA E TERMINAR NO OUTRO, TENDO UMA DURAÇÃO MÍNIMA DE 1 HORA E MÁXIMA DE 24 HORAS.

ENTRADA: A ENTRADA CONTÉM DOIS VALORES INTEIROS REPRESENTANDO A HORA DE INÍCIO E HORA DE FIM DO JOGO.
SAIDA: APRESENTE A DURAÇÃO DO JOGO CONFORME EXEMPLO AVAIXO.
*/

//biblioteca
#include <iostream>
#include <bits/stdc++.h> //todas as bibliotecas

using namespace std; //espaços

int main() //função principal
{
    //declaração de variaveis
    int inicio, fim; //horas de inicio e hora de fim.
    int duracao; //tempo de duracao

    //entrada de dados
    cin >> inicio >> fim; //ler as horas

    //desenvolvimentos
    //calculo da duração, +24 garante que o resuntado nunca seja negativo, %24 corrige jogos que não passam da meia-noite
    duracao = (fim - inicio + 24) % 24;

    //se der 0, será substituido para 24
    if (duracao == 0)
    {
        duracao = 24;
    }

    //saida de dados
    cout << "O JOGO DUROU " << duracao << " HORA(S)" << endl;

    return 0;
}