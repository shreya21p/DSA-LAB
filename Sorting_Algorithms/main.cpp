
#include<cstdlib>
#include<cstdio>
#include "sort.h"
void bubblesort(int *arr,int size);
void selectionsort(int *arr,int size);
void insertionsort(int *arr,int size);
void displayarray(int *arr,int size);
int main(){
    int size,choice;
    int cond=1;
    while(cond){
        printf("\n1.Bubblesort\n");
        printf("2.Selection sort\n");
        printf("3.Insertion sort\n");
        printf("4. Exit\n");
        printf("Please enter your choice:");
        scanf("%d",&choice);
        if(choice!=4){
            printf("enter the number of elements:");
            scanf("%d",&size);
            int *arr=(int*)malloc(size*sizeof(int));
            printf("Enter the elements:");
            for(int i=0;i<size;i++){
                scanf("%d",&arr[i]);
            }
            switch(choice){
                case 1:
                    bubblesort(arr,size);
                    printf("Array after bubblesort:");
                    displayarray(arr,size);
                    break;
                case 2:
                    selectionsort(arr,size);
                    printf("Array after selection sort:");
                    displayarray(arr,size);
                    break;
                case 3:
                    insertionsort(arr,size);
                    printf("Array after insertion sort:");
                    displayarray(arr,size);
                    break;
                default:
                    printf("invalid choice, please try\n");
            }
        } else {
            printf("Exiting the program");
            break;
        }
    }
    return 0;
}
