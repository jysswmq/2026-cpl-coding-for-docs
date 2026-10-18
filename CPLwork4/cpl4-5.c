#include <stdio.h>
#define MAX 11

int main(){
    int m, n, p;
    int A[MAX][MAX]={0}, B[MAX][MAX]={0}, C[MAX][MAX]={0};
    scanf("%d%d%d", &m, &n, &p);
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &A[i][j]);
    for(int i=0; i<n; i++)
        for(int j=0; j<p; j++)
            scanf("%d", &B[i][j]);
    
    for(int i=0; i<m; i++)
        for(int j=0; j<p; j++)
            for(int k=0; k<n; k++)
                C[i][j]+=A[i][k]*B[k][j];
    
    for(int i=0; i<m; i++){
        for(int j=0; j<p; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    return 0;
}