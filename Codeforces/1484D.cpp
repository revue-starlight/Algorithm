#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
struct Node{
    int tag,val,id;
    Node *p,*n,*pgcd,*ngcd;
};
void solve(){
    int n;
    cin>>n;
    int pos,minn;
    Node *head,*now;
    head = NULL;
    now = NULL;
    minn = numeric_limits <int> :: max();
    for (int i=1;i<=n;i++){cin>>a[i];if (a[i]<minn){minn=a[i]; pos=i;}}
    for (int i=1;i<=n;i++){
        Node *tmp;
        tmp = (Node*)malloc(sizeof(Node));
        if (i==1) head = tmp;
        tmp->tag = 0;
        tmp->id = i;
        tmp->val = a[i];
        tmp->p = now;
        if (now!=NULL)
            now->n = tmp;
        tmp->n = NULL;
        tmp->ngcd = tmp->pgcd = NULL;
        now = tmp;
    }
    head->p = now; now->n = head; // list to ring
    Node *lastgcd,*firstgcd;
    lastgcd = firstgcd = NULL;
    now = head;
    int tot = 0;
    while (1){
        if (__gcd(now->val,now->n->val)==1){
            now->tag = 1;
            tot++;
            if (lastgcd!=NULL)
                lastgcd->ngcd = now;
            now->pgcd = lastgcd;
            if (lastgcd==NULL) firstgcd = now;
            lastgcd = now;
        }
        now=now->n;
        if (now==head) break;
    }
    if (tot==0){
        cout<<"0\n";
        return;
    }
    firstgcd->pgcd=lastgcd;lastgcd->ngcd=firstgcd;
    vector <int> ans;
    now = firstgcd;
    while (1){
        if (now->tag!=1) break;
        ans.push_back(now->n->id);
        if (now->n->tag){
            tot--;
            now->n->pgcd->ngcd = now->n->ngcd;
            now->n->ngcd->pgcd = now->n->pgcd;
        }
        Node *tmp = now->n;
        now->n = tmp->n;
        tmp->n->p = now;

        if (__gcd(now->val,now->n->val)!=1){
            tot--;
            now->tag = 0;
            now->pgcd->ngcd = now->ngcd;
            now->ngcd->pgcd = now->pgcd;
        }
        if (tot==0)
            break;
        now = now -> ngcd;
    }
    cout<<ans.size()<<" ";
    for (auto &s:ans) cout<<s<<" ";
    cout<<"\n";
}
int main(){
    int T;
    cin>>T;
    while (T--) solve();
}