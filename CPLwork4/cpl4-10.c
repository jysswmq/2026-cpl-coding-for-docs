#include <stdio.h>
#define MAX 15

char IsStand(char p[][MAX], int i, int j){
    if(( p[i][j-1] &&  p[i][j] &&  p[i][j+1] )
    || ( p[i][j-1] && !p[i][j] && !p[i][j+1] )
    || (!p[i][j-1] && !p[i][j] && !p[i][j+1] ) )
        return 0;
    else return 1;
}
int main(){
    int m, n;
    char Pattern[MAX][MAX]={0};
    scanf("%d%d", &m, &n);
    scanf("%s", &Pattern[0][1]);
    for(int i=1; i<=n; i++) Pattern[0][i]-=48;
    Pattern[0][n+1]=0;
    for(int i=1; i<m; i++){
        for(int j=1; j<=n; j++){
            Pattern[i][j]=IsStand(Pattern, i-1, j);
            printf("%d", Pattern[i][j]);
        }
        printf("\n");
    }
    return 0;
}