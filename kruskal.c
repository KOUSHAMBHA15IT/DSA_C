#include<stdio.h>
#include<stdlib.h>

int find(int a,int par[]){
    if(par[a]==a){
        return a;
    }
    return par[a]=find(par[a],par);
}

void unionn(int a,int b,int par[],int rank[]){
    int parA=find(a,par);
    int parB=find(b,par);

    if(parA==parB){
        par[b]=parA;
        rank[a]++;
    }
    else if(parA>parB){
        par[b]=parA;
    }
    else{
        par[a]=parB;
    }
}

void swap(int a[],int b[],int size){
    int temp[size];
    for(int i=0;i<size;i++){
        temp[i]=a[i];
    }
    for(int i=0;i<size;i++){
        a[i]=b[i];
    }
    for(int i=0;i<size;i++){
        b[i]=temp[i];
    }
}

void sort(int graph[][3],int E){
    for(int i=0;i<E-1;i++){
        for(int j=i+1;j<E;j++){
            if(graph[i][2]>graph[j][2]){
                swap(graph[i],graph[j],3);
            }
        }
    }
}

void krushkal(int graph[][3],int V,int E){
    int par[V];
    int rank[V];
    for(int i=0;i<V;i++){
        par[i]=i;
        rank[i]=0;
    }

    sort(graph,E);

    int finalCost=0;
    for(int i=0;i<E;i++){
        int findSrc=find(graph[i][0],par);
        int findDest=find(graph[i][1],par);

        if(findSrc!=findDest){
            unionn(findSrc,findDest,par,rank);
            finalCost+=graph[i][2];
        }
    }
    printf("FinalCost = %d",finalCost);
}

void main(){
    int V,E;
    printf("enter the number of vertices : ");
    scanf("%d",&V);
    printf("enter the number of edges : ");
    scanf("%d",&E);

    int graph[E][3];

    printf("enter the edge info in the format soource,destination,weight \n");
    for(int i=0;i<E;i++){
        printf("edge %d :",(i+1));
        scanf("%d,%d,%d",&graph[i][0],&graph[i][1],&graph[i][2]);
    }

    krushkal(graph,V,E);
}
