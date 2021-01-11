#include <cstdio>
#include <queue>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
const int N = 105;
int G[N][N];
int pre[N];
int n;
bool BFS(int s, int t)
{
    memset(pre, -1, sizeof(pre));
    queue<int> Q;
    pre[s] = 0;
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i <= n + 1; i++)
            if (pre[i] == -1 && G[u][i] > 0)
            {
                pre[i] = u;
                if (i == t)
                    return true;
                Q.push(i);
            }
    }
    return false;
}
int EK(int s, int t)
{
    int maxflow = 0;
    while (BFS(s, t))
    {
        int minflow = INT_MAX;
        for (int i = t; i != s; i = pre[i])
            minflow = min(minflow, G[pre[i]][i]);
        for (int i = t; i != s; i = pre[i])
        {
            G[pre[i]][i] -= minflow;
            G[i][pre[i]] += minflow;
        }
        maxflow += minflow;
    }
    return maxflow;
}
int main()
{
    int np, nc, m;
    int u, v, z;
    while (~scanf("%d%d%d%d ", &n, &np, &nc, &m))
    {
        memset(G, 0, sizeof(G));
        while (m--)
        {
            scanf("(%d,%d)%d ", &u, &v, &z);
            G[u][v] = z;
        }
        while (np--)
        {
            scanf("(%d)%d ", &u, &z);
            G[n][u] = z;
        }
        while (nc--)
        {
            scanf("(%d)%d ", &u, &z);
            G[u][n + 1] = z;
        }
        printf("%d\n", EK(n, n + 1));
    }
    return 0;
}
