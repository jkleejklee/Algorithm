#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 105;
vector<int> G[N];
int low[N];
int dfn[N];
bool iscut[N]; 
int Dindex;
int n;
void init()
{
    for (int i = 0; i <= n; i++)
        G[i].clear();
    fill(dfn, dfn + N, 0);
    fill(low, low + N, 0);
    fill(iscut, iscut + N, false);
    Dindex = 0;
}
void tarjan(int u, int father)
{
    int child = 0; 
    low[u] = dfn[u] = ++Dindex;
    for (unsigned int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (!dfn[v])
        {
            child++;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u] && u != 1)
                iscut[u] = true;
        }
        else if (dfn[v] < dfn[u] && v != father)
            low[u] = min(low[u], dfn[v]);
    }
    if (u == 1 && child > 1)
        iscut[1] = true;
}
void solve()
{
    int ans = 0;
    tarjan(1, 0);
    for (int i = 1; i <= n; i++)
        ans += iscut[i];
    printf("%d\n", ans);
}
int main()
{
    int a, b;
    char c;
    while (scanf("%d", &n) && n)
    {
        init();
        while (scanf("%d", &a) && a)
        {
            do
            {
                scanf("%d%c", &b, &c);
                G[a].push_back(b);
                G[b].push_back(a);
            } while (c != '\n');
        }
        solve();
    }
    return 0;
}
