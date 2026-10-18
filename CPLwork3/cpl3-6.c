#include <stdio.h>
#include <string.h>

int main(){
    int n, dec, isError;
    char s[31];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        dec=0;  isError=0;
        scanf(" %s", s);
        int l = strlen(s);
        for(int j=0; j<l; j++){
            if(s[j]=='Z') dec = dec*3 -1;
            else if(s[j]=='0' || s[j]=='1') dec = dec*3 + (s[j]-'0');
            else{
                printf("Radix Error\n");
                isError=1;
                break;
            }
        }
        if(!isError) printf("%d\n", dec);
    }
    return 0;
}