#include <iostream>
#include <iomanip> //biblioteca de operação

using namespace std;

int main()
{
    //DECLARAÇÃO DE VARIÁVEIS
    int C; //colunas
    char OP; //(S ou M) - soma ou média
    double M[12][12]; //matrizes 12x12
    double soma = 0.0; //soma

    //ENTRADA DE DADOS
    cin >> C; //coluna
    cin >> OP; //tipo de operação

    //i - linhas e j - colunas
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
        cin >> M[i][j]; //armazenar os dados
        }
    }

    //SOMA E MÉDIA
    //percorrer apenas coluna 5
    for(int i = 0; i < 12; i++)
    {
        soma += M[i][C];
    }

    //SAIDA DE DADOS
    cout << fixed << setprecision(1);

    // verifica se é soma ou média
    if (OP == 'M')
        cout << soma / 12.0 << endl;
        else
        cout << soma << endl;
    return 0;
}
