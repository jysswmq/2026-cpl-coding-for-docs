#include <stdio.h>
#include <string.h>
#define Is_A_Available side_case[0]>=2 && side_case[0]<=4
#define Is_B_Available side_case[1]>=2 && side_case[1]<=4
#define MAX 1007

int main(){
    int n;
    char s[MAX], nexts[MAX];
    scanf("%d", &n);
    scanf("%s", s);
    int len=strlen(s);
    for(int i=0; i<n; i++){
        memset(nexts, '.', len);

        for(int j=0; j<len; j++){
            int side_case[2]={0};                       //记录附近AB数量
            for(int side=-3; side<=3; side++){
                if(side==0) continue;                   //跳过自身
                if(j+side>=0 && j+side<len && s[j+side]=='A') side_case[0]++;
                else if(j+side>=0 && j+side<len && s[j+side]=='B') side_case[1]++;
            }
            
            switch(s[j]){
                case '.':{
                    if(side_case[0]==0 && Is_B_Available)
                        nexts[j]='B';
                    else if(side_case[1]==0 && Is_A_Available)
                        nexts[j]='A';
                    break;
                }
                case 'A':{
                    if( !side_case[1] && Is_A_Available )
                        nexts[j]='A';
                    break;
                }
                case 'B':{
                    if( !side_case[0] && Is_B_Available )
                        nexts[j]='B';
                    break;
                }
                default : return 0;
            }

        }

        strncpy(s, nexts, len);
    }
    printf("%s\n", s);
    return 0;
}