#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
struct SegmentTree
{
    int p; 
    int r;  
    long long k; 
    long long s; 
    SegmentTree() {}
    SegmentTree(int a, int b) : p(a), r(b), k(0) {} 
} T[3 * N];
int A[N];
long long ans;
void build(int x, int p, int r)
{
    T[x] = SegmentTree(p, r);
    if (p == r)
    {
        T[x].s = A[p];
        return;
    }
    build(2 * x, p, (p + r) / 2);
    build(2 * x + 1, (p + r) / 2 + 1, r);
    T[x].s = T[x * 2].s + T[x * 2 + 1].s;
}
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
void update(int x, int p, int r, long long c)
{
    if (T[x].r < p || T[x].p > r)
        return;
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
void query(int x, int p, int r)
{
    if (T[x].r < p || T[x].p > r)
        return;
    if (T[x].p >= p && T[x].r <= r)
    {
        ans += T[x].s; 
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
