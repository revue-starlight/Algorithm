#include <bits/stdc++.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>



using namespace std;
const int N = 100;
int status[N+10][N+10];
int vis[N+10][N+10];
map <pair<int,int> ,int> mp;
inline void work(int x,int y){


    if (min(x,y)==0 || max(x,y)%min(x,y)==0){
        status[x][y]=1;
        return;
    }
    int bo = 1;
    for (int i=1;i<=x;i++){
        int p = 0;
        while (p*i<=y){
            bo = bo & status[x-i][y-p*i];
            p++;
        }
    }
    for (int i=1;i<=y;i++){
        int p = 0;
        while (p*i<=x){
            bo = bo & status[x-p*i][y-i];
            p++;
        }
    }
    if (bo==1) {
        status[x][y]=0;
    } else {
        status[x][y]=1;
    }
}

int main(){
     struct timeval time;
 
    /* 获取时间，理论到us */
    gettimeofday(&time, NULL);
    printf("s: %ld, ms: %ld\n", time.tv_sec, (time.tv_sec*1000 + time.tv_usec/1000));

    for (int i=0;i<=N;i++){
        for (int j=0;j<=N;j++) 
            work(i,j);
    }
    for (int i=0;i<=N;i++){
        for (int j=0;j<=N;j++){
            printf("%d",status[i][j]);
        }
        cout<<"\n";
    }
    for (int i=0;i<=N;i++){
        for (int j=0;j<=N;j++){
            if (status[i][j]==0) {
                mp[{min(i,j),max(i,j)}]++;
            }
        }
    }
    for (auto s:mp){
        cout<<s.first.first<<" "<<s.first.second<<endl;
        cout<<s.second<<endl;
    }




    int ms1 =  (time.tv_sec*1000 + time.tv_usec/1000);
    gettimeofday(&time, NULL);
    int ms2 = (time.tv_sec*1000 + time.tv_usec/1000);
    printf("s: %ld, ms: %ld\n", time.tv_sec, (time.tv_sec*1000 + time.tv_usec/1000));
    cout<<ms2-ms1<<endl;

}