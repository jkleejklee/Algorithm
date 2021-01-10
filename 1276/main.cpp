#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100001;
int V; 
int F[N];
void zeroonePack(int c, int w)
{
    for (int v = V; v >= c; v--)
        F[v] = max(F[v], F[v - c] + w);
}
void completePack(int c, int w)
{
    for (int v = c; v <= V; v++)
        F[v] = max(F[v], F[v - c] + w);
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
    while (~scanf("%d%d", &V, &n))
    {
        fill(F, F + N, 0);
        while (n--)
        {
            int m, d;
            scanf("%d%d", &m, &d);
            multiplePack(d, d, m);
        }
        printf("%d\n", F[V]);
    }
    return 0;
}
