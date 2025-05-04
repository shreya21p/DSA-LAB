//Program to find the number of winners in a given query
#include<stdio.h>

//Calculate the number of winners for each query
int calculateWinners(int players, int positions[], int num_of_pos){
    int min = positions[0];
    return (players < min) ? players : min-1;
}

int main(){
    int tests,num_of_pos,queries,winners;
    printf("Enter the number of test cases: ");
    scanf("%d",&tests);

    while(tests--){
        printf("Enter the number of positions(k) and number of queries(q) separated by space: ");
        scanf("%d %d",&num_of_pos,&queries);

        int positions[num_of_pos];
        printf("Enter the positions separated by space: ");
        for(int idx=0;idx<num_of_pos;idx++){
            scanf("%d",&positions[idx]);
        }
        int players[queries];
        printf("Enter the number of players in each query separated by space: ");
        for(int idx=0;idx<queries;idx++){
            scanf("%d",&players[idx]);
        }
        
        printf("The number of winners: ");
        for(int idx=0;idx<queries;idx++){
            winners = calculateWinners(players[idx],positions,num_of_pos);
            printf("%d ",winners);
        }
        printf("\n");
    }
    return 0;
}
