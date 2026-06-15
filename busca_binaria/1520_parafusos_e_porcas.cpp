/*
1520 - PARAFUSOS E PORCAS

PEDRO ESTÁ TRABALHANDO EM UM NOVO EMPREGO EM
UMA LOJA DE PARAFUSOS E PORCAS. TODA SEMANA ELE IRÁ
RECEBER NOVAS ENCOMENDAS DE PARAFUSOS MISTOS EM
GRANDES CAIXAS E PRECISA SABER ONDE ELE DEVE
ARMAZENAR ESSE PRODUTOS.

MANGO, QUE É O SUPERVISOR DE PEDRO, PEDIU-LHE PARA 
ORGANIZAR TODOS OS PARAFUSOS E PORCAS EM UM RACK
ENORME, DE FORMA QUE SEJA FÁCIL DE RESPONDER ONDE
É POSSÍVEL ENCONTRAR CADA PREDETERMINADO LOTE DE
PARAFUSOS E QUANTO DE CADA UM DESTES LOTES A LOJA
TEM.

PEDRO RECEBE TODOS OS PARAFUSOS E PORCAS EM CAIXAS ETIQUETADAS COM O INTERVALO DE
TAMANHO DOS PRODUTOS. POR EXEMPLO, DUAS CAIXAS COM OS RESPECTIVOS INTERVALO (1, 2)
E (4, 8) REPRESENTAM LOTES DE PRODUTOS COM TAMANHO {1, 2, 4, 5, 6, 7, 8}. UM NÚMERO DE
PARAFUSOS E PORCA PODE ESTAR PRESENTE EM MAIS DE UMA CAIXA COM OS RESPECTUVOS INTERVALOS
(1, 3), (2, 4) E (3, 5) REPRESENTAM LOTES DE PARAFUSOS E PORCAS COM TAMANHO {1, 2, 2, 3, 3
3, 4, 4, 5}

ENTRADA: A ENTRADA CONTÉM VÁRIOS CASOS DE TESTE E TERMINAR COM EOF. CADA CASOS DE TESTE É
COMPOSTO POR VÁRIAS LINHAS. A PRIMEIRA LINHA CONTÉM UM INTEIRO POSITIVO N (N < 100)
QUE INDICA A QUANTIDADE DE CAIXAS DE PARAFUSOS. SEGUEM N LINHAS, CADA UMA DELAS COM 
DOIS VALORES X E Y (1 ≤ X < Y ≤ 100) QUE REPRESENTAM OS TAMANHOS DOS LOTES DE 
PARAFUSOS E PORCAS PRESENTES NAQUELA CAIXA. A PRÓXIMA LINHA DE ENTRADA CONTERÁ UM 
ÚNICO INTEIRO POSITIVO NUM (1 ≤ NUM ≤ 100), QUE INDICA O NÚMERO QUE MANGO DESEJA 
PESQUISAR APÓS TODOS OS PRODUTOS SEREM ORGANIZADOS NA ESTANTE OU RACK.

OBS. A ESTANTE OU RACK POSSUI PRATELEIRAS ENUMERADAS DE 0 A P, SENDO QUE ESTE P NÃO 
DEVE SER SUPERIOR A 10000.

SAÍDA: CADA CASO DE ENTRADA DEVERÁ PRODUZIR UMA ÚNICA LINHA DE SAÍDA, INDICANDO AS POSIÇÕES 
DA PRATELEIRA NAS QUAIS O PARAFUSO DE TAMANHO NUM SE ENCONTRA OU INDICANDO QUE 
NÃO FOI POSSÍVEL ENCONTRAR O PARAFUSO, CONFORME O EXEMPLO ABAIXO.
*/

//biblioteca
#include <iostream>
#include <algorithm> //biblioteca necessária para funçãr sort()

using namespace std;

//declaração global
int rack[100005]; 

//função - encontrar o x mais á esquerda
int busca_esq(int n, int x)
{
    int pos = -1; //-1, não achou
    int baixo = 0; //primeira posição vetor
    int alto = n - 1; //última posição do vetor

    //while - busca binária
    while (baixo <= alto)
    {
        int meio = (baixo + alto) / 2; //corta pela metade
        
        if (x == rack[meio])
        {
            pos = meio; //salva a posição que achou
            alto = meio - 1; //forçar buscar mais a esquerda
        }
        else if (x > rack[meio])
        {
            baixo = meio + 1; //se x é maior, descarta a metade esquerda
        }
        else
        {
            alto = meio - 1; //se c é menor, descarta a metade direta
        }
    }

    return pos;
}

//função - x mais dirita
int busca_dir(int n, int x)
{
    int pos = -1;
    int baixo = 0;
    int alto = n - 1;

    while (baixo <= alto)
    {
        int meio = (baixo + alto) / 2;

        if (x == rack[meio])
        {
            pos = meio; //salva a posição
            baixo = meio + 1; //força a busca mais direita
        }
        else if(x > rack[meio])
        {
            baixo = meio + 1;
        }
        else
        {
            alto = meio - 1;
        }
    }

    return pos;
}


//função principal
int main()
{
    //declaração de váriaveis
    int N; //quantidade de caixas de parafusos
    int X, Y; //representa os tamanhaos dos lotes
    int NUM; //número que deseja pesquisar

    //entrada de dados - fim de arquivos
    while(cin >> N)
    {
        int total = 0; //contar os parafusos

        //desenvolvimento
        //lendo as caixa e desempacotando os lotes
        for (int i = 0; i < N; i++)
        {
            cin >> X >> Y;

            //coloca cada parafuso do intervalo [X, Y] no rack
            for (int j = X; j <= Y; j++)
            {
                rack[total] = j;
                total++;
            }
        }

        cin >> NUM; //parafusos achados

        //ordenar o rack para busca binária
        //o sort() pega o rack do início até o número total de itens e deixa em ordem crescente
        sort (rack, rack + total);

        //executar as buscas modificadas
        int pos_esq = busca_esq(total, NUM);
        int pos_dir = busca_dir(total, NUM);

        //saída de dados
        //se a busca da esquerda retornou algo != -1, o parafuso existe
        if (pos_esq != -1)
        {
            cout << NUM << " found from " << pos_esq << " to " << pos_dir << endl;
        }
        else
        {
            cout << NUM << " not found" << endl;
        }
    }
    return 0;
}