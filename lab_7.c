#include <stdio.h> 
#include <stdlib.h>

void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 


int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high- 1; j++) 
	{ 
		 
		if (arr[j] < pivot) 
		{ 
			i++; 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 


void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		
		int pi = partition(arr, low, high); 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 


void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
} 
void counting_sort(int A[], int k, int n)

{

    int i, j;

    int B[15], C[100];

    for (i = 0; i <= k; i++)

        C[i] = 0;

    for (j = 1; j <= n; j++)

        C[A[j]] = C[A[j]] + 1;

    for (i = 1; i <= k; i++)

        C[i] = C[i] + C[i-1];

    for (j = n; j >= 1; j--)

    {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    printf("Posortowana tablica : \n");

    for (i = 1; i <= n; i++)

        printf("%d ", B[i]);

}
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    }
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) {
        int m = l + (r - l) / 2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
        merge(arr, l, m, r); 
    } 
} 
  

int main() 
{ 
	int* arr;
    arr = (int*)malloc(0);
    int arr_size, i;
    int a, k=0;
    while(1){
    printf("Podaj co chcesz zrobic. \n [1] Sortowanie przez scalanie \n [2] Sortowanie quicksort \n [3] Sortowanie przez zliczanie\n [4] Wyjscie\n");
    scanf("%d", &a);
    if(a != 4)
    {
        printf("Podaj rozmiar tablicy: ");
        scanf("%d", &arr_size);
        arr = (int*)realloc(arr, arr_size*sizeof(int));
    
    printf("Podaj elementy tablicy: ");
    for(i = 0; i < arr_size; i++){
        scanf("%d", &arr[i]);
        if(arr[i] > k) k = arr[i];
    }
    }
    switch(a)
    {
        case 1 : 
            mergeSort(arr, 0, arr_size - 1);
            printf("Posortowana tablica:\n"); 
            printArray(arr, arr_size); 
            break;
        case 2 : 
            quickSort(arr, 0, arr_size-1);
            printf("Posortowana tablica:\n"); 
            printArray(arr, arr_size);  
            break;
        case 3 : 
            counting_sort(arr,k,arr_size);
            break;
        case 4: free(arr);
                return 0;
    }
	
    printf("\n");
    }
	return 0; 
} 
