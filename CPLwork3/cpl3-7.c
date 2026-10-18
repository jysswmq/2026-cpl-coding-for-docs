#include <stdio.h>
#include <string.h>

int main(){
    int n, isError, isNeg, isCarry;
    long long dec;
    char s[16];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        dec=0; isError=0; isNeg=0;
        int j=0;
        char ter[32];
        scanf(" %s", s);
        int l = strlen(s);      //初始化

        if(s[0]=='-'){          //是否负数
            isNeg=1; j++;
        }
        
        while(j<l){             //把输入的string转化long long
            if(s[j]<'0'||s[j]>'9'){
                isError=1; break;
            }
            dec = dec*10 + s[j]-'0';
            j++;
        }

        if(isError){            //有错误提前结束
            printf("Radix Error\n");
            continue;
        }
        if(dec==0){             //输入零特别判断
            printf("%lld\n", dec);
            continue;
        }

        int ter_len=0;
        isCarry=0;
        while(dec>0){           //倒序存三进制
            ter[ter_len] = dec%3 + isCarry +'0';   //存入‘0’‘1’‘2’的ASCII
            isCarry=0;
            dec /= 3;
            switch(ter[ter_len]){    //是否进位
                case '1': case '0': break;
                case '2': isCarry=1; ter[ter_len]='Z'; break;
                case '3': isCarry=1; ter[ter_len]='0'; break;
                default: return 1;
            }
            ter_len++;
        }
        
        if(isCarry==1) ter[ter_len++]='1';//补充最高位进位检查
        ter[ter_len]='\0';

        if(isNeg)                       //负数处理
            for(int i=0; i<ter_len; i++){
                if(ter[i]=='Z') ter[i]='1';
                else if(ter[i]=='1') ter[i]='Z';
            }
        
        for(int i=ter_len-1; i>=0; i--) printf("%c", ter[i]);//倒序输出
        printf("\n");
    }
    return 0;
}