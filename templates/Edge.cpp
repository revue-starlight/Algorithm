int head[N],tot;
struct Edge{
    int u,v,next;
}e[N<<2];
void add(int u,int v){e[++tot]={u,v,head[u]};head[u]=tot;}