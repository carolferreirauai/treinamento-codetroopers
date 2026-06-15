/*
1558 - SOMA DE DOIS QUADRADOS

QUAIS NÚMEROS INTEIROS PODEM SER REPRESENTANDOS POR UMA SOMA DE DOIS INTEIRO 
AO QUADRADO?

É ESSA PERGUNTA QUE SEU PROGRAMA DEVE RESPONDER!
POR EXEMPLO, O NÚMERO 41 PODE SER REPRESENTADO COMO (-4)^2 + 5^2 = 41, JÁ O NÚMERO 7
NÃO PODE SER REPRESENTANDO DA MESMA MANEIRA.

ENTRADA: A ENTRADA É COMPOSTA POR VÁRIAS LINHAS, CADA LINHA CONTÉM UM INTEIRO COM MÓDULO
MENOR OU IGUAL A 10000.

SAÍDA: PARA CADA LINHA, IMPRIMA "YES" SE O NÚMERO PODE SER REPRESENTADO POR UMA SOMA DE 
DOIS INTEIRO AO QUADRADO, CASO CONTRÁRIO IMPRIMA "NO".
*/

//biblioteca
#include <iostream>

using namespace std;

//função checagem
bool possivel (int numero)
{
    if (numero < 0)
    {
        return false;
    }
}

//função principal
int main()
{
    //declaração de váriaveis
    int numero;

    //entrada de dados até EOF
    while (cin >> numero)
    {
        
        //desenvolvimento
        //se o número for negativo
        if (numero < 0)
        {
            //imprima NO
            cout << "NO" << endl;
        }
        
        //se for positivo, fazemos o teste
        else
        {
            bool achou = false;

            //para o número
            for (int i = 0; i <= 100; i++)
            {
                for (int j = 0; j <= 100; j++)
                {
                    //teste matemático: i^2 + j^2
                    if ((i * i) + (j * j) == numero)
                    {
                        //marcamos que achamos a combinação
                        achou = true;
                    }                        
                }
            }

            //saida de dados
            if (achou == true)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}