#include <stdio.h>
#include <string.h>
#define Contain 100
#define Empty 100
int main(){
    int len, select=0;
    char s[Contain], mirror[Contain];

    scanf("%d\n%s", &len, s);

    for(int i=0; i<len; i++) mirror[i]=Empty;

    for(int i=0; i<len; i++){
        if(s[i]=='?'){
            if(s[len-i-1]=='?'){
                if(mirror[i]==Empty){
                    printf("%02d", select);
                    mirror[len-i-1]=select/10+select%10*10;
                    select=(select%10==9 ? (select+1)/10*11 : select+1);
                }
                else printf("%02d", (int)mirror[i]);
            }
            else printf("%c", s[len-i-1]);
        }
        else printf("%c", s[i]);
    }
    return 0;
}