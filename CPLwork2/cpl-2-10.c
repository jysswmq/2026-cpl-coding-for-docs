#include <stdio.h>
#include <string.h>

#define Line 100

void ReverseArray(char *left, char *right){
    char temp;
    while(left<right){
        temp=*left;
        *left=*right;
        *right=temp;

        left++;
        right--;
    }
}


int main(){
    int n, k;
    char line[Line];
    scanf("%d", &n);
    while(getchar()!='\n')
    ;
    fgets(line, n+1, stdin);

    scanf("%d", &k);
    ReverseArray(line, line+k-1);
    ReverseArray(line+k, line+n-1);

    printf("%s", line);
    return 0;
}