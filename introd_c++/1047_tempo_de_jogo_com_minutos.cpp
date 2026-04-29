/*
1047 - TEMPO DE JOGO COM MINUTOS

LEIA A HORA INICIAL, MINUTO INCIAL, HORA FINAL E MINUTO FINAL DE UM JOGO. A SEGUIR CALCULE A DURAÇÃO DO JOGO.
OBS O JOGO TEM DURAÇÃO MÍNIMA DE UM (1) MINUTO E DURAÇÃO DE MÁXIMO 24 HORAS.

ENTRADA: 4 NÚMEROS INTEIROS REPRESENTANDO A HORA DE INICÍO E FIM DO JOGO.

SAÍDA: MOSTRE A SEGUINTE MENSAGEM: "O JOGO DUROU XXX HORA(S) E YYY MINUTOS(S)"
*/

//biblioteca
#include <iostream>
#include <bits/stdc++.h> //todas bibliotecas

using namespace std;

int main() //função principal
{
    //declaração de variaveis
    int h_inicio, m_inicio; //horas e minutos iniciais
    int h_fim, m_fim; //horas e minutos finais
    int inicio, fim; //inicio e fim em minutos
    int delta_tempo; //duração total em minutos
    int horas, minutos; //resultado final

    //entrada de dados
    cin >> h_inicio >> m_inicio >> h_fim >> m_fim; //ler as horas e minutos
    
    //desenvolvimento
    //valores do inicio e final
    //converter os horários em minutos totais
    inicio = (h_inicio * 60) + m_inicio;
    fim = (h_fim * 60) + m_fim;

    //calcule diferençass em minutos
    delta_tempo = fim - inicio;

    //se o resultado for negativo ou zero, passou da meia-noite
    if (delta_tempo <= 0)
    {
        delta_tempo += 1440; //soma 24 horas em minutos
    }

    //converte o delta de volta para horas e minutos
    horas = delta_tempo / 60; //divisão inteira
    minutos = delta_tempo % 60; //resto da divisão

    //saida de dados
    cout << "O JOGO DUROU " << horas << " HORA(S) E " << minutos << " MINUTO(S)" << endl;
    
    return 0;
}