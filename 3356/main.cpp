#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1005;
int main()
{
    int a, b;
    char x[N], y[N];
    int D[N][N];
    while (~scanf("%d %s", &a, x))
    {
        scanf("%d %s", &b, y);
        for (int i = 0; i < N; i++)
            D[i][0] = D[0][i] = i;
        for (int i = 1; i <= a; i++)
            for (int j = 1; j <= b; j++)
            {
                int u = D[i - 1][j] + 1; 
                int v = D[i][j - 1] + 1; 
                int w = D[i - 1][j - 1] + !(x[i - 1] == y[j - 1]); 
                D[i][j] = min(min(u, v), w); 
            }
        printf("%d\n", D[a][b]);
    }
    return 0;
}
