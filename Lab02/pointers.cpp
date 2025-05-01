//Program to find whether a number is a palindrome, perfect, or armstrong
#include<cstdlib>
#include<cstdio>
#include<cmath>
bool ispal(int *numptr);
bool isarmstrong(int *numptr);
bool isperfect(int *numptr);
int main(){ //opening main function
    int *ch=(int*)malloc(sizeof(int));
    int *numptr=(int*)malloc(sizeof(int));
    while(true){
        printf("\nMENU\n");
        printf("1.Palindrome\n");
        printf("2.Armstrong\n");
        printf("3.Perfect\n");
        printf("4.exit\n");
        printf("Please enter your choice: ");
        scanf("%d",ch);
        switch(*ch){
            case 1:
                printf("Enter the number: ");
                scanf("%d",numptr);
                if(ispal(numptr)){
                    printf("Palindrome");
                }
                else{
                    printf("Not a palindrome");
                }
    break;
            case 2:
                printf("Enter the number: ");
                scanf("%d",numptr);
                if(isarmstrong(numptr)){
                    printf("armstrong");
	    }
                else{
                    printf("Not armstrong");
                }
                break;
            case 3:
               printf("Enter the number: ");
                scanf("%d",numptr);
                if(isperfect(numptr)){
                    printf("perfect");
                }
                else{
                    printf("Not perfect");
                }
                break;
            case 4:
                printf("Exiting the program");
                return 0;
            default:
                printf("Please enter a valid number: ");
        }
    }
    return 0;
}
//Check whether a number is palindrome
bool ispal(int *numptr){ 
    int *rn=(int*)malloc(sizeof(int));
    int *ld=(int*)malloc(sizeof(int));
    int *cpy=(int*)malloc(sizeof(int));
    *rn=0;
    *cpy=*numptr;
    while((*cpy)!=0){
        *ld=(*cpy)%10;
        *rn=((*rn)*10)+(*ld);
        *cpy=(*cpy)/10;
    }
    return ((*rn)==(*numptr));
    // return true;
}
//Check whether a number is armstrong
bool isarmstrong(int *numptr){    
    int *i=(int*)malloc(sizeof(int));
    int *nd=(int*)malloc(sizeof(int));
    int *cpy=(int*)malloc(sizeof(int));
    int *sum=(int*)malloc(sizeof(int));
    *sum=0;
    *cpy=(*numptr);
    while((*cpy)!=0){
        (*nd)++;
        (*cpy)/=10;
    }
    *cpy=*numptr;
    for((*i)=0;(*i)<*nd;(*i)++){
        int prod=pow((*cpy)%10,*nd);
        *sum+=prod;
        (*cpy)/=10;
    }
    return *numptr==*sum;
}
//To check if a number is perfect
bool isperfect(int *numptr){ 
    int *i=(int*)malloc(sizeof(int));
    int *sum=(int*)malloc(sizeof(int));
    for((*i)=0;(*i)<=*numptr/2;(*i)++){
        if((*numptr)%(*i)==0){
            (*sum)+=(*i);
        }
    }
    return (*numptr)==(*sum);
}
