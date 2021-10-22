#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
struct NODE{
    int id;
    int val;
};
queue <NODE> q;
struct Node{
    int u,v,next;
}e[N<<2];
int head[N],tot;
void add(int u,int v){e[++tot]={u,v,head[u]}; head[u]=tot;}
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        int uu,vv;
        cin>>uu>>vv;
        add(uu,vv);add(vv,uu);
    }
}