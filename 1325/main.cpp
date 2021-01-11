#include <cstdio>
#include <cstring>
using namespace std;
const int N = 101;
int G[N][N];
bool vis[N];
int match[N];
int n, m;
bool DFS(int i)
{
    for (int j = 0; j < m; j++)
        if (G[i][j] && !vis[j])
        {
            vis[j] = true;
            if (!match[j] || DFS(match[j]))
            {
                match[j] = i;
                return true;
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
    while (scanf("%d", &n) && n)
    {
        memset(G, 0, sizeof(G));
        memset(match, 0, sizeof(match));
        int k;
        scanf("%d%d", &m, &k);
        while (k--)
        {
            int i, x, y;
            scanf("%d%d%d", &i, &x, &y);
            if (x > 0 && y > 0)
                G[x][y] = 1;
        }
        printf("%d\n", KM());
    }
    return 0;
}
