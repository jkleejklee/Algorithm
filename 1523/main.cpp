#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1005;
vector<int> G[N];
int low[N];
int dfn[N];
int cut[N]; 
int Dindex;
int child; 
void init()
{
    for (int i = 0; i <= N; i++)
        G[i].clear();
    fill(dfn, dfn + N, 0);
    fill(low, low + N, 0);
    fill(cut, cut + N, 0);
    Dindex = child = 0;
}
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
            if (low[v] >= dfn[u])
            {
                if (u == 1)
                    child++;
                else
                    cut[u]++;
            }
        }
        else if (dfn[v] < dfn[u] && v != father)
            low[u] = min(low[u], dfn[v]);
    }
    if (u == 1 && child > 1)
        cut[1] = child - 1;
}
void solve(int k)
{
    bool f = false;
    tarjan(1, 0);
    printf("Network #%d\n", k);
    for (int i = 1; i < N; i++)
        if (cut[i])
        {
            f = true;
            printf("  SPF node %d leaves %d subnets\n", i, cut[i] + 1);
        }
    if (!f)
        printf("  No SPF nodes\n");
    printf("\n");
}
int main()
{
    int a;
    int k = 1;
    bool e = false;
    init();
    while (~scanf("%d", &a))
    {
        if (!a && !e)
        {
            solve(k++);
            init();
            e = true;
        }
        if (a)
        {
            int b;
            scanf("%d", &b);
            G[a].push_back(b);
            G[b].push_back(a);
            e = false;
        }
    }
    return 0;
}
