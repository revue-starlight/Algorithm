#include <bits/stdc++.h>
using namespace std;
const int a[]={0,1,2,1,1,4,2,2,1,4,2,4,1,4,4,4,4,2,2,3,1,0,1,1,2,4,1,1,3,1,3,3,4,3,2,3,3,1,4,4,2,1,1,2,2,4,4,2,4,4,4,3,2,3,4,1,4,4,3,4,1,4,2,4};
//               虽然今天是 儿童节但还是需要去上幼儿园老  师们今天格外  亲切给班里每位小朋友买根 棒棒 糖今天学习 到四则运算 看起来好 简单但是每次都算不 对
    int b[100];
    int n;
    int c[100];
    int now;
int main(){
    cin>>n;
    for (int i=0;i<n;i++) cin>>b[i];
    for (int i=0;i<n-1;i++) cin>>c[i];
    now=b[0];
    for (int i=0;i<n-1;i++)
    {
        if (a[c[i]]==1) now=b[i+1]+now;
        if (a[c[i]]==2) now=now-b[i+1];
        if (a[c[i]]==3) now=b[i+1]*now;
        if (a[c[i]]==4) now=now/b[i+1];
    }
    cout<<now;
}