
#include<cstdlib>
#include<cstdio>
#include "sort.h"
void linearsearch(int *arr,int size,int key);
void binarySearch(int *arr,int size,int key);
int main(){
    int size,choice,key;
    int cond=1;
    while(cond){
        printf("\n1.linear search\n");
        printf("2.binary search\n");
        printf("3. exit\n");
        printf("please enter your choice:");
        scanf("%d",&choice);
        if(choice!=3){
            printf("enter the number of elements:");
            scanf("%d",&size);
            int *arr=(int*)malloc(size*sizeof(int));
            printf("Enter the elements:");
            for(int i=0;i<size;i++){
                scanf("%d",&arr[i]);
            }
            switch(choice){
                case 1:
                    printf("enter key to search:");
                    scanf("%d",&key);
                    linearsearch(arr,size,key);
                    break;
                case 2:
                    printf("sorting the array:");
                    bubblesort(arr,size);
                    displayarray(arr,size);
                    printf("enter key to search:");
                    scanf("%d",&key);
                    binarySearch(arr,size,key);
                    break;
                default:
                    printf("invalid choice, please try\n");
            }
        } else {
            printf("Exiting the program, thank you!");
            break;
        }
    }
}
void linearsearch(int *arr,int size,int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            printf("key found at index %d\n",i);
            return;
        }
    }
    printf("key not found\n");
}
void binarySearch(int *arr,int size,int key){
    int low=0,high=size-1;
    while (low<=high){
        int mid=low+(high-low)/2;
        if (arr[mid]==key){
            printf("key found at index%d\n",mid);
            return;
        } else if (arr[mid]<key){
            low=mid+1;
        } else {
            high=mid-1;
        }
    }
    printf("key not found\n");
}
