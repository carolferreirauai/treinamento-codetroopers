/*
2242 - HUAAUHHUAHAU

EM CHATS, É MUITO COMUM ENTRE JOVENS E ADOLESCENTES UTILIZAR SEQUÊNCIAS DE LETRAS, QUE PARECEM MUITAS
VEZES ALEATÓRIAS, PARA REPRESENAR RISADAS. ALGUNS EXEMPLOS COMUNS SÃO:

HUAAUHAHHUAHAU
HEHEHEHE
AHAHAHAHA
JAISJJKASJKSJJSKJAKIJS
HUEHUEHUE

CLÁUDIA É UMA JOVEM PROGRAMADORA QUE FICOU INTRIGADA PELA SONORIDADE DAS "RISADAS DIGITAIS". ALGUMAS
DELAS ELA NEM MESMO CONSEGUE PRONUNCAR! MAS ELA PERCEBEU QUE ALGUMAS DELAS PARECEM TRANSMITIR
MELHOR O SENTIMENTO DE RISADA QUE OUTRAS. A PRIMEIRA COISA QUE ELA PERCEBEU É QUE AS CONSOANTES NÃO
INTERFEREM NO QUANTO AS RISADAS DIGITAIS INFLUENCIAM NA TRANSMISSÃO DO SENTIMENTO. A SEGUNDA COISA QUE ELA
PERCEBEU É QUE AS RISADAS DIGITAIS MAIS ENGRAÇADAS SÃO AQUELAS EM QUE AS SEQUÊNCIAS DE VOGAIS SÃO IGUAIS
QUANDO LIDAS NA ORDEM NATURAL (DA ESQUERDA PARA DIREITA) OU NA ORDEM INVERSA (DA DIREITA PARA A 
ESQUERDA), IGNORANDO AS CONSOANTES. POR EXEMPLO,"HAHAHA" E "HUAAUHAHHUAHAU" ESTÃO ENTRE AS RISADAS
MAIS ENGRAÇADAS, ENQUANTO "RIAJKJDHHIHHJAS" E "HUEHUEHUE" NÃO ESTÃO ENTRE AS MAIS ENGRAÇADAS.

CLÁUDIA ESTÁ MUITO ATAREFADA COM A ANÁLISE ESTATÍSTICA DAS RISADAS DIGITAIS E PEDIU SUA AJUDA PARA ESCREVER
UM PROGRAMA QUE DETERMINE, PARA UMA RISADA DIGITAL, SE ELA É DAS MAIS ENGRAÇADAS OU NÃO.

ENTRADA: A ENTRADA É COMPOSTA PO POR UMA LINHA, CONTENDO UMA SEQUÊNCIA DE NO MÁXIMO 50 CARACTERES, FORMADA
APENAS PÓR LETRA MINÚSCULAS SEM ACENTUAÇÃO. AS VOGAIS SÃO AS LESTRAS 'A', 'E', 'I', 'O', 'U'. A SEQUÊNCIA CONTÉM
PELO MENOS UMA VOGAL.

SAÍDA: SEU PROGRAMA DEVE PRODUZIR UMA LINHA CONTENDO UM CARACTERE, "S" CASO A RISADA SEJA DAS MAIS ENGRAÇADAS, 
OU "N" CASO CONTRÁRIO.
*/

//biblioteca
#include <bits/stdc++.h>

using namespace std;

//função principal
int main()
{
    //declaração de váriaveis
    string risada;
    string vogais = ""; //string vazia para armazenar apenas as vogais

    //entrada de dados
    cin >> risada;

    //desenvolvimento
    //percorrer a string inteira, .size() posição de cada caracter
    for (int i = 0; i < risada.size(); i++)
    { 
        //verificar se o caracter atual é um vogal
        if (risada [i] == 'a' || risada[i] == 'e' || risada[i] == 'i' || risada[i] == 'o' || risada[i] == 'u')
        {
            //se for vogal add na string, .push_back concatenação de apenas 1 caractere
            vogais.push_back(risada[i]);
        }
    }

    //inverter a string da risada
    string vogais_invertida = vogais;
    //reverse = inverte a string de trás para frente
    //begin = primeiro caracter, end = caracter final
    reverse(vogais_invertida.begin(), vogais_invertida.end());

    //saída de dados
    //comparar os vogais
    if(vogais == vogais_invertida)
    {
        cout << "S" << endl;
    }
    else
    {
        cout << "N" << endl;
    }
    return 0;
}