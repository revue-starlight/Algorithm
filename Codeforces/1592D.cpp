#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int head[N],tot;
struct Edge{
    int u,v,next;
}e[N<<2];
void add(int u,int v){e[++tot]={u,v,head[u]};head[u]=tot;}
int n;
vector <int> euler;
void dfs(int u,int fa){
    euler.push_back(u);
    for (int i=head[u];i;i=e[i].next){
        int v = e[i].v;
        if (v!=fa){
            dfs(v,u);
            euler.push_back(u);
        }
    }
}
int check(int l,int r){
    int output[r-l+2];
    for (int i=l;i<=r;i++){
        output[i-l+1] = euler[i];
    }
    sort(output+1,output+1+r-l+1);
    int n = unique(output+1,output+1+r-l+1)-output;
    cout<<"? "<<n-1<<" ";
    for (int i=1;i<n;i++){
        cout<<output[i]<<" ";
    }
    cout<<"\n";
    int x;
    cin>>x;
    return x;
}

int main(){
    cin>>n;
    for (int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        add(u,v); add(v,u);
    }
    dfs(1,0);
    int l = 0,r=euler.size()-1;
    pair<int,int> pp;
    int tar = check(l,r);
    while (l<r){
        if (l+1==r) break;
        int mid = (l+r)>>1;
        int tmp = check(l,mid);
        if (tmp==tar){
            pp = make_pair(l,mid);
            r = mid;
        } else {
            pp = make_pair(mid,r);
            l = mid;
        }
    }
    cout<<"! "<<euler[pp.first]<<' '<<euler[pp.second]<<"\n";
    return 0;
}