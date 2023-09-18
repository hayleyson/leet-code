#include <stdio.h>
#include <stdbool.h>

void dfsHelp(int node, bool *aVisited, int** aIsConnected, int aSize){
    if(aVisited[node]==true){return;}
    else{
        aVisited[node]=true;
        for(int i=0; i< aSize; i++){
            if(aIsConnected[node][i]==1){
                dfsHelp(i, aVisited, aIsConnected, aSize);
            }
        }
        return;
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){

    bool visited[isConnectedSize];
    for(int i=0; i<isConnectedSize; i++){
        visited[i]=false;
    }
    int nCircle=0;
    for(int i=0; i<isConnectedSize; i++){
        if(visited[i]==false){
            nCircle++;
            dfsHelp(i, visited, isConnected, isConnectedSize);
        }
    }
    return nCircle;
}



int main(){
    // int n=3;
    // int *myIsConnected[3] = { // parameter of type int**: https://stackoverflow.com/questions/41647445/incompatible-pointer-types-passing-int55-to-parameter-of-type-int
    //     (int[]){1,1,0}, 
    //     (int[]){1,1,0}, 
    //     (int[]){0,0,1}
    // };
    int n=3;
    int *myIsConnected[3] = {
        (int[]) {1,0,0},
        (int[]) {0,1,0},
        (int[]) {0,0,1}
    };
    int numProvinces = findCircleNum(myIsConnected, n, myIsConnected[0]);
    printf("num provinces : %d\n", numProvinces);
}