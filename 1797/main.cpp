#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1005;
int n;
int D[N];  
int a[N][N]; 
void Dijkstra(int s)
{
    bool vis[N];
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
        D[i] = a[s][i];
    vis[s] = true;
    for (int i = 1; i < n; i++)
    {
        int t = 0;
        int u;
        for (int j = 1; j <= n; j++)
            if (t <= D[j] && !vis[j]) 
                t = D[u = j];
        vis[u] = true;
        for (int v = 1; v <= n; v++)
            if (!vis[v])
                D[v] = max(D[v], min(D[u], a[u][v])); 
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        int m;
        scanf("%d%d", &n, &m);
        memset(a, 0, sizeof(a));
        while (m--)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            a[u][v] = a[v][u] = w;
        }
        Dijkstra(1);
        printf("Scenario #%d:\n%d\n\n", i, D[n]);
    }
    return 0;
}
