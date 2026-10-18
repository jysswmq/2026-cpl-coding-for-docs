#include <stdio.h>
#define MAX 60
static int vectors[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int main(){
    int n, m, pos[2], len=0, step=0;
    char map[MAX][MAX]={0};
    scanf("%d%d%d%d", &n, &m, pos, pos+1);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf(" %c", &map[i][j]);
            if(map[i][j]=='#') len++;
        }
    }
    printf("%d\n", len);
    pos[0]--;
    pos[1]--;
    printf("%d %d\n", pos[0]+1, pos[1]+1);
    while(step<len-1){
        for(int i=0; i<4; i++){
            int newI=pos[0]+vectors[i][0];
            int newJ=pos[1]+vectors[i][1];
            if(newI>=0 && newI<n && newJ>=0 && newJ<m && map[newI][newJ]=='#'){
                map[pos[0]][pos[1]]='_';
                pos[0]=newI;
                pos[1]=newJ;
                printf("%d %d\n", newI+1, newJ+1);
                step++;
                break;
            }
        }
    }
    return 0;
}