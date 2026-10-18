#include <stdio.h>
#define INF 2147483647

int main(){
    int n, hill, last, step=1, IsUp=0;
    double slop=INF, Min=INF;
    scanf("%d", &n);
    scanf("%d", &last);
    for(int i=1; i<n; i++){
        scanf("%d", &hill);
        if(step==1) slop=hill-last;
        if(hill<last){
            if(slop<Min && slop>0)
                Min=slop;
            slop=INF;
            step=1;
        }else{
            if(step!=1) slop=( slop*(step-1)+(hill-last) )/step;
            step++;
            IsUp=1;
        }
        if(i==n-1 && slop>0 && slop<Min) Min=slop;
        last=hill;
    }
    if(IsUp) printf("%.2lf\n", Min);
    else printf("0.00\n");
    return 0;
}