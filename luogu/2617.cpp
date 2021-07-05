// 动态区间第k小
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
struct Node{
    int l,r,sum;
}t[N<<5];
int n,q,tree_cnt,a[N],o[N],len;
int rt[N][N];
int pre_modify(int x,int val){
    for (int i = x;i;i=i-((i)&(-i))) modify(1,len,rt[i][cnt[i]],rt[i][cnt[i]],len);
}
int main(){
    cin>>n>>q;
    for (int i=1;i<=n;i++) {cin>>a[i]; o[i]=a[i];}
    sort(o+1,o+1+n);
    len = unique(o+1,o+1+n)-o-1;
    for (int i=1;i<=len;i++) pre_modify(i,1);
    return 0;
}