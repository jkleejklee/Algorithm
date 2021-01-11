#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1005;
const int M = 20005;
int n; 
int p[N];
struct Edge
{
    int u, v;
    int w; 
    Edge() {}
    Edge(int a, int b, int c) : u(a), v(b), w(c) {}
    bool operator<(const Edge &a) const
    {
        return w > a.w;
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
    int k = 1; 
    int ans = 0;
    sort(e + 1, e + m + 1); 
    for (int i = 1; i <= m; i++)
    {
        if (Find(e[i].u) != Find(e[i].v))
        {
            Union(Find(e[i].u), Find(e[i].v));
            ans += e[i].w;
            k++;
        }
    }
    return k == n ? ans : -1; 
}
int main()
{
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        e[i] = Edge(a, b, c);
    }
    fill(p, p + N, -1);
    printf("%d\n", Kruskal(m));
    return 0;
}
