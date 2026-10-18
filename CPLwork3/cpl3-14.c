#include <stdio.h>
#include <string.h>
#define Contain 100

void Align(char *a, char *b){
    int la=strlen(a), lb=strlen(b);
    if(la>lb){
        int delta=la-lb;
        for(int i=lb; i>=0; i--) b[i+delta]=b[i];
        for(int i=0; i<delta; i++) b[i]='0';
    }
    else if(la<lb){
        int delta=lb-la;
        for(int i=la; i>=0; i--) a[i+delta]=a[i];
        for(int i=0; i<delta; i++) a[i]='0';
    }
}

int Compare(char *a, char *b){
    Align(a, b);
    int len=strlen(a);
    for(int i=0; i<len; i++){
        if(a[i]>b[i]) return 1;
        if(a[i]<b[i]) return 0;
    }
    return 1;
}

void ADD(char *a, char *b){
    int l=strlen(a), isCarry=0, temp;
    for(int i=l-1; i>=0; i--){
        temp = a[i]-'0';
        a[i] = (a[i]+b[i]+isCarry-96)%10+'0';
        isCarry = temp+b[i]+isCarry-'0' >= 10;
    }
    if(isCarry) printf("1");                        //最高位进位不储存了，直接输出补1
    printf("%s\n", a);
}

void MINUS(char *a, char *b, int isDivision){
    int l=strlen(a), isAbd=0, temp;
    for(int i=l-1; i>=0; i--){
        temp = a[i];
        a[i] = (a[i]-b[i]-isAbd+10)%10+'0';
        isAbd = temp-b[i]-isAbd < 0;
    }
    if(isDivision==0){
        int i=0;
        while(a[i]=='0') i++;                       //舍去前导零
        if(l-i==0) printf("0");                     //结果为0单独讨论
        for(; i<l; i++) printf("%c", *(a+i));
        printf("\n");
    }
}

void TIMES(char *a, char *b){
    int s[Contain]={0}, CarryNum[Contain]={0}, fzero=0;
    int la=strlen(a)-1, lb=strlen(b)-1, temp, topCarry=0;
    for(int i=la; i>=0; i--){
        for(int j=lb; j>=0; j--){
            temp = (a[i]-'0')*(b[j]-'0');
            s[i+j] += temp%10;
            if(i+j>0) CarryNum[i+j-1] += temp/10 + s[i+j]/10;
            else topCarry += temp/10 + s[0]/10;
            s[i+j] %= 10;
        }
    }
    for(int i=la+lb; i>=0; i--){
        s[i] += CarryNum[i];
        if(i) CarryNum[i-1] += s[i]/10;
        else topCarry += s[0]/10;
        s[i] = s[i]%10;
    }
    if(topCarry) printf("%d", topCarry);
    else while(s[fzero]==0 && fzero<=la+lb) fzero++;
    if(fzero>la+lb) printf("0");
    else for(int i=fzero; i<=la+lb; i++) printf("%d", s[i]);
    printf("\n");
}

void DIVIDE(char *a, char *b){
    char count[Contain]={0};
    int n=0;                                        //记录count最高位
    while(Compare(a, b)){
        MINUS(a, b, 1);
        int i=0;
        while(1){
            if(count[i]<9){
                count[i]++;
                if(i>n) n=i;
                break;
            }
            else{
                count[i]=0;
                i++;
            }
        }
    }
    if(n==0 && count[0]==0){
        printf("0\n");
        return;
    }
    for(int i=n; i>=0; i--) printf("%d", count[i]);
    printf("\n");
}

int main(){
    int n;
    char types, a[Contain], b[Contain];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s %c %s", a, &types, b);
        Align(a, b);
        switch(types){
            case '+': ADD(a, b); break;
            case '-': MINUS(a, b, 0); break;
            case '*': TIMES(a, b); break;
            case '/': DIVIDE(a, b); break;
            default: return 1;
        }
    }
    return 0;
}