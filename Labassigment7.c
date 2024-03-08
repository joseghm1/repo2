#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n, int arrt[]) {
    int numberofswaps = 0;
    int indexTP[n];
    int indexT[n];
    for(int i = 0; i < n; i++){
        indexT[i] = 0;
        indexTP[i] = 0;
    }
    
    for(int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                for(int k = 0; k < n; k++){
                    if(arrt[k] == arr[j] || arrt[k] == arr[j + 1]){
                        indexT[k]++;
                    }
                }
                swap(&arr[j], &arr[j + 1]);
                numberofswaps++;
            }
        }
    }
    for(int p = 0; p < n; p++){
        for(int g = 0; g < n; g++){
            if(arr[p] == arrt[g]){
                indexTP[p] = indexT[g];
            }
            
        }
        
    }
    
    
    for(int i = 0; i < n; i++){
        printf("%d: %d\n", arr[i], indexTP[i]);
    }
    printf(" %d\n\n", numberofswaps);
}


void selectionSort(int arr[], int n, int arrt[]){
    int numberofswaps = 0;
    int indexT[n];
    int indexTP[n];
  
    for(int i = 0; i < n; i++){
        indexT[i] = 0;
        indexTP[i] = 0;
    }
    
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for( int j= i + 1; j < n;j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(min != i){
            for(int k = 0; k < n; k++){
                if(arrt[k] == arr[i] || arrt[k] == arr[min]){
                    indexT[k]++;
                }
            }
            swap(&arr[i], &arr[min]);
            numberofswaps++;
        }
    }
    
    
    for(int p = 0; p < n; p++){
        for(int g = 0; g < n; g++){
            if(arr[p] == arrt[g]){
                indexTP[p] = indexT[g];
            }
        }
    }
    
    
    for(int i = 0; i < n; i++){
        printf("%d: %d\n", arr[i], indexTP[i]);
    }
    printf("%d\n\n", numberofswaps);
}



int main(){
    int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    
    
    int n1, n2;
    
    n1 =sizeof(arr1) / sizeof(arr1[0]);
    n2 =sizeof(arr2) / sizeof(arr2[0]);
    int temp1[n1];
    int temp2[n2];
    
    for (int i = 0; i < n1; i++) {
        temp1[i] = arr1[i];
    }
    
    for (int i = 0; i < n1; i++) {
        temp2[i] = arr2[i];
    }
    printf("Array 1 bubble sort:\n");
    bubbleSort(temp1, n1,arr1);
    
    printf("Array 2 bubble sort:\n");
    bubbleSort(temp2, n2, arr2);
    
    for (int i = 0; i < n1; i++) {
        temp1[i] = arr1[i];
    }
    
    for (int i = 0; i < n1; i++) {
        temp2[i] = arr2[i];
    }
    
    printf("Array 1 selection sort:\n");

    selectionSort(temp1, n1,arr1);
    
    printf("\n\n");
    
   

    printf("Array 2 selection sort:\n");

    selectionSort(temp2, n2, arr2);
    printf("\n");

    return 0;
    
}
