#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 300000
unsigned long long Reverse(unsigned long long n){                     //翻转数字
    unsigned long long rev=0;
    while(n>0){
        rev = rev*10 + n%10;
        n /= 10;
    }
    return rev;
}
unsigned long long Calc(unsigned long long n, size_t l){              //计算子串和的反序数
    unsigned long long sum=0;
    for(int i=1; i<=l; i++){
        unsigned long long tens=10;
        for(int j=i; j<=l; j++){
            sum += n % tens;
            if (tens <= 1000000000000000000ULL) tens *= 10;
        }
        n/=10;
    }
    return Reverse(sum);
}
int main(){
    char str[MAX];
    size_t len, n_len;
    unsigned long long n;
    while(scanf("%s", str) != EOF){
        n=0; n_len=0;
        char process[MAX]={0};
        len=strlen(str);
        for(int i=0; i<=len; i++){
            if(isalpha(str[i]) || str[i]=='\0'){
                if(n_len>0){
                    snprintf(process+strlen(process), sizeof(process)-strlen(process), "%llu", Calc(n, n_len));
                    n=0; n_len=0;
                }
                process[strlen(process)] = str[i];
            }
            else if(isdigit(str[i])){
                n = n*10 + (str[i]-48);
                n_len++;
            }
        }
        printf("%s\n", process);
    }
    return 0;
}