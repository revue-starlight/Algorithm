void build(int x,int l,int r){
    if (l==r) tree[x] = a[i];
    else {
        int mid = (l+r)>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);   
    }
}