#include <stdio.h>
int gcd(int a, int b){
    if(a==b||b==0) return a;
    else return gcd(b, a%b);
}
int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    if(a>b) printf("%d", gcd(a, b));
    else printf("%d", gcd(b, a));
    return 0;
}