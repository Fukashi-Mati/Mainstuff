#include <stdio.h>
#include <stdlib.h>

struct element
{
    int k;
    struct element *prev;
    struct element *next;
};

struct element *lista_dodaj(struct element *head, struct element *nowy);
void lista_wyswietl(struct element *head);
struct element *lista_szukaj(struct element *head, int zm);
struct element *lista_usun(struct element *head, struct element *x);
struct element *lista_odwroc(struct element *head);
struct element *lista_zwolnij(struct element* head);

main()
{
    struct element *head=NULL, *nowy=NULL, *adres_elementu = NULL, *head_LP = NULL;
    char z;
    int liczba;
    while(1)
    {
        printf("\nco chcesz zrobic?");
        printf("\nd - dodac");
        printf("\ns - szukac");
        printf("\nu - usunac");
        printf("\no - odwrocic liste");
        printf("\nw - wyswietlic");
        printf("\nq - wyjsc\n");
        fflush(stdin);
        z=getchar();
        switch(z)
        {
        case 'd': nowy=(struct element*)malloc(sizeof(struct element));
        printf("\npodaj wartosc elementu do wstawienia: ");
        scanf("%d",&liczba);
        nowy->k=liczba;
        head=lista_dodaj(head,nowy);
        break;
        case 'w': lista_wyswietl(head);
        break;
        case 'q':
        lista_zwolnij(head);
        return 0;
        case 's': printf("\npodaj wartosc szukanego elementu: ");
        scanf("%d", &liczba);
        adres_elementu = lista_szukaj(head, liczba);
        printf("adres szukanego elementu: %p", adres_elementu);
        break;
        case 'u': printf("\npodaj wartosc elementu do usuniecia: ");
        scanf("%d", &liczba);
        adres_elementu = lista_szukaj(head, liczba);
        if (adres_elementu != NULL){
            head = lista_usun(head, adres_elementu);
            printf("Obecny adres head: %p", head);
        }
        else
            printf ("Brak elementu do usuniecia");
        break;
        case 'o': printf("lista odwrocona: \n");
        head_LP = lista_odwroc(head);
        lista_wyswietl(head_LP);
        lista_zwolnij(head_LP);
        break;
        }
    }
}
struct element *lista_dodaj(struct element *head, struct element *nowy){
    nowy->prev = NULL;
    nowy->next = head;
    if(head!=NULL)
        head->prev = nowy;
    head = nowy;
    return head;
}

void lista_wyswietl(struct element *head){
    struct element *x = head;
    while(x!=NULL){
        printf("%d ", x->k);
        x = x->next;
    }
}

struct element *lista_szukaj(struct element *head, int zm){
    struct element *x = head;
    while(x!=NULL){
        if(x->k == zm)
            return x;
        x = x->next;
    }
    return x;
}

struct element *lista_usun(struct element *head, struct element *x){
    if (x->prev != NULL)
        x->prev->next = x->next;
    else
        head = x->next;
    if (x->next != NULL){
        x->next->prev = x->prev;
        free(x);
    }
    return head;
}

struct element *lista_odwroc(struct element *head){
    struct element *head_LP = NULL;
    struct element *x = head;
    struct element *y = NULL;
    while(x != NULL){
        y = (struct element*)malloc(sizeof(struct element));
        y->k = x->k;
        head_LP = lista_dodaj(head_LP, y);
        x = x->next;
    }
    return head_LP;
}

struct element *lista_zwolnij(struct element *head){
    struct element *x = head;
    struct element *next = NULL;
    while(x != NULL){
        next = x->next;
        free(x);
        x = next;
    }
    return head;
}
