#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

using namespace std;
const int N = 5000;
int a[N+10][N+10];
map <pair<int,int> ,int> mp;
int main(){
    // struct timeval time;
    // gettimeofday(&time, NULL);
    // printf("s: %ld, ms: %ld\n", time.tv_sec, (time.tv_sec*1000 + time.tv_usec/1000));
    for (int i=1;i<=N;i++){
        a[i][1]=a[1][i]=a[i][i]=1;
    }
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            if (a[i][j]==0){
                for (int dlt=1;dlt<=N;dlt++){
                    int u = i+dlt;
                    int v = j+dlt;
                    if (u<=N) a[u][j]=1;
                    if (v<=N) a[i][v]=1;
                    if (u>N && v>N) break;
                }
        
                for (int u=1;u<=N;u++){
                    if (i+u>N) break;
                    int xx = i+u;
                    for (int p=1;p<=N;p++){
                        int yy = j + p*u;
                        if (yy>N) break;
                        a[xx][yy]=1;
                    }
                }
                for (int u=1;u<=N;u++){
                    if (j+u>N) break;
                    int yy = j+u;
                    for (int p=1;p<=N;p++){
                        int xx = i + p*u;
                        if (xx>N) break;
                        a[xx][yy]=1;
                    }
                }
            }
        }
    }
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            if (a[i][j]==0) {
                mp[{min(i,j),max(i,j)}]++;
            }
        }
    }
    freopen("a.in","w",stdout);
    for (auto s:mp){
         cout<<"a["<<s.first.first<<"]["<<s.first.second<<"]=";
    }
    //  int ms1 =  (time.tv_sec*1000 + time.tv_usec/1000);
    // gettimeofday(&time, NULL);
    // int ms2 = (time.tv_sec*1000 + time.tv_usec/1000);
    // printf("s: %ld, ms: %ld\n", time.tv_sec, (time.tv_sec*1000 + time.tv_usec/1000));
    // cout<<ms2-ms1<<endl;

}