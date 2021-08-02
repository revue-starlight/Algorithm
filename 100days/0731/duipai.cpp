#include<bits/stdc++.h>
using namespace std;
int main(){
    int i;
  for (i=1;;i++){
        printf("The result of No. %d Case is:  ",i);
        system("./data");
        system("./std");
        system("./test");
        if (system("diff data.out data2.out --ignore-trailing-space")){
            printf("Wrong Answer\n");
            return 0;
        }
        else printf("Accepted\n");
    }
    return 0;
}