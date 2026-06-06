/*
1607 - AVANCE AS LETRAS

É DADO NA ENTRADA UMA STRING A E OUTRA B. EM UMA OPERAÇÃO VOCÊ PODE ESCOLHER UMA LETRA DA PRIMEIRA
STRING E AVANÇAR ESTA LETRA. AVANÇAR UMA LETRA SIGNIFICA TRANSFORMÁ-LA NA PRÓXIMA LETRA DO ALFABETO, VEJA QUE
A PRÓXIMA LETRA DEPOIS DE Z VEM A LETRA A NOVAMENTE!

POR EXEMPLO, PODEMOS TRANSFORMAR A STRING AB EM BD EM NO MÍNIMO 3 OPERAÇÕES: AB -> BB -> BC -> BD.
PODEMOS APLICAR OPERAÇÕES NAS LETRAS EM QUALQUER ORDEM, OUTRA POSSIBILIDADE SERIA: AB -> AC -> BC -> BD.

DADAS AS DUAS STRINGS, CALCULE O MÍNIMO NÚMERO DE OPERAÇÕES NECESSÁRIAS PARA TRANSFORMAR A PRIMEIRA NA
SEGUNDA.

ENTRADA: NA PRIMEIRA LINHA TERÁ UM INTEIRO T (T <= 100) INDICANDO O NÚMEROS DE TESTE.

PARA CADA CASO, NA ÚNICA LINHA TEREMOS AS DUAS STRING A (1 <= |A| <= 100* OU 1 <= |A| <= 10^4** - SENDO QUE |A|
SIGNIFICA O TAMANHO DA STRING A) E B(|B| = |A|* OU |B| = |A|**) SEPARADAS POR UM ESPAÇO. AMBAS AS STRINGS
SÃO COMPOSTAS POR LETRAS DO ALFABETO MINÚSCULAS APENAS E SÃO DO MESMO TAMANHO.

/*OCORRE EM APROXIMADAMENTE 90% DOS CASOS DE TESTE;

**OCORRE NOS DEMAIS CASOS DE TESTE.

SAÍDA: PARA CADA CASO IMPRIMA O NÚMERO MÍNIMO DE OPERAÇÕES
*/

//biblioteca
#include <bits/stdc++.h>

using namespace std;

//função principal
int main()
{
    //declaração de dados
    int T; //casos de teste

    //entrada de dados
    cin >> T; //lê quantidade de casos

    //desenvolvimento
    //percorrer o casos de testes
    for (int i = 0; i < T; i++)
    {
        //declaração de variáveis
        string A, B;
        int soma = 0;

        //entrada de dados
        cin >> A >> B;

        //percorre cada caractere, tratanto a string como vetor
        for (int j = 0; j < A.size(); j++)
        {
            //a é menor que b
            if(A[j] <= B[j])
            {
                soma += (B[j] - A[j]);
            }
            else
            {
                soma += (B[j] - A[j]) + 26;
            }
        }
        
        //saída de dados
        cout << soma << endl;
    }
    
    return 0;
}