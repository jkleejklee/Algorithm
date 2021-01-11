#include <cstdio>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
const int N = 1005;
const int M = 50005;
struct Edge
{
    int u, v, w;
    int f; 
    int next;
    Edge() {}
    Edge(int a, int b, int c, int d, int e) : u(a), v(b), w(c), f(d), next(e) {}
} e[M];
int head[N], p;
int D[N];
int pre[N]; 
int s, t;
void init()
{
    fill(head, head + N, -1);
    p = 0;
}
void addEdge(int u, int v, int w, int f)
{
    e[p] = Edge(u, v, w, f, head[u]);
    head[u] = p++;
}
bool relax(int u, int v, int w)
{
    return (D[v] > D[u] + w) ? (D[v] = D[u] + w, true) : false;
}
bool SPFA()
{
    queue<int> Q;
    fill(D, D + N, INT_MAX);
    fill(pre, pre + N, -1);
    D[s] = 0;
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int i = head[u]; i + 1; i = e[i].next)
            if (e[i].f && relax(u, e[i].v, e[i].w))
            {
                pre[e[i].v] = i;
                Q.push(e[i].v);
            }
    }
    return D[t] != INT_MAX; 
}
int Maxflow()
{
    int f = INT_MAX;
    int cost = 0;
    while (SPFA())
    {
        cost += D[t];
        for (int i = pre[t]; i + 1; i = pre[e[i].u])
            f = min(f, e[i].f);
        for (int i = pre[t]; i + 1; i = pre[e[i].u])
        {
            e[i].f -= f;
            e[i ^ 1].f += f;
        }
    }
    return cost;
}
int main()
{
    int n, m;
    init();
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w, 1);
        addEdge(v, u, -w, 0);
        addEdge(v, u, w, 1);
        addEdge(u, v, -w, 0);
    }
    s = 0;
    addEdge(s, 1, 0, 2);
    addEdge(1, s, 0, 0);
    t = n + 1;
    addEdge(n, t, 0, 2);
    addEdge(t, n, 0, 0);
    printf("%d\n", Maxflow());
    return 0;
}
