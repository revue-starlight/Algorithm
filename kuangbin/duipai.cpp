#include <bits/stdc++.h>
using namespace std;
int main(){
    system("g++ HDU1698.cpp -o test");
    system("g++ HDU1698ac.cpp -o std");
    system("g++ makedata.cpp -o data");
    while (1){
        system("./data > data.in");
        system("./std < data.in >std.out");
        system("./test < data.in >test.out");
        if (system("diff std.out test.out")){
            printf("Wrong Answer\n");
            return 0;
        }
        else printf("Accepted\n");
    }
}