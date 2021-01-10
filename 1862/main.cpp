#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int n;
    double a[102];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = n; i > 1; i--)
        a[i - 1] = 2 * sqrt(a[i] * a[i - 1]);
    printf("%.3lf\n", a[1]);
    return 0;
}
