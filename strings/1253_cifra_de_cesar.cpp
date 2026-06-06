/*
1253 - CIFRA DE CÉSAR

JÚLIO CÉSAR USAVA UM SISTEMA DE CRIPTOGRAFIA, AGORA CONHECIDO COMO CIFRA DE CÉSAR,
QUE TROCAVA CADA LETRA PELO EQUILVALENTE EM DUAS POSIÇÕES ADIANTE NO ALFABETO (POR
EXEMPLO 'A' VIRA 'C', 'R' VIRA 'T', ETC.). AO FINAL DO ALFABETO NÓS VOLTAMOS PARA O COMEÇO,
ISTO É 'Y' VIRA 'A'. NÓS PODEMOS, É CLARO, TENTAR TROCAR AS LETRAS COM QUAISQUER NÚMERO
DE POSIÇÕES.

ENTRADA: A ENTRADA CONTÉM VÁRIOS CASA DE TESTE. A PRIMEIRA LINHA DE ENTRADA CONTÉM UM
INTEIRO N QUE INDICA A QUANTIDADE DE CASOS DE TESTE. CADA CASO DE TESTE É COMPOSTO
POR DUAS LINHAS. A PRIMEIRA LINHA CONTÉM UMA STRING COM ATÉ 50 CARCTERES MAIÚSCULOS
('A'-'Z') QUE É SETENÇA APÓS ELA TER SIDO CODIFICADA ATRAVÉS DESTA CIFRA DE CÉSAR
MODIFICADA. A SEGUNDA LINHA CONTÉM UM NÚMERO QUE VARIA DE 0 A 25 E QUE REPRESENTA
QUANTAS POSIÇÕES CADA LETRA FOI DESLOCADA PARA DIREITA.

SAÍDA: PARA CADA CASO DE TESTE DE ENTRADA, IMPRIMA UMA LINHA DE SAÍDA COM O TEXTO
DECODIFICADO (TRANSFORMADO NOVAMENTE PARA O TEXTO ORIGINAL) CONFORME AS REGRAS
ACIMA E O EXEMPLO
*/

//biblioteca
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //declaração de variáveis
    int N;

    //entrada de dados
    cin >> N; //lê a quantidade de casos de teste 

    //desenvovimento
    //roda o cód Nx
    for (int i = 0; i < N; i++)
    {
        //declaração da variáveis
        string texto; //caractere maiúsculos
        int deslocamento; //quantas posição cada letra doi deslocada para direta

        //entrada de dados
        cin >> texto >> deslocamento;

        //percorre cada caractere da string, como se fosse um vetor
        for (int j = 0; j < texto.size(); j++) //que retorna o tamanho exato da string lida
        {
            //subtrai o deslocamento para voltar a letra original na tabela
            texto[j] -= deslocamento;

            //se a letra passar do 'A', voltamos para o 'Z'
            if (texto[j] < 'A')
            {
                texto[j] += 26;
            }
        }

        //saida de dados
        //imprime a palavra decodificada
        cout << texto << endl;
    }
    return 0;
}