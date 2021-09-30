#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;
inline void read(int &x){
    x = 0;
    char c = getchar();
    while(c<'0'||c>'9') c = getchar();
    while(c>='0'&&c<='9'){
        x = (x<<3)+(x<<1)+c-'0';
        c = getchar();
    }
}
unordered_map<int,int>mp;
struct EDGE{
    int u,v,next;
}e[N];
int T,n,i,typ,num,x,y,cnt,tot,head[N],ch[N],weight[N],start[N],length[N],cal[N];
queue <int> q;
void add(int x,int y){
    e[++tot]={x,y,head[x]}; head[x]=tot;
}
void solve(){
    cnt = 0; tot = 0; num = 0; 
    read(n);
    for (i=1;i<=n;i++) head[i]=0;
    for (i=1;i<=n;i++) weight[i]=0;
    for (i=1;i<=n;i++) cal[i]=0;
    for (i=1;i<=n;i++){
        read(typ);
        if (typ==1){
            read(num);
            start[i]=cnt;
            length[i]=num;
            while (num--)
                read(ch[cnt++]);
        } else {
            read(x); read(y);
            add(i,x); add(i,y);
        }
    }
    while (!q.empty()) q.pop();
    q.push(n);
    weight[n]=1;
    while (!q.empty()){
        int node = q.front(); q.pop();
        for (i=head[node];i;i=e[i].next){
            q.push(e[i].v);
            weight[e[i].v]+=weight[node];
        }
    }
    for (i=1;i<=n;i++){
        for (int p=0;p<length[i];p++){
            int now = start[i]+p;
            mp[now]+=weight[i];
        }
    }
    unordered_map<int,int>::iterator iter;
    int sum,maxx;
    maxx = -1;
    for (iter=mp.begin();iter!=mp.end();iter++){
        maxx = max(iter->second,maxx);
        sum += maxx;
    }
    if (maxx*2>=sum) printf("%lld\n",sum);
    else printf("%lld\n",2*(sum-maxx));
}
signed main()
{
    read(T);
    while (T--) solve();
    return 0;
}