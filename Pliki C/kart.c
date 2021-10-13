#include <stdio.h>
#include <stdlib.h>
char* slowo(char*tekst, char zn)
{
    char* wynik;
    int i, dl= 0;
    int zmiana = 0;
    wynik = (char*)malloc(0);
    while(tekst[dl] != '\0')
    {
        dl++;
    }
    if(tekst[0] == zn)
        zmiana = 1;
    for( i = 0; i < dl; i++)
    {
        if(tekst[i-1] == ' ' && tekst[i] == zn)
            zmiana = 1;
        if(zmiana == 1)
        {
        wynik = (char*)realloc(wynik, (i+1)*sizeof(char));
        if(tekst[i] == ' ' || tekst[i] == '\t' || tekst[i] == '\n')
            {
                wynik[i] = '\n';
                if(tekst[i+1] == zn)
                    zmiana = 1;
                else
                    zmiana = 0;
            }
        else wynik[i] = tekst[i];
        }
        
    }
    return wynik;
}    

int main()
{
    
    char tablica[] = "ku su ku";
    char *wynik;
    char znak = 'k';
    wynik = slowo(tablica,znak );
    printf("%s\n",wynik);
    return 0;
}
