#include <bits/stdc++.h>
using namespace std;
    int countSpecialSubsequences(vector<int>& nums) {
        int N = 1e5+10;
        int mod = 1e9+7;
        int dp2[N],dp1[N],dp0[N];
        int cnt[N][3];
        int f[N];
        f[0]=1;
        for (int i=1;i<N;i++){
            f[i]=2*f[i-1];
            f[i]%=mod;
        }
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        int len = nums.size();
        for (int i=0;i<len;i++){
            int pos = i+1;
            for (int j=0;j<3;j++) cnt[pos][j]=cnt[pos-1][j];
            cnt[pos][nums[i]]+=1;

            if (nums[i]==0){
                dp1[pos]=dp1[pos-1];
                dp2[pos]=dp2[pos-1];
            }
            if (nums[i]==1){
                dp1[pos]=(f[cnt[pos][0]]+mod-1)%mod+(2*dp1[pos-1])%mod;
                dp2[pos]=dp2[pos-1];
            }
            if (nums[i]==2){
                dp1[pos]=dp1[pos-1];
                dp2[pos]=dp1[pos-1]+(2*dp2[pos-1])%mod;
                dp2[pos]%=mod;
            }
        }
        return dp2[len];
    }
int main(){
    vector <int> vec = {0,1,2,0,1,2};
    countSpecialSubsequences(vec);
}