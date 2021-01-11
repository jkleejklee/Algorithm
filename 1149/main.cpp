#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;
const int N = 1300;
int G[N][N];
int n;
int s; 
int t; 
int level[N];
int maxflow;
bool BFS()
{
    memset(level, -1, sizeof(level));
    queue<int> Q;
    level[s] = 0;
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i <= n + 1; i++)
        {
            if (level[i] == -1 && G[u][i] > 0)
            {
                level[i] = level[u] + 1;
                Q.push(i);
            }
        }
    }
    return level[t] >= 0;
}
int DFS(int u, int flow)
{
    int used = 0;
    if (u == t)
    {
        maxflow += flow;
        return flow;
    }
    for (int v = 0; v <= n + 1; v++)
        if (level[v] == level[u] + 1 && G[u][v])
        {
            int a = DFS(v, min(G[u][v], flow - used));
            G[u][v] -= a;
            G[v][u] += a;
            used += a;
            if (used == flow)
                return used;
        }
    return used;
}
int Dinic()
{
    maxflow = 0;
    while (BFS())
        DFS(s, INT_MAX);
    return maxflow;
}
int main()
{
    int cow[N];
    int pre[N];
    int m;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &cow[i]);
        pre[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        scanf("%d", &a);
        while (a--)
        {
            int k;
            scanf("%d", &k);
            if (pre[k] == 0)
                G[0][i] += cow[k];
            else
                G[pre[k]][i] = INT_MAX;
            pre[k] = i;
        }
        scanf("%d", &b);
        G[i][n + 1] = b;
    }
    s = 0;
    t = n + 1;
    printf("%d\n", Dinic());
    return 0;
}
