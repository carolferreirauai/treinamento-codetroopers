/*
2452 - SEMENTES

UM EXPERIMENTO BIOLÓGICO UTILIZA UMA FITA DE PAPEL BRANCO ESPECIAL, NA QUAL ALGUMAS
GOTAS DE UM REAGENTES SÃO COLOCADAS EM POSIÇÕES ESPECÍFICAS. INICIALMENTE A GOTA DE
REAGENTE FAZ COM QUE O PAPEL SE TORNE PRETO NA POSIÇÃO EM QUE FOI COLCOADA. A CADA
DIA O REAGENTE SE PROPAGA PELO PAPEL, EM TODAS AS DIREÇÕES, COM VELOCIDADE DE 1
POSIÇÕES POR DIA, COLORINDO A REGIÃO EM QUE O REAGENTE SE PROPAGOU. A FIGURA ABAIXO
MOSTRA UM EXPERIMENTO COM UMA FITA DE 13 POSIÇÕES, COM 3 GOTAS DE REAGENTE 
INICIALMENTE, COLOCADA NAS POSIÇÕES 2, 6, 13 (A POSIÇÃO 1 É A PRIMEIRA MAIS Á 
ESQUERDA DA FITA). AO FINAL DO TERCEIRO DIA, A FITA ESTÁ COMPLETAMENTE TOMADA PELO
REAGENTE.

VOCÊ FOI CONTRATADO PARA ESCREVER UM PROGRAMA QUE, DADOS O COMPRIMENTO DA FITA DE
PAPEL E AS POSIÇÕES DAS GOTAS DE REAGENTE NO ÍNICIO DO EXPERIMENTO, DETERMINE
QUANTOS DIAS SERÃO NECESSÁRIOS PARA A FITA DE PAPEL FICAR COMPLETAMENTE TOMADA PELO
REAGENTE.

ENTRADA: A PRIMEIRA LINHA CONTÉM 2 INTEIROS F (1 <= F <= 100000) E R (1 <= R <= 1000), INDICANDO
RESPECTIVAMENTE O COMPRIMENTO DA FITA DE PAPEL, EM NÚMEROS DE POSIÇÕES, E O
NÚMERO DE GOTAS NO ÍNICIO DO EXPERIMENTO. A SEGUNDA LINHA CONTÉM R INTEIROS,
INDICANDO AS POSIÇÕES DAS GOTAS DE REAGENTES, QUE SÃO DADAS EM ORDEM CRESCENTE.

SAÍDA: SEU PROGRAMA DEVE PRODUZIR UMA ÚNICA LINHA, CONTENDO UM ÚNICO INTEIRO, O NÚMERO DE
DIAS NECESSÁRIOS PARA QUE A FITA DE PAPEL FIQUE TOTALMENTE TOMADA PELO REAGENTE.
*/

//biblioteca
#include <iostream>

using namespace std;

//função principal
int main()
{
    //declaração de váriaveis
    int F; //tamanho da fita
    int R; //quantidade de gotas
    int gotas[10005];
    int distancia_meio;
    int distancia_direita;

    //entrada de dados
    cin >> F >> R;

    for (int i = 0; i < R; i++)
    {
        cin >> gotas[i]; //preencher posição
    }

    //desenvolvimento
    //tempo, 1° gota leva para pintar a fita até a ponta esquerda
    int dias = gotas[0] - 1;

    //tempo que as gotas levam para se encontrar no meio do caminho
    for (int i = 1; i < R; i++)
    {
        distancia_meio = ((gotas[i] - gotas[i - 1]) / 2);

        //verifique se esse tempo do meio é maior que o atual
        if (distancia_meio > dias)
        {
            dias = distancia_meio;
        }
    }

    //tempo, última gota leva para pintar a finta até a ponta direta
    distancia_direita = (F - gotas[R - 1]);
    
    if (distancia_direita > dias)
    {
        dias = distancia_direita;
    }

    //saída de dados
    cout << dias << endl;

    return 0;
}