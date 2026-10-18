#include <stdio.h>
#define contain 30

int main(){
    int n, bit[contain]={0};
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        int shift=i-1;
        while(shift<n){
            bit[shift]++;
            shift+=i;
        }
    }
    for(int i=0; i<n; i++){
        if(bit[i]%2) printf("%d ", i+1);
    }
    return 0;
}