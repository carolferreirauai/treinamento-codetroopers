/*
1471 - MERGULHO

O RECENTE TERREMOTO EM NLOGÔNIA NÃO CHEGOU A AFETAR MUITO AS EDIFICAÇÕES DA
CAPITAL, PRINCIPAL EPICENTRO DO ABALO. MAS OS CIENTISTA DETECTARAM QUE O PRINCIPAL
DIQUE DE CONTENÇÃO TEVE UM DANO SIGNIFICATIVO NA SUA PARTE SUBTERRÂNEA QUE, SE NÃO
FOR CONSERTADO RAPIDAMENTE, PODE CAUSAR O SEU DESMORONAMENTO, COM A
CONSEQUENTE INUNDAÇÃO DE TODA A CAPITAL

O CONSERTO DEVE SER FEITO POR MERGULHADORES, A UMA GRANDE PROFUNDIDADE, EM
CONDIÇÕES EXTREMAMENTE DIFICIEIS E PERIGOSAS. MAS COMO É A SOBREVIVÊNCIA DA PRÓPRIA
CIDADE QUE ESTÁ EM JOGO, SEUS MORADORES ACUDIRAM EM GRANDE NÚMETO COMO
VOLUNTÁRIOS PARA ESSA PERIGOSA MISSÃO.

COMO É TRADICIONAL EM MISSÕES PERIGOSAS, CADA MERGULHADOR RECEBEU NO INÍCIO DO
MERGULHO UMA PEQUENA PLACA COM UM NÚMERO DE IDENTIFICAÇÃO. AO TERMINAR O
MERGULHO, OS VOLUNTÁRIOS DEVOLVIAM A PLACA DE IDENTIFICAÇÃO, COLOCANDO-A EM UM REPOSITÓRIO.

O DIQUE VOLTOU A SER SEGURO, MAS APARENTEMENTE ALGUNS VOLUNTÁRIOS NÃO VOLTARAM DO
MERGULHO. VOCÊ FOI CONTRATADO PARA A PENOSA TAREFA DE, DADAS AS PLACAS COLOCADAS NO
REPOSITÓRIO, DETERMINAR QUAIS VOLUNTÁRIOS PERDERAM A VIDA SALVANDO A CIDADE.

ENTRADA: A ENTRADA CONTÉM VÁRIOS CASOS DE TESTE E TERMINA COM EOF, CADA CASO DE TESTE É
COMPOSTO DE DUAS LINHAS. A PRIMEIRA LINHA CONTÉM DOIS INTEIROS N E R (1 <= R <= N <=
10^4), INDICANDO RESPECTIVAMENTE O NÚMERO DE VOLUNTÁRIOS QUE MERGULHOU E O NÚMERO
DE VOLUNTÁRIOS QUE RETONROU DO MERGULHO. OS VOLUNTÁRIOS SÃO IDENTIFICADOS POR
NÚMEROS DE 1 A N. A SEGUNDA LINHA DA ENTRADA CONTÉM R INTEIROS, INDICANDO OS 
VOLUNTÁRIOS QUE RETORNARAM DO MERGULHO (AO MENOS UM VOLUNTÁRIO RETORNA DO
MERGULHO).

SAIDA: SEU PROGRAMA DEVE PRODUZIR UMA ÚNICA LINHA PARA CADA CASO DE TESTE, CONTENDO OS
IDENTIFICADORES DOS VOLUNTÁRIOS QUE NÃO RETORNARAM DO MERGULHO, NA ORDEM 
CRESCENTE DE SUAS IDENTIFICAÇÕES. DEIXE UM ESPAÇO EM BRANCO APÓS CADA IDENTIFICADOR
(NOTE QUE ISTO SIGNIFICA QUE DEVE HAVER UM ESPAÇO EM BRANCO TAMBÉM APÓS O ÚLTIMO
IDENTIFICADOR). SE TODOS OS VOLUNTÁRIOS RETORNARAM DO MERGULHO, IMPRIMA APENAS O
CARACTERE '*'(ASTERISCO).
*/

//biblioteca
#include <iostream> //entrada e saida
#include <bits/stdc++.h> //todas as bibliotecas

using namespace std;

int main() //função principal
{
    //declaração de variáveis
    int N, R; //total //retornaram
    int retornou[10005]; //vetor que marca quem retonrou (0 = não voltou, 1 = voltou)
    int identificador; //lê temporiamente cada ID retornada

    //entrada de dados
    while (cin >> N >> R) //lê até ter um EOF - fim de arquivos, só termina quanto ler um false
    {
        //desenvolvimento
        for (int i = 1; i <= N; i++) //limpando a lista de chamada para novo caso de teste
        {
            retornou[i] = 0; //0 significa que ainda não sabemos
        }
        for (int i = 1; i <= R; i++) //lê quem retornou
        {
            cin >> identificador;
            retornou[identificador] = 1; //1 significa que voltou com vida
        }

        //saida de dados
        if (N == R)
        {
            cout << "*" << endl; //todos voltaram
        }
        else
        {
            for (int i = 1; i <= N; i++)
            {
                if (retornou[i] == 0) //se não foi marcado como retornado...
                {
                    cout << i << " "; //...é porque voltou
                }
            }
            cout << endl;
        }

    }

    return 0;
}