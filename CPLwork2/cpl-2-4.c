#include <stdio.h>
int main(){
    int n;
    char st[2000];
    scanf("%d", &n);
    scanf("%s", st);
    for(int i=0; i<n; i++)
        if(st[i]=='?')
            st[i]=st[n-i-1];
    printf("%s", st);
    return 0;
}