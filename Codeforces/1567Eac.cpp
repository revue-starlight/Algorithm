#include<stdio.h>
#define lc(x) (x)<<1
#define rc(x) (x)<<1|1
using namespace std;
const int maxn=200005,maxt=maxn<<2;
int n,m;
int a[maxn],b[maxn];
struct node{
	int pre,suf,z,tot;
	long long sum;
}t[maxt];
node merge(node a,node b){
	node res;
	res.pre=a.z? a.tot+b.pre:a.pre,res.suf=b.z? b.tot+a.suf:b.suf;
	res.z=a.z&b.z,res.tot=a.tot+b.tot,res.sum=a.sum+b.sum;
	if(a.suf&&b.pre)
		res.sum-=1ll*a.suf*(a.suf+1)/2+1ll*b.pre*(b.pre+1)/2,res.sum+=1ll*(a.suf+b.pre)*(a.suf+b.pre+1)/2;
	return res;
}
inline void pushup(int now){
	t[now]=merge(t[lc(now)],t[rc(now)]);
}
void build(int l,int r,int now){
	if(l==r){
		t[now].pre=t[now].suf=t[now].z=t[now].tot=t[now].sum=b[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,lc(now)),build(mid+1,r,rc(now));
	pushup(now);
}
void update(int l,int r,int now,int pos){
	if(l==r){
		b[l]^=1,t[now].pre=t[now].suf=t[now].z=t[now].tot=t[now].sum=b[l];
		return ;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)
		update(l,mid,lc(now),pos);
	else update(mid+1,r,rc(now),pos);
	pushup(now);
}
node query(int l,int r,int now,int L,int R){
	if(L<=l&&r<=R)
		return t[now];
	int mid=(l+r)>>1;
	if(L<=mid&&mid<R)
		return merge(query(l,mid,lc(now),L,R),query(mid+1,r,rc(now),L,R));
	if(L<=mid)
		return query(l,mid,lc(now),L,R);
	return query(mid+1,r,rc(now),L,R);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
		b[i]=a[i]<=a[i+1];
	if(n>1)
		build(1,n-1,1);
	while(m--){
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(t==1){
			a[x]=y;
			if(x>1&&b[x-1]!=(a[x-1]<=a[x]))
				update(1,n-1,1,x-1);
			if(x<n&&b[x]!=(a[x]<=a[x+1]))
				update(1,n-1,1,x);
		}
		if(t==2)
			printf("%lld\n",x==y? 1:(query(1,n-1,1,x,y-1).sum+(y-x+1)));
	}
	return 0;
}