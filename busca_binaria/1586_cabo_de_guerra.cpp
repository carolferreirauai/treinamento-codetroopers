/*
1586 - CABO DE GUERRA

NA FINAL NACIONAL DA MARATONA DE PROGRAMAÇÃO DE 2013, EM UBERLÂNDIA, DURANTE UM
PERÍODO DE LAZER, O PROF. CARLINHOS (USP) PROPÔS UMA ATIVIDADE A TODOS OS ESTUDANTES.
ELE PRIMEIRO ORGANIZOU OS ESTUDANTES EM ORDEM LEXICOGRÁFICA CRESCENTE,
CONSIDERANDO APENAS O PRIMEIRO NOME E DESCONSIDERANDO DIACRÍTICOS. EM SEGUIDA,
SORTEOU UM ESTUDANTE E MONTOU DUAS EQUIPES, A E B: A EQUIPE A SERIA FORMADA POR
TODOS OS ESTUDANTES NA ORDEM ATÉ O ESTUDANTE SORTEADO, INCLUSIVE; A EQUIPE B SERIA
FORMADA POR TODOS OS ESTUDANTES NA ORDEM A PARTIR DO ESTUDANTE SORTEADO, EXCLUSIVE.
AS DUAS EQUIPES, ENTÃO, COMPETIRIAM NUM CABO DE GUERRA TRADICIONAL, E OS VENCEDORES
GANHARIAM UM CAFÉ.

MUITAS COISAS CURIOSAS O PROF. CARLINHOS PERCEBEU NAQUELE DIA:

A FORÇA DE CADA ESTUDANTE, QUANDO POSICIONADO IMEDIATAMENTE EM FRENTE AO
ADVERSÁRIO (POSIÇÃO 1), ERA EXATAMENTE IGUAL À SOMA DOS VALORES CORRESPONDENTES AOS
CARACTERES DE SEU PRIMEIRO NOME NA TABELA ASCII. DESSARTE, A FORÇA DO ESTUDANTE
LEANDRO, SE FICASSE NA POSIÇÃO 1 DE UMA EQUIPE (FOSSE A OU FOSSE B), SERIAL IGUAL A:
709 = 76 + 101 + 97 + 110 + 100 + 114 + 111 = 'L' + 'E' + 'A' + 'N' + 'D' + 'R' + 'O'

QUANTO MAIS DISTANTE DA EQUIPE ADVERSÁRIA, MENOS INTIMIDADO — E, PORTANTO, MAIS
FORTE — FICAVA UM ESTUDANTE. MAIS ESPECIFICAMENTE, UM ESTUDANTE NA POSIÇÃO 2 DE
UMA EQUIPE TINHA O DOBRO DA FORÇA QUE TERIA SE FICASSE NA POSIÇÃO 1. NA POSIÇÃO 3, O
TRIPLO, E ASSIM POR DIANTE. AS POSIÇÕES DE AMBAS AS EQUIPES SÃO NUMERADAS A PARTIR DA
POSIÇÃO MAIS PRÓXIMA DA EQUIPE ADVERSÁRIA, COMEÇANDO A CONTAGEM EM 1. POR
EXEMPLO, SE O ESTUDANTE LEANDRO FICASSE NA POSIÇÃO 3 DE UMA EQUIPE, TERIA FORÇA IGUAL
A 3 × 709 = 2127.

A FORÇA DE UMA EQUIPE ERA IGUAL À SOMA DAS FORÇAS DE CADA UM DE SEUS INTEGRANTES.
NÃO OBSTANTE, SE A FORÇA DA EQUIPE A FOSSE MAIOR QUE A DA EQUIPE B, A EQUIPE A
CERTAMENTE GANHARIA. POR OUTRO LADO, SE A FORÇA DA EQUIPE A FOSSE MENOR QUE A DA
EQUIPE B, A EQUIPE B CERTAMENTE GANHARIA. FINALMENTE, SE AS FORÇAS DE AMBAS AS
EQUIPES FOSSEM IGUAIS, HAVERIA UM EMPATE.

EXISTE ALGUM ESTUDANTE QUE O PROF. CARLINHOS PODERIA SORTEAR QUE FIZESSE AS EQUIPES A
E B EMPATAREM?

ENTRADA: A ENTRADA CONSISTE DE VÁRIOS CASOS DE TESTE. A PRIMEIRA LINHA DE CADA CASO DE TESTE É
COMPOSTA POR UM ÚNICO INTEIRO N (1 ≤ N ≤ 10^5), O QUAL REPRESENTA O NÚMERO DE
ESTUDANTES. SEGUEM, ENTÃO, N LINHAS, CADA UMA CONTENDO O PRIMEIRO NOME DE UM
ESTUDANTE. OS NOMES DOS ESTUDANTES SÃO FORNECIDOS SEGUNDO A ORDEM LEXICOGRÁFICA
CRESCENTE, E NO MÍNIMO 1 E NO MÁXIMO 10 LETRAS DO ALFABETO LATINO COMPÕEM O NOME
DE UM ESTUDANTE. NÃO HÁ NUM MESMO CASO DE TESTE DOIS ESTUDANTES COM O MESMO
PRIMEIRO NOME, E A PRIMEIRA LETRA DE UM NOME É SEMPRE MAIÚSCULA, SENDO AS DEMAIS
MINÚSCULAS. N = 0 FINALIZA A ENTRADA.

SAÍDA: IMPRIMA O NOME DO ESTUDANTE QUE, SE SORTEADO, FARIA AS EQUIPES A E B EMPATAREM. SE
NÃO HÁ TAL ESTUDANTE, IMPRIMA A LINHA: "IMPOSSIBILIDADE DE EMPATE." (SEM AS ASPAS).
*/
//biblioteca
#include <iostream>
#include <string> //necessário para usar o tipo string

using namespace std;

//declaração globais
string nomes[100005];
long long base[100005];

//função principal
int main()
{
    //declaração de váriaveis
    int N; //número de estudantes

    //entrada de dados
    while (cin >> N && N != 0) //condição de parada, se N for == 0
    {
        //ler os N nomes e calcular a força base de cada estudantes
        for (int i = 0; i < N; i++)
        {
            cin >> nomes[i];

            //desenvolvimento
            long long aluno = 0;

            //percorre as letrasa strings do aluno atual
            for (int j = 0; j < (int)nomes[i].size(); j++)
            {
                aluno += (int)nomes[i][j]; //soma os valores ASCII
            }

            base[i] = aluno; //força base do estudante i
        }   

        //desenvolvimento
        //busca binária
        int baixo = 0, alto = N - 1, empate = -1;

        while(baixo <= alto)
        {
            int meio = (baixo + alto) / 2;

            //zera a cada iteração
            long long A = 0, B = 0;

            //calcular a equipe a
            for (int i = 0; i <= meio; i++)
            {
                //posição do aluno é meio - i + 1;
                A += base[i] * (meio - i + 1);
            }

            //calcuar a equipe b
            for (int i = meio + 1; i < N; i++)
            {
                B += base[i] * (i - meio);
            }

            if (A == B)
            {
                empate = meio; //achou o aluno perfeito
                break; //encerra o while
            }
            else if (A > B)
            {
                alto = meio - 1; //
            }
            else
            {
                baixo = meio + 1;
            }
        }
        //saida de dados
        if (empate != -1)
        {
            cout << nomes[empate] << endl;
        }
        else
        {
            cout << "Impossibilidade de empate." << endl;
        }
    }   
    return 0;
}