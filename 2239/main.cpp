#include <cstdio>
#include <cstring>
using namespace std;
const int N = 310;
int G[N][N];  
bool vis[N]; 
int match[N]; 
int n, m;
bool DFS(int i)
{
    for (int j = 1; j <= m; j++)
        if (G[i][j] && !vis[j])
        {
            vis[j] = true;
            if (match[j] == 0 || DFS(match[j]))
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
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        if (DFS(i))
            ans++;
    }
    return ans;
}
int main()
{
    while (~scanf("%d", &n))
    {
        memset(G, 0, sizeof(G));
        memset(match, 0, sizeof(match));
        for (int i = 1; i <= n; i++)
        {
            int t;
            scanf("%d", &t);
            while (t--)
            {
                int p, q;
                scanf("%d%d", &p, &q);
                G[i][(p - 1) * 12 + q] = 1;
            }
        }
        m = 84;
        printf("%d\n", KM());
    }
    return 0;
}
