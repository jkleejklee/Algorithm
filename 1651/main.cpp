#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
const int N = 105;
int main()
{
    int n;
    int a[N];
    int D[N][N] = {0}; 
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int s = 2; s <= n - 1; s++)
        for (int i = 1; i <= n - s; i++)
        {
            int j = i + s;
            D[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++) 
                D[i][j] = min(D[i][j], D[i][k] + D[k][j] + a[i] * a[k] * a[j]);
        }
    printf("%d\n", D[1][n]);
    return 0;
}
