/*
1285 - DÍGITOS DIFERENTES

OS HABITANTES DE NLOGÔNIA SÃO MUITOS SUPERSTICIOSOS. UMA DE SUAS CRENÇAS É QUE OS
NÚMEROS DAS CASAS DE RUA QUE TÊM UM DÍGITO REPETIDO TRAZ SORTE RUIM PARA OS
MORADORES. PORTANTO, ELES NUNCA IRIAM VIVER EM UMA CASA QUE TEM O NÚMERO 838 OU
1004, POR EXEMPLO.

A RAINHA DE NLOGÔNIA ORDENOU A CONSTRUÇÃO DE UMA NOVA AVENIDA À BEIRA-MAR E QUER
ATRIBUIR PARA AS NOVAS CASAS APENAS NÚMEROS SEM DÍGITOS REPETIDOS, PARA EVITAR
DESCONFORTO ENTRE OS SEUS SÚDITOS. VOCÊ FOI NOMEADO POR SUA MAJESTADE PARA
POSSÍVEL DE CASAS QUE PODEM ASSUMIR UM NÚMERO ENTRE N E M INCLUSIVE, SEM QUE
OCORRAM DÍGITOS REPETIDOS NESTES NÚMEROS.

ENTRADA: CADA TESTE É DESCRITO USANDO UMA LINHA. A LINHA CONTÉM DOIS INTEIROS N E M, CONFORME
DESCRITO ACIMA (1 <= N <= M <= 5000).

SAÍDA: PARA CADA CASO DE TESTE IMPRIMA UM VALOR INTEIRO QUE REPRESENTA A QUANTIDADE 
MÁXIMA POSSÍVEL DE NÚMEROS DE CASA ENTRE N E M INCLUSIVE, SEM DÍGITOS REPETIDOS.
*/

//biblioteca
#include <iostream>

using namespace std;

//função se possui um número repetidos
bool repetido(int numero)
{
    //0-9, vetor booleano[10], inicia em false, pois ainda não vimos nenhum dígitos
    bool visto[10] = {false};

    while (numero > 0)
    {
        //irá dar o último dígito
        int digito = numero % 10;

        //verificar se o número repete
        if(visto[digito] == true)
        {
            return true;
        }

        //se for a primeira vez, marcamos true no vetor
        visto[digito] = true;

        //divide para tirar o último digito.
        numero /= 10;
    }

    //se terminar sem dar true significa que nenhum digito se repetiu! retorna false
    return false;
}


//função principal
int main()
{
    //declração váriaveis
    int N;
    int M;

    //entrada de dados
    while (cin >> N >> M)
    {
        //declaração de váriaveis
        int contador = 0; //zera a contagem cada novo casos teste
        
        //desenvolvimento
        //o for vai de N até M
        for (int i = N; i <= M; i++)
        {
            //chama a função, se for retorn o false, conta mais 1.
            if (repetido(i) == false)
            {
                contador++;
            }

        }

        //saída de dados
        cout << contador << endl;
    }
    return 0;
}