#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int vis[10];
    int n,m;
    int ret;
    vector<vector<int>> student;
    vector<vector<int>> mentor;
    void work(int dep,int ans){
        if (dep==m) {
            ret = max(ret,ans);
            return;
        }
        for (int i=0;i<m;i++){
            if (!vis[i]){
                vis[i]=1;
                int p = 0;
                for (int j=0;j<n;j++){
                    if (student[dep][j]==mentor[i][j]) p++;
                }
                work(dep+1,ans+p);
                vis[i]=0;
            }
        }
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        student = students; mentor = mentors;
        ret = -1;
        m = students.size();
        n = students[0].size();
        memset(vis,0,sizeof(vis));
        work(0,0);
        return ret;
    }
};

int main(){
    Solution S;
    vector<vector<int>> v1 ={{0,1,0,1,1,1},{1,0,0,1,0,1},{1,0,1,1,0,0}};
     vector<vector<int>> v2 = {{1,0,0,0,0,1},{0,1,0,0,1,1},{0,1,0,0,1,1}};
    cout<<S.maxCompatibilitySum(v1,v2);
}