#include<iostream>
using namespace std;

const int maxn = 1e5 + 10;
struct segTree
{
    int left, right;
    int val;
    int addMark;    //延迟标记
} segTree[maxn * 4];

void pushUp(int rt)    //更新父节点值
{
    segTree[rt].val = segTree[rt * 2].val + segTree[rt * 2 + 1].val;
}
void build(int l, int r, int rt)
{
    segTree[rt].addMark = 0;
    segTree[rt].left = l;
    segTree[rt].right = r;
    segTree[rt].val = 1;    //刚开始都是铜棒1
    if(l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, rt * 2);
    build(mid + 1, r, rt * 2 + 1);
    pushUp(rt);
}

void pushDown(int rt)    //更新延迟标记
{
    if(segTree[rt].addMark != 0)    //被标记了
    {
        //延迟标记传递更新
        segTree[rt * 2].addMark = segTree[rt].addMark;    //因为这里是直接改变，只记录最后结果，所以不用+=。eg：铜变银再变金，只记录金即可
        segTree[rt * 2 + 1].addMark = segTree[rt].addMark;
        //节点值传递更新
        segTree[rt * 2].val = segTree[rt].addMark * (segTree[rt * 2].right - segTree[rt * 2].left + 1);
        segTree[rt * 2 + 1].val = segTree[rt].addMark * (segTree[rt * 2 + 1].right - segTree[rt * 2 + 1].left + 1);
        segTree[rt].addMark = 0;    //标记清空
    }
}

void update(int x, int y, int w, int l, int r, int rt)
{
    if(x > r || y < l)
    {
        return;
    }
    if(x <= l && y >= r)
    {
        segTree[rt].addMark = w ;
        segTree[rt].val = w * (segTree[rt].right - segTree[rt].left + 1) ;
        return;
    }
    pushDown(rt);
    int mid = (l + r) / 2;
    if(x <= mid)
        update(x, y, w, l, mid, rt * 2);
    if(y > mid)
        update(x, y, w, mid + 1, r, rt * 2 + 1);
    pushUp(rt);
}

int main()
{
    ios::sync_with_stdio(false);
    int t, n, q, x, y, w, ca = 1;
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        build(1, n, 1);
        while(q--)
        {
            cin >> x >> y >> w;
            update(x, y, w, 1, n, 1);
        }
        cout << "Case " << ca << ": The total value of the hook is " << segTree[1].val << "." << endl;
        ca++;
    }
    return 0;
}