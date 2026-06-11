/*
1310 - LUCRO

GEORGE É DONO DE UM CIRCO E TRAZ SEU CIRCO DE CIDADE EM CIDADE. ELE SABE O QUANTO DE
RECEITA ELE PODE OBTER EM QUALQUER DIA DE UM SÉRIE DE DIAS EM UMA CIDADE. ELE
TAMBÉM SABE O CUSTO CONSTANTE DIÁRIO PARA MANTER O SEU CIRCO. GEORGE QUER TRAZER
SEU CIRCO Á CIDADE PARA A SÉRIE DE DIAS QUE RESULTA EM MAIOR LUCRO.

POR EXEMPLO, SE EM UMA DETERMINADA CIDADE O CUSTO FOR DE $20 POR DIA EM UM
EXEMPLO COM 6 DIAS, SENDO QUE AS RECEITAS PREVISTAS POR DIA SÃO ($18, $35, $6, $80,
$15, $21), GEORGE PODE OBTER O MÁXIMO DE LUCRO TRAZENDO O SEU CIRCO PARA ESTA
CIDADE DO DIA 2 AO DIA 4. DESTA FORMA ELE PODE LUCRAR (35 + 80 + 6) - (3 * 20) = $61.

NOTA: A SÉRIE DE DIAS QUE GEORGE TRAZ SEU CIRCO PARA A CIDADE PODE SER ENTRE 0 E O
NÚMERO MÁXIMO DE DIAS, INCLUSIVE. OBVIAMENTE, SE GEORGE TRAZ SEU CIRCO PARA A CIDADE
POR 0 DIAS, ELE OBTÉM $0 DE LUCRO.

ENTRADA: A ENTRADA CONTÉM MUITO CASOS DE TESTE. A PRIMEIRA LINHA DE CADA CASO DE TESTE
CONTÉM UM INTEIRO N (1 <= N <= 50) QUE REPRESENTA O NÚMERO DE DIAS QUE GEORGE PODE
TRAZER O SEU CIRCO NA CIDADE. A SEGUNDA LINHA DO CASO DE TESTE CONTÉM UM NÚMERO
INTEIRO CUSTOPORDIA (0 <= CUSTOPORDIA < 1000) QUE REPRESENTA O CUSTO EM MANTER O
CIRCO NA CIDADE. SEGUE A N LINHAS (UMA POR CADA DIA), CONTENDO CADA UM UM INTEIRO
RECEITA (0 <= RECEITA < 1000) REPRESENTA A RECEITA QUE O CIRCO OBTEM EM CADA DIA. O
FINAL DA ENTRADA É INDICADO POR EOF (FIM DE ARQUIVO).

SAÍDA: PARA CADA CASO DE TESTE IMPRIMA O MÁXIMO DE DINHEIRO QUE GEORGE PODE GANHAR
TRAZENDO O SEU CIRCO PARA A CIDADE DE ACORDO COM O EXEMPLO ABAIXO.
*/

//biblioteca
#include <iostream>

using namespace std;

//função principal
int main()
{
    //declaração de váriaveis
    int N; //dias
    int custopordia; //custos por dias
    int receita; //receitas - ganho do dias
    int soma; //soma das receitas

    //entrada de dados
    while (cin >> N)
    {
        int lucro = 0; //soma dos lucros - resetar a cada caso
        int recorde = 0; //maior do dia

        cin >> custopordia; //lendo o custos

        for (int i = 0; i < N; i++)
        {
            cin >> receita; //lendo as receitas

            //calcular o lucro do dia
            lucro += (receita - custopordia);
            
            //se ficar negativo george prefere não trabalhar, então zera
            if (lucro < 0)
            {
                lucro = 0;
            }
            //se lucro for maior que os recorde, recorde vira o lucro
            if (lucro > recorde)
            {
                recorde = lucro;
            }
        }
        //saida de dados
        cout << recorde << endl;
    }
    return 0;
}