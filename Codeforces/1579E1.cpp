#include <bits/stdc++.h>
using namespace std;
deque <int> dq;
int main(){
    int T;
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        while (n--){
            int x;
            cin>>x;
            if (dq.empty() || x<=dq.front()){
                dq.push_front(x);
            } else dq.push_back(x);
            
        }
        while (!dq.empty()){
                cout<<dq.front()<<" "; dq.pop_front();
        }
        cout<<"\n";
    }
}