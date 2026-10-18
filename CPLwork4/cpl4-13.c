#include <stdio.h>
static char alpha[52]={'a','A','b','B','c','C','d','D','e','E','f','F','g','G','h','H','i','I','j','J','k','K','l','L','m','M','n','N','o','O','p','P','q','Q','r','R','s','S','t','T','u','U','v','V','w','W','x','X','y','Y','z','Z'};
int main(){
    int n, num[52]={0}, max=0;
    char ch;
    scanf("%d", &n);
    for(int i=0; i<n; i ++){
        scanf(" %c", &ch);
        if(ch>='a'&&ch<='z') ch=(ch-'a')*2;
        else ch=(ch-'A')*2+1;
        num[(int)ch]++;
        if(max<num[ch]) max=num[ch];
    }

    for(int i=max; i>0; i--){
        int started=0;
        for(int j=0; j<52; j++){
            if(j>0 && j%2==0 && num[j-1] && num[j] &&started) printf(" ");
            if(num[j]>=i){
                printf("=");
                started=1;
            }
            else if(num[j]){
                printf(" ");
                started=1;
            }
            else{
                while(j+1<52&&num[j+1]==0) j++;
                if(started) printf(" ");
            }
        }
        printf("\n");
    }

    int started=0;
    for(int i=0; i<52; i++){
        if(i>0 && i%2==0 && num[i-1] && num[i] &&started) printf("-");
        if(num[i]){
            printf("-");
            started=1;
        }
        else{
            while(i+1<52&&num[i+1]==0) i++;
            if(i==51&&num[i]==0) break;
            if(started) printf("-");
        }
    }
    printf("\n");

    started=0;
    for(int i=0; i<52; i++){
        if(i>0 && i%2==0 && num[i-1] && num[i] &&started) printf(" ");
        if(num[i]){
            printf("%c", alpha[i]);
            started=1;
        }
        else{
            while(i+1<52&&num[i+1]==0) i++;
            if(started) printf(" ");
        }
    }
    return 0;
}