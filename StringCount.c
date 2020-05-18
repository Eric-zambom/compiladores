#include <stdio.h>

static
int count_occurrences(const char *text, const char *palavraAnalisada)
{
       //Não é o melhor algoritmo mas faz o trabalho
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) // O primeirto for garante a busca em todos os caracteres diponiveis no texto
    {
        int j;
        for (j = 0; palavraAnalisada[j] != '\0' && palavraAnalisada[j] == text[i+j]; j++); //O segundo for garante a comparação com a palavra analisada
        if (palavraAnalisada[j] == '\0')
            count++;
    }
    return count;
}

int main(void)
{
    {
    const char text[] = "casa caasa casacasacas";
    const char palavraAnalisada[] = "casa";

    printf("text <<%s>> vs palavraAnalisada <<%s>> = %d\n",
           text+0, palavraAnalisada+0, count_occurrences(text+0, palavraAnalisada+0));
    printf("text <<%s>> vs palavraAnalisada <<%s>> = %d\n",
           text+1, palavraAnalisada+1, count_occurrences(text+1, palavraAnalisada+1));
    printf("text <<%s>> vs palavraAnalisada <<%s>> = %d\n",
           text+1, palavraAnalisada+0, count_occurrences(text+1, palavraAnalisada+0));
    printf("text <<%s>> vs palavraAnalisada <<%s>> = %d\n",
           text+1, palavraAnalisada+2, count_occurrences(text+1, palavraAnalisada+2));
    }

    {
    char *text = "lapis lapis lapiiis lap lapi la lap55is lapi9ssllapis55 lapislip peplic lapisrlapispe";
    char *palavraAnalisada = "lapis"; 
    printf("text <<%s>> vs palavraAnalisada <<%s>> = %d\n",
           text+0, palavraAnalisada+0, count_occurrences(text+0, palavraAnalisada+0));
    }

    {
    char *text = "O papa é pop mas o pop não poupa ninguém.";
    char *palavraAnalisada = "pop"; 
    printf("text <<%s>> vs palavraAnalisada <<%s>> = %d\n",
           text+0, palavraAnalisada+0, count_occurrences(text+0, palavraAnalisada+0));
    }

    return 0;
}