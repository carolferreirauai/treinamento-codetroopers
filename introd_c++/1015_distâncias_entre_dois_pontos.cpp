/*
1015 - DISNTÂNCIA ENTRE DOIS PONTOS

LEIA OS 4 VALORES CORREPONDENTES AOS EIXOS X E Y DE DOIS PONTOS QUAISQUER NO PLANO, P1(X1,Y1) E 
P2(X2,Y2) E CALCULE A DISTÂNCIA ENTRE ELES, MOSTRANDO 4 CASAS DECIMAIS, SEGUNDO FÓRMULA:

DISTÂNCIA = RAIZ(X2-X1)^2 + (Y2-Y1)^2

ENTRADA: O ARQUIVO DE ENTRADA CONTÉM DUAS LINHAS DE DADOS. A PRIMEIRA LINHA CONTÉM 2 VALORES DE PONTO FLUTUANTES: X1 Y1 
E A SEGUNDA LINHA CONTÉM 2 VALORES DE PONTO FLUTUANTE X2 Y2.

SAIDA: CALCULE E IMPRIMA O VALOR DA DISTÂNCIA SEGUNDO A FÓRMULA FORNECIDA, CONSIDERANDO 4 CASAS DECIMAIS.
*/

//biblioteca
#include <iostream>
#include <cmath> //matemático
#include <bits/stdc++.h> //todas bibliotecas

using namespace std;

int main() //função principal
{
    //declaração de variaveis
    float x1, y1; //ponto 1
    float x2, y2; //ponto 2
    float d; //distância

    //entrada de dados
    //ler os pontos
    cin >> x1 >> y1; //ponto 1
    cin >> x2 >> y2; //ponto 2

    //desenvolvimento
    //calculo da distancia
    d = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)); //raiz(), pow(base, expoente)

    //saida de dados
    cout << fixed << setprecision(4); //casa decimal até 4
    cout << d << endl;

    return 0;
}