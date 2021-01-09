#include <cstdio>
using namespace std;
int f(int m, int n)
{
    if (m < 0 || n == 0)
        return 0;
    if (m == 1 || n == 1)
        return 1;
    return f(m, n - 1) + f(m - n, n);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int m, n;
        scanf("%d%d", &m, &n);
        printf("%d\n", f(m, n));
    }
    return 0;
}
