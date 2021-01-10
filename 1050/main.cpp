#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int ans = -128;
    int a[101][101] = {0};
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int t;
            scanf("%d", &t);
            a[i][j] = a[i][j - 1] + t;
        }
    for (int j = 1; j <= n; j++)
        for (int k = 0; k < j; k++)
            for (int i = 1, sum = 0; i <= n; i++)
            {
                sum = a[i][j] - a[i][k] + max(0, sum);
                ans = max(ans, sum);
            }
    printf("%d\n", ans);
    return 0;
}
