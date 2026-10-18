#include <stdio.h>
#define Blank -1
#define Border 0
#define MAX 15
static int vectors[4][2]={{1,0},{0,1},{-1,0},{0,-1}};//同向+2
int map[MAX][MAX]={0};

int Find_Out(int startI, int startJ, int direction){
    int newPos[2] = {startI+vectors[direction][0], startJ+vectors[direction][1]};
    while(map[newPos[0]][newPos[1]]==Blank){
        newPos[0] += vectors[direction][0];
        newPos[1] += vectors[direction][1];
    }
    return map[newPos[0]][newPos[1]]==Border;
}


int main(){
    int n, m;                           //map保证最外圈是0，数字消除后为-1，其他为1~maxnum
    int num[MAX*MAX/2+1][2][2]={0};     //num[n][a][b]记录数字n第a+1次出现所在行(b=0)列(b=1)位置
    scanf("%d%d", &n, &m);
    int maxnum=n*m/2;
    for(int i=1; i<=n; i++){            //输入
        for(int j=1; j<=m; j++){
            scanf("%d", &map[i][j]);
            if(num[map[i][j]][0][0]==0){
                num[map[i][j]][0][0]=i;
                num[map[i][j]][0][1]=j;
            }
            else{
                num[map[i][j]][1][0]=i;
                num[map[i][j]][1][1]=j;
            }
        }
    }
    
    for(int cur=1; cur<=maxnum; cur++){
        int i1=num[cur][0][0], j1=num[cur][0][1];
        int i2=num[cur][1][0], j2=num[cur][1][1];
        for(int k=0; k<4; k++){
            if(Find_Out(i1, j1, k) && Find_Out(i2, j2, k)){ //两个数以同方向连通外部
                printf("%d ", cur);
                map[i1][j1]=Blank;
                map[i2][i2]=Blank;                       //数字清除
                break;
            }
        }
    }
    return 0;
}