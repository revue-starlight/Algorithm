#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
const int N = 5e5+10;
int a[N];
int tmp[N];
int ans = 0;
void merge(int l,int r){
    if (l==r) return;
    int mid=(l+r)>>1;
    merge(l,mid); merge(mid+1,r);
    int p = mid+1;
    int cnt=0;
    for (int i=l;i<=mid;i++){
        if (p==r+1 && a[r]<a[i]) ans+=r-mid;
        else {
            while (p<=r && a[p]<a[i]){
                tmp[cnt++] = a[p];
                p++;
            }
            ans+=p-1-mid;
        }
        tmp[cnt++] = a[i];
    }
    while (p<=r){
        tmp[cnt++]=a[p]; p++;
    }
    for (int i=l;i<=r;i++){
        a[i] = tmp[i-l];
    }
    return;
}
void solve(){
    ans = 0;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    merge(1,n);
    cout<<ans<<endl;

}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //cin>>T;
     T = 1;
    while(T--)solve();
}