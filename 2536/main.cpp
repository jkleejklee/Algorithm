#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 310;
int G[N][N];
bool vis[N];
int match[N];
int n, m;
double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
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
    int s, v;
    while (~scanf("%d%d%d%d", &n, &m, &s, &v))
    {
        memset(G, 0, sizeof(G));
        memset(match, 0, sizeof(match));
        double x[N], y[N];
        for (int i = 1; i <= n; i++)
            scanf("%lf%lf", &x[i], &y[i]);
        for (int j = 1; j <= m; j++)
        {
            double xh, yh;
            scanf("%lf%lf", &xh, &yh);
            for (int i = 1; i <= n; i++)
                G[i][j] = (dist(x[i], y[i], xh, yh) < s * v);
        }
        printf("%d\n", n - KM());
    }
    return 0;
}
