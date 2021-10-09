#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int rnk[N],a[N];
multiset <int> s;
multiset <int> :: iterator iter;
multiset <int> :: iterator itera;
multiset <int> :: iterator iterb;
multiset <int> :: iterator iterc;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin>>T;

    while (T--){
        s.clear();
        int n;
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>a[i]; 
        }
        int tot = 0 ;  
        for (int i=1;i<=n;i++){
            iter = s.begin();
            itera = lower_bound(s.begin(),s.end(),a[i]);

            int aa = distance(s.begin(),lower_bound(s.begin(),s.end(),a[i]));
            iter = s.end();
            itera = upper_bound(s.begin(),s.end(),a[i]);
            
            int bb = distance(upper_bound(s.begin(),s.end(),a[i]),s.end());
            tot+=min(aa,bb);
            s.insert(a[i]);
        }
        cout<<tot<<"\n";
    }
}