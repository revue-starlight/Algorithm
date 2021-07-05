#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int MX = 1e5+100;
struct Node{
    int l,r,ch;
}t[N<<5];
int n,rt[N],step,tree_cnt,len[N];
int type(char ch,int l,int r,int pre,int len){
    tree_cnt++; 
    int pos = tree_cnt;
    t[pos]=t[pre];
    int mid = (l+r)>>1;
    if (l==r){
        t[pos].ch=ch;
        return pos;
    }
    else {
        if (len<=mid) t[pos].l = type(ch,l,mid,t[pre].l,len);
        else t[pos].r = type(ch,mid+1,r,t[pre].r,len);
    }
    return pos;
}

char query(int pos,int l,int r,int k){
    int mid = (l+r)>>1;
    if (l==r) return (char)t[pos].ch;
    if (k<=mid){
        return query(t[pos].l,l,mid,k);
    }
    else{
        return query(t[pos].r,mid+1,r,k);
    }
}

int undo(int l,int r,int pre){
    tree_cnt++;
    t[tree_cnt] = t[pre];
    return tree_cnt;
}
int main(){
    cin>>n;
    while (n--){
        char ch;
        cin>>ch;
        if (ch=='T'){
            step++;
            len[step]=len[step-1]+1;
            char ch;
            cin>>ch;
            rt[step] = type(ch,1,MX,rt[step-1],len[step]);
        }
        if (ch=='Q'){
            int p;
            cin>>p;
            cout<<query(rt[step],1,MX,p)<<"\n";
        }
        if (ch=='U'){
            step++;
            int p;
            cin>>p;
            len[step]=len[step-p-1];
            rt[step] = undo(1,MX,rt[step-p-1]);
        }
    }
    return 0;
}