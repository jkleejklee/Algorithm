#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 50005;
const int MIN = -10000;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int L[N], R[N];
        L[0] = R[n + 1] = MIN;
        int a[N];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            L[i + 1] = max(a[i], L[i] + a[i]);
        }
        for (int i = 1; i <= n; i++)
            L[i] = max(L[i - 1], L[i]);
        for (int i = n; i > 0; i--)
            R[i] = max(a[i - 1], R[i + 1] + a[i - 1]);
        for (int i = n; i > 0; i--)
            R[i] = max(R[i + 1], R[i]);
        int ans = MIN;
        for (int i = 1; i < n; i++)
            ans = max(ans, L[i] + R[i + 1]);
        printf("%d\n", ans);
    }
    return 0;
}
