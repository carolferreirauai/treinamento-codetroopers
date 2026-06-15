/*
2817 - POSTO DO DARLAN

UMA DAS CONSEQUÊNCIAS DA GREVE DOS CAMINHONEIROS FOI A FALTA DE GASOLINA EM TODO
PAÍS. EM SANTA RITA DO SAPUCAÍ, CIDADE DO SUL DE MINAS GERAIS, NÃO FOI DIFERENTE.
CENTENAS DE CARROS E MOTOS FIZERAM FILA NO ÚLTIMO POSTO COM GASOLINA DISPONÍVEL PARA
CONSEGUIREM ENCHER SEUS TANQUES ANTES QUE ELA ESGOTASSE, PARECIA CENA DE FILME
SOBRE APOCALIPSE ZUMBI.

O POSTO POSSUI N BOMBAS E EM CADA DELAS EXISTE UMA FILA EM LINHA RETA COM M
VEICULOS (CARROS OU MOTOS). SEGUE UMA ILUSTRAÇÃO DE UM POSTO COM 4 BOMBA E 1
FILA DE 2 VEICULOS POR BOMBA.

DARLAN, DONO DO POSTO, LIMITOU A QUANTIDADE DE GASOLINA QUE CADA CARRO PODERIA
ABASTECER EM 25 LITROS E CADA MOTO EM 12 LITROS. COMO TODOS OS DONOS DOS VEÍCULOS 
DAS FILAS ESTAVAM COM MEDO DE NUNCA MAIS ABASTECER, ELES COM CERTEZA
IRIAM COLOCAR O MÁXIMO DE GASOLINA PERMITIDO POR DARLAN.

A EQUIPE DA EMISSORA DE TV LOCAL ESTAVA AO VIVO COM SEU DRONE FILMANDO AS LONGAS
FILAS DE VEÍCULO EM TORNO DO POSTO DO DARLAN, QUANDO UM TELESPECTADOR ENVIOU UMA
PERGUNTA UM TANTO QUANTO ALEATÓRIA: "SE LEVARMOS EM CONSIDERAÇÃO QUE AS FILEIRAS DE
CARROS CARACTERIZAM UMA MATRIZ DE N LINHAS POR M COLUNAS, QUAL A MAIOR QUANTIDADE
DE GASOLINA QUE OS VEÍCULOS EM QUADRADO DE TAMANHO L IRÃO COLOCAR? DADO QUE
NESSE QUADRADO DEVE EXISTIR AO MENOS UM VEÍCULO DE CADA TIPO (CARRO E MOTO)."

A EQUIPE DE TV NÃO FAZ IDEIA DE COMO RESPONDER ESSA PERGUNTA E NECESSITA DE SUA
AJUDA!

ENTRADA: A PRIMEIRA LINHA DE ENTRADA POSSUI DOIS INTEIROS N, M (1 <= N, M <= 1000), REPRESENTANDO
A QUANTIDADE DE BOMBAS E QUANTIDADE DE VEÍCULOS ENFILEIRADOS EM CADA BOMBA.
SEGUEM N LINHAS, CADA UMA CONTENDO M CARACTERES 'C' OU 'M' REPRESENTANDO UM CARRO 
OU UMA MOTO, RESPECTIVAMENTE. APÓS ISSO HAVERÁ UM INTEIRO L (1 <= L <= 1000), SENDO O
TAMANHO DO LADO DO QUADRADO QUE O TELESPECTADOR DESEJA SABER.

SAÍDA: EXIBA UM ÚNICO INTEIRO, A MAIOR QUANTIDADE POSSÍVEL DE GASOLINA QUE OS VEÍCULOS QUE
ESTÃO EM UM QUADRADO L IRÃO ABASTECER, DADO QUE DEVE EXISTIR AO MENOS UM VEÍCULO
DE CADA TIPO. CASO NÃO EXISTA UM QUADRADO QUE CARACTERIZE A DÚVIDA DO TELESPECTADOR,
IMPRIMA -1.
*/

//biblioteca
#include <iostream>
#include <algorithm> //biblioteca necessária para usar função max()

using namespace std;

//declaração global, evitar TLE
int litros[1005][1005];
int carros[1005][1005];

//função principal
int main()
{
    //declaração de váriaveis
    int N; //quantidade de bombas
    int M; //quantidade de veiculos
    int L; //tamanho do lado do quadrado
    char veiculo; //M - moto, C - carro

    //entrada de dados
    cin >> N >> M;

    //desenvolvimento
    //matriz
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> veiculo;

            int valor_litro = 0;
            int valor_carro = 0;

            //verificar se é carro ou moto
            if (veiculo == 'C')
            {
                valor_litro = 25;
                valor_carro = 1;
            }
            else if (veiculo == 'M')
            {
                valor_litro = 12;
                valor_carro = 0;
            }

            //construção das matrizes
            litros[i][j] = valor_litro + litros[i - 1][j] + litros[i][j - 1] - litros[i - 1][j - 1];
            carros[i][j] = valor_carro + carros[i - 1][j] + carros[i][j - 1] - carros[i - 1][j - 1];
        }
    }

    //entrada de dados
    cin >> L;

    int maior_gasolina = -1;

    //verificar cantos inferiores direitos
    for (int i = L; i <= N; i++)
    {
        for (int j = L; j <= M; j++)
        {
            //formula soma 2D
            int total_litros = litros[i][j] - litros[i - L][j] - litros[i][j - L] + litros[i - L][j - L];
            int total_carros = carros[i][j] - carros[i - L][j] - carros[i][j - L] + carros[i - L][j - L];

            //regra do darlan: o quadrado precisa ter > 0 carros e < L * L carros e motos
            if (total_carros > 0 && total_carros < L * L)
            {
                //função max() compara dois valores e guarda o maior deles
                maior_gasolina = max(maior_gasolina, total_litros);
            }
        }
    }

    //saída de dados
    cout << maior_gasolina << endl;

    return 0;
}