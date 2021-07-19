#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+17;
// struct Node{
//     int val,l,r;
// } tree[N<<3];
struct aaa{
    int val,id;
    const bool operator < (const aaa &rhs) const {
        return id<rhs.id;
    }
}a[N];

struct Listpoint{
    int id;
    Listpoint *next,*last;
};
Listpoint *head,*endd,*normal;
Listpoint *aa[N];
int siz;
int ans[N];
int main(){
    freopen("make.in","r",stdin);
    freopen("2.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        cin>>a[i].id>>a[i].val;
    }
    head = (Listpoint*)malloc(sizeof(Listpoint));
    head->id = 0;
    head->last = NULL;
    head->next = NULL;
    endd = head;
    siz = 0;
    sort(a+1,a+1+m);
    aa[0]=head;
    int now = 1;
    for (int i=1;i<=n;i++){
        normal = (Listpoint*)malloc(sizeof(Listpoint));
        if (a[now].id!=i){
            normal->id = i;
            normal->last = aa[siz];
            normal->next = aa[siz]->next;
            if (aa[siz]->next!=NULL) aa[siz]->next->last = normal;
            aa[siz]->next = normal;
            aa[++siz]=normal;
        } else {
            int val = a[now].val;
            if (val>siz+1) {
                cout<<-1<<endl;
                return 0;
            } else {
                normal->id = i;
                normal->last = aa[val-1];
                if (aa[val-1]->next!=NULL) normal->next = aa[val-1]->next;
                aa[val-1]->next = normal;
                if (aa[val-1]->next!=NULL) aa[val-1]->last = normal;
                aa[val] = normal;
                siz = val; 
            }
            now++;
        }
    }
    Listpoint *s=head;
    int cnt = 0;
    while (s!=NULL){
        int id = s->id;
        ans[id]=cnt;
        s = s->next;
        cnt++;
    }
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}