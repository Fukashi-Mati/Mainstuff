#include <stdio.h>
#include <stdlib.h>
int dlugosc(char *lan);
int *init_next(char*wzor);
void init_shift(char *w, int *shift);
int KMP(char*tekst, char*wzor, int*next);
int BM(char *tekst, char *wzor);
int *KMP_w(char *tekst, char *wzor, int *next,int *ilosc);
int *BM_w(char *tekst, char *wzor, int *ilosc);
int main()
{
    int *next;
    char tekst[128];
    char wzor[128];
    printf("Wprowadz tekst: ");
    scanf("%[^\n]%*c",tekst);
    printf("Podaj wzor: ");
    scanf("%[^\n]%*c",wzor);
    int *tab_kmp;
    int *tab_bm;
    int ilosc, ilosc2, i, wynik_kmp, bm;
    next = init_next(wzor);
    wynik_kmp = KMP(tekst,wzor,next);
    tab_kmp = KMP_w(tekst,wzor,next,&ilosc);
    printf("\nWynik dzialania funkcji KMP:\nPierwsze wystapienie wzorca: %d\nwzorzec wystapil %d razy, oto indeksy: ",wynik_kmp,ilosc);                              
    for(i = 0; i < ilosc; i++){
        if(i == 0)
        printf("%d",tab_kmp[i]);
        else
        printf(", %d",tab_kmp[i]);
    }
    printf("\n");
    printf("\nWynik dzialania funkcji BM:\n");
    bm = BM(tekst, wzor);
    tab_bm = BM_w(tekst, wzor, &ilosc2);
    printf("Pierwsze wystapienie wzorca: %d\nwzorzec wystapil %d razy, oto indeksy: ", bm, ilosc);
    for(i = 0; i < ilosc; i++){
        if(i == 0)
        printf("%d",tab_bm[i]);
        else
        printf(", %d",tab_bm[i]);
    }
    printf("\n");
    return 0;
}
int dlugosc(char *lan)
{
    int dl = 0;
    for(int i = 0; lan[i] != '\0'; i++)
    {
        dl++;
    }
    return dl;
}
int *init_next(char*wzor)
{
    int m = dlugosc(wzor);
    int *next;
    next = (int*) malloc(m*sizeof(int));
    next[0] = -1;
    for(int i=0, j=-1; i<m-1; i++, next[i] = j)
    {
        while((j >= 0) && (wzor[i]!=wzor[j]))
        {
            j = next[j];
        }
    }
    return next;
}
void init_shift(char *w, int *shift)
{
    int M = dlugosc(w);
    int K=256;
    for(int i = 0; i < K; i++)
    {
        shift[i] = M;
    }
 
    for(int i = 0; i < M; i++)
    {
        shift[(int)w[i]] = M-i-1;
    }
}
int KMP(char *tekst, char *wzor, int *next)
{
    int N = dlugosc(tekst);
    int M = dlugosc(wzor);
    int i = 0, j = 0;
    for (i = 0, j = 0; i < N && j < M; i++, j++)
        while ((j>=0) && (tekst[i] != wzor[j]))
            j = next[j];

    if (j == M)
        return i-M+1;
    else
        return -1;
}
int BM(char *tekst, char *wzor)
{
    int M=dlugosc(wzor);
    int N=dlugosc(tekst);
    int x, i, j;
    int shift[256];
    init_shift(wzor, shift);
    if(M>N)
    {
        return (-1);
    }
    for(i=M-1, j=M-1; j>=0; i--, j--)
    {
        while(tekst[i]!=wzor[j])
        {
            x = shift[tekst[i]];
            if(M-j>x)
            {
                i+=M-j;
            }
            else
            {
                i+=x;
            }
            if(i>=N)
            {
                return (-1);
            }
            j=M-1;
        }
        return i-1;
    }
}
int *KMP_w(char *tekst, char *wzor, int *next,int *ilosc){
    int i = 0, j = 0, count = 0, k = 0;
    int m = dlugosc(wzor), n = dlugosc(tekst);
    int *indeksy;
    indeksy = (int*)malloc(0*sizeof(int));  
    for(i = 0, j = 0; i <= n && j <= m; i++, j++){    
        if(j == m){
            indeksy = (int*)realloc(indeksy,(count+1)*sizeof(int));
            indeksy[count] = i-m+1;
            count++;
    }
        while((j>=0) && (tekst[i] != wzor[j])){
            j = next[j];
        }
    }

        *ilosc = count;
        return indeksy;
}
int *BM_w(char *tekst, char *wzor, int *ilosc)
{
   
    
    int M=dlugosc(wzor);
    int N=dlugosc(tekst);
    int x, i, j, count = 0 ;
    int shift[256];
    init_shift(wzor, shift);
    int *indeksy;
    indeksy = (int*)malloc(0);  
    for(i=M-1, j=M-1; j>=0; i--, j--)
    {
        while(tekst[i]!=wzor[j])
        {
            
            x = shift[tekst[i]];
            if(M-j>x)
            {
                i+=M-j;
            }
            else
            {
                i+=x;
            }
            if(i >= N)
            {
                    *ilosc = count;
                    return indeksy;
            }
            j=M-1;
        }
            indeksy = (int*)realloc(indeksy,(count+1)*sizeof(int));
            indeksy[count] = i-M+2;
            count++;
            i += M;
        }
            
        *ilosc = count;
        return indeksy;
}
