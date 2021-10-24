#include <bits/stdc++.h>
using namespace std;
int main(){
    int cnt = 0;
    system("g++ main.cpp -o main.exe");
    system("g++ std.cpp -o std.exe");
    system("g++ data.cpp -o data.exe");
    cout<<"initialize completed .... \n";
    while (1){
        cnt++;
        cout<<cnt<<"\n";
        system("./data.exe > data.in");
        system("./main.exe < data.in > test.out");
        system("./std.exe < data.in >  std.out");
        int e = system("diff test.out std.out --ignore-trailing-space");
        if (e) break;
    }
}