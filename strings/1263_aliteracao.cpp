/*
1263 - ALITERAÇÃO

UMA ALITERAÇÃO OCORRE QUANDO DUAS OU MAIS PALAVRAS CONSECUTIVAS DE UM TEXTO POSSUEM A MESMA LETRA
INICIAL (IGNORADO MAIÚSCULAS E MINÚSCULAS). SUA TAREFAS É DESENVOLVER UM PROGRAMA QUE IDENTIFIQUE, A PARTIR
DE UMA SEQUÊNCIA DE PALAVRAS, O NÚMERO DE ALITERAÇÕES QUE ESSA SEQUEÊNCIA POSSUI.

ENTRADA: A ENTRADA CONTÉM DIVERSOS CASOS DE TESTE. CADA CASO É EXPRESSO COMO UM TEXTO EM UMA ÚNICA LINHA,
CONTENDO DE 1 A 100 PALAVRAS SEPARADAS POR UM ÚNICO ESPAÇO, CADA PALAVRAS TENDO DE 1 A 50 LETRAS
MINÚSCULAS OU MAIÚSCULAS ('A'-'Z','A'-'Z'). A ENTRADA TERMINA EM EOF.

SAÍDA: PARA CADA CASO DE TESTE IMPRIMA O NÚMERO DE ALITERAÇÕES EXISTENTES NO TEXTO INFORMADO, CONFORME
EXEMPLOS ABAIXOS.
*/

//biblioteca
#include <bits/stdc++.h>

using namespace std;

//função principal
int main()
{
    //declaração de váriáveis
    string texto;

    //entrada de dados e desenvolvimento
    //getline - ler a linha oda, while por conta do EOF
    while (getline(cin, texto))
    {
        //declaração de variáveis
        int total = 0;
        bool contando = false;
        char letra_anterior = ' ';  

        //verificar se o texto é maior que 0
        if (texto.size() > 0)
        {
            char letra_atual = texto[0];

            if(letra_atual < 'a')
            {
                letra_atual += 32;
            } 

            letra_anterior = letra_atual;
        }
        //percorrer o resto da frases
        for (int i = 0; i < texto.size(); i++)
        {
            //se encontrar o espaço em branco, pula pro próximo
            if (texto[i] == ' ' && i + 1 < texto.size())
            {
                char letra_atual = texto[i+1];

                //novamente, convertemos maiúscula em minúsculas
                if (letra_atual < 'a')
                {
                    letra_atual += 32;
                }

                //verificar letra_atual == letra_anterior
                if (letra_atual == letra_anterior)
                {
                    //se for false, é uma aliteração nova
                    if (contando == false)
                    {
                        total++;
                        contando = true; //sem repetir novamente
                    }
                }
                //se for diferentes a aliteração quebra
                else
                {
                    letra_anterior = letra_atual;
                    contando = false; //resetar para o próximo
                }
            }
        }
        //saida de dados - imprimir a quantidade encontrada naquela linha
        cout << total << endl;
    }
    return 0;
}