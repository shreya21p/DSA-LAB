
void bubblesort(int *arr, int size){
    for (int i=0;i<size-1;i++){
        for (int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void selectionsort(int *arr,int size){
    for (int i=0;i<size-1;i++){
        int minindex=i;
        for (int j=i+1;j<size;j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minindex];
        arr[minindex]=temp;
    }
}
void insertionsort(int *arr,int size){
    for(int i=1;i<size;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void displayarray(int *arr,int size){
    for (int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
