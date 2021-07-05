    #include <iostream>
    using namespace std;
    #define int long long
    const int mod = 1e9+7;
    int fpow (int a, int b) { int ret = 1; while (b) { if (b & 1) ret = 1ll * ret * a % mod; a = 1ll * a * a % mod; b >>= 1; } return ret; }
    signed main(){
        int n,m;
        int T;
        cin>>T;
        int flag = 0;
        while (T--){
            cin>>n>>m;
            int cnt = 0;
            int flag=1;
            for (int i=1;i<=n;i++){
                string s;
                cin>>s;
                for (int j=0;j<s.length();j++){
                    if (s[j]=='0') flag = 0;
                    if (s[j]=='#') cnt++;
                }
            }
            if (!flag)
            cout<<fpow(2,cnt)<<endl;
            else
            cout<<fpow(2,cnt)-1<<endl;
        }
    }