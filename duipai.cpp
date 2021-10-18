#include <bits/stdc++.h>
using namespace std;
int main(){
    int cnt = 0;
    system("g++ 1575L.cpp -o test.exe");
        system("g++ 1575Lac.cpp -o std.exe");
        system("g++ data.cpp -o data.exe");
    while (1){
        cnt++;
        cout<<cnt<<"\n";
        system("./data.exe > data.in");
        system("./test.exe < data.in > test.out");
        system("./std.exe < data.in >  std.out");
        int e = system("diff test.out std.out --ignore-trailing-space");
        if (e) break;
    }
}