#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
int T,n;
struct mouse{
    int x,y;
}mice[N];
map <int,int> col,row;
unordered_set <int> rowid[2],colid[2];
int maxrow[2],maxcol[2];
void getmax(){
    memset(maxrow,0,sizeof(maxrow)); 
    memset(maxcol,0,sizeof(maxcol));
    for (auto s :row){
        if (s.second > maxrow[0]){
            maxrow[1] = maxrow[0];
            maxrow[0] = s.second;
        } else {
            if (s.second<maxrow[0] && s.second>maxrow[1]){
                maxrow[1] = s.second;
            }
        }
    }
    for (auto s :col){
        if (s.second > maxcol[0]){
            maxcol[1] = maxcol[0];
            maxcol[0] = s.second;
        } else {
            if (s.second<maxcol[0] && s.second>maxcol[1]){
                maxcol[1] = s.second;
            }
        }
    }
}



void getmaxid(){
    for (auto s:row){
        if (s.second == maxrow[0]) rowid[0].insert(s.first);
        if (s.second == maxrow[1]) rowid[1].insert(s.first);
    }
    for (auto s:col){
        if (s.second == maxcol[0]) colid[0].insert(s.first);
        if (s.second == maxcol[1]) colid[1].insert(s.first);
    }
}


int getk(){
    if (n==1) {
        return 1;
    }
    int kk = maxrow[0]+maxcol[0];
    if (kk == 2){
        return 2;
    } else {
        int originalCnt = rowid[0].size()*colid[0].size();
        for (int i=1;i<=n;i++){
            if (rowid[0].find(mice[i].x)!= rowid[0].end() && colid[0].find(mice[i].y)!=colid[0].end()){
                originalCnt--;
            }
        }
        if (originalCnt == 0) return kk-1;
        return kk;
    }
}

void getans(){
    int kk = maxrow[0]+maxcol[0];
    int originalCnt = rowid[0].size()*colid[0].size();
    for (int i=1;i<=n;i++){
        if (rowid[0].find(mice[i].x)!= rowid[0].end() && colid[0].find(mice[i].y)!=colid[0].end()){
            originalCnt--;
        }
    }
    if (originalCnt > 0){
        cout<<kk<<" "<<originalCnt<<"\n";
        return;
    } 

    originalCnt = rowid[0].size()*colid[0].size();
    int addCnt = 0;
    if (rowid[1].size()>0 && maxrow[1]+maxcol[0] == kk-1){
        addCnt += rowid[1].size()*colid[0].size();
        for (int i=1;i<=n;i++)
            if (rowid[1].find(mice[i].x)!= rowid[1].end() && colid[0].find(mice[i].y)!=colid[0].end()){
                addCnt--;
            }
    }

    if (colid[1].size()>0 && maxrow[0]+maxcol[1] == kk-1){
        addCnt += rowid[0].size()*colid[1].size();
        for (int i=1;i<=n;i++)
            if (rowid[0].find(mice[i].x)!= rowid[0].end() && colid[1].find(mice[i].y)!=colid[1].end()){
                addCnt--;
            }
    }
    cout<<kk-1<<" "<<addCnt + originalCnt<<"\n";
    return;
}
int tt = 0;
void solve(){
    rowid[0].clear(); col.clear(); rowid[1].clear();
    colid[0].clear(); row.clear(); colid[1].clear();
    cout<<"Case "<<++tt<<": ";
    cin>>n;
    int aa,bb;
    for (int i=1;i<=n;i++){
        cin>>aa>>bb;
        mice[i] = {aa,bb};
        row[aa]++; col[bb]++;
    }
    getmax();
    getmaxid();
    int k = getk();
    if (k==1){
        cout<<"1 1\n";
    } else if (k==2) {
        cout<<"2 "<<n*(n-1)/2<<'\n';
    } else {
        getans();
    }
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)solve();
}