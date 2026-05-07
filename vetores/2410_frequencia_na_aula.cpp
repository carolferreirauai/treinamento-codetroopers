/*
2410 - FREQUENCIA NA AULA

CERTA VEZ, NUMA AULA, A PROFESSORA PASSOU UM FILME PARA OS ALUNOS ASSISTIREM.
DURANTE ESTE FILME, ELA PASSOU UMA LISTA DE PRESENÇA EM SUA SALA PARA VERIFICAR A
PRESENÇA DOS ALUNOS, ONDE CADA ALUNO DEVERIA INSERIR APENAS SEU NÚMERO DE REGISTRO.
ALGUNS ALUNOS CONTUDO, COMO POSSUEM AMIGOS QUE FOGEM DA AULA, DECIDIRAM SER
CAMARADAS E INSERIRAM OS NÚMEROS DE REGISTRO DE SEUS AMIGOS FUJÕES. O PROBLEMA É
QUE MUITOS ALUOS SÃO AMIGOS DE ALUNOS QUE FOGEM DA AUAL E ALGUNS NÚMEROS DE
REGISTRO ACABARAM SENDO REPETIDAMENTE INSERIDOS NA LISTA DE PRESENÇA. ALÉM DE TUDO,
ALGUNS DOS ALUNOS QUE SE ESPERAVA QUE NÃO ESTIVESSEM NA AULA DE FATO ESTAVAM!

A PROFESSORA, AO NOTAR QUE A LISTA DE PRESENÇA CONTINHA ALGUNS NÚMEROS REPETIDOS,
FICOU SEM ENTENDER, MAS DECIDIU DAR UM VOTO DE CONFIANÇA E DAR PRESENÇA A TODOS OS
ALUNOS CUJOS NÚMEROS DE REGISTRO ESTAVAM NA LISTA. COMO SÃO MUITOS ALUNOS NA SALA E
MUITOS NÚMEROS COM REPETIÇÃO, ELA PEDIU A SUA AJUDA PARA DETERMINAR O TOTAL 
DE ALUNOS QUE RECEBERAM PRESENÇA NA AULA.

ENTRADA: A PRIMEIRA LINHA DA ENTRADA CONTÉM UM NÚMETO INTEIRO N (1 <= N <= 10^5), QU INFORMA A
QUANTIDADE DE NÚMETOS DE REGISTRO QUE APARECERAM NA LISTA DE PRESENÇA. CADA UMA
DAS N LINHAS SEGUINTES CONTÉM UM NÚMERO DE REGISTRO V_I (0 <= V_I <= 10^6) QUE FOI INSERIDO
NA LISTA DE PRESENÇA.

SAÍDA: SEU PROGRAMA DEVE IMPRIMIR UMA ÚNICA LINHA, CONTENDO APENAS UM NÚMERO INTEIRO, O
NÚMETOS DE ALUNOS QUE RECEBERAM PRESENÇA.
*/

//biblioteca
#include <iostream> //entrada e saidas
#include <bits/stdc++.h> //todas bibliotecas

using namespace std; //espaços

//declaração de variaveis
int presente[1000005] = {0}; //vetor que armazena presenças

int main() //função principal
{
    //declaração de variaveis
    int N; //quantidade de números de registro que apareceram na lista de presença
    int V_i; //número de registro que foi inserido na lista de presença
    int frequencia = 0; //contador de alunos únicos com presença
    
    //entrada de dados
    cin >> N;

    //desenvolvimento
    for (int i = 0; i < N; i++)
    {
        cin >> V_i;
        if (presente[V_i] == 0) //esse registro ainda não foi visto?
        {
            presente[V_i] = 1; //marcar como visto
            frequencia++; //conta mis um aluno único
        }
    }

    //saida de dados
    cout << frequencia << endl;

    return 0;
}