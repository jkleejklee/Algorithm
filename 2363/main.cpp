#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    int c;
    scanf("%d", &c);
    while (c--)
    {
        int n;
        int ans = INT_MAX;
        scanf("%d", &n);
        for (int x = 1; x * x * x <= n; x++)
            for (int y = 1; y * y <= n; y++)
                for (int z = 1; z <= n; z++)
                    if (x * y * z == n)
                        ans = min(ans, (x * y + y * z + z * x) * 2);
        printf("%d\n", ans);
    }
    return 0;
}
