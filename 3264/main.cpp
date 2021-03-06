#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
const int N = 50005;
struct SegmentTree
{
    int p;   
    int r;   
    int Max; 
    int Min; 
} T[3 * N];
int A[N];
int maxi; 
int mini; 
void build(int x, int p, int r)
{
    T[x].p = p;
    T[x].r = r;
    if (p == r)
    {
        T[x].Max = T[x].Min = A[p];
        return;
    }
    build(2 * x, p, (p + r) / 2);
    build(2 * x + 1, (p + r) / 2 + 1, r);
    T[x].Max = max(T[x * 2].Max, T[x * 2 + 1].Max);
    T[x].Min = min(T[x * 2].Min, T[x * 2 + 1].Min);
}
void query(int x, int p, int r)
{
    if (T[x].r < p || T[x].p > r)
        return;
    if (T[x].p >= p && T[x].r <= r)
    {
        maxi = max(maxi, T[x].Max);
        mini = min(mini, T[x].Min);
        return;
    }
    int q = (T[x].p + T[x].r) / 2;
    query(x * 2, p, min(q, r));
    query(x * 2 + 1, max(q + 1, p), r);
}
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    build(1, 1, n);
    for (int i = 1; i <= q; i++)
    {
        maxi = 0;
        mini = INT_MAX;
        int a, b;
        scanf("%d%d", &a, &b);
        query(1, a, b);
        printf("%d\n", maxi - mini);
    }
    return 0;
}
