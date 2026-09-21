#include <stdio.h>
int main()
{
    int n;
    int m;
    printf("enter");
    scanf("%d %d", &n, &m);
    int c;
    int d;
// array stores value from 0 to size-1 therefore to avoid the data loss ,we are just keeping till n+1
    int adj[n + 1][n + 1]; 
//having a adj[n+1][n+1] bcz we it is as 1 based indexing thats why we are having n+1
//Use adj[n+1][n+1] only when you’re using 1-based node numbering, so you can safely access adj[1] to adj[n] without errors.

// the loop is running from 1 in place of 0 because it is a one base node thats why we need to have it running from 1 other than that
// if u run from 0 whihc is not present then it will give me the error of out of bound
    for (c = 1; c <= n; c++)
    {
        //simple 1 based indexing thats why from 1 
        //if would have been 0 base indexing then from 0 we runned like 0 to n-1
        for (d = 1; d <= n; d++)
        {
            adj[c][d] = 0;
        }
    }
    /*⚠️ Adjacency Matrix Is Not About Number of Edges — It's About Possibilities
If you have n nodes:
There are n × n = n² possible pairs of connections.
So you need a full n x n matrix to cover all possible edge positions, even if most are empty (0).
✅ So adjacency matrix is not insufficient — in fact, it's often overkill, especially for sparse graphs.
    */

    for (c = 0; c < m; c++) // as we are taking the adjancy then it must run till the number of edges are present which is m not the number of nodes which is n
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Printing the adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 1; i <= n; i++) // Start from 1 (since nodes are from 1 to n)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}