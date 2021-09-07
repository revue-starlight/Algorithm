#include<bits/stdc++.h>
using namespace std;
int main(){
    int i;
    cout<<"g++ test.cpp\n";
    system("g++ test.cpp -o test");

    cout<<"g++ data.cpp\n";
    system("g++ data.cpp -o data");
    cout<<"g++ std.cpp\n";
    system("g++ std.cpp -o std");
  for (i=1;;i++){
        printf("The result of No. %d Case is:  ",i);
        system("./data >data.in");
        system("./std <data.in >std.out");
        system("./test <data.in >test.out" );
        if (system("diff std.out test.out  --ignore-trailing-space")){
            printf("Wrong Answer\n");
            return 0;
        }
        else printf("Accepted\n");
    }
    return 0;
}