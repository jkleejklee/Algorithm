#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100001;
int V, F[N];
void zeroonePack(int c, int w)
{
    for (int v = V; v >= c; v--)
        if (F[v] < F[v - c] + w)
            F[v] = F[v - c] + w;
}
void completePack(int c, int w)
{
    for (int v = c; v <= V; v++)
        if (F[v] < F[v - c] + w)
            F[v] = F[v - c] + w;
}
void multiplePack(int c, int w, int m)
{
    if (c * m >= V)
    {
        completePack(c, w);
        return;
    }
    int k = 1;
    while (k < m)
    {
        zeroonePack(k * c, k * w);
        m -= k;
        k <<= 1;
    }
    zeroonePack(m * c, m * w);
}
int main()
{
    int n;
    while (scanf("%d%d", &n, &V) && (n || V))
    {
        fill(F, F + N, 0);
        F[0] = 1;
        int a[101], c[101];
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &c[i]);
        for (int i = 0; i < n; i++)
            multiplePack(a[i], 0, c[i]); 
        int ans = 0;
        for (int i = 1; i <= V; i++)
            if (F[i])
                ans++;
        printf("%d\n", ans);
    }
    return 0;
}
