#include <stdio.h>
#define Contain 3


void DescendingOrder(int* a){
    int temp;
    for(int i=0; i<Contain; i++)
        for(int j=0; j<Contain-i-1; j++)
            if(a[j+1]>a[j]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
}

int main(){
    int a[Contain];
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    DescendingOrder(a);
    if(a[0] >= (a[1]+a[2])) printf("not triangle\n");
    else if(a[0]==a[1] && a[1]==a[2]) printf("equilateral triangle\n");
    else{
        int b[3]={a[0]*a[0],a[1]*a[1],a[2]*a[2]};
        if(b[0] == (b[1]+b[2])) printf("right triangle\n");
        else{
            if(b[0] > (b[1]+b[2])){
                printf("obtuse ");
                if(a[1]==a[2]) printf("isosceles ");
                printf("triangle\n");
            }
            else{
                printf("acute ");
                if(a[1]==a[2] || a[0]==a[1]) printf("isosceles ");
                printf("triangle\n");
            }
        }
    }

    return 0;
}