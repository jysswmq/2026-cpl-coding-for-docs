#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if(n>100 || n<0){
        printf("Wrong score");
        return 0;
    }
    switch(n/10){
        case 10: case 9: printf("A"); break;
        case 8: printf("B"); break;
        case 7: printf("C"); break;
        case 6: printf("D"); break;
        default: printf("F"); break;
    }
    return 0;
}