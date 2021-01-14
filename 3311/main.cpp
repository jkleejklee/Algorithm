#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 11;
const int INF = 0x3f3f3f3f;
int n;  
int dis[N][N]; 
int D[1 << N][N];
void floyd()
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
void TSP()
{
    memset(D, 0x3f, sizeof(D));
    D[(1 << n) - 1][0] = 0;
    for (int S = (1 << n) - 2; S >= 0; S--)
        for (int v = 0; v < n; v++)
            for (int u = 0; u < n; u++)
                D[S][v] = min(D[S][v], D[S | (1 << u)][u] + dis[v][u]);
}
int main()
{
    while (scanf("%d", &n) && n)
    {
        n++;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &dis[i][j]);
        floyd();
        TSP();
        printf("%d\n", D[0][0]);
    }
    return 0;
}
