#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
struct SegmentTree
{
    int p;       //线段左端点
    int r;       //线段右端点
    long long k; //暂存子节点还需累加的值
    long long s; //区间和
    SegmentTree() {}
    SegmentTree(int a, int b) : p(a), r(b), k(0) {} // k初始值为0
} T[3 * N];
int A[N];
long long ans;
//构建求和线段树
void build(int x, int p, int r)
{
    T[x] = SegmentTree(p, r);
    //如果为叶子节点，则s值等于对应A中的值
    if (p == r)
    {
        T[x].s = A[p];
        return;
    }
    build(2 * x, p, (p + r) / 2);
    build(2 * x + 1, (p + r) / 2 + 1, r);
    //否则s值等于左右儿子节点的s值之和
    T[x].s = T[x * 2].s + T[x * 2 + 1].s;
}
//根据父节点的k值更新子节点的s值和k值，完成后将父节点的k值置0
void updatechild(int x)
{
    if (T[x].k)
    {
        T[x * 2].s += (T[x * 2].r - T[x * 2].p + 1) * T[x].k;
        T[x * 2].k += T[x].k;
        T[x * 2 + 1].s += (T[x * 2 + 1].r - T[x * 2 + 1].p + 1) * T[x].k;
        T[x * 2 + 1].k += T[x].k;
        T[x].k = 0;
    }
}
//给定区间[p,r]的元素每个加上c，依次更新各个节点的s值和k值
void update(int x, int p, int r, long long c)
{
    if (T[x].r < p || T[x].p > r)
        return;
    //如果节点表示的区间完全在所求区间内，直接用节点的s值，而不用立刻更新该节点的所有子节点信息
    if (T[x].p >= p && T[x].r <= r)
    {
        T[x].s += (T[x].r - T[x].p + 1) * c;
        if (T[x].p < T[x].r)
            T[x].k += c;
        return;
    }
    updatechild(x);
    update(x * 2, p, r, c);
    update(x * 2 + 1, p, r, c);
    T[x].s = T[x * 2].s + T[x * 2 + 1].s;
}
//查询区间[p,r]的累加和
void query(int x, int p, int r)
{
    if (T[x].r < p || T[x].p > r)
        return;
    //如果所查询的节点表示的区间完全在所求区间内，直接用节点的s值，而不用立刻更新该节点的所有子节点信息
    if (T[x].p >= p && T[x].r <= r)
    {
        ans += T[x].s; //将累加和放入ans中
        return;
    }
    updatechild(x);
    query(2 * x, p, r);
    query(2 * x + 1, p, r);
}
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    build(1, 1, n);
    while (q--)
    {
        int a, b;
        char Q;
        scanf("\n%c%d%d", &Q, &a, &b);
        if (Q == 'C')
        {
            long long c;
            scanf("%lld", &c);
            update(1, a, b, c);
        }
        else
        {
            ans = 0;
            query(1, a, b);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
