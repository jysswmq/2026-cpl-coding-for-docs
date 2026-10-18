#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int abs(int a){
    return a>0 ? a : -a;
}

void print_RL(int x1, int x2){
    if(x1<x2)
        for(int i=0; i<x2-x1; i++) printf("R");
    else
        for(int i=0; i<x1-x2; i++) printf("L");
    
}

void print_UD(int y1, int y2){
    if(y1<y2)
        for(int i=0; i<y2-y1; i++) printf("U");
    else
        for(int i=0; i<y1-y2; i++) printf("D");
}

int main(){
    int xA, yA, xB, yB, xC, yC;
    scanf("%d%d%d%d%d%d", &xA, &yA, &xB, &yB, &xC, &yC);
    int dist=abs(xB-xA)+abs(yB-yA), IsNeedFurther=0;

    if(xA==xB && xC==xA && yC > min(yA, yB) && yC < max(yA, yB)){
        IsNeedFurther = 1;
        dist += 2;
    }
    else if(yA==yB && yC==yA && xC > min(xA, xB) && xC < max(xA, xB)){
        IsNeedFurther=1;
        dist+=2;
    }
    printf("%d\n", dist);

    if(IsNeedFurther){
        if(xA==xB){
            printf("R");
            print_UD(yA, yB);
            printf("L");
        }
        else{
            printf("U");
            print_RL(xA, xB);
            printf("D");
        }
    }
    else{
        int hit_path1 = 0;         //先水平后垂直
        if(yA==yC && xC >= min(xA, xB) && xC <= max(xA, xB)) hit_path1=1;
        if(xB==xC && yC >= min(yA, yB) && yC <= max(yA, yB)) hit_path1=1;
        if(!hit_path1){
            print_RL(xA, xB);
            print_UD(yA, yB);
        }
        else{
            print_UD(yA, yB);
            print_RL(xA, xB);
        }
    }
    return 0;
}