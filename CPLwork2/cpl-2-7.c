#include <stdio.h>

int main(){
    int max, num, other=0, more=0;
    scanf("%d", &max);
    for(int i=0; i<=max; i++){
        scanf("%d", &num);
        if(num==0){
            if(more==0) other++;
            else more--;
        }
        else{
            more += (num-1);
        }
    }
    printf("%d", other);
    return 0;
}