#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int N = 2e5+10;
struct matrix{
    int a[2][2];
    matrix(){memset(a,0,sizeof(a)); a[0][0]=a[1][1]=1;}
    inline matrix operator *(const matrix &b)const{
        matrix c;
        c.a[0][0]=c.a[1][1]=0;
        for (int i=0;i<2;++i){
            for (int j=0;j<2;++j){
                for (int k=0;k<2;++k){
                    c.a[i][j]+=a[i][k]*b.a[k][j];
                    c.a[i][j]%=mod;
                }
            }
        }
        return c;
    }
};
void clear(matrix &a){
    a.a[0][0]=a.a[1][1]=1;
    a.a[1][0]=a.a[0][1]=0;
}
void pushdown(int x,int l,int r){
    int mid = (l+r)/2;
    wok(x<<1,l,mid,l,mid,t[x].tag);
    wok(x<<1|1,mid+1,r,mid+1,r,t[x].tag);
    clear(t[x].tag);
}



void pushup(int x){
    t[x].sm = (t[x<<1].sm + t[x<<1|1].sm)%mod;
    t[x].sum1[0] = (t[x<<1|1].sum1[0] + t[x<<1].sum1[0])%mod;
    t[x].sum1[1] = (t[x<<1|1].sum1[1] + t[x<<1].sum1[1])%mod;
    t[x].sum[0] = (t[x<<1].sum[0] + t[x<<1|1].sum[0])%mod;
    t[x].sum[1] = (t[x<<1].sum[1] + t[x<<1|1].sum[1])%mod;
}
void build(int x,int l,int r){
    if (l==r){
        t[x].sum[0]=a[l][0];
        t[x].sum[1]=a[l][1];
        t[x].sm = a[l][0]*a[l][1];
        t[x].sum1[0]=a[l][0]*a[l][0];
        t[x].sum1[1]=a[l][1]*a[l][1];
        return;
    }
    int mid = (l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}

int q(int x,int l,int r,int L,int R){
    if (L<=l && r<=R) return t[x].sum;
    int mid=(l+r)>>1;
    pushdown(x,l,r);
    int ans = 0;
    if (mid>=L) ans+=q(x<<1,l,mid,L,R);
    if (mid<R) ans+=q(x<<1|1,mid+1,r,L,R);
    return ans;
}

void upd(int x,int l,int r,int tag,int L,int R,int s){
    if (L<=l && r<=R){
        t[x].adtag[tag]+=x; t[x].adtag[tag]%=mod;
        t[x].sum1[tag]+=(r-l+1)*s*s%mod+2*s*t[x].sum[tag]%mod; t[x].sum1[tag]%=mod;
        t[x].sum[tag]+=((r-l+1)*s)%mod; t[x].sum[tag]%=mod;
        t[x].sm+=t[x].sum[tag^1]*s%mod; t[x].sm%=mod;
        return;
    }
    int mid=(l+r)>>1;
    pushdown(x,l,r);
    if (L<=mid) upd(x<<1,l,mid,tag,L,R,s);
    if (mid<R) upd(x<<1|1,mid+1,r,tag,L,R,s);
    pushup(x);
}

void wok(int x,int l,int r,int L,int R,matrix s){
    if (L<=l && r<=R){
        int sm = t[x].sm;
        int c = s.a[0][0],d=s.a[0][1],e=s.a[1][0],f=s.a[1][1];
        int xx = t[x].sum1[0],yy = t[x].sum1[1];
        t[x].sm = c*d*xx+t[x].sm*(c*f+e*d)+e*f*yy;
        t[x].sm %=t[x].sm;
        t[x].sum1[0] = xx*c*c + sm*c*e*2 + yy*e*e;
        t[x].sum1[1] = xx*d*d + sm*d*f*2 + yy*f*f;
        xx = t[x].sum[0],yy=t[x].sum[1];
        t[x].sum[0] = c*xx+e*yy;
        t[x].sum[1]= d*xx+f*yy;
        xx = t[x].adtag[0],yy = t[x].adtag[0];
        t[x].adtag[0]=(xx*s.a[0][0]+yy*s.a[1][0]);
        t[x].adtag[1]=(xx*s.a[0][1]+yy*s.a[1][1]);

    }
}

matrix rev,wk;
struct SEG{
    int sum[2],sm,sum1[2],adtag[2];
    matrix tag;
}t[N<<2];
int a[N][2];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=0;j<2;j++) cin>>a[i][j];
    }
    build(1,1,n);
    int m;
    cin>>m;
    int l,r,tag,x,opt;
    while (m--){
        cin>>opt;
        wk.a[0][0]=wk.a[0][1]=3;
        wk.a[1][0]=2;
        wk.a[1][1]=mod-2;
        rev.a[0][0]=rev.a[1][1]=0;
        if (opt==1){
            cin>>tag>>l>>r>>x;
            upd(1,1,n,tag,l,r,x);
        }
        if (opt==2){
            cin>>l>>r;
            wok(1,1,n,l,r,wk);
        }
        if (opt==3){
            cin>>l>>r;
            wok(1,1,n,l,r,rev);
        }
        if (opt==4){
            cin>>l>>r;
            cout<<q(1,1,n,l,r);
        }
    }
}