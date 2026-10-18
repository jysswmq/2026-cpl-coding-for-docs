#include <stdio.h>
#include <string.h>
#define MAX 200
#define Blank 0
#define Filled 1
char map[20][MAX]={Blank};
int have_cleared=0, top_layer[20];

int max(int p, int l){                                      //找第p至p+l列最高值
    int m=top_layer[p];
    for(int i=1; i<l; i++)
        if(m<top_layer[p+i]) m=top_layer[p+i];
    return m;
}
void Kill(int layer, int w){                                //清除layer层，并下落
    int m=max(0, w);
    for(int i=layer; i<m; i++)
        for(int j=0; j<w; j++)
            map[j][i]=map[j][i+1];
    for(int i=0; i<w; i++) map[i][m]=Blank;
    for(int i=0; i<w; i++){
        if(top_layer[i]>layer) top_layer[i]--;
        else if(top_layer[i]==layer){
            top_layer[i]--;
            while(top_layer[i]>=0&&map[i][top_layer[i]]==Blank) top_layer[i]--;
        }
    }
}
void Clear_Line(int w){                                     //前k列，从上往下扫描
    for(int layer=max(0, w); layer>=0; layer--){
        int isFilled=1;
        for(int i=0; i<w; i++){
            if(map[i][layer]==Blank) isFilled=0;            //一行已满
        }
        if(isFilled){
            have_cleared++;
            Kill(layer, w);
        }
    }
}

int main(){
    int W, k, flag, pos;
    scanf("%d%d", &W, &k);
    memset(top_layer, -1, sizeof(top_layer));

    for(int i=0; i<k; i++){
        scanf("%d%d", &flag, &pos);
        pos--;
        if(flag){                                           //flag=1表示竖I
            for(int j=1; j<=4; j++) map[pos][top_layer[pos]+j]=Filled;
            top_layer[pos] += 4;
        }
        else{                                               //flag=0表示横I
            int top=max(pos, 4);
            for(int j=0; j<4; j++){
                map[pos+j][top+1]=Filled;
                top_layer[pos+j]=top+1;
            }
        }
        Clear_Line(W);
    }

    printf("%d %d\n", max(0, W)+1, have_cleared);
    for(int layer=max(0, W); layer>=0; layer--){
        for(int i=0; i<W; i++){
            if(map[i][layer]==Filled) printf("#");
            else printf(".");
        }
        printf("\n");
    }
    return 0;
}