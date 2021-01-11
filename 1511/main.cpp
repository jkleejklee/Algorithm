#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1000005;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int u, v, w;
    int next;
    Edge() {}
    Edge(int a, int b, int c) : u(a), v(b), w(c), next(-1) {}
} e[N];
int head[N];
int p;
long long d[N];
void init()
{
    fill(head, head + N, -1);
    p = 0;
}
void addEdge(int u, int v, int w)
{
    e[p] = Edge(u, v, w);
    e[p].next = head[u];
    head[u] = p++;
}
bool relax(int u, int v, int w)
{
    return (d[v] > d[u] + w) ? (d[v] = d[u] + w, true) : false;
}
void SPFA(int n, int s)
{
    queue<int> Q;
    bool in[N] = {0}; 
    fill(d, d + n + 1, INF);
    d[s] = 0;
    in[s] = true;
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        in[u] = false;
        for (int i = head[u]; i + 1; i = e[i].next)
            if (relax(u, e[i].v, e[i].w) && !in[e[i].v])
            {
                Q.push(e[i].v);
                in[e[i].v] = true;
            }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int p, q;
        scanf("%d%d", &p, &q);
        init();
        for (int i = 0; i < q; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
        }
        SPFA(p, 1); 
        long long ans = 0;
        for (int i = 1; i <= p; i++)
            ans += d[i];
        init();
        for (int i = 0; i < q; i++)
            addEdge(e[i].v, e[i].u, e[i].w);
        SPFA(p, 1); 
        for (int i = 1; i <= p; i++)
            ans += d[i];
        printf("%lld\n", ans);
    }
    return 0;
}
