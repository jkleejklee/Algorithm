#include <cstdio>
#include <cstring>
using namespace std;
const int N = 121;
int G[N][N];
bool vis[N];
int match[N];
int m;
bool DFS(int i)
{
    for (int j = 1; j <= m; j++)
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
    for (int i = 1; i <= m; i++)
    {
        memset(vis, 0, sizeof(vis));
        if (DFS(i))
            ans++;
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(G, 0, sizeof(G));
        memset(match, 0, sizeof(match));
        int k;
        scanf("%d%d", &m, &k);
        while (k--)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            G[x][y] = 1;
        }
        printf("%d\n", m - KM());
    }
    return 0;
}
