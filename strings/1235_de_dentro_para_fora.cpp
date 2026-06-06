/*
1235 - DE DENTRO PARA FORA

A SUA IMPRESSORA FOI INFECTADA POR UM VÍRUS E ESTÁ IMPRIMINDO DE FORMA INCORRETA. DEPOIS DE OLHAR PARA
VÁRIAS PÁGINAS IMPRESSAS POR UM TEMPO, VOCÊ PERCEBE QUE ELE ESTÁ IMPRIMINDO CADA LINHA DE DENTRO PARA
FORA. EM OUTRAS PALAVRAS, A METADE ESQUERDA DE CADA LINHA ESTÁ SENDO IMPRESSA A PARTIR DO MEIO DA PÁGINA
ATÉ A MARGEM ESQUERDA. DO MESMO MODO, A METADE DIREITA DE CADA LINHA ESTÁ SENDO IMPRESSA Á PARTIR DA
MARGEM DIREITA E PROSSEGUINDO EM DIREÇÃO AO CENTRO DA PÁGINA.

POR EXEMPLO A LINHA:
THIS LINE IS GIBBERISH

ESTÁ SENDO IMPRESSA COMO:
I ENIL SIHTHSIREBBIG S

DA MESMA FORMA, A LINHA "MANGOS" ESTÁ SENDO IMPRESSA INCORRETAMENTE COMO "NAM SOG". SUA TAREFA É
DESEMBARALHAR (DECIFRAR) A STRING A PARTIR DA FORMA COMO ELA FOI IMPRESSA PARA A SUA FORMA ORIGINAL. VOCÊ
PODE ASSUMIR QUE CADA LINHA CONTERÁ UM NÚMERO PAR DE CARACTERES.

ENTRADA: A ENTRADA CONTÉM VÁRIOS CASOS DE TESTE. A PRIMEIRA LINHA DE ENTRADA CONTÉM UM INTEIRO N QUE INDICA A 
QUANTIDADE DE CASOS DE TESTE. SEGUEM N LINHAS, CADA UMA COM UMA FRASE COM NO MÍNIMO 2 E NO MÁXIMO
100 CARACTERES DE LETRAS MAIÚSCULAS E ESPAÇOS QUE DEVERÁ SER DESEMBARALHADA (DECIFRADA) Á PARTIR DA FORMA
IMPRESSA PARA A SUA FORMA ORIGINAL, CONFORME ESPECIFICAÇÃO ACIMA.

SAÍDA: PARA CASA LINHA DE ENTRADA DEVERÁ SER IMPRESSA UMA LINHA DE SAÍDA COM A FRASE DECIFRADA, CONFORMA A
ESPECIFICAÇÃO ACIMA.
*/

//biblioteca
#include <bits/stdc++.h>

using namespace std;

//função principal
int main()
{
    //declaração de variáveis
    int N; //casos de teste

    //entrada de dados
    cin >> N; //lê a quantidade de caso de teste
    cin.ignore(); //próxima leitura será getline

    //desenvolvimento
    for (int i = 0; i < N; i++)
    {
        //declaração de váriavel
        string frase;

        //entrada de dados
        getline(cin, frase); //recebe a linha toda

        //decobrir o tamanho da frase
        int tamanho = frase.size();

        //descobrir a metade da frase
        int metade = (tamanho / 2);

        //strings vazias para armazenar
        string metade1 = "";
        string metade2 = "";

        //primeiro for: de 0 até metade
        for (int j = 0; j < metade; j++)
        {
            //add o único caractere
            metade1.push_back(frase[j]);
        }

        //segundo for: metade para final
        for (int j = metade; j < tamanho; j++)
        {
            //add o único caractere
            metade2.push_back(frase[j]);
        }

        //reverse - inverter
        //consertar o erro
        reverse(metade1.begin(), metade1.end());
        reverse(metade2.begin(), metade2.end());

        //juntamos as metades
        string frase_decifrada = (metade1 + metade2);

        //saida de dados - imprimir a frase correta
        cout << frase_decifrada << endl;
    }
    return 0;
}