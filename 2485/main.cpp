#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 505;
const int M = N * (N - 1) / 2;
int p[N];
struct Edge
{
    int u, v; 
    int w; 
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
int Kruskal(int m)
{
    int ans = 0;
    sort(e + 1, e + m + 1); 
    for (int i = 1; i <= m; i++)
    {
        if (Find(e[i].u) != Find(e[i].v))
        {
            Union(Find(e[i].u), Find(e[i].v));
            ans = e[i].w;
        }
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n; 
        scanf("%d", &n);
        int m = 0; 
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                int a;
                scanf("%d", &a);
                if (i < j)
                    e[++m] = Edge(i, j, a);
            }
        fill(p, p + N, -1);
        printf("%d\n", Kruskal(m));
    }
    return 0;
}
