/*
209 - SOMA SUBARRAY DE TAMANHO MÍNIMO

DADA UMA MATRIZ DE NÚMEROS INTEIROS POSITIVOS NUMS E UM INTEIRO POSITIVO ALVO, 
RETORNO O THE COMPRIMENTO MÍNIMO DE UM SUBARRANJO CUJA
SOMA SEJA MAIOR OU IGUAL A ALVO. SE NÃO HOUVER ESSE SUBARRANJO, RETORNE 0 EM VEZ.

EXEMPLO 1:
ENTRADA: ALVO = 7, NUMS = [2,3,1,2,4,3]
SAÍDA: 2
EXPLICAÇÃO: 0 SUBARRAY [4,3] TEM O COMPRIMENTO MÍNIMO SOB A RESTRIÇÃO DO PROBLEMA.

EXEMPLO 2:
ENTRADA: ALVO = 4, NUMS = [1,4,4]
SAÍDA: 1

EXEMPLO 3:
ENTRADA: ALVO = 11, NUMS = [1,1,1,1,1,1,1,1]
SAÍDA: 0

RESTRIÇÕES:
- 1 <= ALVO <= 10^9
- 1 <= NUMS.LENGTH <= 10^5
- 1 <= NUMS[I] <= 10^4

ACOMPANHAR: SE VOCÊ DESCOBRIU O O(N) SOLUÇÃO, TENTE CODIFICAR OUTRA SOLUÇÃO DA QUAL 
A COMPLEXIDADE DE TEMPO É O(N LOG (N)).
*/

class Solution
{
public:
    //função testadora - verificar se existe algum subarray
    bool testa(int tamanho, int N, long long alvo, const vector<long long>& soma)
    {
        //loop para verificar as janelas possíveis
        for (int i = tamanho; i <= N; i++)
       {
            //soma de prefixos
            long long soma_atual = soma[i] - soma[i - tamanho];

            if (soma_atual >= alvo)
            {
                return true; //achou um pedaço válido
            }
        }
        return false; //nenhum subarray
    }

    //função principal
    int minSubArrayLen(int target, vector<int>& nums)
    {
        //declaração de váriaveis
        int N = nums.size();
        vector<long long> soma(N + 1, 0);

        //o loop leitura e construção do prefixo
        for (int i = 1; i <= N; i++)
        {
            //soma de prefixo 1D
            soma[i] = soma[i - 1] + nums[i - 1];
        }

        // ========== BUSCA BINÁRIA ========== //
        //baixo = menor número possível, alto = maior número possível, melhor_tamanho = começa 0, mas se não achar, mantém
        int baixo = 1, alto = N, melhor_tamanho = 0;

        while(baixo <= alto)
        {
            int meio = (baixo + alto) / 2;

            if(testa(meio, N, target, soma))
            {
                melhor_tamanho = meio; //se existe, salva
                alto = meio - 1; //se não forçamos para a esquerda
            }
            else
            {
                baixo = meio + 1; //se nenhum, forçamos para direita
            }
        }
       return melhor_tamanho;     
    }
};