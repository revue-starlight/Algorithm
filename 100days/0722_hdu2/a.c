#include <stdio.h>
int main(){
    for (int i=1;i<=10;i++){
        int n = i;
        int ans = 0;
        while (n>>=1) ans++;
        printf("i:%d, log:%d\n",i,ans);

    }
}