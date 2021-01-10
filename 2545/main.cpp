#include <cstdio>
#include <algorithm>
using namespace std;
long long h[1000000];
int main()
{
    int p1, p2, p3, i;
    while (~scanf("%d%d%d%d", &p1, &p2, &p3, &i))
    {
        h[0] = 1;
        int k1, k2, k3;
        k1 = k2 = k3 = 0;
        for (int k = 1; k <= i; k++)
        {
            long long x1 = h[k1] * p1;
            long long x2 = h[k2] * p2;
            long long x3 = h[k3] * p3;
            h[k] = min(min(x1, x2), x3);
            if (h[k] == x1)
                k1++;
            if (h[k] == x2)
                k2++;
            if (h[k] == x3)
                k3++;
        }
        printf("%lld\n", h[i]);
    }
    return 0;
}
