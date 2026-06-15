/*
1579 - TRANSPORTE DE PAINÉIS SOLARES

HÁ ALGUNS ANOS, ALGUMAS EMPRESAS VEM ATUANDO FORTE NA PRODUÇÃO DE ENERGIA
BASEADA EM PAINÉIS SOLARES. OBVIAMENTE O LOCAL MAIS ADEQUADO PARA ISSO SÃO OS
DESERTOS. NO DESERTO DE MOJAVE, NOS ESTADOS UNIDOS, JÁ FORAM INSTALADOS VÁRIAS USINAS
PARA GERAÇÃO DE ENERGIA SOLAR, COMO POR EXEMPLO A USINA SOLAR NELLIS, QUE FICA NA BASE
AÉREA DE NELLIS, EM CLARK COUNTY, NEVADA. ESTA USINA GERA MAIS DE 30 MILHÕES DE
QUILOWATTS-HORA DE ELETRICIDADE POR ANO. O PROJETO DE 100 MILHÕES DÓLARES
AMERICANOS COMEÇOU A PRODUÇÃO DE ENERGIA NO FINAL DE 2007, A PLANTA É ALIMENTADA
POR 72.000 PAINÉIS SOLARES DE RASTREAMENTO DO SOL COBRINDO 140 ACRES. ALÉM DA NELLIS,
OUTRAS USINAS COMO A SIERRA SUN TOWER, COPPER MOUNTAIN, SOLAR ONE E OUTRAS FORAM
CONSTRUÍDAS NESTE MESMO DESERTO.

A ESPANHA JÁ UTILIZA UMA USINA SOLAR NO DESERTO DO SAARA QUE FOI CONSTRUÍDA PELA SOLAR
MILLENIUM. O PROJETO DEU TÃO CERTO QUE AGORA OUTRAS EMPRESAS ESTÃO INICIANDO NOVOS
PROJETOS NESTA REGIÃO PARA GERAR ENERGIA PARA A EUROPA.

BEM, VOCÊ POSSUI UMA EMPRESA DE TRANSPORTES COM MUITOS CAMINHÕES E FOI
CONTRATADO PELA EMPRESA DELTA SOLAR FAZER O TRANSPORTE DE PAINÉIS SOLARES NO SAARA.
OS PAINÉIS POSSUEM TAMANHOS E PESOS DIFERENTES RELACIONADOS COM A ESTRUTURA DE
CADA CONJUNTO DE PAINÉIS, QUE MUDA DE ACORDO COM O LOCAL AONDE DEVERÃO SER
INSTALADOS. O TRANSPORTE DELES DEVERÁ SER FEITO NA SEQUÊNCIA CORRETA, QUE É
EXATAMENTE A SEQUÊNCIA NA QUAL ELES APARECEM NA ENTRADA.

O CÁLCULO DO FRETE É FEITO DE ACORDO COM O PESO DOS PAINÉIS TRANSPORTADOS PELOS SEUS
CAMINHÕES E A DISTÂNCIA QUE OS CAMINHÕES DEVERÃO PERCORRER. FOI ACERTADO QUE VOCÊ
INFORME TODO DIA A QUANTIDADE DE CAMINHÕES DISPONÍVEIS (ISSO MUDA PORQUE ALGUNS
VÃO PARA MANUTENÇÃO, OUTROS NOVOS CHEGAM, ETC) E UM ENCARREGADO DA DELTA SOLAR VAI
TENTAR SEPARAR AS CARGAS PARA MINIMIZAR O VALOR DO TRANSPORTE, UMA VEZ QUE POR UM
ACERTO INICIAL, PAGARÃO O FRETE UTILIZANDO COMO REFERÊNCIA A CARGA MAIS PESADA
TRANSPORTADA NO DIA, MULTIPLICADA PELO NÚMERO DE CAMINHÕES UTILIZADOS NO TRASPORTE.

ENTRADA: A PRIMEIRA LINHA DE ENTRADA CONTÉM UM INTEIRO N QUE DETERMINA A QUANTIDADE DE
CASOS DE TESTE (OU DIAS DE TRABALHO NO DESERTO). CADA CASO DE TESTE É COMPOSTO POR
DUAS LINHAS. A PRIMEIRA LINHA CONTÉM TRÊS VALORES INTEIROS NPAINEIS (4 ≤ NPAINEIS ≤
100), CAMINHOES (1 ≤ CAMINHOES ≤ 10) E FRETE (1 ≤ FRETE ≤ 50) SEPARADOS POR UM
ESPAÇO, QUE INDICAM RESPECTIVAMENTE A QUANTIDADE DE PAINÉIS QUE DEVEM SER
TRANSPORTADOS, NÚMERO DE CAMINHÕES UTILIZADOS PARA O TRANSPORTE E O FRETE COBRADO
POR CADA CAMINHÃO PARA CADA KG TRANSPORTADO. A LINHA SEGUINTE CONTÉM O PESO (1 ≤
PESO ≤ 1000) DE CADA UM DOS PAINÉIS, SEPARADOS POR UM ESPAÇO EM BRANCO.

SAÍDA: PARA CADA CASO DE TESTE DE ENTRADA, SEU PROGRAMA DEVERÁ IMPRIMIR UMA LINHA,
INFORMANDO O PESO DO CAMINHÃO MAIS CARREGADO SEGUIDO POR UM ESPAÇO E O VALOR
TOTAL DO FRETE COBRADO PELO DIA DE TRABALHO.
*/

//biblioteca
#include <iostream>
#include <algorithm> //necessária para usar a função max()

using namespace std;

//declração globais
int paineis[105];

//função - verifique se é possivel fazer transporte
bool testa(int peso_maximo, int n_paneis, int limite_caminhoes)
{
    int caminhoes_usados = 1; //começa com 1 caminhão
    int carga_atual = 0;

    for (int i = 0; i < n_paneis; i++)
    {
        //se colocar o painel atual estourar o limite, precisamos de outro caminhão
        if (carga_atual + paineis[i] > peso_maximo)
        {
            caminhoes_usados++; ///painel não cabe no caminhão atual -> abre um novo
            carga_atual = paineis[i]; //o novo caminhão começa o painel atual
        }
        else
        {
            carga_atual += paineis[i]; //vai empilhando no caminhão atual
        }
    }

    //retorna verdadeiro, se usamos uma quantidade válida de caminhões
    return (caminhoes_usados <= limite_caminhoes);
}

int main()
{
    int N; //quantidade casos de teste
    cin >> N;

    //rodar N dias de trabalho
    for (int dia = 0; dia < N; dia++)
    {
        int npaineis, caminhoes, frete;
        cin >> npaineis >> caminhoes >> frete;

        int maior_painel = 0;
        long long soma_total = 0;

        //lendo os paíneis e ja descobrindo os nosso limites "baixo" e "alto"
        for (int i = 0; i < npaineis; i++)
        {
            cin >> paineis[i];

            //qual é a placa mais pesada de todas
            maior_painel = max(maior_painel, paineis[i]);

            //soma o peso de todos os paineis
            soma_total += paineis[i];
        }

        //busca binária em resposta
        long long baixo = maior_painel, alto = soma_total, melhor_peso = alto;

        while(baixo <= alto)
        {
            long long meio = (baixo + alto) / 2;

            if (testa(meio, npaineis, caminhoes))
            {
                melhor_peso = meio; //se funcionar, salva
                alto = meio - 1;
            }
            else
            {
                baixo = meio + 1;
            }
        }

        //calculo final e saída de dados
        long long custo_total = melhor_peso * caminhoes * frete;

        cout << melhor_peso << " $" << custo_total << endl;
    }

    return 0;
}