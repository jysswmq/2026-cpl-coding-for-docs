#include <stdio.h>
static int answer[12]={-1,2,-3,-4,-5,6,-7,8,9,-10,11,12};

int main(){
    int n, and=-1, or=0, xor=0, ques;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &ques);
        and &= answer[ques-1];
        or |= answer[ques-1];
        xor ^= answer[ques-1];
    }
    printf("%d %d %d", and, or, xor);
    return 0;
}