#include <stdio.h>

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", a&b);
    printf("%d\n", a|b);
    printf("%d\n", a^b);
    printf("%d\n", ~a);
    printf("%d\n", a<<b);
    printf("%d\n", a>>b);
    printf("%d\n", (a>>b)&1);
    b=0;
    while(a){
        if(a&1) b++;
        a>>=1;
    }
    printf("%d", b);
    return 0;
}