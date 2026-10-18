#include <stdio.h>
#define N 1000000007

int main(){
    long long mult=1, sum=1;
    int n;
    scanf("%d", &n);
    if(n==1){
        printf("1\n");
        return 0;
    }
    for(int i=1; i<n; i++){
        mult = mult*(i+1)%N;
        sum = (sum+mult)%N;
    }
    printf("%d\n", sum%N );
    return 0;
}