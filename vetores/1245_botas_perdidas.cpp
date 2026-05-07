/*
1245 - BOTAS PERDIDAS

A DIVISÃO DE SUPRIMENTOS DE BOTAS E CALÇADOS DO EXERCITOS COMPROU UM GRANDE 
NÚMEROS DE PARES DE BOTAS DE VÁRIOS TAMANHOS PARA SEUS SOLDADOS. NO ENTANTO, POR 
UMA FALHA DE EMPACOTAMENTO DA FÁBRICA CONTRATADA, NEM TODAS AS CAIXAS ENTREGUES 
CONTINHAM UM PAR DE BOTAS CORRETO, COM DUAS BOTAS DO MESMO TAMANHO, UMA PARA 
CADA PÉ. O SARGENTO MANDOU QUE OS RECRUTAS RETIRASSEM TODAS AS BOTAS DE TODAS AS
CAIXAS PARA REEMBALÁ-LAS, DESTA VEZ CORRETAMENTE.

QUANDO O SARGENTO DESCOBRIU QUE VOCÊ SABIA PROGRAMAR, ELE SOLICITOU COM A GENTILEZA
HABITUAL QUE VOCÊ ESCREVESSE UM PROGRAMA QUE, DADA A LISTA CONTENDO A DESCRIÇÃO DE
CADA BOTA ENTREGUE, DETERMINA QUANTOS PARES CORRETOS DE BOTAS PODERÃO SER
FORMADOS NO TOTAL.

ENTRADA: A ENTRADA É COMPOSTA POR DIVERSOS CASOS DE TESTE E TERMINA COM FINAL DE ARQUIVO
(EOF). A PRIMEIRA LINHA DE UM CASOS DE TESTE CONTÉM UM INTEIRO N (2 <= N <= 10^4), N É
PAR, INDICANDO O NÚMEROS DE BOTAS INDIVISUAIS ENTREGUES. CADA UMA DAS N LINHAS
SEGUINTES DESCREVE UMA BOTA, CONTENDO UM NÚMEROS INTEIRO M (30 <= M <= 60) E UMA
LETRA L, SEPARADOS POR UM ESPAÇO EM BRANCO. M INDICA O NÚMEROS DA BOTA E L INDICA O
PÉ DA BOTA: L = 'D' INDICA QUE BOTA É PARA O PÉ DIREITO, L = 'E' INDICA QUE A BOTA É PARA
PÉ ESQUERDO.

SAIDA: PARA CADA CASO DE TESTE IMPRIMA UMA LINHA CONTENDO UM ÚNICO NÚMERO INTEIRO
INDICANDO O NÚMERO TOTAL DE PARES CORRETOS QUE PODEM SER FORMADOS.
*/

//biblioteca
#include <iostream> //entrada e saida
#include <bits/stdc++.h> //total de biblioteca

using namespace std; //espaços

int main() //função principal
{
    //declaração de variaveis
    int numeros_individuais; //par, número de botas individuais entregues.
    int tamanho; //número (tamanho) da bota
    char lados; //L seria os lados ('D' ou 'E')

    //entrada de dados
    while (cin >> numeros_individuais) //EOF
    {
        //declarar e zera os vetires a cada novo caso de teste//
        int esquerda[61] = {0};
        int direta[61] = {0};

        //desenvolvimento
        for (int i = 0; i < numeros_individuais; i++) //lendo todos os números de botas
        {
            cin >> tamanho >> lados; //inserir o tamanho e o lado
            

            if (lados == 'E')
            {
                esquerda[tamanho]++; //coloca na "prateleira" esquerda
            }
            else if (lados == 'D')
            {
                direta[tamanho]++; //coloca na "prateleira" direita
            }
        }

        int pares_total = 0; //variável para somar os pares formados

        for (int i = 30; i <= 60; i++) //verificar os tamanhos possíveis (int i = 30, porque inicia em 30)
        {
            if (esquerda[i] < direta[i])
            {
                pares_total += esquerda[i];
            }
            else
            {
                pares_total += direta[i];
            }
        }

        //saida de dados
        cout << pares_total << endl;
    }
    
    return 0;
}