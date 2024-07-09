#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 

struct Link { 
    int hop, dest, wt; 
}; 

struct Network { 
    int H, L; 
    struct Link *link; 
}; 

int main() { 
    int H, L, S, i, j; 
    printf("Enter Number of Hops: "); 
    scanf("%d", &H); 
    printf("Enter Number of Links: "); 
    scanf("%d", &L); 
    printf("Enter Source Node: "); 
    scanf("%d", &S); 
    
    struct Network *n = (struct Network *)malloc(sizeof(struct Network)); 
    n->H = H; 
    n->L = L; 
    n->link = (struct Link *)malloc(L * sizeof(struct Link)); 
    int *dist = (int *)malloc(H * sizeof(int)); 

    for (i = 0; i < H; i++) { 
        dist[i] = INT_MAX; 
    } 
    dist[S] = 0; 

    for (i = 0; i < L; i++) { 
        printf("\nLink %d: enter source, destination and weight\n", i + 1); 
        scanf("%d", &n->link[i].hop); 
        scanf("%d", &n->link[i].dest); 
        scanf("%d", &n->link[i].wt); 
    } 

    // Bellman-Ford Algorithm
    for (i = 0; i < H - 1; i++) { 
        for (j = 0; j < L; j++) { 
            int u = n->link[j].hop; 
            int v = n->link[j].dest; 
            int wt = n->link[j].wt; 
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) { 
                dist[v] = dist[u] + wt; 
            }
        } 
    } 

    // Check for negative weight cycles
    for (i = 0; i < L; i++) { 
        int u = n->link[i].hop; 
        int v = n->link[i].dest; 
        int wt = n->link[i].wt; 
        if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) { 
            printf("Network contains negative weight cycle\n"); 
            free(n->link); 
            free(n); 
            free(dist); 
            return 0; 
        } 
    } 

    printf("\nHop\tDistance from Source\n"); 
    for (i = 0; i < H; i++) { 
        printf("%d\t%d\n", i, dist[i]); 
    } 

    free(n->link); 
    free(n); 
    free(dist); 
    return 0; 
}


//output
/*
Enter Number of Hops: 5
Enter Number of Links: 6
Enter Source Node: 0

Link 1: enter source, destination and weight
0 1 2

Link 2: enter source, destination and weight
0 2 4

Link 3: enter source, destination and weight
1 3 2

Link 4: enter source, destination and weight
2 4 3

Link 5: enter source, destination and weight
4 3 -5

Link 6: enter source, destination and weight
4 5 3

Hop	Distance from Source
0	0
1	2
2	4
3	2
4	7
*/