#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mp[128];

void init(){
    for (int i=65;i<=75;i++) mp[i]=i-55;
    for (int i=48;i<58;i++) mp[i]=i-48;
}

ll trans_sys(string x,int sys){
    ll tmp=0;
    for (int i=0;i<x.length();i++){
        tmp=tmp*sys+mp[(int)x[i]];
    }
    return tmp;
}

int main(){
    string equ;
    init();
    while (cin>>equ){
        ll len=equ.length();
        string a,b,c;
        ll zuixiaojinzhi=2;
        ll i=0;
        while (equ[i]!='+' && equ[i]!='-' && equ[i]!='*' && equ[i]!='/') {a+=equ[i]; if (zuixiaojinzhi<=mp[(int)equ[i]]) zuixiaojinzhi=mp[(int)equ[i]]+1; i++;}
        char op=equ[i]; i++;
        while (equ[i]!='=') {b+=equ[i]; if (zuixiaojinzhi<=mp[equ[i]]) zuixiaojinzhi=mp[equ[i]]+1; i++;}
        i++;
        while (i<len){
            c+=equ[i]; if (zuixiaojinzhi<=mp[(int)equ[i]]) zuixiaojinzhi=mp[equ[i]]+1; i++;
        }

        bool bo=true;
        if (op=='+') {
            for (int i=zuixiaojinzhi;i<=16;i++){
                if (trans_sys(a,i)+trans_sys(b,i)==trans_sys(c,i)) {cout<<i<<endl; bo=false; break;}
            }
        }
        if (op=='-') {
            for (int i=zuixiaojinzhi;i<=16;i++){
                if (trans_sys(a,i)-trans_sys(b,i)==trans_sys(c,i)) {cout<<i<<endl; bo=false; break;}
            }
        }
        if (op=='*') {
            for (int i=zuixiaojinzhi;i<=16;i++){
                if (trans_sys(a,i)*trans_sys(b,i)==trans_sys(c,i)) {cout<<i<<endl; bo=false; break;}
            }
        }
        if (op=='/') {
            for (int i=zuixiaojinzhi;i<=16;i++){
                if (trans_sys(c,i)*trans_sys(b,i)==trans_sys(a,i)) {cout<<i<<endl; bo=false; break;}
            }
        }
        if (bo) cout<<"-1"<<endl;
    }
}