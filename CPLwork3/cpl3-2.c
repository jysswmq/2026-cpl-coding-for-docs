#include <stdio.h>
#define N 100


int main(){
    int n, k, IsDeath[N]={1}, death=1, p=0;
    scanf("%d%d", &n, &k);
    while(death<n){
        for(int count=0; count<k; ){
            p++;
            if(p>n) p-=n;
            if(!IsDeath[p]) count++;
        }
        IsDeath[p]=1;
        death++;
    }
    for(int i=1; i<=n; i++)
        if(!IsDeath[i])
            printf("%d", i);
    return 0;
}