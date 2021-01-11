#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 510;
const int M = 20000;
bool vis[N];
int match[N];
int n;
struct Edge
{
    int u, v, w, next;
    Edge() {}
    Edge(int a, int b, int c, int d) : u(a), v(b), w(c), next(d) {}
} e[M];
int head[N], p;
void init()
{
    fill(head, head + N, -1);
    p = 0;
}
void addEdge(int u, int v)
{
    e[p] = Edge(u, v, 1, head[u]);
    head[u] = p++;
}
bool DFS(int u)
{
    for (int i = head[u]; i + 1; i = e[i].next)
    {
        int v = e[i].v;
        if (e[i].w && !vis[v])
        {
            vis[v] = true;
            if (match[v] == -1 || DFS(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}
int KM()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        memset(vis, 0, sizeof(vis));
        if (DFS(i))
            ans++;
    }
    return ans;
}
int main()
{
    while (~scanf("%d", &n))
    {
        init();
        memset(match, -1, sizeof(match));
        for (int i = 0; i < n; i++)
        {
            int p;
            scanf("%*d: (%d)", &p);
            while (p--)
            {
                int q;
                scanf("%d", &q);
                addEdge(i, q);
            }
        }
        printf("%d\n", n - KM() / 2);
    }
    return 0;
}
