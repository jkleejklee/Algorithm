#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 10005;
struct SegmentTree
{
    int p; 
    int r; 
    int k; 
    SegmentTree() {}
    SegmentTree(int a, int b) : p(a), r(b), k(0) {} 
} T[10 * N];
int ans;
bool v[N];
void build(int x, int p, int r)
{
    T[x] = SegmentTree(p, r);
    if (p == r)
        return;
    build(2 * x, p, (p + r) / 2);
    build(2 * x + 1, (p + r) / 2 + 1, r);
}
void update(int x, int p, int r, int i)
{
    if (T[x].r < p || T[x].p > r)
        return;
    if (T[x].p == p && T[x].r == r)
    {
        T[x].k = i;
        return;
    }
    if (T[x].k != 0 && T[x].k != i)
    {
        T[x * 2].k = T[x].k;
        T[x * 2 + 1].k = T[x].k;
        T[x].k = 0;
    }
    int q = (T[x].p + T[x].r) / 2;
    update(x * 2, p, min(q, r), i);
    update(x * 2 + 1, max(q + 1, p), r, i);
}
void query(int x)
{
    if (T[x].k != 0)
    {
        if (!v[T[x].k])
        {
            v[T[x].k] = true;
            ans++;
        }
    }
    else if (T[x].p != T[x].r)
    {
        query(2 * x);
        query(2 * x + 1);
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        fill(v, v + N, false);
        int n;
        scanf("%d", &n);
        int L[N]; 
        int R[N]; 
        int P[2 * N]; 
        for (int i = 1, j = 1; i <= n; i++)
        {
            scanf("%d%d", &L[i], &R[i]);
            P[j++] = L[i];
            P[j++] = R[i] + 1;
        }
        sort(P + 1, P + n * 2 + 1);
        int m = unique(P + 1, P + n * 2 + 1) - P - 1; 
        build(1, 1, m);
        for (int i = 1; i <= n; i++)
        {
            int p = lower_bound(P + 1, P + m, L[i]) - P; 
            int r = upper_bound(P + 1, P + m, R[i]) - P - 1; 
            update(1, p, r, i);
        }
        ans = 0;
        query(1);
        printf("%d\n", ans);
    }
    return 0;
}
