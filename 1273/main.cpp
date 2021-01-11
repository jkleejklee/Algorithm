#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
const int N = 205;
const int M = 405;
int p;
int head[N];
int n;
int s;
int t;
int maxflow;
int level[N]; 
int gap[N];   
void init()
{
    memset(head, -1, sizeof(head));
    p = 0;
}
struct Edge
{
    int to, next, w;
    Edge() {}
    Edge(int a, int b, int c) : to(a), next(b), w(c) {}
} e[M];
void addEdge(int u, int v, int w)
{
    e[p] = Edge(v, head[u], w);
    head[u] = p++;
}
void BFS()
{
    memset(level, -1, sizeof(level));
    memset(gap, 0, sizeof(gap));
    level[t] = 0;
    gap[0] = 1;
    queue<int> q;
    q.push(t);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i + 1; i = e[i].next)
        {
            int v = e[i].to;
            if (level[v] != -1)
                continue;
            q.push(v);
            level[v] = level[u] + 1;
            gap[level[v]]++;
        }
    }
}
int DFS(int u, int flow)
{
    int used = 0;
    if (u == t)
    {
        maxflow += flow;
        return flow;
    }
    for (int i = head[u]; i + 1; i = e[i].next)
    {
        int v = e[i].to;
        if (e[i].w && level[v] + 1 == level[u])
        {
            int a = DFS(v, min(e[i].w, flow - used));
            e[i].w -= a;
            e[i ^ 1].w += a;
            used += a;
            if (used == flow)
                return used;
        }
    }
    gap[level[u]]--;
    if (gap[level[u]] == 0)
        level[s] = n + 1;
    level[u]++;
    gap[level[u]]++;
    return used;
}
int ISAP()
{
    maxflow = 0;
    BFS();
    while (level[s] < n)
        DFS(s, INT_MAX);
    return maxflow;
}
int main()
{
    int m;
    while (~scanf("%d%d", &m, &n))
    {
        init();
        while (m--)
        {
            int u; 
            int v; 
            int c; 
            scanf("%d%d%d", &u, &v, &c);
            addEdge(u, v, c);
            addEdge(v, u, 0);
        }
        s = 1;
        t = n;
        printf("%d\n", ISAP());
    }
    return 0;
}
