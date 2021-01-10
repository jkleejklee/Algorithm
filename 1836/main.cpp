#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1005;
int main()
{
    double a[N];
    int n;
    scanf("%d", &n);
    int L[N], R[N];
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &a[i]);
        L[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[j] < a[i])
                L[i] = max(L[i], L[j] + 1);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        R[i] = 1;
        for (int j = n - 1; j > i; j--)
            if (a[j] < a[i])
                R[i] = max(R[i], R[j] + 1);
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans = max(ans, L[i] + R[j]);
    printf("%d\n", n - ans);
    return 0;
}
