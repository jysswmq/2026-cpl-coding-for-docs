#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(){
    int N;
    scanf("%d", &N);

    bool *isPrime = malloc((N+1)*sizeof(bool));

    for (int i=0; i<=N; i++) isPrime[i] = true;
    isPrime[0]=false; isPrime[1]=false;

    for (int i=2; (long long)i*i<=N; i++)
        if (isPrime[i])
            for(int j=i*i; j<=N; j+=i)
                isPrime[j] = false;

    int cnt=0;
    for(int i=2; i<=N; i++)
        if(isPrime[i]) cnt++;
    
    printf("%d", cnt);

    free(isPrime);
    return 0;
}