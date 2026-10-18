#include <stdio.h>
#include <math.h>

int main(){
    int a, b;
    while (scanf("%d", &a) != EOF){
        char r[2]={-1, '\0'};
        scanf(" %[^ ]%d", r, &b);
        switch(r[0]){
            case '+': printf("%d\n", a+b); break;
            case '-': printf("%d\n", a-b); break;
            case '*': 
                    if(r[1]=='\0') printf("%d\n", a*b);
                    else if(r[1]=='*') printf("%d\n", (int)pow(a,b));
                    else return 1;
                    break;
            case '/': 
                    if(r[1]=='\0') printf("%d\n", a/b);
                    else if(r[1]=='*') printf("%.3lf\n", (double)a/b);
                    else return 1;
                    break;
            case '%': printf("%d\n", a%b); break;
            default: return 1;
        }
    }
    return 0;
}