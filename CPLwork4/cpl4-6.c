#include <stdio.h>
#define MAX 12
static int vectors[8][2]={{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};

int main(){
    int n, map[MAX][MAX]={0};
    char ch;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            scanf(" %c", &ch);
            if(ch=='*') map[i][j]=9;
        }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(map[i][j]!=9)
                for (int k=0; k<8; k++){
                    int newI = i+vectors[k][0];
                    int newJ = j+vectors[k][1];
                    if (map[newI][newJ]==9)
                        map[i][j]++;
                }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(map[i][j]==9) printf("*");
            else printf("%d", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}