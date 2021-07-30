#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for (auto i=(x);i<=(y);++i)
#define dep(i,x,y) for (auto i=(x);i>=(y);--i)
#define fr first
#define sc second
typedef long long ll;
typedef pair<int,int> pii;
const int N = 1e5+10;
const int M = 1e5+10;
struct Node{
    int son[2];
    vector <int> vec;
}trie[N*18];
int n,q,l,r,a,b;
int c[N];

int main(){
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++) scanf("%d",&c[i]);
    int tot = 1;
    trie[1].son[0]=trie[1].son[1]=-1; trie[1].vec.clear();
    for (int i=1;i<=n;i++){
        int now = 1;
        for (int j=16;j>=0;j--){
            int w = ((c[i]>>j)&1);
            trie[now].vec.push_back(i);
            if (trie[now].son[w]==-1){
                trie[now].son[w]=++tot;
                trie[tot].son[0]=trie[tot].son[1]=-1;
                trie[tot].vec.clear();
            }
            now = trie[now].son[w];
        }
        trie[now].vec.push_back(i);
    }
    while (q--){
        scanf("%d%d%d%d",&l,&r,&a,&b);
        int now = 1,ans=0;
        dep(j,16,0){
            int w = ((b>>j)&1);
            if (w){
                int lson = trie[now].son[0];
                if (lson!=-1){
                    int posl = lower_bound(trie[lson].vec.begin(),trie[lson].vec.end(),l)-trie[lson].vec.begin();
                    int posr = upper_bound(trie[lson].vec.begin(),trie[lson].vec.end(),r)-trie[lson].vec.begin()-1;
                    ans +=posr-posl+1;
                }
            }
            now = trie[now].son[1];
            if (!now) break;
        }
        
    }
}