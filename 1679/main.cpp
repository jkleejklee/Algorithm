#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 105;
const int M = N * (N - 1) / 2;
int p[N];
struct Edge
{
    int u, v, w;
    Edge() {}
    Edge(int a, int b, int c) : u(a), v(b), w(c) {}
    bool operator<(const Edge &a) const
    {
        return w < a.w;
    }
} e[M];
int Find(int x)
{
    return (p[x] < 0) ? x : Find(p[x]);
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x > y)
        p[x] = y;
    if (x < y)
        p[y] = x;
}
int Kruskal(int n)
{
    int s = 0;
    sort(e + 1, e + n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x = Find(e[i].u);
        int y = Find(e[i].v);
        if (x != y)
        {
            for (int j = i + 1; j <= n; j++)
                if (e[j].w == e[i].w && x == Find(e[j].u) && y == Find(e[j].v))
                    return -1;
            Union(x, y);
            s += e[i].w;
        }
    }
    return s;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            int x, y, w;
            scanf("%d%d%d", &x, &y, &w);
            e[i] = (x < y) ? Edge(x, y, w) : Edge(y, x, w);
        }
        fill(p, p + N, -1);
        int ans = Kruskal(m);
        ~ans ? printf("%d\n", ans) : printf("Not Unique!\n");
    }
    return 0;
}
