#include <cstdio>
using namespace std;
const int N = 20000;
struct SegmentTree
{
    int p;
    int r; 
    int n; 
    SegmentTree() {}
    SegmentTree(int a, int b) : p(a), r(b), n(b - a + 1) {}
} T[N];
void build(int x, int p, int r)
{
    T[x] = SegmentTree(p, r);
    if (p == r)
        return;
    build(2 * x, p, (p + r) / 2);
    build(2 * x + 1, (p + r) / 2 + 1, r);
}
int query(int x, int k)
{
    T[x].n--;
    if (T[x].p == T[x].r)
        return T[x].p;
    else if (k <= T[2 * x].n)
        return query(2 * x, k);
    else
        return query(2 * x + 1, k - T[2 * x].n);
}
int main()
{
    int n;
    scanf("%d", &n);
    build(1, 1, n);
    int a[N]; 
    for (int i = 2; i <= n; i++)
        scanf("%d", &a[i]);
    int ans[N];
    for (int i = n; i >= 1; i--)
        ans[i] = query(1, a[i] + 1);
    for (int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
    return 0;
}
