#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int dlugosc(char* lan);
int sprawdz(char* tekst, char* wzor);
int* sprawdz_w(char* tekst, char* wzor, int* ilosc);
int main()
{
    char lancuch[128] ;
    char tekst[128] ;
    int ilosc, i;
    int* tablica;
    printf("Podaj tekst: ");
    fgets(lancuch,128,stdin);
    lancuch[dlugosc(lancuch) -1] = '\0';
    
    printf("Podaj wzorzec: ");
    fgets(tekst,128,stdin);
    tekst[dlugosc(tekst) -1] = '\0';
    if(sprawdz(lancuch, tekst) >= 0)
        printf("Pierwsze wystapienie wzorca %s w tekscie %s zaczyna sie od indeksu: %d\n",tekst ,lancuch ,sprawdz(lancuch, tekst));
    else
    {
        printf("Brak wzorca %s w tekscie %s\n",tekst, lancuch);
        return 0;
    }
    tablica = sprawdz_w(lancuch, tekst, &ilosc);
    printf("Tablica indeksow od ktorych zaczyna sie wzorzec:");
    for(i = 0; i < ilosc; i++)
    {
        printf("%d  ", tablica[i]);
    }
    printf("\n");
    return 0;
}
int dlugosc(char* lan)
{
    int i = 0, dl = 0;
    while(lan[i] != '\0')
    {
        dl++;
        i++;
    }
    return dl;
}
int sprawdz(char* tekst, char* wzor)
{
    int i, j, len_tekst = dlugosc(tekst), len_wzor = dlugosc(wzor) ;
    int check = 0;
    for( i = 0; i <= (len_tekst - len_wzor); i++)
    {
        for(j = 0; j < len_wzor; j++)
        {
            if(tekst[i+j] == wzor[j])
            check++;
        }
        if(check == len_wzor)
        {
            return i;
        }
        check = 0;
    }
    return (-1);
}
int* sprawdz_w(char* tekst, char* wzor, int* ilosc)
{
    int x = 100 ,check = 0, num= 0;
    int *tab;
    tab = (int*) malloc(x*sizeof(int));
    int i, j, len_tekst = dlugosc(tekst), len_wzor = dlugosc(wzor);
    for(i = 0; i <= (len_tekst - len_wzor); i++)
    {
        for(j = 0; j < len_wzor; j++)
        {
            if(tekst[i+j] == wzor[j])
            check++;
        }
        if(check == len_wzor)
        {
            tab[num] = i;
            num++;
        }
        check = 0;
    }
    printf("liczba wystapien: %d\n", num);
    *ilosc = num;
    return tab;
}
