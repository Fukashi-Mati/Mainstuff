#include <stdio.h>
#include <string.h>
typedef struct Liczenie{
    int dod;
    int ode;
    int mno;
    int dzi;}liczenie;
int zmiana(char tablica[5], int dl);
int main()
{
    struct Liczenie A;
    FILE* plik;
    FILE* plik2;
    plik2 = fopen("wyniki_zad.txt", "w");
    plik = fopen("przyklad.txt", "r");
    int wynik , i , j = 0, liczba, z;
    char tab[100], znak, licz[5], operacja;
    int bufor = 100;
    char *w = &tab;
    while(1)
    {
        wynik = 0;
        A.dod = 0, A.ode = 0; A.mno = 0; A.dzi = 0;
        getline(&w, &bufor, plik);
        printf("dlugosc: %ld\n", strlen(tab));
        if(feof(plik) != 0) break;
        i = 0;operacja = 'x';
        printf("%s", tab);
        while(tab[i] != '=')
            {
                znak = tab[i];
                if((znak >= '0' )&&( znak <= '9'))
                {
                    licz[j] = znak;
                    j++;
                }
                else
                {
                    if(znak == ' ')
                    {
                        liczba = zmiana(licz,j);
                        j = 0;
                        switch(operacja)
                        {
                            case '+': wynik += liczba; A.dod++; break;
                            case '-': wynik -= liczba; A.ode++; break;
                            case '*': wynik *= liczba; A.mno++; break;
                            case 'd': wynik /= liczba; A.dzi++; break;
                            case 'x': wynik = liczba ; break;
                        }
                    }
                    else
                    {
                        operacja = znak;
                    }
                }
                i++;
        }
    fprintf(plik2,"%d +%d -%d *%d d%d \n", wynik, A.dod, A.ode, A.mno, A.dzi);
    
    }
    return 0;
    
}
int zmiana(char tablica[5], int dl)
{
    int i, temp, wynik = 0, mno = 1;
    for(i = (dl-1); i >= 0; i--)
    {
        temp = tablica[i] - '0';
        wynik += temp * mno;
        mno *= 10;
    }
    return wynik;
}
