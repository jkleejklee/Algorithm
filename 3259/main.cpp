#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 505;
const int INF = 0x3f3f3f3f;
int D[N][N];
int n;
bool Floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                if (D[i][j] > D[i][k] + D[k][j])
                    D[i][j] = D[i][k] + D[k][j];
            if (D[i][i] < 0)
                return true;
        }
    return false;
}
int main()
{
    int f;
    scanf("%d", &f);
    while (f--)
    {
        int m, w, s, e, t;
        scanf("%d%d%d", &n, &m, &w);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                D[i][j] = (i == j) ? 0 : INF;
        while (m--)
        {
            scanf("%d%d%d", &s, &e, &t);
            D[s][e] = D[e][s] = min(D[s][e], t);
        }
        while (w--)
        {
            scanf("%d%d%d", &s, &e, &t);
            D[s][e] = -t;
        }
        Floyd() ? puts("YES") : puts("NO");
    }
    return 0;
}
