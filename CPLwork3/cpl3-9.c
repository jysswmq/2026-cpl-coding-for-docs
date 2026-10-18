#include <stdio.h>
int main(){
    int n, max, step=0;
    scanf("%d", &n);
    max=n;
    while(n>1){
        n= n%2 ? 3*n+1 : n/2;
        max= n>max ? n : max;
        step++;
    }
    printf("%d %d", step, max);
    return 0;
}