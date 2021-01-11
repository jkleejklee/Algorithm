#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 101;
const int INF = 0x3f3f3f3f;
int D[N][N];
int n;
void Floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
}
int main()
{
    while (scanf("%d", &n) && n)
    {
        memset(D, 0x3f, sizeof(D));
        for (int i = 1; i <= n; i++)
        {
            D[i][i] = 0;
            int m;
            scanf("%d", &m);
            while (m--)
            {
                int j, v;
                scanf("%d%d", &j, &v);
                D[i][j] = v;
            }
        }
        Floyd();
        int minD = INF; 
        int mini = 0;
        for (int i = 1; i <= n; i++)
        {
            int maxD = 0; 
            for (int j = 1; j <= n; j++)
                maxD = max(maxD, D[i][j]);
            if (maxD < minD)
            {
                minD = maxD;
                mini = i;
            }
        }
        mini ? printf("%d %d\n", mini, minD) : printf("disjoint\n");
    }
    return 0;
}
