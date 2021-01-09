#include <cstdio>
using namespace std;
int main()
{
    int s, d;
    while (~scanf("%d%d", &s, &d))
    {
        int ans = -1;
        if (4 * s - d < 0)
            ans = 10 * s - 2 * d;
        else if (3 * s - 2 * d < 0)
            ans = 8 * s - 4 * d;
        else if (2 * s - 3 * d < 0)
            ans = 6 * s - 6 * d;
        else if (s - 4 * d < 0)
            ans = 3 * s - 9 * d;
        ans < 0 ? printf("Deficit\n") : printf("%d\n", ans);
    }
    return 0;
}
