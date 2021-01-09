#include <cstdio>
using namespace std;
int a, b, c, d, e, f;
int solve()
{
    int ans = d + e + f;
    if (e > 0)
        a -= 11 * e;
    if (d > 0)
    {
        b -= 5 * d;
        if (b < 0 && a > 0)
            a -= -4 * b;
    }
    ans += c / 4;
    c = c % 4;
    if (c > 0)
        ans++;
    if (c == 1 && b > 0)
    {
        b -= 5;
        a -= 7;
    }
    if (c == 2 && b > 0)
    {
        b -= 3;
        a -= 6;
    }
    if (c == 3 && b > 0)
    {
        b -= 1;
        a -= 5;
    }
    if (b > 0)
    {
        ans += b / 9;
        b = b % 9;
    }
    if (b > 0)
    {
        ans++;
        a -= 36 - b * 4;
    }
    if (a > 0)
        ans += (a - 1) / 36 + 1;
    return ans;
}
int main()
{
    while (scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f) && a + b + c + d + e + f)
        printf("%d\n", solve());
    return 0;
}
