#include <stdio.h>
int main(){
    int week, total;
    scanf("%d %d", &total, &week);
    week= week==1 ? 7 : week-1;
    for(int i=0; i<week-1; i++) printf("    ");
    for(int day=1; day<=total; ){
        while(week<=7&&day<=total){
            printf("%2d  ", day);
            week++;
            day++;
        }
        week=1;
        printf("\n");
    }
    return 0;
}