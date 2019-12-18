#include <stdio.h>
#include <stdlib.h>
/*
int main() {
    FILE *plik;
    plik = fopen("plik.txt","w");
    int liczba = 10;
    fprintf(plik,"%d", liczba);
    fclose(plik);
    return 0;
}

int main(){
    FILE *plik;
    plik = fopen("plik2.txt", "r");
    int suma = 0, zmienna, i;
    while((fscanf(plik, "%d", &zmienna) != EOF))
    {
        suma += zmienna;
    }
    printf("%d", suma);
    fclose(plik);
    return 0;
}

int main(){
    FILE *plik;
    plik = fopen("plik3.txt","w");
    char wiersz[100];
    int bufor= 100;
    char *w = &wiersz;
    while(wiersz[0] != '\n')
    {
        getline(&w, &bufor, stdin);
        fprintf(plik, "%s", wiersz);
        fflush(plik);
    }
    fclose(plik);
    return 0;
}
*/
int main()
{
    FILE *plik1, *plik2;
    plik1 = fopen("odczyt.txt", "r");
    plik2 = fopen("zapis.txt", "w");
    int liczba, i;
    char znak;
    while((fscanf(plik1, "%d; %c", &liczba, &znak) != EOF))
    {
        for( i = 0; i < liczba; i++)
        {
            fprintf(plik2, "%c", znak);
        }
        fprintf(plik2, "\n");
    }
}

