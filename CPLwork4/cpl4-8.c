#include <stdio.h>
#define MAX 100

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void Backward(int *L, int *P){
    *P += *L;
    swap(L, L+2);
}
void Forward(int *L, int *P){
    *P -= *(L+2);
    swap(L, L+2);
}
void Right(int *L, int *P){
    *(P+1) += *(L+1);
    swap(L+1, L+2);
}
void Left(int *L, int *P){
    *(P+1) -= *(L+2);
    swap(L+1, L+2);
}

int main(){
    int L[3], P[2]={0};//L分别表示与x，y，z轴平行的边长，P表示xyz坐标都最小的点坐标
    char op[MAX]={0};
    scanf("%d%d%d", &L[0], &L[1], &L[2]);
    scanf("%s", op);
    int i=0, JUMP=1;
    while(JUMP){
        switch(op[i]){
            case 'W': Forward(L, P); break;
            case 'S': Backward(L, P); break;
            case 'A': Left(L, P); break;
            case 'D': Right(L, P); break;
            default : JUMP=0;
        }
        i++;
    }
    printf("%d %d %d %d", P[0], P[0]+L[0], P[1], P[1]+L[1]);
    return 0;
}