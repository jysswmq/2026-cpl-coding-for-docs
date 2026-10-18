#include <stdio.h>
#define MAX 1000000
int main(){
    int n, m, temp;
    char t[MAX]={0};
    scanf("%d", &n);
    m=2*n-1;
    for(int i=0; i<m; i++){
        scanf("%d", &temp);
        t[temp-1] = !t[temp-1];
    }
    for(int i=0; i<MAX; i++){
        if(t[i]){
            printf("%d", i+1);
            break;
        }
    }
    return 0;
}