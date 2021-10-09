#include <bits/stdc++.h>
using namespace std;
int skill[10][6][3];
int skill_detail[10][3] = {{0,0,0},{0,0,1},{0,0,2},{1,1,1},{0,1,1},{1,1,2},{2,2,2},{0,2,2},{1,2,2},{0,1,2}};
int dp[6];
int newdp[6];
int invert[256];
int compare (int pre[],int now[]){
    if (pre[0]==now[0] && pre[1]==now[1] && pre[2]==now[2]) return 0;
    if (pre[1]==now[0] && pre[2]==now[1]) return 1;
    if (pre[2]==now[0]) return 2;
    return 3;
}
void init(){
    for (int i=0;i<10;i++){
        int aa[3]={0,1,2};
        int ret = 0;
        do {
            skill[i][ret][0]=skill_detail[i][aa[0]]; skill[i][ret][1]=skill_detail[i][aa[1]]; skill[i][ret][2]=skill_detail[i][aa[2]];
            ret++;
        } while (next_permutation(aa,aa+3));
    }
}
int main(){
    init();
    string s;
    cin>>s;
    invert['Y']=0;
    invert['V']=1;
    invert['G']=2;
    invert['C']=3;
    invert['X']=4;
    invert['Z']=5;
    invert['T']=6;
    invert['F']=7;
    invert['D']=8;
    invert['B']=9;
    for (int i=0;i<6;i++) dp[i]=3;
    for (int i=1;i<s.length();i++){
        int pre = invert[s[i-1]];
        int now = invert[s[i]];
        for (int j=0;j<6;j++) newdp[j]=numeric_limits<int>::max();
        for (int j=0;j<6;j++){
            for (int k=0;k<6;k++){
                newdp[j]=min(newdp[j],dp[k]+compare(skill[pre][k],skill[now][j]));
            }
        }
        for (int j=0;j<6;j++)
            dp[j]=newdp[j];
    }
    int minn = numeric_limits<int>::max();
    for (int i=0;i<6;i++) minn = min(minn,dp[i]);
    minn+=s.length();
    cout<<minn<<"\n";
    return 0;
}