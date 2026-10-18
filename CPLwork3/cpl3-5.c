#include <stdio.h>

int main(){
    int l, b, num;
    long long sum=0;
    char s[31];
    scanf("%d%d %s", &l, &b, s);
    for(int i=0; i<l; i++){
        if( (b<=10 && (s[i]<48 || s[i]>b+47)) || (b>10 && (s[i]<48 || (s[i]>57 && s[i]<65) || s[i]>b+55)) ){
            printf("Error");
            return 0;
        }
        if(s[i]<58) num=s[i]-48;
        else num=s[i]-55;
        sum = sum*b + num;
    }
    printf("%d", sum);
    return 0;
}