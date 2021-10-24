#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int bucket[1000][1000];
int main(){
    srand(time(NULL));
    int T = 10;
    cout<<T<<"\n";
    while (T--)
    {
        /* code */
    memset(bucket,0,sizeof(bucket));
    int n = rand()%10+1, m = rand()%n+1;
    cout<<n<<" "<<m<<"\n";
    for (int i=1;i<=m;i++){
        int u,v;
        u = rand()%n+1,v = rand()%n+1;
        while (bucket[u][v]==1){
            u = rand()%n+1,v = rand()%n+1;
        }
        bucket[u][v]=1;
        bucket[v][u]=1;
        cout<<u<<" "<<v<<'\n';
    }
    cout<<"\n";
    for (int i=1;i<=n;i++){
        int u,v;
        u = rand()%n+1,v = rand()%n+1;
        cout<<u<<" "<<v<<'\n';
    }
    }
}