#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+100;
struct PP{
    int need,half;
    const bool operator < ( const PP &b) const{
        return half<b.half;
    }
}item[N];
signed main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>item[i].need>>item[i].half;
    }
    sort(item,item+n);
    int i = 0;
    int j = n-1;
    int sum = 0;
    int cost = 0;
    while (1){
        while (i<j && sum<item[i].half){
            if (item[j].need<=(item[i].half-sum)){
                sum+=item[j].need;
                cost += (2*item[j].need);
                item[j].need = 0;
                j--;
            }
            else {
                cost += (2* (item[i].half - sum));
                item[j].need -= (item[i].half - sum);
                sum = item[i].half;
            }
        }
        if (i==j){
            int needtohalf = item[i].half - sum;
            if (needtohalf <= 0){
                cost += item[i].need;
            } else {
                if (needtohalf>=item[i].need){
                    cost += (item[i].need*2);
                } else {
                    int price2 = needtohalf;
                    int price1 = item[i].need-needtohalf;
                    cost+=(price1+price2*2);
                }
            }
            break;
        } else {
            cost += item[i].need;
            sum += item[i].need;
            item[i].need = 0;
            i++;
        }
    }
    cout<<cost<<endl;
    return 0;
}