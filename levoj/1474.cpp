#include <bits/stdc++.h>
using namespace std;
#define int long long
priority_queue <int> pq;
void solve(int n){
    
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        pq.push(-x);
    }
    int ans = 0;
    while (1){
        int m = pq.top();
        pq.pop();
        if (pq.empty()){
            cout<<-m<<"\n";
            return;
        }
        int n = pq.top();
        pq.pop();
        pq.push((n*m+1)*-1);
    }
}
int main(){
    int n;
    while (cin>>n) solve(n);
}