#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1005;
vector<int> G[N];
int low[N];
int dfn[N];
int Dindex = 0;
int n; 
void tarjan(int u, int father)
{
    low[u] = dfn[u] = ++Dindex;
    for (unsigned int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if (dfn[v] < dfn[u] && v != father)
            low[u] = min(low[u], dfn[v]);
    }
}
void solve()
{
    int k = 0;  
    int D[N] = {0}; 
    tarjan(1, 0);
    for (int i = 1; i <= n; i++)
        for (unsigned int j = 0; j < G[i].size(); j++)
            if (low[i] != low[G[i][j]])
                D[low[i]]++;
    for (int i = 1; i <= n; i++)
        if (D[i] == 1)
            k++;
    printf("%d\n", (k + 1) / 2);
}
int main()
{
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        G[i].clear();
    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (find(G[a].begin(), G[a].end(), b) != G[a].end())
            continue;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    solve();
    return 0;
}
