#include <bits/stdc++.h>
using namespace std;
int bucket[26][200005];
int main(){
    int T;
    cin>>T;
    while (T--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int len = n/k;
        swap(len,k);
        int p = len / 2;
        for (int i=0;i<p;i++){
            for (int j=0;j<26;j++) bucket[j][i]=0;
        }
        for (int i=0;i<k;i++){
            for (int j=0;j<p;j++){
                int posl = i*len+j;
                int posr = (i+1)*(len)-j-1;
                bucket[s[posl]-'a'][j]++;
                bucket[s[posr]-'a'][j]++;
            }
        }
        int ans=0;
        for (int i=0;i<p;i++){
            int maxx = 0;
            for (int j=0;j<26;j++){
                maxx = max(maxx,bucket[j][i]);
            }
            ans += 2*k-maxx;
        }
        int b2[26];
        memset(b2,0,sizeof(b2));
        if (len%2 == 1){
            int maxx = 0;
            for (int i=0;i<k;i++){
                int pos = i*len+p;
                b2[s[pos]-'a']++;
                maxx = max(maxx,b2[s[pos]-'a']);
            }
            ans+=(k-maxx);
        }
        cout<<ans<<endl;
    }
}