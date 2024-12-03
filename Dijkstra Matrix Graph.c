#include <stdio.h>
#include <stdlib.h>
#define INF 69000

int *dijkstraAlgo(int graph[][5], int startingVertex){
    int i, x, y, count = 0, minVertex = 0, min = INF;
    int *distanceArr = malloc(sizeof(int) * 5);
    int finalSet[5] = {0};
    int allNodes[5] = {0, 1, 2, 3, 4};
    
    if(distanceArr != NULL){
        finalSet[0] = startingVertex;
        count++;
        
        for(i = 0; i < 5; ++i){
            distanceArr[i] = graph[startingVertex][i];
        }
        
        for(i = 1; i < 5; ++i){
            for(x = 0; x < 5; ++x){
                for(y = 0; y < count && allNodes[x] != finalSet[y]; ++y){}
                if(y == count && distanceArr[allNodes[x]] < min){
                    min = distanceArr[allNodes[x]];
                    minVertex = allNodes[x];
                }
            }
        
        finalSet[count] = minVertex; 
        count++;
        
        for(x = 0; x < 5; ++x){
            for(y = 0; y < count && allNodes[x] != finalSet[y]; ++y){}
                if(y == count){
                    if(distanceArr[allNodes[x]] > distanceArr[minVertex] + graph[minVertex][allNodes[x]]){
                        distanceArr[allNodes[x]] = distanceArr[minVertex] + graph[minVertex][allNodes[x]];
                    }
                }
            }
            min = INF;
        }
    }
    return distanceArr;
}

void main() {
    int graph[5][5] = {
        {0, 10, INF, 30, 100},
        {10, 0, 50, INF, INF},
        {INF, 50, 0, 20, 10},
        {30, INF, 20, 0, 60},
        {100, INF, 10, 60, 0}
    };

    int* distances = dijkstraAlgo(graph, 0);

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\t%d\n", i, distances[i]);
    }
}