#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int samo(char*);
int main()
{
    FILE* plik1;
    FILE* plik2;
    
    if(!(plik1 = fopen("plik.txt", "r")) || !(plik2 = fopen("Wyniki.txt", "w")))
    {
        exit(EXIT_FAILURE);
    }
    char tekst[128];
    int islowa = 0;
    int isamo = 0;
    int iliczba = 0;
    while(fscanf(plik1, "%d %s", &iliczba, &tekst) != EOF)
    {
        if(iliczba == 0 && strcmp(&tekst, "koniec") == 0)
        {
            if(islowa >= 0 && isamo != 0)
            {
                fprintf(plik2, " %d", isamo);
            }
            fprintf(plik2, "\n");
            islowa = 0;
            isamo = 0;
            continue;
        }
        islowa += iliczba;
        if(islowa != 0)
        {
            fprintf(plik2, "%s", tekst);
            isamo += samo(tekst);
            islowa--;
        }
        else if(islowa == 0)
        {
            isamo = samo(tekst);
            fprintf(plik2, "%s %d ", tekst, isamo);
            isamo = 0;
        }
    }
    fclose(plik1);
    fclose(plik2);
    return 0;
}
int samo(char* string)
{
    int liczba = 0;
    for(int i = 0; i < strlen(string);i++)
    {
        switch(tolower(string[i]))
        {
            case 'a':
            case 'e':
            case 'u':
            case 'i':
            case 'y':
            case 'o':
                liczba++;
        }
    }
    return liczba;
}
