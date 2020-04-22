#include <stdio.h>
#include <stdlib.h>
int szukanie_liniowe_1(int TAB[],int n, int x)
{
    int i = 0;
    for(;i<=n;i++)
    {
        if(TAB[i] == x)
            return i;
    }
    return -1;
}
int* szukanie_liniowe_2(int TAB[],int n, int x, int* ilosc)
{
    int i = 0, num = 0;
    int* indeksy;
    indeksy = (int*)malloc(0);
    for(; i<n;i++)
    {
        if(TAB[i] == x)
        {
            indeksy = (int*)realloc(indeksy,(num+1)*sizeof(int));
            indeksy[num] = i;
            num++;
        }
    }
    *ilosc = num;
    return indeksy;
}
void sort(int* tab, int n)
{
    int i, temp;
    do
    {
        i = 0;
        for(int j = 0; j < n-1; j++)
        {
            if(tab[j+1] < tab[j])
            {
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
                i++;
            }
        }
    }while(i != 0);
}
int szukanie_binarne(int TAB[], int n, int x)
{
    int left, right, mid;
    left = 0;
    right = n-1;
    while(left <= right)
    {
        mid = (left + right)/2;
        if(TAB[mid] == x)
            return mid;
        if(TAB[mid] > x)
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }
    if(left == right && TAB[left] == x)
        return left;
    return -1;
}
int main()
{
    int n, ilosc, i, wynik, x;
    printf("Podaj dlugosc tablicy: ");
    scanf("%d", &n);
    int *tablica;
    tablica = (int*)malloc(n*sizeof(int));
    printf("Podaj elementy tablicy: ");
    for(i = 0; i < n; i++)
        scanf("%d", &tablica[i]);
    sort(tablica, n);
    printf("Podaj element szuakny: ");
    scanf("%d", &x);
    printf("----------------\n");
    printf("Tablica po posortowaniu wyglada następujaco:\n");
    for(i = 0; i < n; i++)
        printf("%d ", tablica[i]);
    printf("\n----------------\n");
    wynik = szukanie_liniowe_1(tablica, n,x);
    if(wynik == -1)
    {
        printf("Nie znaleziono elementu w tablicy\n");
        return 0;
    }
    int*indeksy;
    indeksy = szukanie_liniowe_2(tablica,n, x, &ilosc);
    printf("Element znaleziono %d raz(y) na pozycji/ach", ilosc);
    for( i = 0; i < ilosc; i++)
    {
        printf(" %d ",  indeksy[i]);       
    }
    printf("\n----------------\n");
    wynik = szukanie_binarne(tablica, n, x);
    printf("Element znaleziono na pozycji %d \n", wynik);
    return 0;
}
