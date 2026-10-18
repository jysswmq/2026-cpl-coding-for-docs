#include <stdio.h>
#include <stdlib.h>
int main(){
    long long guess=2147483647, border[2]={-1, 4294967296};
    char cmp[10];
    while(1){
        printf("%lld\n", guess);
        fflush(stdout);
        scanf("%s", cmp);
        switch(cmp[0]){
            case 'G':
                border[1]=guess; break;
            case 'L':
                border[0]=guess; break;
            case 'E': case 'O': return 0;
            default: return 1;
        }
        guess=(border[0]+border[1])/2;
    }
    return 0;
}