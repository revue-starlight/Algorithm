#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
};
Node *a;
int n;
int len = 0;
void ins(){
    int pos,val;
    cin>>pos>>val;
    for (int i=len+1;i>=pos;i--){
        *(a+i)=*(a+i-1);
    }
    (a+pos)->val=val;
    len++;
}
void del(){
    int pos;
    cin>>pos;
    for (int i=pos;i<len;i++){
        *(a+i)=*(a+i+1);
    }
    len--;
}
void print(){
    for (int i=1;i<=len;i++){
        cout<<(a+i)->val<<" ";
    }
    cout<<"\n";
}
int main(){
    a = (Node*)malloc(100*sizeof(int));
    while (cin>>n){
        if (n==0) ins();
        if (n==1) del();
        if (n==2) print();
    }
}